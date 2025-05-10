#include <stdio.h>
#include <stdlib.h>

#include "variantes.h"
#include "utils.h"
#include "animal.h"

void INV_AGE_ASC(Animal *animals, int animalCount)
{

}

void DAY_CLEAN(Animal *animals, int animalCount)
{
    int minutes = 0; // Temps en minutes
    for (int i = 0; i <= 50; i++)
    {
        if (animalCount >= i)
        {
            if (animals[i].species == "chat" || animals[i].species == "hamster")
            {
                minutes += 7 * 10 + 20;
            }
            else if (animals[i].species == "autruche")
            {
                minutes += 7 * 20 + 45;
            }
            else if (animals[i].species == "chien")
            {
                minutes += 7 * 5 + 20;
            }
        }
        else
        {
            minutes += 2;
        }
    }
    printf("Le temps de nettoyage est de %d minutes par semaine.\n", minutes);
}