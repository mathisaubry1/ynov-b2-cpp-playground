#include "human.h"

int menu()
{
    int in;
    int stop;
    int x;
    int y;

    stop = 0;
    getmaxyx(stdscr, x, y);
    clear();
    x = x - 6;
    mvprintw(x / 2, (y / 2) - (sizeof("Bienvenue dans le jeu des humains") / 2), "Bienvenue dans le jeu des humains\n");
    refresh();
    while (stop == 0)
    {
        printMenu();
        refresh();
        in = getch() - '0';
        if (in > 3 || in < 1)
            printError();
        else
        {
            if (in == 1)
                printRules();
            if (in == 2)
            {
                if (play() == -1)
                    return (-1);
            }
            if (in == 3)
                return (0);
        }
        refresh();
    }
    return (0);
}

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    if (menu() == -1)
        return (-1);
    endwin();
    return (0);
}