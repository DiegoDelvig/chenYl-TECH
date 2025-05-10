#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "animal.h"
#include "utils.h"

int removeAnimal(char *dirPath, Animal **panimals, int animalCount)
{
    int id;
    printf("Entrez l'id de l'animal à supprimer: ");
    scanf("%d", &id);

    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s%d.txt", dirPath, id);
    
    if (remove(filePath) == 0)
    {
        printf("Fichier supprimé avec succès.\n");
    }
    else
    {
        printf("Erreur lors de la suppression du fichier.\n");
        return animalCount;
    }

    // Libéré la mémoire
    if (*panimals == NULL)
    {
        free(*panimals);
        *panimals = NULL;
    }

    *panimals = getEachAnimals(dirPath, animalCount - 1);

    return animalCount - 1; // Retourne la nouvelle taille
}

int addAnimal(char *dirPath, Animal **panimals, int animalCount)
{
    int id = getMaxId(*panimals, animalCount) + 1;
    printf("id: %d \n", id);
    char name[256];
    printf("Entrez le nom: ");
    scanf("%s", name);
    strlwr(name);

    int speciesChoice;
    printf("Choisissez l'espèce:\n");
    printf("1. Chien\n");
    printf("2. Chat\n");
    printf("3. Hamster\n");
    printf("4. Autruche\n");
    scanf("%d", &speciesChoice);
    char species[256];
    switch (speciesChoice)
    {
        case 1:
            strcpy(species, "chien");
            break;
        case 2:
            strcpy(species, "chat");
            break;
        case 3:
            strcpy(species, "hamster");
            break;
        case 4:
            strcpy(species, "autruche");
            break;
        default:
            printf("Choix invalide.\n");
            return -1;
    }

    int birthDate;
    printf("Entrez l'année de naissance: ");
    scanf("%d", &birthDate);
    
    float weight;
    printf("Entrez le poid: ");
    scanf("%f", &weight);

    char comment[256];
    printf("Entrez le commentaire: ");
    scanf("%s", comment);

    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/%d.txt", dirPath, id);
    
    FILE *file = fopen(filePath, "w");
    if (file) {
        fprintf(file, "%d\n", id);
        fprintf(file, "%s\n", name);
        fprintf(file, "%s\n", species);
        fprintf(file, "%d\n", birthDate);
        fprintf(file, "%f\n", weight);
        fprintf(file, "%s", comment);
        fclose(file);
    }
    
    // Libéré la mémoire
    if (*panimals == NULL)
    {
        free(*panimals);
        *panimals = NULL;
    }

    *panimals = getEachAnimals(dirPath, animalCount + 1);

    printf("Animal ajouté avec succès.\n");
    return animalCount + 1; // Retourne la nouvelle taille
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
    animal.age = 2025 - atoi(line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    animal.weight = atof(line);

    fgets(line, sizeof(line), file);
    trimWhitespace(line);
    strcpy(animal.comment, line);
    
    fclose(file);
    return animal;

}

Animal *getEachAnimals(char *dirPath, int animalCount)
{
    Animal *animals = malloc(animalCount * sizeof(Animal));
    if (animals == NULL)
    {
	printf("Erreur d'allocation mémoire");
	return NULL;
    }

    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
	printf("Erreur lors de l'ouverture du dossier: %s \n", dirPath);
	return NULL;
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
    return animals;
}
    






