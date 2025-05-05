#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "animal.h"
#include "utils.h"


void addAnimal(char *dirPath)
{
    int id = countFiles(dirPath) + 1;

    char name[256];
    printf("Entrez le nom de l'animal "); 
    scanf("%s", name);

    char species[256];
    printf("Entrez l'espece de l'animal ");
    scanf("%s", species);

    int birth;
    printf("Entrez l'année de naissance de l'animal ");
    scanf("%d", &birth);

    float weight;
    printf("Entrez le poid de l'animal ");
    scanf("%f", &weight);

    char comment[256];
    printf("Entrez un commentaire sur l'animal ");
    scanf("%s", comment);

    char filePath[1000];
    snprintf(filePath, sizeof(filePath), "%s%d%s", dirPath, id, ".txt");
    printf("%s", filePath);

    FILE *file = fopen(filePath, "w");
    
    if (file == NULL)
    {
	printf("Erreur lors de l'ouverture du fichier \n");
	return;
    }

    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", species);
    fprintf(file, "%d\n", birth);
    fprintf(file, "%f\n", weight);
    fprintf(file, "%s\n", comment);

    fclose(file);
}

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
    






