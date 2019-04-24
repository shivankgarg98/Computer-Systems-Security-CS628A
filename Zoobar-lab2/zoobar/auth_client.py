from debug import *
from zoodb import *
from rpclib import *
from auth import *

def shot(arg1, arg2): ##helper function to reduce the code size
        return client_connect("/auth_svc/sock").call(arg1)

def login(username, password):
        return client_connect("/auth_svc/sock").call("login",**{"username":username,"password":password})

def register(username, password):
        return client_connect("/auth_svc/sock").call("register",**{"username":username,"password":password})

def commit_person(username, person):
        if (isinstance(person, Person) == False):
                return None
        kwarg = {"username": username, "zoobars": person.zoobars, "profile": person.profile}
        return client_connect("/auth_svc/sock").call("person_commit",**kwarg)

def check_token(username, token):
        return client_connect("/auth_svc/sock").call("check_token",**{"username":username,"token":token})

def get_person(username):
        json_person = client_connect("/auth_svc/sock").call("get_person",**{"username":username})
        if json_person is None or "username" not in json_person:
                return None
        person = Person()
        person.zoobars = json_person["zoobars"]
        person.username, person.profile = json_person["username"], json_person["profile"]
        return person

def get_creds(username):
        json_creds =  client_connect("/auth_svc/sock").call("get_creds",**{"username":username})
        if json_creds is None or "username" not in json_creds:
                return None
        creds = Credentials()
        creds.token = json_creds["token"]
        creds.username, creds.password = json_creds["username"], json_creds["password"]
        return creds

def commit_creds(username, creds):
        if (isinstance(creds, Credentials) == False):
                return None
        if (username != creds.username):
                return None
        kwarg = {"username": username, "password": creds.password, "token": creds.token}    
        return client_connect("/auth_svc/sock").call("credential_commit",**kwarg)

def transact(sender, recipient, zoobars):    
        return client_connect("/auth_svc/sock").call("transact",**{"sender":sender, "recipient": recipient, "zoobars": zoobars})


