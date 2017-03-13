#include "race.hpp"
#include "horse.hpp"

Race::Race(void)
{
    numHorses = 0;
    totNumRaces = 0;
}

void Race::addHorse(Horse horse)
{
    horses[numHorses] = horse;
    numHorses++;
}

void Race::clearRace()
{
    numHorses = 0;
}

void Race::runRace()
{
    for (int i = 0; i < numHorses - 1; i++)
    {
        for (int j = i+1; j < numHorses; j++)
        {
            if (horses[j].getTime() < horses[i].getTime())
            {
                Horse h = horses[i];
                horses[i] = horses[j];
                horses[j] = h;
            }
        }
    }
    totNumRaces++;
}

int Race::getTotNumRaces()
{
    return totNumRaces;
}

Horse Race::getHorseAtPlace(int place)
{
    return horses[place-1];
}

