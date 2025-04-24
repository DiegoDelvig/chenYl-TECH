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
    
    char name[256];
    scanf("%s", name);
    getEachAnimals(DIRPATH, animals);
    int resultCount;
    int *presultCount = &resultCount;
    Animal *searchResult = searchByName(animals, animalCount, presultCount, name);

    printf("%d \n", resultCount);
    

    free(searchResult);
    free(animals);
    return 0;
}
