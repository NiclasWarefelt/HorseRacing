#ifndef RACE_HPP_INCLUDED
#define RACE_HPP_INCLUDED

#include "horse.hpp"

class Race {
public:
    Race(void);

    void clearRace();
    void addHorse(Horse horse);
    void runRace();

    Horse getHorseAtPlace(int place);
    int getTotNumRaces();

private:
    int numHorses;
    int totNumRaces;
    Horse horses[5];
};

#endif // RACE_HPP_INCLUDED
