#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "utils.h"

/*
* Différent type de recherche possible:
* 1. Le nom
* 2. L'espèce
* 3. Le type d'age: rechercher un animal jeune (<= 2 ans, ou sénior >= 10 ans)
*/

Animal *searchByAge(Animal *animals, int animalCount, int *presultCount, int ageType)
{
    int count = 0;

    // Compte les correspondaces.
    for (int i = 0; i < animalCount; i++)
    {
	// Jeune
	if (ageType == 1)
	{
	    if (animals[i].age <= 2)
		count++;
	}

	// Senior
	if (ageType == 2)
	{
	    if (animals[i].age >= 10)
		count++;
	}
    }


    if (count == 0)
    {
	presultCount = 0;
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
	// Jeune
	if (ageType == 1)
	{
	    if (animals[i].age <= 2)
	    {
		searchResult[n] = animals[i];
		n++;
	    }
	}

	// Senior
	if (ageType == 2)
        {
            if (animals[i].age >= 10)
            {
            searchResult[n] = animals[i];
            n++;
            }
        }
    }

    *presultCount = count;
    return searchResult;

}

Animal *searchBySpecies(Animal *animals, int animalCount, int *presultCount, char *species)
{
    int count = 0;

    // Compte les correspondaces.
    for (int i = 0; i < animalCount; i++)
    {
        trimWhitespace(animals[i].species);
        if (strcmp(animals[i].species, species) == 0)
            count++;
    }

    if (count == 0)
    {
        presultCount = 0;
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
        if (strcmp(animals[i].species, species) == 0)
        {
                searchResult[n] = animals[i];
                n++;
        }
    }

    *presultCount = count;
    return searchResult;

}

Animal *searchByName(Animal *animals, int animalCount, int *presultCount, char *name)
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
        presultCount = 0;
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

    *presultCount = count;
    return searchResult;
}
