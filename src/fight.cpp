#include "human.h"

Human   getNextOpponent()
{
    Human next;

    next.setName("NewOpponent");
    next.setHealth(10);
    next.setStrenght(4);
    return (next);
}

int punch(Human &puncher, Human &target)
{
    int health = target.getHealth();
    int random;

    srand(time(NULL));
    random = rand() % (4-1) + 1;
    target.setHealth(health - (puncher.getStrength() / random));
    return (0);
}

int fight(Human &my_human)
{
    int     x;
    int     y;
    long    round;
    Human   opponent = getNextOpponent();

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
    srand(time(NULL));
    round = rand() % (2-1) + 1;
    while (my_human.getHealth() > 0 && opponent.getHealth() > 0)
    {
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
        if (round % 2 == 0)
        {
            punch(my_human, opponent);
            x = x + 2;
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - ((sizeof(" frappe .") + sizeof(my_human.getName()) + sizeof(my_human.getName())) / 2),
            "%s frappe %s.", my_human.getName(), opponent.getName());
            refresh();
        } else {
            punch(opponent, my_human);
            x = x + 2;
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - ((sizeof(" frappe .") + sizeof(my_human.getName()) + sizeof(my_human.getName())) / 2),
            "%s frappe %s.", opponent.getName(), my_human.getName());
            refresh();
        }
        x = x + 2;
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
        round++;
    }
    if (my_human.getHealth() > 0)
    {
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
    } else {
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
    return (0);
}