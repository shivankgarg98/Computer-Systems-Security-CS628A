from flask import g, render_template, request
from flask import jsonify
from login import requirelogin
from debug import *
from zoodb import *
from auth_client import *
@catch_err
@requirelogin
def index():
    if 'profile_update' in request.form:
        
        per, cre = get_person(g.user.person.username), get_creds(g.user.person.username)
        commit_person(g.user.person.username, per)
        per.profile = request.form['profile_update']
        log("persons : %s, credential: %s" % (pre, cre))
        cre.profile = request.form['profile_update']
        commit_creds(g.user.person.username, cre)

        ## also update the cached version (see login.py)
        g.user.person.profile = person.profile
    return render_template('index.html')

