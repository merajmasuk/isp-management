
#include <climits>

#include "admin.h"
#include "client.h"

int main() {

    CENTER('*', "LYNX INTERNET");

    char choice;
    do {

        CENTER('=');
        cout << "Enter L to Sign In"       << endl;
        cout << "Enter R to Sign Up"       << endl;
        cout << "Enter Q to Quit"          << endl;

        CENTER('=');

        cout << "Enter Your Choice: ";
        cin >> choice;

        admin controller;
        client customer;
        switch (choice) {
            case 'L':
                cout << "Are you a [1] client or an [2] administrator?\n>>> ";
                char USER_STAT; cin >> USER_STAT;

                while (USER_STAT != '1' && USER_STAT != '2'){
                    cout << "ERR: Wrong designation!\n";
                    cout << "Are you a [1] client or [2] administrator?\n>>> ";
                }

                if (USER_STAT == '1')   customer.LOGIN("Please log in using the security credentials you provided during sign up: ");
                else                  controller.LOGIN("Please sign in using the security credentials provided by your organization: ");

                break;
            case 'R':
                customer.REGISTER("Please set up your account by entering your credentials: ");
                break;
            case 'Q':
                break;
            default:
                cout << "Undefined choice!\n" << endl;
        }
    } while (choice != 'Q');

    return 0;
}

/**
    class A
    {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
    };

    class B : public A
    {
        // x is public
        // y is protected
        // z is not accessible from B
    };

    class C : protected A
    {
        // x is protected
        // y is protected
        // z is not accessible from C
    };

    class D : private A    // 'private' is default for classes
    {
        // x is private
        // y is private
        // z is not accessible from D
    };
*/
