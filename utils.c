#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"
#include "animal.h"

Animal *sortById(Animal *animals, int animalCount) //trie les animaux par leur id avec l'algorithme de tri à bulles
{
    Animal *sortedAnimals = malloc(animalCount * sizeof(Animal));
    if (sortedAnimals == NULL) //l'allocation échoué
    {
        printf("Erreur d'allocation mémoire");
        return NULL;
    }

    for (int i = 0; i < animalCount; i++)
    {
        sortedAnimals[i] = animals[i]; //copie les animaux dans sortedAnimals
    }

    for (int i = 0; i < animalCount - 1; i++) //trie les animaux par leur id avec l'algorithme de tri à bulles
    {
        for (int j = 0; j < animalCount - i - 1; j++)
        {
            if (sortedAnimals[j].id > sortedAnimals[j + 1].id) //compare les animaux 2 à 2
            {
                Animal temp = sortedAnimals[j]; //échange les deux animaux s'ils ne sont pas dans l'ordre
                sortedAnimals[j] = sortedAnimals[j + 1];
                sortedAnimals[j + 1] = temp;
            }
        }
    }
    return sortedAnimals; //retourne le tableau ordonné
}

char* strlwr(char* str) //convertit une chaîne de caractères en minuscules
{
    for(char *p = str; *p; p++) //parcourt chaque caractère de la chaîne
    {
        *p = tolower(*p); //convertit le caractère en minuscule
    }
    return str; //retourne la chaine convertie
}

void clear_screen() //efface l'écran en fonction du système d'exploitation
{
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}

void printAnimalsShorted(Animal *animals, int animalCount) //affiche la liste des animaux triés par id (id et nom)
{
    Animal *sortedAnimals = sortById(animals, animalCount); //trie les animaux par id
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

void printAnimals(Animal *animals, int animalCount) //affiche tous les animaux
{
    Animal *sortedAnimals = sortById(animals, animalCount);
    for (int i = 0; i < animalCount; i++)
    {
        printAnimal(sortedAnimals[i]);
        printf("\n");
    }
}

int getId(Animal *animals, int animalCount) //donne un id à un nouvel animal
{
    Animal *sortedAnimals = sortById(animals, animalCount); //trie les animaux par id
    if (sortedAnimals == NULL)
    {
        printf("Erreur lors du tri des animaux.\n");
        return -1;
    }

    if (sortedAnimals[0].id != 1) //si l'id 1 n'est pas utilisé, on l'utilise
    {
        return 1;
    }
    
    for (int i = 0; i < animalCount - 1; i++)
    {
        if (sortedAnimals[i + 1].id != sortedAnimals[i].id + 1) //s'il y a un id manquant dans la séquence...
        {
            return sortedAnimals[i].id + 1;  //...on le return
        }
    }
    return sortedAnimals[animalCount - 1].id + 1; //si tous les id sont consécutifs, return l'id suivant
}

int countFiles(char *dirPath) //compte le nombre de fichiers
{
    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir(dirPath); //fonction qui permet d'ouvrir le répertoire

    if (dir == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) //lit le répertoire
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        count++;
    }
    closedir(dir); //ferme le répertoire
    return count;
}


void trimWhitespace(char *str) //supprime les espaces d'une chaîne de caractères
{
    char *end;

    while (isspace((unsigned char)*str)) str++; //ignore les espaces au début de la chaîne

    if (*str == 0) return; 

    end = str + strlen(str) - 1; //trouve le dernier caractère de la chaîne
    while (end > str && isspace((unsigned char)*end)) end--; //ignore les espaces à la fin de la chaîne

    *(end + 1) = '\0'; 
}

void printAnimal(Animal animal) //affiche les détails de l'animal.
{
    printf("id: %d \n", animal.id);
    printf("name: %s \n", animal.name);
    printf("specie: %s \n", animal.species);
    printf("age: %d \n", animal.age);
    printf("weight: %.2f \n", animal.weight);
    printf("comment: %s \n", animal.comment);
}
