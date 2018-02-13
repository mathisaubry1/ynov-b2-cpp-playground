#include "human.h"

void    printMenu()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    x = x - 4;
    mvprintw((x / 2), (y / 2) - (sizeof("----------------") / 2), "----------------");
    x = x + 2;
    mvprintw((x / 2), (y / 2) - (sizeof("MENU") / 2), "MENU");
    x = x + 2;
    mvprintw((x / 2), (y / 2) - (sizeof("----------------") / 2), "----------------");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "1\tRègles");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "2\tJouer");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "3\tQuitter");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "----------------");
    x = x + 2; 
}

void    printRules()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    x = x - 3;
    clear();
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "----------------");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("Règles") / 2), "Règles");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("----------------") / 2), "----------------");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("Dans le jeu des humains il faut que votre humain survive") / 2), "Dans le jeu des humains il faut que votre humain survive");
    x = x + 2;
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), "(Appuyez sur un bouton)");
    x = x + 2;
    refresh();
    getch();
    clear();
}

void    printError()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    x = x - 1;
    clear();
    mvprintw(x / 2, (y / 2) - (sizeof("Erreur") / 2), "Erreur");
    x = x + 2;
    mvprintw(x / 2, (y / 2) - (sizeof("(Appuyez sur un bouton)") / 2), "(Appuyez sur un bouton)");
    refresh();
    getch();
    clear();
}