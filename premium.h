

#ifndef PREMIUM_H
#define PREMIUM_H

#include "functions.h"

class premium {
    protected:
        int rate, discount;

    public:
        premium(){
            rate = 250, discount = 15;
        }

        void billing_annually();
        void billing_monthly();
};

#endif // PREMIUM_H


