#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "utils.h"
#include "animal.h"
#include "search.h"

#define DIRPATH "animals/"

int main()
{
    int animalCount = countFiles(DIRPATH);
    Animal *animals = malloc(animalCount * sizeof(Animal));

    if (animals == NULL)
    {
	printf("Erreur d'allocation mémoire");
	return 1;
    }

    getEachAnimals(DIRPATH, animals);

    Animal *searchResult = malloc(animalCount * sizeof(Animal));
    if (searchResult == NULL)
    {
	printf("Erreur d'allocation mémoire");
	return 1;
    }

    searchByName(animals, searchResult, animalCount, "Diego");

    free(searchResult);
    free(animals);
    return 0;
}
