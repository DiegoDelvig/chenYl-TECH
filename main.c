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


int main()
{
    /*
    int animalCount = countFiles(DIRPATH);
    Animal *animals = malloc(animalCount * sizeof(Animal));
    if (animals == NULL)
    {
	printf("Erreur d'allocation mémoire");
	return 1;
    }
    getEachAnimals(DIRPATH, animals);
    int resultCount;
    int *presultCount = &resultCount;
    Animal *searchResult = searchByAge(animals, animalCount, presultCount, 2);

    printf("%d \n", resultCount);
    for (int i = 0; i <= resultCount; i++)
	printAnimal(searchResult[i]);

    free(searchResult);
    free(animals);
    */

    addAnimal(DIRPATH);

    return 0;
}
