from zoodb import *
from debug import *
from flask import jsonify
from os import *
import hashlib
import random
import pbkdf2

#helper function to generate token forn loging and registering
def __gen_token__(db_person, db_creds, creds, person):
    hashinput = "%s%.10f" % (creds.password, random.random())
    creds.token = hashlib.md5(hashinput).hexdigest()
    db_creds.commit()
    db_person.commit()
    return creds.token

def login(username, password):
    person = person_setup().query(Person).get(username)
    creds = cred_db().query(Credentials).get(username)
    if person is None:
        return None
    if creds is None:
        return None
    if creds.password == str( pbkdf2.PBKDF2(password, creds.salt).read(16) ).encode('hex'):
        return __gen_token__(person_setup(), cred_db(), creds, person)
    return None

def register(username, password):
    db_person = person_setup()
    db_creds = cred_db()
    person = db_person.query(Person).get(username)
    creds = db_creds.query(Credentials).get(username)
    if person != None:
        return None
    if creds != None:
        return None
    newperson = Person()
    newperson.username = username
    db_person.add(newperson)

    
    newcreds = Credentials()
    newcreds.username = username
    newcreds.salt = str( urandom(16) ).encode('hex')
    newcreds.password = str( pbkdf2.PBKDF2(password, newcreds.salt).read(16) ).encode('hex')
    db_creds.add(newcreds)
    return __gen_token__(db_person, db_creds, newcreds, newperson)

def get_person(username):
    db_person = person_setup()
    person = db_person.query(Person).get(username)
    if person:
        return row2dict(person) 
    return None 
    
def check_token(username, token):
    db_creds = cred_db()
    creds = db_creds.query(Credentials).get(username)
    if creds != None and creds.token == token:
        return True
    return False

def get_creds(username):
    db_creds = cred_db()
    creds = db_creds.query(Credentials).get(username)
    if creds != None:
        dictionary = {}
        for col in creds.__table__.columns:
            dictionary[col.name] = str(getattr(creds, col.name))
        return dictionary
    return None 

def row2dict(r):
    dictionary = {}
    for col in r.__table__.columns:
        dictionary[col.name] = str(getattr(r, col.name))
    return dictionary

# Added this function here since this file has access to the database files
def process_transaction(sender, recipient, zoobars):
    database = person_setup()
    send = database.query(Person).get(sender)
    sender_balance = send.zoobars - zoobars
    if sender_balance < 0:
        return False
    
    rec = database.query(Person).get(recipient)
    recipient_balance = rec.zoobars + zoobars

    if recipient_balance < 0:
        return False
    send.zoobars, rec.zoobars = sender_balance, recipient_balance
    database.commit()

    return True

def person_commit(username, zoobars, profile):
    person = person_setup().query(Person).get(username)
    if person is None:
        return False
    person.username, person.zoobars, person.profile  = username, zoobars, profile
    return True

def credential_commit(username, password, token):
    cred = cred_db().query(Credentials).get(username)
    hashed_pass = str(pbkdf2.PBKDF2(password, creds.salt).read(32)).encode('hex')
    if (creds.password != hashed_pass):
        return None
    creds.salt = str(urandom(32)).encode('hex') 
    creds.password = str(pbkdf2.PBKDF2(password, creds.salt).read(32)).encode('hex')
    creds.token = token
    cred_db().commit()
    return True
