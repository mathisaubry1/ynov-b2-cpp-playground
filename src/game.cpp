#include "human.h"

int playScence2_2()
{
    int x;
    int y;

    getmaxyx(stdscr, x, y);
    clear();
    attron(COLOR_PAIR(2));
    mvprintw((x / 2), (y / 2) - (sizeof("Votre Humain va maintenant affronter d'autres humains.") / 2), 
    "Votre Humain va maintenant affronter d'autres humains.");    
    refresh();
    x = x + 2;
    mvprintw(x / 2, (y / 2)- (sizeof("Le jeu se termine losque votre humain meurt.") / 2), 
    "Le jeu se termine losque votre humain meurt.");
    refresh();
    x = x + 2;
    mvprintw(x / 2, (y / 2)- (sizeof("Bonne chance !") / 2), "Bonne chance !");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
    return (0);
}

int playScene2(Human &my_human)
{
    int x;
    int y; 

    getmaxyx(stdscr, x, y);
    clear();
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2) - (sizeof("################") / 2), 
    "################");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2)- (sizeof("STATS") / 2), "STATS");
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(1));
    mvprintw((x / 2), (y / 2) - (sizeof("################") / 2), 
    "################");
    x = x + 2;
    attron(COLOR_PAIR(2));
    mvprintw(x / 2, (y / 2)- ((sizeof("Nom: ") + sizeof(my_human.getName())) / 2), 
    "Nom: %s", my_human.getName());
    refresh();
    x = x + 2;
    mvprintw(x / 2, (y / 2)- (sizeof("Force: ") / 2), 
    "Force: %d", my_human.getStrength());
    refresh();
    x = x + 2;
    mvprintw(x / 2, (y / 2)- (sizeof("Vie: ") / 2), 
    "Vie: %d", my_human.getHealth());
    refresh();
    x = x + 2;
    attron(COLOR_PAIR(3));
    mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
    "(Appuyez sur un bouton)");
    refresh();
    getch();
    playScence2_2();
    fight(my_human);
    return (0);
}

int playScene1(int sc)
{
    int x;
    int y;
    int stop;
    char   name[100];

    stop = 0;
    while (stop == 0)
    {
        getmaxyx(stdscr, x, y);
        if (sc == 1)
        {
            Human my_human;

            clear();
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - (sizeof("Très bien ! comment voulez-vous appeller votre humain ?") / 2), 
            "Très bien ! comment voulez-vous appeller votre humain ?");
            refresh();
            x = x + 2;
            mvscanw(x / 2, y / 2, "%s", name);
            refresh();
            x = x + 2;
            my_human.setName(name);
            x = x + 2;
            mvprintw(x / 2, (y / 2) - ((sizeof("Votre humain s'apelle: ") + sizeof(my_human.getName())) / 2), 
            "Votre humain s'apelle: %s", my_human.getName());
            refresh();
            x = x + 2;
            attron(COLOR_PAIR(3));
            mvprintw((x / 2), (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
            "(Appuyez sur un bouton)");
            refresh();
            getch();
            if (playScene2(my_human) == 0)
                stop = 1;
            else
                return (-1);
        }
        if (sc == 2)
        {
            clear();
            attron(COLOR_PAIR(2));
            mvprintw(x / 2, (y / 2) - (sizeof("Ah...Bon bah autant stopper tout de suite alors...") / 2), 
            "Ah...Bon bah autant stopper tout de suite alors...");
            refresh();
            x = x + 2;
            attron(COLOR_PAIR(3));
            mvprintw(x / 2, (y / 2)- (sizeof("(Appuyez sur un bouton)") / 2), 
            "(Appuyez sur un bouton)");
            refresh();
            getch();
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
        clear();
        attron(COLOR_PAIR(2));
        getmaxyx(stdscr, x, y);
        mvprintw(x / 2, (y / 2) - (sizeof("Bonjours ! vous allez pouvoir creer votre premier humain ! Content ?") / 2), 
        "Bonjours ! vous allez pouvoir creer votre premier humain ! Content ?");
        refresh();
        x = x + 2;
        mvprintw(x / 2, (y / 2) - (sizeof("1\tOui !") / 2), 
        "1\tOui !");
        refresh();
        x = x + 2;
        mvprintw(x / 2, (y / 2) - (sizeof("2\tNon !") / 2), 
        "2\tNon !");
        refresh();
        x = x + 2;
        in = getch() - '0';
        if (in > 2 || in < 1)
            printError();
        else
            if (playScene1(in) == 0)
                stop = 1;
    }
    return (0);
}