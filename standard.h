
#ifndef STANDARD_H
#define STANDARD_H

#include "functions.h"

class standard {

    protected:
        int rate, discount;

    public:
        standard(){
            rate = 150, discount = 10;
        }

        void billing_annually();
        void billing_monthly();
};

#endif // STANDARD_H
