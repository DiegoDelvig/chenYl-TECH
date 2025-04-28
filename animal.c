#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "animal.h"
#include "utils.h"

Animal buildAnimal(char *filePath)
{
    Animal animal;
    FILE *file = fopen(filePath, "r");

    if (file == NULL)
    {
	printf("Erreur lors de l'ouverture du fichier %s \n", filePath);
	return animal;
    }

    char line[256];
    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    animal.id = atoi(line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    strcpy(animal.name, line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    strcpy(animal.species, line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    animal.birth = atoi(line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    animal.weight = atof(line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    strcpy(animal.comment, line);
    
    fclose(file);
    return animal;

}

void getEachAnimals(char *dirPath, Animal *animals)
{
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
	printf("Erreur lors de l'ouverture du dossier: %s \n", dirPath);
	return;
    }

    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
	// Ignore les entrées spéciale "." et ".."
	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	    continue;

	char filePath[256];
	snprintf(filePath, sizeof(filePath), "%s%s", dirPath, entry->d_name);
	animals[i] = buildAnimal(filePath);
	i++;
    }
    closedir(dir);
}
    






