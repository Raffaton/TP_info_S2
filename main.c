#include <stdio.h>
#include "tp.h"

int main (){
    Menu photoMenus[] = {{"Regarder une photo"}, {"Prendre une photo"}};
    Menu messageMenus[] = {{"Lire un message"}, {"Envoyer un message"}};

    Application photoApp = {
        "Photo", photoMenus, 2
    };

    Application messageApp = {
        "Messages", messageMenus, 2
    };
    
    runPhone(&photoApp, &messageApp);
    return 0;
}

// gcc "./*.c" -o main.exe
// .\main.exe