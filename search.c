#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "utils.h"

/* 
Différent type de recherche possible:
1. Le nom
2. L'espèce
3. Le type d'age: rechercher un aimal jeune (< 2 ans), ou sénior (> 10 ans)
*/

void searchByName(Animal *animals, Animal *searchResult, int animalCount, char *name)
{
    int count = 0;
    for (int i = 0; i < animalCount; i++)
    {
	if (strcmp(animals[i].name, name) == 0)
	{
	    searchResult[count] = animals[i];
	    printf("%s\n", animals[i].name);
	    count++;
	}
    }
}
