//
// Created by Stephanie Agbim on 27/02/2022.
//

#include "mainCharacter.h"
#include <math.h>
#include "Enemies.h"

//implemting all the qualities of the main player
mainCharacter::mainCharacter() { //initializing
    this->missionCovered_dist = 0;
    this->name = " ";
    this->level = 0;


    this->exp = 0;
    this->expNext =  0;



    this->hp = 0;
    this->hpMax = 0;
    this->boost = 0; //stamina
    this->defence = 0;
    //this->unfortunate_eventsmin = 0; //damagemin
    //this->unfortunate_eventsmax = 0; //damagemax

    this->mainCharStatPoints = 0;
    this->statPoints = 0;


    this-> strength=0;
    this->intelligence=0;

    this->brave=0;
    this->brave_m = 0;

    this-> speed=0;
    this->resilient=0;

    this->navigation = 0;
    this->shooting =0;
    this->engineeringSkill =0;
    this->fighting =0;

    this->statPoints = 0;

    this->creditAccount = 0;










}



mainCharacter::~mainCharacter()
{

}


mainCharacter::mainCharacter(std::string name, int missionCovered_dist, int creditAccount, int level, int exp,
                             int strength, int statPoints, int hp, int speed, int intelligence) {
    this->missionCovered_dist = missionCovered_dist;
    this->name = " ";
    this->level = level;


    this->exp = exp;
    this->expNext =  0;



    this->hp = 0;
    this->hpMax = 0;
    this->boost = 0; //stamina
    this->defence = 0;
    //this->unfortunate_eventsmin = 0; //damagemin
    //this->unfortunate_eventsmax = 0; //damagemax

    this->mainCharStatPoints = 0;
    this->statPoints = 0;


    this-> strength= 0;
    this->intelligence= 0;
    this->brave= 0;
    this->brave_m = 0;
    this-> speed= 0;
    this->resilient = 0;

    this->navigation = 0;
    this->shooting =0;
    this->engineeringSkill =0;
    this->fighting =0;

    this->statPoints = statPoints;
    this->update();

    this->creditAccount = creditAccount;





}



//functions
void mainCharacter::initialise (const std::string name)
{
    this->name = name;
    this->level = 1;


    this->exp = 0;
    this->expNext =
            (30*2)+(pow(this->level,2)+
                    6*pow(this->level,2) -
                    (16* this->level)-8); //==expNext



    this->hp = hpMax;
    this->hpMax = (this->boost * 2) + (this->strength/2);
    this->boost = 10;
    this->defence = 1;
    //this->unfortunate_eventsmin = 1;
    //this->unfortunate_eventsmax = 4;

    this->mainCharStatPoints = 0;
    this->statPoints = 0;
    this-> strength= (this->speed/2) + (this->fighting * 2);
    this->intelligence=15;

    this-> speed=10;
    this->resilient=10;

    this->navigation = 5;
    this->shooting =5;
    this->engineeringSkill =5;
    this->fighting =5;
    this->creditAccount = 500;

    this->update();
    //this->creditAccount=CrewManager::GetCredit(); // (crew - 500);




}

void mainCharacter::printMaincStats()const
{ //everything there is to know about the player

    std::cout << "= Player Menu =" << std::endl;
    std::cout << std::setw(5) << std::setfill('=') << std::endl;
    std::cout << "=Savings Credit Balance: " << this->creditAccount << std::endl;
    std::cout << std::setw(5) << std::setfill('=') << std::endl;
    std::cout << "= Name: " << this->name << std::endl;
    std::cout << "= level: " << this->level << std::endl;
    std::cout << "= Experience Points: " << this->exp << std::endl;
    std::cout << "= Exp Next Level: " << this->expNext << std::endl;
    std::cout << "= Medical: " <<  this->hp << "/" << this->hpMax << std::endl;
    std::cout << "= Defence: " << this->defence << "( +" << this->getProof() << ")" << std::endl;
    std::cout << "= Vigour: " << this->boost << std::endl;
    std::cout << std::setw(5) << std::setfill('=') << std::endl;
    std::cout << "Captain Statistics" << std::endl;
    std::cout << "= Strength: " << this->strength << std::endl;
    std::cout << "= Intelligence: " << this->intelligence << std::endl;
    std::cout << "= Brave: " << this->brave << "( +" << this->battle.getHp() << ")" << "-" << this->brave_m << "( +" << this->battle.getHpMax() << ")" << std::endl;
    std::cout << "= Speed: " << this->speed << std::endl;
    std::cout << "= Resilient: " << this->resilient << std::endl;
    std::cout << "= Navigation: " << this->navigation << std::endl;
    std::cout << "= Shooting: " << this->shooting << std::endl;
    std::cout << "= Engineering Skill: " << this->engineeringSkill << std::endl;
    std::cout << "= Fighting: " << this->fighting << std::endl;
    std::cout << "\n";
    std::cout << "Progression Metre: " <<this->missionCovered_dist << "\n";
    std::cout << "\n";
    std::cout << "Battle: " << this->battle.getName()
              << " Level 1: " << this->battle.getLevel()
              << "Health: " << this->battle.getHp() << "-" << this->battle.getHpMax() << "\n";
    std::cout << "CREW PROTECT: " << this->listBattle_crew.getName()
              << " Level 1: " << this->listBattle_crew.getLevel()
              << " Defence: " << this->listBattle_crew.getDefend() << "\n";
    std::cout << "SHIP PROTECT: " << this->listBattle_ship.getName()
              << " Level 1: " << this->listBattle_ship.getLevel()
              << " Defence: " << this->listBattle_ship.getDefend() << "\n";
    std::cout << "PLAYER PROTECT: " << this->listBattle_player.getName()
              << " Level 1: " << this->listBattle_player.getLevel()
              << " Defence: " << this->listBattle_player.getDefend() << "\n";

    std::cout << std::endl;





}

void mainCharacter::levelUp() { //player moves to next level
    while (this->exp >= this->expNext) {
        this->exp -= this->expNext;
        this->level++;
        this->expNext =
                (30 * 2) + (pow(this->level, 2) +
                            6 * pow(this->level, 2) -
                            (16 * this->level) - 8); //==expNext


        this->mainCharStatPoints++;
        this->statPoints++;
    }
}

void mainCharacter::update() //upgrade for some general attributes
{
    this->expNext = static_cast<int>(
            (30*2)+(pow(this->level,2)+
                    6*pow(this->level,2) -
                    (16* this->level)-8)); //==expNext


    this->hpMax = (this->speed * 4) + (this->strength) + this->level*5;
    this->defence = this->brave + (this->intelligence / 2);


    this->hp = this->hpMax;

}

void mainCharacter::addUpdate(int num, int stat)  //further implemented here
{
    if (this->statPoints < num)
        std::cout << "ERROR! NOT ENOUGH STATPOINTS!" << "\n";
    else
    {
        switch (stat)
        {
            case 0:
                this->strength += num;
                std::cout << "INFLATED STRENGTH!" << "\n";

                break;

            case 1:
                this->intelligence += num;
                std::cout << "EINSTEIN INTELLIGENCE!" << "\n";
                break;

            default:
                std::cout << "NO SUCH STAT!" << "\n";
                break;
        }

        this->statPoints -= num;

        this->update();
    }
}


void mainCharacter::equipObject(unsigned index) {  //player inputs wrong number of selection
    if (index < 0 || index >= this->manage.size()) {
        std::cout << "No valid object selected!" << "\n\n";
    }
    else {
        Battle *b = nullptr;
        b = dynamic_cast<class Battle*>(&this->manage[index]);

        ListBattle *l = nullptr;
        l = dynamic_cast<ListBattle*>(&this->manage[index]);

        if (b != nullptr) {
            if (this->battle.getQuality() >= 0)
                this->manage.addObject(this->battle);
            this->battle = *b;
            this->manage.removeObject(index);
        } else if (l != nullptr) {
            switch (l->getVariety()) {
                case protection::SHIP:
                    if (this->listBattle_ship.getQuality() >= 0)
                        this->manage.addObject(this->listBattle_ship);
                    this->listBattle_ship = *l;
                    this->manage.removeObject(index);
                    break;
                case protection::CREW:
                    if (this->listBattle_crew.getQuality() >= 0)
                        this->manage.addObject(this->listBattle_crew);
                    this->listBattle_crew = *l;
                    this->manage.removeObject(index);
                    break;
                case protection::PLAYER:
                    if (this->listBattle_player.getQuality() >= 0)
                        this->manage.addObject(this->listBattle_player);
                    this->listBattle_player = *l;
                    this->manage.removeObject(index);
                    break;

            }


        }
        else
        {
            std::cout << "CHOOSE OBJECT FAILED, NO SUCH OBJECT EXIST" << std::endl;
        }


    }
}








void mainCharacter::removeObject(const int index) {  //if user tries to remove an object that isn't meant to be removed acts as a precaution
    if (index < 0 || index >= this->manage.size())
        std::cout << "ERROR!" << "\n\n";
    else
    {
        this->manage.removeObject(index);
    }
        }



void mainCharacter::Die(const int impact){ //impact player recerives after fight with enemy
    this->hp -= impact;

    if (this->hp <= 0)
    {
        this->hp = 0;
    }
        }




//for the experience points I've decided to use the idea of euler's(level)
//formula for polyhedra which basically concerns 3D shapes
// I think its ironic using a 3D formula for a 2D game.
// Though i dont understand most of what I'm doing. I'm confident that this game will have the layout i have imagined concerning my game characters
// formula;  v+f-e=2
//Update; it can't be equal to 2 :)