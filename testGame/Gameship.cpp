//
// Created by Stephanie Agbim on 27/02/2022.
//


#include <string>
#include <iostream>
#include "Gameship.h"
#include "CrewManager.h"



Gameship::Gameship()  {
    choice = 0;
    start = true;
    //crew = 4;

}

Gameship::~Gameship()
{
}






void Gameship::mainStart() {
    cout << "\x1b[31;40m";
    cout << "                ∩         Good day, captain!           \n";
    cout << "　　　　         ＼＼       The year is 2639, you are the captain of a small freighter class            \n";
    cout << "　　　　         ／　 ）     spaceship currently docked at an asteroid belt mining space station colony. \n";
    cout << "⊂＼＿／￣￣￣　 ／           Many seek jobs on ships desperate to escape space station life ! :(        \n";
    cout << "　＼＿／   ° ͜ʖ ° （         Our ship has space for 6 more crew.But you don’t have much money,         \n";
    cout << "　　　）　　 　／⌒＼          only 2000 credits to spare         \n";
    cout << "　　／　 ＿＿＿／⌒＼⊃                   \n";
    cout << "　（　 ／                             \n";
    cout << "　　＼＼                               \n";
    cout << "     U                                \n\n";


}
    //cout << "\033[0;34m";








//functions
void Gameship::initGameship()
{
    //Enemies e(rand() & 6 + 1);
    //std::cout << e.getCcString() << std::endl;

    std::string name;
    std::cout << "Input Captain's name to start: ";
    getline(std::cin, name);


    maincharacter.initialise(name);



    Battle::initCall();
    ListBattle::initCall();



}



void Gameship::mainInterface()
{

    std::cout << "卌MAIN INTERFACE "  << std::endl << std::endl;

    std::cout << "      _____\n"
                 "     |.---.|\n"
                 "     ||___||\n"
                 "     |+  .'|\n"
                 "     | _ _ |\n"
                 "@22  |_____/ " << std::endl << std::endl;

    std::cout << "  99: PLAYER MENU ☰ " << std::endl; //this sheet will contain everything there is to know
    // about the main player
    //personal credit balance etc
    std::cout << "  8:   £££   Hire Crew" << std::endl;
    std::cout << "  2: ╚(•⌂•)╝ Mission" <<std::endl;
    std::cout << "  3:   ⚡+    Boost" << std::endl;
    std::cout << "  00: ⚠ ⚠ ⚠   Quit" << std::endl;
    std::cout << std::endl;


    std::cout << std::endl << "Choice: ";
    std::cin >> choice;




    switch (choice)
    {
        case 00:
            start = false;
            break;

        case 99:
            maincharacter.printMaincStats();
            break;
        case 2:
            mission();
            break;
        case 8:
            CrewManager::handleHire();
            break;
        case 3:
            boost();
            break;


        default:
            break;
    }

}
void Gameship::mission()
{
    this->maincharacter.mission();

    UnfortunateEvent ev;
    ev.createUnfortunateEvent(this->maincharacter, this->enemies);
}


void Gameship::boost()
{
    int boostPrice = this->maincharacter.getHPMax()- this->maincharacter.getHP();
    std::cout << "BOOST" << "\n\n";
    std::cout << "Bill" << boostPrice << "\n";
    std::cout << "Savings Credit Account: " << this->maincharacter.getCreditAccount() << "\n";
    std::cout << "Medical: " << this->maincharacter.getHP() << "/" << this->maincharacter.getHPMax() << "\n";

    if (this->maincharacter.getCreditAccount() < boostPrice)
    {
        std::cout << "Virtual Decline: NOT ENOUGH MONEY" <<  "\n";
    }
    else
    {
        std::cout << "\n Boost? (1) Yes, (0) No" << "\n\n";
        cin >> this->choice;
        while (cin.fail() || this->choice < 0 || this->choice > 1)
        {
            cout << "Input Unacceptable!" << "\n";
            cin.clear();
            cin.ignore(100, '\n');

            cout << "\n\n Rejuvenate? (1) Yes, (2) No..." << "\n\n";
            cin >> this->choice;
        }

        cin.ignore(100, '\n');
        cout << "\n";
    }
    if (this->choice == 1)
    {
        this->maincharacter.resetHP();
        this->maincharacter.pay(boostPrice);
        std::cout << "Your health is at its peak captain!" << "\n";
    }
    else
    {
        std::cout << "ANOTHER TIME THEN!" << "\n";
    }


}


