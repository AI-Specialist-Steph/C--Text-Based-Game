//
// Created by Stephanie Agbim on 07/03/2022.
//



//Things to do -------- DONE!
//fix this code so that it manages the functions in the Character file
// 10 crew members are displayed, user is given the option to hire 4 crew members for his ship
// User initially has a sum of 2000 credit. Each crew member has a different hire cost. For every crew member the
//user hires- his credit balance reduces
//also display "congratulations your crew is complete" after player has successfully hired 4 crew members


#include "CrewManager.h"


int CrewManager::credit = 2000;
std::array<Character, 10> CrewManager::crewOptions = {Character("Chris Brooks", "male ","34", "Space","Gang member ","Security Guard ",
                                                                "Scoundrel: 10 percent chance of leaving after performing two legal missions in a row,"
                                                                "as well as higher credibility with crime syndicates giving 5 percent bigger pay",
                                                                1, 7, 6, 1, 3, 6, 6, 0, 500), Character("Tilda McKenna", "female ","22", "Mars","Child Prodigy","Aeronautical Engineer ",
                                                                                                        "Greedy (Requires 10 percent more credits)",
                                                                                                        1, 1, 4, 3, 9, 2, 6, 0, 500), Character("Shesha Ina", "female ","32", "Earth","Imperial Pilot ","Pilot ",
                                                                                                                                                "Loyal (Will never leave you or revolt)",
                                                                                                                                                1, 4, 4, 1, 4, 4, 6, 0, 500), Character("Edin-50", "robot "," 2019-Present", "Space","Military Assassin ","Chef ",
                                                                                                                                                                                        "Loyal and nice to humans, until programmed otherwise.",
                                                                                                                                                                                        1, 2, 7, 6, 1, 3, 6, 0, 500), Character("Fav Yhana", "male ","23", "Jupyter","Drug Lord ","Lead proplusion engineer ",
                                                                                                                                                                                                                                "Extremely skilled with guns",
                                                                                                                                                                                                                                9, 2, 1, 4, 1, 3, 6,  0, 3000),
                                                      Character("Cee Crooks", "female ","33", "Space","Nurse ","Lead electrical engineer ",
                                                                "Thief(Obssessed with gold)",
                                                                1, 4, 3, 6, 1, 3, 6, 0, 5000),
                                                      Character("Princess Gate", "male ","34", "Saturn","Soldier ","Military crewman ",
                                                                "Gets mad when people mistake him for a female-extremely good at climbing",
                                                                1, 2, 7, 5, 4, 3, 2, 0, 5000),
                                                      Character("Christian", "female ","44", "Earth","House cleaner ","Training recruitment commander ",
                                                                "Easily Irritable-Half AI",
                                                                1, 2, 7, 5, 1, 9, 6,0, 1000),
                                                      Character("Magnum", "male ","34", "Space","Tech analyst ","Hacker",
                                                                "Good at combat",
                                                                1, 2, 7, 6, 1, 3, 6, 0, 8000),
                                                      Character("Sponge Bob", "male ","35", "Moon","Hero ","Hero ",
                                                                "Can breathe in space and is good at everything-Weakness unknown",
                                                                1, 9, 9, 9, 9, 9, 9, 0, 3000000)};
std::array<Character, 4> CrewManager::crew;


//CrewManager::CrewManager()
//{

//}

int CrewManager::GetCredit() { return credit; }

bool CrewManager::crewFull()
{
    int crewNumber = 0;
    for (int i = 0; i<crew.size(); i++) {
        if (crew[i].GetName() != " ") {
            crewNumber++;
        }
    }
    if (crewNumber == 4)
        return true;
    else
        return false;
}

void CrewManager::HireCrewMember(int crewID) //adds members to crew once selected
{
    bool crewfull = crewFull();
    bool enoughCredit = false;
    if (crewfull == false && credit >= crewOptions[crewID].GetHireCost())
    {
        enoughCredit = true;
        for (int i = 0; i<crew.size(); i++) {
            if (crew[i].GetName() == " ") {
                crew[i] = crewOptions[crewID];
                credit -= crewOptions[crewID].GetHireCost();
                break;
            }
        }



        //add function to see if crew selected ==4
    }
    if (enoughCredit == false)
        std::cout << "UH OH! Not enough credit balance" << std::endl;

    if (crewfull && enoughCredit)
        std::cout << "Ship full" << std::endl;
}



void CrewManager::displayMemberInfo()
{

    std::cout << "Displaying member info: " << std::endl;
    for (int i = 0; i<crewOptions.size(); i++) {
        std::cout << "ID: " << i << std::endl;
        crewOptions[i].printStats();
    }
}



//player selection

// - allows player to input the id of characters he want-if character is over 500
//prompt player to select new character

//player input selection
static int GetInput() {
    int  input;
    std::cin >> input;

    while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5
           && input != 6 && input != 8 && input != 9 )
    {
        std::cout << "Crew member does not exist";
        std::cout << "Please choose a crew member to continue:\n";
        std::cin >> input;
    }
    return input;
}


void CrewManager::handleHire()
{
    displayMemberInfo();
    while (crewFull() == false)
    {
        int id = GetInput();
        HireCrewMember(id);
    }
    std::cout << "\n";
    std::cout << "You currently have zero credits in your current account." << std::endl;
    std::cout << "Select (2) to start mission" << std::endl;

}



//After player selects character, print- your crew has been hired-return to main menu to select mission
//function that reduces credit amount of player after a character has been hired


/*function that prints details of crew*/


//function asking player to select crew members out of the printed stats


