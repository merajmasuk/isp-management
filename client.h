
#ifndef CLIENT_H
#define CLIENT_H

#include "user.h"
#include "package.h"

class client : public user, public package {
    private:
        int clientID;

    public:
        void billing ();
        void CLIENT_DASHBOARD ();
        void changePWD (echo SHOW_ASTERISK=ECHO_ON);
        void LOGIN     (const string& prompt, echo show_asterisk=ECHO_ON);
        void REGISTER  (const string& prompt, echo show_asterisk=ECHO_ON);
};

#endif // CLIENT_H

