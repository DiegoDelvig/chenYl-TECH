#ifndef UTILS_H
#define UTILS_H

#include "animal.h"

char* strlwr(char* str);
void clear_screen();
void printAnimalsShorted(Animal *animals, int animalCount);
void printAnimals(Animal *animals, int animalCount);
int getId(Animal *animals, int animalCount);
int countFiles(char *dirPath);
void trimWhitespace(char *str);
void printAnimal(Animal animal);

#endif
