#include <stdio.h>
#include "tp.h"

void displayMenu(const Application* app) {
    printf("------ %s ------\n", app->nom);
    for (int i = 1; i <= app->nb_menus; i++) {
        printf("%d. %s\n", i, app->menus[i-1]);
    }
    printf("Choisissez une option (0 pour quitter) : ");
}