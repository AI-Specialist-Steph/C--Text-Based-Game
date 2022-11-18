cmake_minimum_required(VERSION 3.21)
project(testGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(testGame main.cpp spaceship.h mainCharacter.cpp mainCharacter.h Gameship.cpp Gameship.h Enemies.cpp Enemies.h Character.cpp Character.h CrewManager.cpp CrewManager.h Manage.cpp Manage.h Battle.cpp Battle.h Object.cpp Object.h ListBattle.cpp ListBattle.h BountyHunt.cpp BountyHunt.h battleArr.h UnfortunateEvents.cpp UnfortunateEvents.h )



