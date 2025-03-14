
#include "functions.h"

void CENTER (char FILL, string TEXT){
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
}
