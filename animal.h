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


int removeAnimal(char *dirPath, Animal **animals, int animalCount);
int addAnimal(char *dirPath, Animal **animals, int animalCount);
Animal buildAnimal(char *filePath);
Animal *getEachAnimals(char *dirPath, int animalCount);

#endif
