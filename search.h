#ifndef SEARCH_H
#define SEARCH_H

#include "animal.h"

Animal *searchByAge(Animal *animals, int animalCount, int *resultCount, int ageType);
Animal *searchBySpecies(Animal *animals, int animalCount, int *resultCount, char *species);
Animal *searchByName(Animal *animals, int AnimalCount, int *resultCount, char *name);

#endif
