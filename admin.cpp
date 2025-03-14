
#include "admin.h"

void admin::LOGIN (const string& prompt, echo SHOW_ASTERISK){

    unsigned char ch=0;
    cout << prompt << endl;

    string name, input;
    cout << "Username: ";
    cin >> name;
    cout << "Password: ";

    DWORD dwMode, dwRead;
    HANDLE  InputHandle = GetStdHandle( STD_INPUT_HANDLE);
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(InputHandle, &dwMode);
    SetConsoleMode(InputHandle,
                   dwMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    //WriteConsoleA(OutputHandle, prompt.c_str(), prompt.size(), &dwRead, NULL);
    while (ReadConsoleA(InputHandle, &ch, 1, &dwRead, NULL) && ch != '\r' && ch != RETURN) {
        if (ch == BACKSPACE) {
            if (input.size() != 0) {
                if (SHOW_ASTERISK == ECHO_ON)
                    WriteConsoleA(OutputHandle, "\b \b", 3, &dwRead, NULL);
                input.erase(input.end()-1);
            }
        }

        else {
            if (SHOW_ASTERISK == ECHO_ON)
                WriteConsoleA(OutputHandle, "*", 1, &dwRead, NULL);
            input += ch;
        }
    } SetConsoleMode(InputHandle, dwMode);

    cout << endl;
    if (input == password) cout << "Logging as an administrator... " << endl;
    else cout << "Wrong credentials!" << endl;
}
