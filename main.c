#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "utils.h"
#include "animal.h"
#include "search.h"

#define DIRPATH "animals/"

/*
 * VARIANTES:
 * INV_AGE_ASC
 * DAY_CLEAN
 */

void INV_AGE_ASC(Animal *animals, int animalCount)
{
    printf("Nombre total d'animaux! %d\n", animalCount);
    int resultCount;
    int *presultCount = &resultCount;
    Animal *searchResult = searchByAge(animals, animalCount, presultCount, 1);
    
    free(searchResult);

}


int main()
{
    int animalCount = countFiles(DIRPATH);
    Animal *animals = getEachAnimals(DIRPATH, animalCount);

    
    
    printAnimals(animals, animalCount);
    animalCount = removeAnimal(DIRPATH, &animals, animalCount);
    printAnimals(animals, animalCount);
    return 0;
}
