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
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2) - (sizeof("Bienvenue dans le jeu des humains") / 2), "Bienvenue dans le jeu des humains\n");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
    while (stop == 0)
    {
        printMenu();
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
    }
    return (0);
}

int main()
{
    initscr();
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    keypad(stdscr, TRUE);
    if (menu() == -1)
        return (-1);
    endwin();
    return (0);
}