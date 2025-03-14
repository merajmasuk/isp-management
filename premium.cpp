

#include "premium.h"

void premium::billing_monthly(){
    CONSOLE_SCREEN_BUFFER_INFO n;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &n);
    int CONSOLE_WIDTH = n.srWindow.Right - n.srWindow.Left+1;

    string TEXT="INVOICE";
    char FILL='#';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    TEXT=""; FILL='=';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    double payment;
    cout << "Insert the amount to pay: "; cin >> payment;
    cout << "Bill: " << 1.0 * premium::rate << endl;
    cout << "Paid: " << payment << endl;


    FILL='-';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    cout << "Change: " << payment-1.0 * premium::rate << endl;
}

void premium::billing_annually(){
    CONSOLE_SCREEN_BUFFER_INFO n;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &n);
    int CONSOLE_WIDTH = n.srWindow.Right - n.srWindow.Left+1;

    string TEXT="INVOICE";
    char FILL='#';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    TEXT=""; FILL='=';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    double payment;
    cout << "Insert the amount to pay: "; cin >> payment;
    cout << "Bill: " << 1.0 * premium::rate << endl;
    cout << "Paid: " << payment << endl;


    FILL='-';
    cout << setfill(FILL);
    if (TEXT.size() == 0) cout << setw(CONSOLE_WIDTH-1) << FILL << endl;
    else {
        cout << setw(CONSOLE_WIDTH/2 + (TEXT.length()+1)/2 - 1) << right << TEXT;
        cout << setw(CONSOLE_WIDTH/2 - (TEXT.length()-1)/2 - 1)          << FILL;
        cout << endl;
    }

    cout << "Change: " << payment-1.0 * premium::rate << endl;
}
