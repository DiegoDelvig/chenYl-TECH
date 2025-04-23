#include <stdio.h>
#include <dirent.h>
#include <string.h>

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

void formatLine(char *line)
{
    int len = sizeof(line);
    if (len > 0 && line[len - 1] == '\n')
	line[len - 1] = '\0';
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
