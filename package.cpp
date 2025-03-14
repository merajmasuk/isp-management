
#include "package.h"

package::package(){
    packageType = STANDARD;
}

void package::bill (billing_method METHOD){
    if      (METHOD == MONTHLY){
        if      (packageType == STANDARD) standard::billing_monthly();
        else if (packageType == PREMIUM)   premium::billing_monthly();
    }
    else if (METHOD == YEARLY){
        if      (packageType == STANDARD) standard::billing_annually();
        else if (packageType == PREMIUM)   premium::billing_annually();
    }
}

