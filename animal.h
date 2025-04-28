#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct {
    int id;
    char name[256];
    char species[256];
    int birth;
    float weight;
    char comment[256];
} Animal;

Animal buildAnimal(char *filePath);
void getEachAnimals(char *dirPath, Animal *animals);

#endif
