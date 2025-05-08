#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"
#include "animal.h"

void printAnimals(Animal *animals, int animalCount)
{
    for (int i = 0; i < animalCount; i++)
    {
	printAnimal(animals[i]);
	printf("\n"); 
    }
}

int getMaxId(Animal *animals, int animalCount)
{
    int id = 0;

    for (int i = 0; i < animalCount; i++)
    {
	if (animals[i].id > id)
	    id = animals[i].id;
    }
    return id;
}

int countFiles(char *dirPath)
{
    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
	printf("Erreur lors de l'ouverture du fichier");
	return 0;
    }

    while ((entry = readdir(dir)) != NULL)
    {
	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	    continue;
	count++;
    }
    closedir(dir);
    return count;
}


void trimWhitespace(char *str) 
{
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return; 

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

void printAnimal(Animal animal)
{
    printf("id: %d \n", animal.id);
    printf("name: %s \n", animal.name);
    printf("specie: %s \n", animal.species);
    printf("birth: %d \n", animal.birth);
    printf("weight: %.2f \n", animal.weight);
    printf("comment: %s \n", animal.comment);
}
