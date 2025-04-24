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


Animal *searchByName(Animal *animals, int animalCount, int *resultCount, char *name)
{
    int count = 0;

    // Compte les correspondaces.
    for (int i = 0; i < animalCount; i++)
    {
	trimWhitespace(animals[i].name);
	if (strcmp(animals[i].name, name) == 0)
	    count++;
    }

    if (count == 0)
    {
	resultCount = 0;
	return NULL;
    }

    // Allouer dynamiquement la mémoire du tableau
    Animal *searchResult = malloc(count * sizeof(Animal));
    if (searchResult == NULL)
    {
	printf("Erreur d'allocation mémoire");
	return NULL;
    }

    int n = 0;
    for (int i = 0; i < animalCount; i++)
    {
	if (strcmp(animals[i].name, name) == 0)
	{
	    searchResult[n] = animals[i];
	    n++;
	}
    }

    resultCount = count;
    return searchResult;
}
