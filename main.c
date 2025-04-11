#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define DIRPATH "animals/"


void readTextFile(char *filePath) 
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    char line[1024]; // Buffer pour lire les lignes
    printf("Contenu du fichier %s :\n", filePath);
    while (fgets(line, sizeof(line), file)) 
    {
        printf("%s", line); // Affiche chaque ligne
    }
    printf("\n");
    fclose(file);
}

void processDirectory(char *dirPath)
{
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
	printf("Erreur lors de l'ouvertur du dossier\n");
	return;
    }


    while ((entry = readdir(dir)) != NULL)
    {
	// Ignore les entrées spéciale "." et ".."
	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	    continue;
	
	char filePath[256]; // Buffer large enough for the path
	snprintf(filePath, sizeof(filePath), "%s%s", dirPath, entry->d_name);
	
	readTextFile(filePath);
    }

}

int main()
{
    processDirectory(DIRPATH);
    return 0;
}
