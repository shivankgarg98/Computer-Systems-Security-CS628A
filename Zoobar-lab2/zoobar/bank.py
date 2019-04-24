from zoodb import *
from debug import *
from auth_client import *
import time
from flask import jsonify

def transfer(sender, recipient, zoobars):
    if transact(sender, recipient, zoobars) is False:
        raise ValueError()
    transfer = Transfer()
    transfer.sender = sender
    log("sender = %s, zoobars = %s" % (sender, zoobars))
    if zoobars < 0: #check sanity of zoobars
        zoobars = 0
        raise ValueError()
    log(zoobars)
    transfer.amount = zoobars
    transfer.recipient = recipient
    transfer.time = time.asctime()
    transferdb = transfer_setup()
    transferdb.add(transfer)
    transferdb.commit()
    
def balance(username):
    return get_person(username).zoobars

def get_log(username):
    db = transfer_setup()
    q = db.query(Transfer).filter(or_(Transfer.sender==username,
                                    Transfer.recipient==username))
    log("qury : %s" % (q))
    return q