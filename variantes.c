#include <stdio.h>
#include <stdlib.h>

#include "variantes.h"
#include "utils.h"
#include "animal.h"

Animal *sortedByAge(Animal *animals, int animalCount) //fonction qui permet de trier un tableau d'animaux par âge croissant
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

void INV_AGE_ASC(Animal *animals, int animalCount) //affiche les animaux triés par âge
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

void DAY_CLEAN(Animal *animals, int animalCount) //calcule le temps total de nettoyage des cages en minutes/semaine
{
    int minutes = 0;
    for (int i = 0; i < 50; i++)
    {
        if (animalCount > i)
        {
            if (strcmp(animals[i].species, "chat") == 0 || strcmp(animals[i].species, "hamster") == 0)
            {
                minutes += 7 * 10 + 20;
            }
            else if (strcmp(animals[i].species, "autruche") == 0)
            {
                minutes += 7 * 20 + 45;
            }
            else if (strcmp(animals[i].species, "chien") == 0)
            {
                minutes += 7 * 5 + 20;
            }
        }
        else 
        {
            minutes += 2*7;
        }
    }
    printf("Le temps de nettoyage est de %d minutes par semaine.\n", minutes);
}
