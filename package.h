
#ifndef PACKAGE_H
#define PACKAGE_H

#include "standard.h"
#include "premium.h"

enum type {
    STANDARD, PREMIUM
};

enum billing_method {
    MONTHLY, YEARLY
};

class package : public standard, public premium {
    protected:
        int packageID;
        type packageType;

    public:
        package();

        void bill (billing_method METHOD);
};

#endif // PACKAGE_H
