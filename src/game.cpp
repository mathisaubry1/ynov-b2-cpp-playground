#include "human.h"

int playScene1(int sc)
{
    int x;
    int y;
    int stop;

    stop = 0;
    while (stop == 0)
    {
        getmaxyx(stdscr, x, y);
        x = 4;
        if (sc == 1)
        {
            mvprintw(x, (y / 2) - (sizeof("Très bien ! Mais c'est dommage parce que y'a pas de suite. Allez sans rancune !") / 2), "Très bien ! Mais c'est dommage parce que y'a pas de suite. Allez sans rancune !");
            x++;
            mvprintw(x, (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), "(Appuyez sur un bouton)");
            getch();
            clear();
            return (0);
        }
        if (sc == 2)
        {
            mvprintw(x, (y / 2) - (sizeof("Ah...Bon bah autant stopper tout de suite alors...") / 2), "Ah...Bon bah autant stopper tout de suite alors...");
            x++;
            mvprintw(x, (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), "(Appuyez sur un bouton)");
            getch();
            clear();
            return (0);
        }
    }
    return (0);
}

int play()
{
    int x;
    int y;
    int in;
    int stop;

    stop = 0;
    while (stop == 0)
    {
        getmaxyx(stdscr, x, y);
        x = 0;
        clear();
        mvprintw(x, (y / 2) - (sizeof("Bonjours ! vous allez pouvoir creer votre première humain ! Content ?") / 2), "Bonjours ! vous allez pouvoir creer votre première humain ! Content ?");
        x++;
        mvprintw(x, (y / 2) - (sizeof("1\tOui !") / 2), "1\tOui !");
        x++;
        mvprintw(x, (y / 2) - (sizeof("2\tNon !") / 2), "2\tNon !");
        x++;
        in = getch() - '0';
        if (in > 2 || in < 1)
            printError();
        else
            if (playScene1(in) == 0)
                stop = 1;
        clear();
    }
    return (0);
}