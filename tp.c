#include <stdio.h>
#include "tp.h"

void displayMenu(const Application* app) {
    printf("------ %s ------\n", app->nom);
    for (int i = 1; i <= app->nb_menus; i++) {
        printf("%d. %s\n", i, app->menus[i-1]);
    }
    printf("Choisissez une option (0 pour quitter) : ");
}

void runApplication(const Application* app) {
    int choix = -1;
    while (1) {
        displayMenu(app);
        scanf("%d", &choix);
        if (choix < 0 || choix > app->nb_menus) {
            continue;
        }
        else {
            if (choix == 0) {
                printf("Vous avez choisi de quitter l'application !\n");
                break;
            }
            else {
                printf("Vous avez selectionne : %s\n", app->menus[choix - 1]);
                break;
            }
        }
    }
}