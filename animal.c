#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "animal.h"
#include "utils.h"

int removeAnimal(char *dirPath, Animal **panimals, int animalCount)
{
    int id;
    printf("Entrez l'id de l'animal à supprimer (0 pour quitter): ");
    scanf("%d", &id);

    if (id == 0)
    {
        printf("Suppression annulée.\n");
        return animalCount;
    }

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
    int id = getId(*panimals, animalCount);
    printf("id: %d \n", id);
    char name[256];
    printf("Entrez le nom (Mettre rien pour annuler): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Supprime le \n en fin de chaîne
    strlwr(name);

    if (name[0] == '\0')
    {
        printf("Anullation de l'ajout.\n");
        return animalCount;
    }

    int speciesChoice;
    do {
        printf("Choisissez l'espèce (0 pour annuler):\n");
        printf("1. Chien\n");
        printf("2. Chat\n");
        printf("3. Hamster\n");
        printf("4. Autruche\n");
        scanf("%d", &speciesChoice);
        
        if (speciesChoice == 0)
        {
            printf("Anullation de l'ajout.\n");
            return animalCount;
        }
    
    } while (speciesChoice < 1 || speciesChoice > 4);
    
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
    }

    int birthDate;
    printf("Entrez l'année de naissance (0 pour annuler): ");
    scanf("%d", &birthDate);  
    if (birthDate < 1950 || birthDate > 2025)
    {
        do {
            if (birthDate == 0)
            {
                printf("Anullation de l'ajout.\n");
                return animalCount;
            }
            printf("Choisir une année entre 1950 et 2025: ");
            scanf("%d", &birthDate);    
        } while (birthDate < 1950 || birthDate > 2025);
    }

    
    float weight;
    printf("Choisir un poid entre 0.1 et 150.0 (0 pour annuler): ");
    scanf("%f", &weight);
    if (weight < 0.1 || weight > 150.0)
    {
        do {
            if (weight == 0)
            {
                printf("Anullation de l'ajout.\n");
                return animalCount;
            }
            printf("Choisir un poid entre 0.1 et 150.0 (0 pour annuler): ");
            scanf("%f", &weight);    
        } while (weight < 0.05 || weight > 150.0);
    }

    // Vider le buffer avant de lire le commentaire
    getchar();

    char comment[256];
    printf("Entrez le commentaire (Mettre rien pour annuler): ");
    fgets(comment, sizeof(comment), stdin);
    comment[strcspn(comment, "\n")] = '\0';

    if (comment[0] == '\0')
    {
        printf("Anullation de l'ajout.\n");
        return animalCount;
    }

    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/%d.txt", dirPath, id);
    
    FILE *file = fopen(filePath, "w");
    if (file) 
    {
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