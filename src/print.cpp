#include "human.h"

void    printMenu()
{
    int x;
    int y;

    clear();
    getmaxyx(stdscr, x, y);
    x = x - 4;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2) - (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2) - (sizeof("MENU") / 2), 
    "MENU");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2) - (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "1\tRègles");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "2\tJouer");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "3\tQuitter");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
}

void    printRules()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    x = x - 3;
    clear();
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2)- (sizeof("Règles") / 2), 
    "Règles");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2)- (sizeof("Dans le jeu des humains il faut que votre humain survive") / 2), 
    "Dans le jeu des humains il faut que votre humain survive");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    x = x + 2;
    getch();
}

void    printError()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    x = x - 1;
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - (sizeof("Erreur") / 2), 
    "Erreur");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw(x / 2, (y / 2) - (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
}