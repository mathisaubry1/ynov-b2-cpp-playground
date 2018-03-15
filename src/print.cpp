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

void    printLose(Human &my_human)
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - ((sizeof(" a perdu !") + sizeof(my_human.getName())) / 2), 
    "%s a perdu !", my_human.getName());
    refresh();
    x = x + 2;
    mvprintw(x / 2, (y / 2) - (sizeof("Votre Humain est mort, vous devez recommencer.") / 2), 
    "Votre Humain est mort, vous devez recommencer.");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
}

void    printVictory(Human &my_human)
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - ((sizeof(" a gagné !") + sizeof(my_human.getName())) / 2), 
    "%s a gagné !", my_human.getName());
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
    my_human.setHealth(10);
    fight(my_human);
}

void    printLife(Human &my_human, Human &opponent, int x, int y)
{
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - ((sizeof(" : vie | :  vie ") + sizeof(my_human.getName()) + sizeof(opponent.getName()) + sizeof(my_human.getName())) / 2), 
    "%s : %i vie | %s : %i vie", my_human.getName(), my_human.getHealth(), opponent.getName(), opponent.getHealth());
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
}

void    printFight(Human &my_human, Human &opponent)
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - ((sizeof(" VS ") + sizeof(my_human.getName()) + sizeof(opponent.getName())) / 2),
    "%s VS %s", my_human.getName(), opponent.getName());
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2)- (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
}

void    printPunch(Human &my_human, Human &opponent, int round, int x, int y)
{
    if (round % 2 == 0)
        {
            punch(my_human, opponent);
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - ((sizeof(" frappe .") + sizeof(my_human.getName()) + sizeof(my_human.getName())) / 2),
            "%s frappe %s.", my_human.getName(), opponent.getName());
            refresh();
        } else {
            punch(opponent, my_human);
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - ((sizeof(" frappe .") + sizeof(my_human.getName()) + sizeof(my_human.getName())) / 2),
            "%s frappe %s.", opponent.getName(), my_human.getName());
            refresh();
        }
}