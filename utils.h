#ifndef UTILS_H
#define UTILS_H

#include "animal.h"

void printAnimals(Animal *animals, int animalCount);
int getMaxId(Animal *animals, int animalCount);
int countFiles(char *dirPath);
void trimWhitespace(char *str);
void printAnimal(Animal animal);

#endif
