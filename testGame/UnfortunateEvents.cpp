//
// Created by Stephanie Agbim on 14/03/2022.
//

#include "UnfortunateEvents.h"





using namespace std;

int UnfortunateEvent::listOfUnfortunateEvents = 2;
UnfortunateEvent::UnfortunateEvent()
{

}

UnfortunateEvent::~UnfortunateEvent()
{

}



void UnfortunateEvent::createUnfortunateEvent(mainCharacter &maincharacter, battleArr<Enemies> &enemies)
{
    int i = rand() % UnfortunateEvent::listOfUnfortunateEvents;

    switch (i)
    {
        case 0:
            //Enemies||Robbers
            this->bandits_attack(maincharacter, enemies);
            break;
        case 1:
            //Bounty Hunt||Dialogue files-contains all unfortunate events listed in the team plan;
            //dialogue1.txt-bountyhunt
            //dialogue2.txt-navigation error
            //dialogue3.txt-crew mutiny
            this->bountyHunt_mission(maincharacter);
            break;
        default:
            break;
    }
}
//made a change
void UnfortunateEvent::bandits_attack(mainCharacter &maincharacter, battleArr<Enemies>& enemies)
{

    bool yourTurn = false;
    int choice = 0;


    int roll_dice = rand() % 6 + 1;

    if (roll_dice == 1)
        yourTurn = true;
    else
        yourTurn = false;

    //break
    //options when player is in an encounter with robbers
    bool run_away = false;
    bool failedGame = false;
    bool robbers_subdued = false;

    //Creating enemies
    int nrOfRobbers = rand() % 3 + 1;

    for (size_t i = 0; i < nrOfRobbers; i++)
    {
        enemies.push(Enemies(maincharacter.getLevel() + rand()%2));
    }


    //Battle
    int hp = 0;
    int gainExp = 0;
    int gainCreditAccount = 0;
    int highScore = 0; //player total
    int robbers_score = 0; // enemy total
    int skill_Total = 0; //combat total
    int skillR_Player = 0; //combatRoll player
    int skillR_robbers = 0; //combatRoll enemy

    while (!run_away && !failedGame && !robbers_subdued)
    {
        if (yourTurn && !failedGame)
        {

            cout << "@@@@@@********************************************************"  << "\n";
            cout << "                                                             #"  << "\n";
            cout << "                     (ง'̀-'́)ง (ง︡'-'︠)ง                       #"  << "\n";
            cout << "                                                              #######@@@@@@@@@@@@@---."  << "\n";
            cout << "= ************************************************************** PLAYER COMBAT ******************************************************************** =" << "\n\n";
            cout << "BANDITS ARE ATTACKING-THEY MAY STEAL CREDITS OR EXPLODE SHIP! YOU MUST DO SOMETHING!!!             #PRESS ANY NUMBER TO CONTINUE# " << "\n\n";
            cin.get();
            system("clear");


            cout << "     *  ___--___                                           ___--___ *  "  << "\n";
            cout << "    *                          ***=BATTLE MENU***=                    *"  << "\n";
            cout << "/***                                                                    ***+ " << "\n\n";
            cout << "HP: " << maincharacter.getHP() << " / " << maincharacter.getHPMax() << "\n\n";

            cout << "                               0: |+  ESCAPE" << "\n";
            cout << "                               1: |+  ATTACK" << "\n";
            cout << "                               2: |+  PROTECT SHIP" << "\n";
            cout << "                               3: |+  USE WEAPON AKA BOMB THESE **...!" << "\n";
            cout << "\n";

            cout << "Choice: ";

            cin >> choice;

            while (cin.fail() || choice > 3 || choice < 0)
            {
                system("clear");  //some commands are linux and macosx specific
                                  //-using macosx

                cout << "                                                           GAME ERROR: Input does not exist!" << "\n";
                cin.clear();
                cin.ignore(100, '\n');

                cout << "     *  ___--___                                           ___--___ *  "  << "\n";
                cout << "    *                          ***=BATTLE MENU***=                    *"  << "\n";
                cout << "/***                                                                    ***+ " << "\n\n";
                cout << "HP: " << maincharacter.getHP() << " / " << maincharacter.getHPMax() << "\n\n";

                cout << "                               0: |+  ESCAPE" << "\n";
                cout << "                               1: |+  ATTACK" << "\n";
                cout << "                               2: |+  PROTECT SHIP" << "\n";
                cout << "                               3: |+  USE WEAPON AKA BOMB THESE **...!" << "\n";
                cout << "\n";

                cout << "Choice: ";
                cin >> choice;
            }

            cin.ignore(100, '\n');
            cout << "\n";

            //Player selection
            switch (choice)
            {
                case 0: //Run Away
                    run_away = true;
                    break;

                case 1: //Attack

                    //Select robber
                    cout << "      ___,.                                              Choose an enemy and sneak attack! : " << "\n\n";

                    for (size_t i = 0; i < enemies.size(); i++)
                    {
                        cout << i << "  :"
                             << "                                      (•̀ᴗ•́) Level: " << enemies[i].getLevel() << " - " <<
                             "                                         (•̀ᴗ•́) HIT:       "        << enemies[i].getHit() << " - " <<
                             "                                         (•̀ᴗ•́) Defence: " << enemies[i].getDefence() << " - " <<
                             "                                         (•̀ᴗ•́) Damage: " << enemies[i].getBrave() << " - " << enemies[i].getBrave_m() <<
                             "\n";
                    }

                    cout << "\n";
                    cout << "Choice: ";

                    cin >> choice;

                    while (cin.fail() || choice >= enemies.size() || choice < 0)
                    {
                        cout << "                                                                       GAME ERROR: Input does not exist!!" << "\n";
                        cin.clear();
                        cin.ignore(100, '\n');

                        cout << "                                                                         SELECT ENEMY: " << "\n\n";
                        cout << "Choice: ";
                        cin >> choice;
                    }

                    cin.ignore(100, '\n');
                    cout << "\n";

                    //skillR_Player
                    skill_Total = enemies[choice].getDefence() + maincharacter.getFighting();
                    robbers_score = enemies[choice].getDefence() / (double)skill_Total * 70;
                    highScore = maincharacter.getFighting() / (double)skill_Total * 70;
                    skillR_Player = rand() % highScore + 2;
                    skillR_robbers = rand() % robbers_score + 2;

                    cout << "                                                   ||| ---Fighting Tally: " << skill_Total << "\n";
                    cout << "                                                   ||| ---Robber's High Score: " << robbers_score << "\n";
                    cout << "                                                   ||| ---Player's High Score: " << highScore << "\n\n";
                    cout << "                                                   ||| ---Player(Fighting): " << skillR_Player << "\n";
                    cout << "                                                   ||| ---Thieves(Fighting): " << skillR_robbers << "\n\n";

                    if (skillR_Player > skillR_robbers)
                    {
                        cout << "                                                    SHOOT " << "\n";
                        cout << "                                                                (⌐▀͡ ̯ʖ▀)︻̷┻̿═━一- (^^**-BOOM **^)   " << "\n";

                        hp = maincharacter.getHP();
                        enemies[choice].Die(hp); //an issue exists here

                        cout << "Damage: " << hp << "!" << "\n\n";

                        if (!enemies[choice].isOn())
                        {
                            cout << "                                                It's been confirmed that your ship is safe and robbers have retreated!" << "\n\n";
                            gainExp = enemies[choice].getLevel();
                            maincharacter.gainExp(gainExp);
                            gainCreditAccount = rand() % enemies[choice].getLevel() * 10 + 1;
                            maincharacter.gainCreditAccount(gainCreditAccount);
                            cout << "                                                         You've gained more experience, captain!: " << gainExp << "\n";
                            cout << "                                                         SAVINGS BALANCE INCREASED: " << gainCreditAccount << "\n\n";

                            //Objects (weapons)
                            int toss = rand() % 70 + 1;
                            int quality = -1;

                            if (toss > 10)
                            {
                                quality = 0; //Common

                                toss = rand() % 70 + 1;
                                if (toss > 20)
                                {
                                    quality = 2; //Rare

                                    toss = rand() % 70 + 1;

                                            }
                                        }




                            if (toss >= 0)
                            {
                                toss = rand() % 70 + 1;

                                if (toss > 30)
                                {
                                    Battle ba_t(maincharacter.getLevel(), quality); //ba_t not needed for more than a moment
                                    maincharacter.addObject(ba_t);
                                    cout << "                                         __,_____, : WEAPONS    \n";
                                    cout << "                                        / __.==--0 : ACQUIRED! \n";
                                    cout << "                                       /#(-'         \n";
                                    cout << "                                       `-'            \n";
                                }
                                else
                                {
                                    ListBattle lb_t(maincharacter.getLevel(), quality); //same for lb_t
                                    maincharacter.addObject(lb_t);
                                    cout << "                                           DEFENCE ENABLED!" << "\n";
                                }
                            }

                            enemies.rid(choice);
                        }
                    }
                    else //Miss
                    {
                        cout << "                                                                    ^%attack dodged! \n\n";
                    }

                    break;

                case 2: //protect ship

                    break;

                case 3: // weapon use

                    break;

                default:
                    break;
            }

            //End turn
            yourTurn = false;
        }
        else if(!yourTurn && !failedGame && !run_away && !robbers_subdued)
        {
            cout << "@@@@@@********************************************************"  << "\n";
            cout << " @   @/     @/                 |@   \n"
                    "/|>  /|>    |                  /|--   \n"
                    "/ )  /)     />                / )_                                         #"  << "\n";
            cout << "                                                                             #"  << "\n";
            cout << "            ******** ROBBERS COMBAT *******                             #######@@@@@@@@@@@@@---."  << "\n";


            cout << "  WARNING! WARNING! SHIP IS UNDER ATTACK AND HAS BEEN INFILTRATED BY UNKOWN GUNMEN                           START!" << "\n\n";
            cin.get();
            system("clear");


            for (size_t i = 0; i < enemies.size(); i++)
            {
                cout << "#PRESS ANY KEY TO CONTINUE#                         Continue..." << "\n\n";
                cin.get();
                system("clear");

                cout << "Enemy: " << i << "\n\n";

                //Attack
                skill_Total = enemies[i].getDefence() + (maincharacter.getDefence() + maincharacter.getProof());
                robbers_score = enemies[i].getDefence() / (double)skill_Total * 100;
                highScore = (maincharacter.getDefence() + maincharacter.getProof()) / (double)skill_Total * 100;
                skillR_Player = rand() % highScore + 2;
                skillR_robbers = rand() % robbers_score + 1;

                cout << "                                                   ||| ---Fighting Tally: " << skill_Total << "\n";
                cout << "                                                   ||| ---Robber's High Score: " << robbers_score << "\n";
                cout << "                                                   ||| ---Player's High Score: " << highScore << "\n\n";
                cout << "                                                   ||| ---Player(Fighting): " << skillR_Player << "\n";
                cout << "                                                   ||| ---Thieves(Fighting): " << skillR_robbers << "\n\n";

                if (skillR_Player < skillR_robbers)
                {
                    cout << "                                                    SHOOT " << "\n";
                    cout << "                                                                O\n"
                            "                                                               < #==-   -   - -   -  -  - ---   _/)_^_O\n"
                            "                                                              ./|_                             " << "\n";



                    hp = enemies[i].getHit();
                    maincharacter.Die(hp); //an issue exists here



                    cout << "                                 Damage: " << hp << "!" << "\n";
                    cout << "                                 HP: " << maincharacter.getHP() << " / " << maincharacter.getHPMax() << "\n\n";

                    if (!maincharacter.isOn())
                    {
                        cout << "                                                      YOU HAVE BEEN DEFEATED!" << "\n\n";
                        failedGame = true;
                    }
                }
                else
                {
                    cout << "                                                     attack dodged! \n\n";
                }
            }


            yourTurn = true;
        }


        if (!maincharacter.isOn())
        {
            failedGame = true;
        }
        else if (enemies.size() <= 0)
        {
            robbers_subdued = true;
        }
    }
}


//Error; libc++abi terminating with uncaught expression type char const*
void UnfortunateEvent::bountyHunt_mission(mainCharacter &maincharacter)
{
    bool finished = false;
    int player_answer = 0;
    int opportunities = 1;
    int gainExp = (opportunities * maincharacter.getLevel() * (rand()% 7 + 1));
    int gainCreditAccount = (opportunities * maincharacter.getLevel() * (rand() % 7 + 1));


    BountyHunt bountyHunt("/Users/acsb/CLionProjects/testGame/cody/dialogue1.txt");

    while (!finished && opportunities > 0)
    {
        std::cout << "Choose Wisely: " << opportunities << "\n\n";
        opportunities--;
        std::cout << bountyHunt.getCcString() << "\n";

        cout << "\nYour CHOICE: ";
        cin >> player_answer;

        while (cin.fail())
        {
            cout << "Input not accepted!" << "\n";
            cin.clear();
            cin.ignore(100, '\n');

            cout << "\nCHOICE: ";
            cin >> player_answer;
        }

        cin.ignore(100, '\n');
        cout << "\n";

        if (bountyHunt.getShipVoli() == player_answer)
        {
            finished = true;

            maincharacter.gainExp(gainExp);
            maincharacter.gainExp(gainCreditAccount);
            std::cout << "INCREASED " << gainExp << " EXP!" << "\n";
            std::cout << "MORE " << gainCreditAccount << " CREDIT!" << "\n\n";
        }
    }


    if (finished)
    {
        std::cout << "Tatu Nossan has been caught alive! \n\n";
    }
    else
    {
        std::cout << "MISSION FAILED: GET READY TO BE ATTACKED BY LADDY JOE AND BANDITS IN YOUR NEXT MISSION! \n\n";
    }
}


/* BOUNTY HUNT EXPLAINED
 * It first starts with a dialogue and then three options are laid out
 * player is only given one chance (Choose wisely: 1)
 * First option is the correct answer since a captain should do everything to protect and provide for his ship
 * Options are counted from 0
 * If player wins he gets more credit and his experience as a captain increases
 * last two answers are wrong. If player picks either one of them-then for sure, bandits will attack!!
 * Inevitably, whether the player passes the mission or not, and he picks mission again, bandits will still attack
 * it is noted, that implementing the mission class was not my task-it had been done has a personal source code since i
 * was done with mine
 * */
