//
// Created by Stephanie Agbim on 11/03/2022.
//
#include "BountyHunt.h"
BountyHunt::BountyHunt(std::string cody)
{


    this->shipVolition = 0;
    std::ifstream acsbFile("/Users/acsb/CLionProjects/testGame/cody/dialogue1.txt"); //path reference to the file-could be anything

    int options = 0;  //implementing how many options the player has with his choice
    std::string playerInput = " ";  //allows the player to input choice
    int shipVoli = 0; //ship volition is the indefinite choice the player makes for the ship

    if (acsbFile.is_open())  //This function is to read and open the file cody which is like an interactive story
        //originally this was classified as a mission in our game file-it still is but not as complex as the
        //unfortunate event-bandits attack-whatever choice the player makes here will lead to the bandits attack
    {
        std::string str;
        while (std::getline(acsbFile, str)) //this allows the whole file to be printed
        {
            this->dialogue +=str;
            this->dialogue.push_back('\n'); //push elements from the dialogue to the back
        }
        acsbFile >> options;
        acsbFile.ignore();

        for (size_t i = 0; i<options; i++)
        {
            std::getline(acsbFile, playerInput);
            this->playerInput.push_back(playerInput);
        }
        acsbFile >> shipVoli;
        this->shipVolition = shipVoli;
        acsbFile.ignore();
    }
    else
        throw("Uh oh bounty not found");  //acts as a test for the if statement
    acsbFile.close();
}

BountyHunt::~BountyHunt() {

}


std::string BountyHunt::getCcString() {  //converting everything to string
    std::string playerInput = " ";
    for (size_t i = 0; i <this->playerInput.size(); i++)
    {
        playerInput += std::to_string(i) + ": "+ this->playerInput[i] + "\n";
    }

    return this->dialogue + "\n" + "\n"
           +playerInput + "\n";
}