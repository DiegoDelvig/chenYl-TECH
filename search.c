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

Animal *searchByAge(Animal *animals, int animalCount, int *presultCount, int ageType) //recherche les animaux en fonction de leur type d'âge
{
    // Compte le nombre de résultats de la recherche
    int count = 0;
    for (int i = 0; i < animalCount; i++)
    {
        
        if (ageType == 1)
        {
            if (animals[i].age <= 2)
                count++;
        }

        
        if (ageType == 2)
        {
            if (animals[i].age >= 10)
                count++;
        }
    }

    printf("Nombre d'animaux trouvés: %d\n", count);
    if (count == 0)
    {
        presultCount = 0;
        return NULL;
    }

    Animal *searchResult = malloc(count * sizeof(Animal));
    if (searchResult == NULL)
    {
        printf("Erreur d'allocation mémoire");
        return NULL;
    }


    int n = 0;
    for (int i = 0; i < animalCount; i++)
    {
        
        if (ageType == 1)
        {
            if (animals[i].age <= 2)
            {
                searchResult[n] = animals[i];
                n++;
            }
	    }

        
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

Animal *searchBySpecies(Animal *animals, int animalCount, int *presultCount, char *species) //recherche les animaux en fonction de leur espèce
{
    int count = 0;

    // Compte le nombre de résultats de la recherche
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

Animal *searchByName(Animal *animals, int animalCount, int *presultCount, char *name) //recherche les animaux en fonction de leur nom
{
    int count = 0;
    strlwr(name);

    // Compte le nombre de résultats de la recherche
    for (int i = 0; i < animalCount; i++)
    {
        trimWhitespace(animals[i].name);
        if (strcmp(animals[i].name, name) == 0)
            count++;
    }

    if (count == 0)
    {
        presultCount = 0;
        printf("Aucun animal trouvé avec ce nom.\n");
        return NULL;
    }

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
