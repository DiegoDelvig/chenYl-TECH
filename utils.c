#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"
#include "animal.h"

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

// Function to trim leading and trailing whitespace
void trimWhitespace(char *str) 
{
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    if (*str == 0) return; // All spaces?

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null-terminate the string
    *(end + 1) = '\0';
}

void printAnimal(Animal animal)
{
    printf("id: %d \n", animal.id);
    printf("name: %s \n", animal.name);
    printf("specie: %s \n", animal.specie);
    printf("birth: %d \n", animal.birth);
    printf("weight: %.2f \n", animal.weight);
    printf("comment: %s \n", animal.comment);
}
