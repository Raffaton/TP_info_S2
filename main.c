#include <stdio.h>
#include "tp.h"

int main (){
    Menu photoMenus[] = {{"Regarder une photo"}, {"Prendre une photo"}};

    Application photoApp = {
        "Photo", photoMenus, 2
    };
    
    displayMenu(&photoApp);
    return 0;
}

// gcc "./*.c" -o main.exe
// .\main.exe