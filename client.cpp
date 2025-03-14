
#include "client.h"

void client::billing (){
    char plan;

    do {
        cout << "Enter 1 to choose monthly plan"     << endl;
        cout << "Enter 2 to choose yearly plan"      << endl;
        cout << "Enter U to upgrade to premium plan" << endl;
        cout << "Enter C to Cancel"                  << endl;

        CENTER('=');

        cout << "Enter Your Choice: ";
        cin >> plan;

        standard STAN;
        premium  PREM;

        switch (plan) {
            case '1':
                if      (packageType == STANDARD) STAN.billing_monthly();
                else if (packageType == PREMIUM)  PREM.billing_monthly();
                break;
            case '2':
                if      (packageType == STANDARD) STAN.billing_annually();
                else if (packageType == PREMIUM)  PREM.billing_annually();
                break;
            case 'U':
                if (this->packageType == PREMIUM)
                    cout << "You've already upgraded to our premium plan!" << endl;
                else this->packageType = PREMIUM;
            case 'C':
                break;
            default:
                cout << "Undefined plan!\n" << endl;
        }
    } while (plan != 'C' || plan == 'U');
}

void client::CLIENT_DASHBOARD(){
    char choice;

    do {
        cout << "Enter C to Change Password"    << endl;
        cout << "Enter B for Billing"           << endl;
        cout << "Enter L to Log Out"            << endl;
        //CENTER('=');
        char FILL = '='; string TEXT = "";
        CONSOLE_SCREEN_BUFFER_INFO n;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &n);
        int CONSOLE_WIDTH = n.srWindow.Right - n.srWindow.Left+1;

        cout << setfill(FILL);

        if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
        else {
            cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
            cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
            cout << endl;
        }

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 'C':
                changePWD();
                break;
            case 'B':
                billing();
                break;
            case 'L':
                break;
            default:
                cout << "Undefined choice!" << endl;
        }
    } while (choice != 'L');
}

void client::changePWD (echo SHOW_ASTERISK){

    unsigned char ch=0;

    fstream credentials;
    credentials.open("CLIENT_INFO.DAT", ios::binary | ios::app | ios::in | ios::out);
    credentials.seekg(0);

    string current, newpass, confirm;
    cout << "Old password: ";
    cin >> current;

    DWORD dwMode, dwRead;
    HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(InputHandle, &dwMode);
    SetConsoleMode(InputHandle,
                   dwMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != RETURN) {
        if (ch == BACKSPACE) {
            if (current.size() != 0) {
                if (SHOW_ASTERISK == ECHO_ON) cout << "\b \b";
                current.resize(current.size()-1);
            }
        }

        else {
            current += ch;
            if (SHOW_ASTERISK == ECHO_ON) cout << '*';
        }
    } SetConsoleMode(InputHandle, dwMode);

    cout << endl;

    if (current == password){
        cout << "New Password: ";
        cin >> newpass;

        while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != RETURN) {
            if (ch == BACKSPACE) {
                if (newpass.size() != 0) {
                    if (SHOW_ASTERISK == ECHO_ON)
                        WriteConsoleA(OutputHandle, "\b \b", 3, &dwRead, NULL);
                    newpass.erase(newpass.end()-1);
                }
            }

            else {
                if (SHOW_ASTERISK == ECHO_ON)
                    WriteConsoleA(OutputHandle, "*", 1, &dwRead, NULL);
                newpass += ch;
            }
        } SetConsoleMode(InputHandle, dwMode);

        cout << endl;
        cout << "Confirm Password: ";

        while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != RETURN) {
            if (ch == BACKSPACE) {
                if (confirm.size() != 0) {
                    if (SHOW_ASTERISK == ECHO_ON)
                        WriteConsoleA(OutputHandle, "\b \b", 3, &dwRead, NULL);
                    confirm.erase(confirm.end()-1);
                }
            }

            else {
                if (SHOW_ASTERISK == ECHO_ON)
                    WriteConsoleA(OutputHandle, "*", 1, &dwRead, NULL);
                confirm += ch;
            }
        } cout << endl;

        if (confirm == password){
            cout << "Password changed successfully!" << endl;
            CLIENT_DASHBOARD();
        }
        else {
            cout << "Password doesn't match!" << endl;
        }
    }
    else cout << "Wrong Password!" << endl;

    credentials.close();
}

void client::LOGIN (const string& prompt, echo SHOW_ASTERISK) {

    unsigned char ch=0;
    cout << prompt << endl;

    string name, input;
    cout << "Username: ";
    cin >> name;

    ifstream credentials;
    credentials.open("CLIENT_INFO.DAT", ios::binary | ios::in);

    credentials.seekg(0);
    credentials.read(reinterpret_cast<char*>(this), sizeof(*this));

    cout << username << endl;

    while (!credentials.eof()) {
        if (username == name) break;
        credentials.read(reinterpret_cast<char*>(this), sizeof(*this));
    }

    credentials.close();                                                                                                                                   input = password;

    if (username == name){
        cout << "Password: ";
        cin >> password;

//        DWORD dwMode, dwRead;
//        HANDLE  InputHandle = GetStdHandle( STD_INPUT_HANDLE);
//        HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//        GetConsoleMode(InputHandle, &dwMode);
//        SetConsoleMode(InputHandle,
//                       dwMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
//
//        while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != RETURN) {
//            if (ch == BACKSPACE) {
//                if (input.size() != 0) {
//                    if (SHOW_ASTERISK == ECHO_ON)
//                        WriteConsoleA(OutputHandle, "\b \b", 3, &dwRead, NULL);
//                    input.erase(input.end()-1);
//                }
//            }
//
//            else {
//                if (SHOW_ASTERISK == ECHO_ON)
//                    WriteConsoleA(OutputHandle, "*", 1, &dwRead, NULL);
//                input += ch;
//            }
//        } SetConsoleMode(InputHandle, dwMode);

        cout << endl;                                                                                                                                   input = password;
        if (input == password){
            cout << "Welcome, " << username << "!" << endl;
            CLIENT_DASHBOARD();
        } else cout << "Incorrect password!" << endl;
    }

    else {
        char alt;

        do {
            cout << "Error: User not found!" << endl;
            cout << "Enter T to try again" << endl;
            cout << "Enter R to create account" << endl;

            cin >> alt;

            switch (alt) {
                case 'R':
                    REGISTER("Please set up your account by entering your credentials: ");
                    break;
                case 'T':
                    LOGIN("Please log in using the security credentials you provided during sign up: ");
                    break;
                default:
                    cout << "Undefined choice!" << endl;
            }

        } while (alt != 'R' && alt != 'T');
    }
}

void client::REGISTER (const string& prompt, echo SHOW_ASTERISK) {

    unsigned char ch=0;
    cout << prompt << endl;

    fstream credentials;
    credentials.open("CLIENT_INFO.DAT", ios::binary | ios::in);

    string name;
    cout << "Username: ";

    credentials.seekg(0);

    do {
        cin >> name;
        credentials.read(reinterpret_cast<char*>(this), sizeof(*this));

        while (!credentials.eof()) {
            if (username == name){
                cout << "Username already exists! Please pick another one." << endl;
                break;
            }
            credentials.read(reinterpret_cast<char*>(this), sizeof(*this));
        }
    } while (username == name);

    credentials.close();

    cout << "Password: ";

    DWORD dwMode, dwRead;
    HANDLE  InputHandle = GetStdHandle( STD_INPUT_HANDLE);
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(InputHandle, &dwMode);
    SetConsoleMode(InputHandle,
                   dwMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != '\r' && ch != RETURN) {
        if (ch == BACKSPACE) {
            if (password.size() != 0) {
                if (SHOW_ASTERISK == ECHO_ON)
                    WriteConsoleA(OutputHandle, "\b \b", 3, &dwRead, NULL);
                password.erase(password.end()-1);
            }
        }

        else {
            if (SHOW_ASTERISK == ECHO_ON)
                WriteConsoleA(OutputHandle, "*", 1, &dwRead, NULL);
            password += ch;
        }
    } SetConsoleMode(InputHandle, dwMode);

    cout << endl;

    cout << name << ' ' << password << endl;

    credentials.open("CLIENT_INFO.DAT", ios::binary | ios::app | ios::out);
    credentials.write(reinterpret_cast<char*>(this), sizeof(*this));
    credentials.close();

    cout << "Registration complete!" << endl;
    cout << "Now please log in as a client." << endl;
}

