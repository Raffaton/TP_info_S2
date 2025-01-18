#include <stdio.h>
#include <stdlib.h>
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
    int choix = -1;
    char newOption[100];
    int menuIndex;   
    char nomApp[100];   
    Menu newMenus[100];  
    char option[100];

    while (choix != 0) {
        printf("\n---- Applications ----\n");
        printf("1. %s\n", app1->nom);
        printf("2. %s\n", app2->nom);
        printf("3. Modifier le menu de '%s'\n", app1->nom);
        printf("4. Modifier l'application '%s'\n", app2->nom);
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        
        scanf("%d", &choix);
        getchar();
        
        switch (choix) {
            case 0:
                printf("Vous avez quitte votre telephone!\n");
                break;
                
            case 1:
                runApplication(app1);
                break;
                
            case 2:
                runApplication(app2);
                break;
                
            case 3:
                printf("Entrez l'index du menu a modifier (1-%d) : ", app1->nb_menus);
                scanf("%d", &menuIndex);
                getchar();
                printf("Entrez la nouvelle option : ");
                fgets(newOption, sizeof(newOption), stdin);
                newOption[strcspn(newOption, "\n")] = 0; 
                updateMenu(app1, menuIndex, strdup(newOption));
                break;
                
            case 4:
                {
                    int nbMenu = 0;
                    int i = 1;

                    printf("Quel est le nom de l'application : ");
                    fgets(nomApp, sizeof(nomApp), stdin);
                    nomApp[strcspn(nomApp, "\n")] = 0;
                    
                    while (1) {
                        printf("Quel est la %d option du menu (ou 'q' pour terminer) : ", i);
                        fgets(option, sizeof(option), stdin);
                        option[strcspn(option, "\n")] = 0;
                        
                        if (option[0] == 'q' || option[0] == 'Q') {
                            break;
                        }
                        
                        newMenus[i-1].option = strdup(option);
                        i++;
                    }
                    nbMenu = i - 1;
                    
                    updateApplication(app2, strdup(nomApp), newMenus, nbMenu);
                }
                break;
                
            default:
                printf("Option invalide! Veuillez choisir entre 0 et 4\n");
                break;
        }
    }
}

void updateMenu(Application* app, int menuIndex, const char* newOption) {
    while(1) {
        if (menuIndex <= 0 || menuIndex > app->nb_menus) {
            printf("Index invalide! Veuillez choisir entre 1 et %d\n", app->nb_menus);
            continue;
        }
    
        app->menus[menuIndex - 1].option = newOption;
        printf("Option de menu mise a jour avec succes !\n");
        break;
    }
}

void updateApplication(Application* app, const char* newName, Menu* newMenus, int newMenuCount) {
    app->nom = newName;
    app->menus = newMenus;
    app->nb_menus = newMenuCount;
    printf("Application mise a jour avec succes !\n");
}