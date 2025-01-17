#ifndef TP_H
#define TP_H

typedef struct {
    const char * option ;
}Menu;

typedef struct {
    const char * nom;
    Menu *menus;
    int nb_menus;
}Application;

void displayMenu(const Application* app);
void runApplication(const Application* app);
void runPhone(Application* app1, Application* app2);


#endif 