#include"Gameship.h"

#include <stdio.h>
#include <unistd.h> // for usleep function
using namespace std;

const char spaceship[]=  //ASCII art spaceship and logo
        "\x1b[34;40m \n" //Foreground and backgrounf colour
        "           * .--.\n"
        "            / /  `       \n"
        "      +     | |             \n"
        "    '       #__#, \n"
        "   *     +   '--'  * \n"
        "    +              / *                 \n"
        "                 .'    '.   *     + \n"
        "                / ====== ^     *     + \n"
        "                ;:.  _    ;                       \n"
        "                |:. (_)   |                        \n"
        "                |:.  _    |                       \n"
        "                |:. (_)   |      +    *  \n"
        "                ;:.       ;                       \n"
        "             .' @:.    /  `.                          \n"
        "             / .-'':._.'`-..£                       \n"
        "             |/    /|||    ||         \n"
        "         @22 _..--""""""""--.._               \n"
        "      _.-'``                       ``'-._        \n"
        "    -'                                    '-       \n"
        "     *********************************************************************  \n"
        "     ************************************************************  \n"
        "    ********************************************  \n"
        "    *************************  \n"
        "                            *   \n"
        "    c.-')            ('-.         \n"
        "    ( OO ).         ( OO ).-.              \n"
        "    (_)---|)        / . --. /           \n"
        "    /    _ |         | |-.   |                 \n"
        "    |  :` `.       .-'-'  |  |               \n"
        "     '..`''.)        | |_.'  |             \n"
        "    .-._)   |        |  .-.  |               \n"
        "    |       /        |  | |  |     **^@SPACESHIP ADVENTURES!±§~~           \n"
        "     `-----'         `--' `--'                  \n";





int main()  //print first
{
    for (int i = 0; i < 50; i++) printf("\n"); // jump to bottom of console
    printf("%s", spaceship);

    int k = 700000;  //numbers determine how slow or fast ascii characters would move
    for (int i = 0; i < 50; i++) {
        usleep(k);
        k = (int) (k * 0.9); //  sleeps less each time
        printf("\n"); // moves spaceship a line upward
    }
    srand(time(NULL));

    Gameship games;

    games.mainStart();  //shows menu prints last after user input name
    games.initGameship();//ask user for name, second to be shown



    while (games.getStart())  //after the game starts, print main interface
    {
        games.mainInterface();

    }

    return 0;

}


