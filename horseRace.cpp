#include "race.hpp"
#include "horse.hpp"
#include <iostream>

using namespace std;

const int NUMBER_OF_HORSES = 125;

int times[NUMBER_OF_HORSES] = {107,47,102,64,50,100,28,91,27,5,22,114,23,42,13,3,93,8,92,79,53,83,63,7,15,66,105,57,14,65,58,113,112,1,62,103,120,72,111,51,9,36,119,99,30,20,25,84,16,116,98,18,37,108,10,80,101,35,75,39,109,17,38,117,60,46,85,31,41,12,29,26,74,77,21,4,70,61,88,44,49,94,122,2,97,73,69,71,86,45,96,104,89,68,40,6,87,115,54,123,125,90,32,118,52,11,33,106,95,76,19,82,56,121,55,34,24,43,124,81,48,110,78,67,59};
//int times[NUMBER_OF_HORSES] = {107,47,102,64,50,100,28,91,27,5,22,114,23,42,13,3,93,8,92,79,53,83,63,7,15};
//int times[NUMBER_OF_HORSES] = {107,47,102,64,50,100,28,91,27,5};

class Horse horses[NUMBER_OF_HORSES];
class Race race;

void runRaceAndStoreResult(int startIndex, int endIndex)
{
    race.clearRace();
    for (int i = startIndex; i <= endIndex; i++)
    {
        race.addHorse(horses[i]);
    }
    race.runRace();
    for (int i = startIndex, place = 1; i <= endIndex; i++, place++)
    {
       horses[i] = race.getHorseAtPlace(place);
    }
}


int findPivot(int pivot, int horseId)
{
    while (horses[pivot].getId() != horseId)
    {
        pivot++;
    }
    return pivot;
}

int prepareNextRace(int pivot, int lastIndex, int maxIndex)
{
    int endIndex = min(lastIndex+4, maxIndex);

    for (int i = lastIndex+1, j=1; i <= endIndex; i++, j++ )
    {
        cout << "swapping index " << (pivot+j) << " with index " << i << "\n";
        class Horse h = horses[pivot+j];
        horses[pivot+j] = horses[i];
        horses[i] = h;
    }

    return endIndex;
}

printHorses()
{
    for (int i=0; i<NUMBER_OF_HORSES; i++)
    {
        cout << horses[i].getTime() << ", ";
        if ((i % 10) == 9 )
        {
            cout << "\n";
        }
    }
    cout << "\n";
}

void QuickSortHorses(int startIndex, int endIndex)
{
    int numberOfHorses = endIndex - startIndex + 1;
    cout << "QuickSorting from index " << startIndex << " to " << endIndex << "\n";
    cout << "numberOfHorses = " << numberOfHorses << "\n";
    if (numberOfHorses > 0)
    {
        if (numberOfHorses <= 5)
        {
            runRaceAndStoreResult(startIndex, endIndex);
        }
        else
        {
            runRaceAndStoreResult(startIndex, startIndex+4);
            cout << "Racing horse index " << startIndex << " to index " << (startIndex+4) << "\n";
            int pivot = startIndex+2;
            int horseId = horses[pivot].getId();
            int lastIndex = startIndex+4;

            while (lastIndex < endIndex)
            {
                pivot = findPivot(pivot, horseId);
                //printHorses();
                cout << "Pivot = " << pivot << "\n";
                lastIndex = prepareNextRace(pivot, lastIndex, endIndex);
                int lastHorse = min(pivot+4, endIndex);
                runRaceAndStoreResult(pivot, lastHorse);
                cout << "Racing horse index " << pivot << " to index " << lastHorse << "\n";
            }
            pivot = findPivot(pivot, horseId);
            //printHorses();
            cout << "Pivot = " << pivot << "\n";

            cout << "Calling QuickSortHorses from index " << startIndex << " to " << (pivot-1) << "\n";
            QuickSortHorses(startIndex, pivot - 1);
            cout << "Calling QuickSortHorses from index " << (pivot+1) << " to " << endIndex << "\n";
            QuickSortHorses(pivot+1, endIndex);
        }
    }
}

main()
{
    for (int i=0; i<NUMBER_OF_HORSES; i++)
    {
        horses[i].setId(i+1);
        horses[i].setTime(times[i]);
    }

    QuickSortHorses(0, NUMBER_OF_HORSES-1);

    printHorses();

    cout << "Total number of races = " << race.getTotNumRaces() << "\n";


}
