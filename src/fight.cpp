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

    printFight(my_human, opponent);
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
        x = x + 2;
        printPunch(my_human, opponent, round, x, y);
        x = x + 2;
        printLife(my_human, opponent, x, y);
        round++;
    }
    if (my_human.getHealth() > 0)
    {
        printVictory(my_human);
    } else {
        printLose(my_human);
    }
    return (0);
}