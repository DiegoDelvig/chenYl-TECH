#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"
#include "animal.h"

Animal *sortById(Animal *animals, int animalCount)
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
            if (sortedAnimals[j].id > sortedAnimals[j + 1].id)
            {
                Animal temp = sortedAnimals[j];
                sortedAnimals[j] = sortedAnimals[j + 1];
                sortedAnimals[j + 1] = temp;
            }
        }
    }
    return sortedAnimals;
}

char* strlwr(char* str) 
{
    for(char *p = str; *p; p++) 
    {
        *p = tolower(*p);
    }
    return str;
}

void clear_screen() 
{
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}

void printAnimalsShorted(Animal *animals, int animalCount)
{
    Animal *sortedAnimals = sortById(animals, animalCount);
    if (sortedAnimals == NULL)
    {
        printf("Erreur lors du tri des animaux.\n");
        return;
    }
    for (int i = 0; i < animalCount; i++)
    {
        printf("[%d] | %s \n", sortedAnimals[i].id, sortedAnimals[i].name);
        printf("\n"); 
    }
}

void printAnimals(Animal *animals, int animalCount)
{
    Animal *sortedAnimals = sortById(animals, animalCount);
    for (int i = 0; i < animalCount; i++)
    {
        printAnimal(sortedAnimals[i]);
        printf("\n"); 
    }
}

int getId(Animal *animals, int animalCount)
{
    Animal *sortedAnimals = sortById(animals, animalCount);
    if (sortedAnimals == NULL)
    {
        printf("Erreur lors du tri des animaux.\n");
        return -1;
    }

    if (sortedAnimals[0].id != 1)
    {
        return 1;
    }
    
    for (int i = 0; i < animalCount - 1; i++)
    {
        if (sortedAnimals[i + 1].id != sortedAnimals[i].id + 1)
        {
            return sortedAnimals[i].id + 1;
        }
    }
    return sortedAnimals[animalCount - 1].id + 1;
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
    printf("age: %d \n", animal.age);
    printf("weight: %.2f \n", animal.weight);
    printf("comment: %s \n", animal.comment);
}
