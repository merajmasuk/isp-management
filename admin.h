
#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class admin : public user {
    private:
        int employeeID;

    public:
        void LOGIN (const string& prompt, echo show_asterisk=ECHO_ON);
};

#endif // ADMIN_H
