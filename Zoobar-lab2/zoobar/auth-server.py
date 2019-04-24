#!/usr/bin/python
import rpclib
import sys
from auth import *
from debug import *

class AuthRpcServer(rpclib.RpcServer):
    def rpc_login(self, username, password):
        logg = login(username, password)
        return logg

    def rpc_register(self, username, password):
        reg=register(username, password)
        return reg

    def rpc_check_token(self, username, token):
        tok_boo = check_token(username, token)
        return tok_boo

    def rpc_get_person(self, username):
        pers = get_person(username)
        return pers

    def rpc_get_creds(self, username):
        creds = get_creds(username) 
        return creds

    def rpc_transact(self, sender, recipient, zoobars):
        pro_tra = process_transaction(sender, recipient, zoobars)
        return pro_tra

    def rpc_person_commit(self, username, zoobars, profile):
        per_com = person_commit(username, zoobars, profile)
        return per_com

    def rpc_credential_commit(self, username, password, token):
        cre_com = credential_commit(username, password, token)
        return cre_com

(_, dummy_zookld_fd, sockpath) = sys.argv

s = AuthRpcServer()
s.run_sockpath_fork(sockpath)
