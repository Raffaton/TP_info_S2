#include <stdio.h>
#include <string.h>
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

void runPhone(Application* app1, Application* app2) {
    int choix;
    printf("---- Application ----\n");
    printf("1. %s\n", app1->nom);
    printf("2. %s\n", app2->nom);
    printf("3. Modifier le menu de '%s'\n", app1->nom);
    printf("4. Modifier l'application '%s'\n", app2->nom);
    printf("0. Quitter\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);
    
    switch (choix) {
        case 0:
            printf("Vous avez quitte votre telephone !");
            break;
        case 1:
            runApplication(app1);
            break;
        case 2:
            runApplication(app2);
            break;
        case 3:
            int menuIndex;
            char newOption[100];
            printf("Entrez l'index du menu à modifier (1-%d) : ", app1->nb_menus);
            scanf("%d", &menuIndex);
            printf("Entrez la nouvelle option : ");
            getchar();
            fgets(newOption, sizeof(newOption), stdin);
            
        
    }
}

void updateMenu(Application* app, int menuIndex, const char* newOption) {
    while(1) {
        if (menuIndex <= 0 || menuIndex > app->nb_menus) {
            printf("Index invalide! Veuillez choisir entre 1 et %d\n", app->nb_menus);
            continue;
        }
    
        app->menus[menuIndex - 1].option = newOption;
        printf("Option de menu mise à jour avec succes !\n");
        break;
    }
}

void updateApplication(Application* app, const char* newName, Menu* newMenus, int newMenuCount) {
    app->nom = newName;
    app->menus = newMenus;
    app->nb_menus = newMenuCount;
    printf("Application mise à jour avec succes !\n");
}