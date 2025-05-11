#include <stdio.h>
#include <stdlib.h>

#include "variantes.h"
#include "utils.h"
#include "animal.h"

Animal *sortedByAge(Animal *animals, int animalCount)
{
    Animal *sortedAnimals = malloc(animalCount * sizeof(Animal));
    if (sortedAnimals == NULL)
    {
        printf("Erreur d'allocation mémoire");
        return NULL;
    }

    for (int i = 0; i < animalCount; i++)
    {
        sortedAnimals[i] = animals[i];
    }

    for (int i = 0; i < animalCount - 1; i++)
    {
        for (int j = 0; j < animalCount - i - 1; j++)
        {
            if (sortedAnimals[j].age > sortedAnimals[j + 1].age)
            {
                Animal temp = sortedAnimals[j];
                sortedAnimals[j] = sortedAnimals[j + 1];
                sortedAnimals[j + 1] = temp;
            }
        }
    }
    return sortedAnimals;
}

void INV_AGE_ASC(Animal *animals, int animalCount)
{
    Animal *sortedAnimals = sortedByAge(animals, animalCount);
    if (sortedAnimals == NULL)
    {
        printf("Erreur lors du tri des animaux.\n");
        return;
    }

    int q1 = 0;
    int q2 = animalCount / 4;
    int q3 = animalCount / 2;
    int q4 = (animalCount * 3) / 4;

    printf("Animaux triés par âge:\n");
    printf("---- 1er quartile: ----\n");
    for (int i = q1; i < q2; i++)
    {
        printAnimal(sortedAnimals[i]);
    }
    printf("---- 2ème quartile: ----\n");
    for (int i = q2; i < q3; i++)
    {
        printAnimal(sortedAnimals[i]);
    }
    printf("---- 3ème quartile: ----\n");
    for (int i = q3; i < q4; i++)
    {
        printAnimal(sortedAnimals[i]);
    }
    printf("---- 4ème quartile: ----\n");
    for (int i = q4; i < animalCount; i++)
    {
        printAnimal(sortedAnimals[i]);
    }
    free(sortedAnimals);
}

void DAY_CLEAN(Animal *animals, int animalCount)
{
    int minutes = 0; //temps en minutes par semaine
    for (int i = 0; i < 50; i++) //car 50 fichiers max
    {
        if (animalCount > i)
        {
            if (strcmp(animals[i].species, "chat") == 0 || strcmp(animals[i].species, "hamster") == 0) //si animal = chat ou hamster
            {
                minutes += 7 * 10 + 20; //90min
            }
            else if (strcmp(animals[i].species, "autruche") == 0) // si animal = autruche
            {
                minutes += 7 * 20 + 45; // entretien = 185min
            }
            else if (strcmp(animals[i].species, "chien") == 0) //si animal = chien
            {
                minutes += 7 * 5 + 20; //55min
            }
        }
        else //si la cage est vide
        {
            minutes += 2*7; //entretien = 14min
        }
    }
    printf("Le temps de nettoyage est de %d minutes par semaine.\n", minutes);
}
