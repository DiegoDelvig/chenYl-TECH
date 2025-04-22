#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define DIRPATH "animals/"

typedef struct {
    int id;
    char name[256];
    char specie[256];
    int birth;
    float weight;
    char comment[256];
} Animal;

int countFiles(char *dirPath)
{
    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
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


Animal buildAnimal(char *filePath)
{
    Animal animal;
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier %s\n", filePath);
        return animal;
    }

    char line[256];
    fgets(line, sizeof(line), file);
    
    // Suprimme le "\n" de line
	int len = strlen(line);
	if (len > 0 && line[len - 1] == '\n') 
	    line[len - 1] = '\0';

    animal.id = atoi(line);

    fgets(line, sizeof(line), file);
    strcpy(animal.name, line);

    fgets(line, sizeof(line), file);
    strcpy(animal.specie, line);

    fgets(line, sizeof(line), file);
    // Suprimme le "\n" de line
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n') 
	    line[len - 1] = '\0';

    animal.birth = atoi(line);

    fgets(line, sizeof(line), file);
    // Suprimme le "\n" de line
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n') 
	    line[len - 1] = '\0';

    animal.weight = atof(line);

    fgets(line, sizeof(line), file);
    strcpy(animal.comment, line);
    fclose(file);
    return animal;
}

Animal *getEachAnimals(char *dirPath, Animal *animals)
{
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
        printf("Erreur lors de l'ouvertur du dossier\n");
        return NULL;
    }
    
    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore les entrées spéciale "." et ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
	
        char filePath[256]; // Buffer large enough for the path
        snprintf(filePath, sizeof(filePath), "%s%s", dirPath, entry->d_name);
        animals[i] = buildAnimal(filePath);
        i++;
    }
    closedir(dir);
    return animals;
}

void printAnimal(Animal animal)
{
    printf("%s \n", animal.name);
}


int main()
{
    int animalCount = countFiles(DIRPATH);
    Animal *animals = malloc(animalCount * sizeof(Animal));
    if (animals == NULL)
    {
        printf("Erreur d'allocation de mémoire");
        return 1;
    }

    getEachAnimals(DIRPATH, animals);

    for (int i = 0; i < animalCount; i++)
        printAnimal(animals[i]);
    
    free(animals);
    return 0;
}
