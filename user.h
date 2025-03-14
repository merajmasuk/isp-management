
#ifndef USER_H
#define USER_H

#include "functions.h"

#define BACKSPACE (const char) 8
#define RETURN    (const char) 13

enum echo {
    ECHO_OFF=false, ECHO_ON=true
};

class user {
    protected:
        string username, password;

    public:
        virtual void LOGIN (const string& prompt, echo show_asterisk=ECHO_ON) = 0;
};

#endif // USER_H
