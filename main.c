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

void printArr(char arr[][50], int n)
{
    for (int i = 0; i < n; i++)
    {
	printf("%s \n", arr[i]);
    }
}

void getLine(char *filePath, int lineNumber, char *line)
{
   int countLine = 1;

   FILE *file = fopen(filePath, "r");
   if (file == NULL)
   {
       printf("Erreur lors de l'ouverture du fichier\n");
       return;
   }

   while (fgets(line, sizeof(line), file))
   {
       if (countLine == lineNumber)
       {
	   break;
       }
       countLine++;
   }
   fclose(file);
}

void searchByLineInEachFile(char *dirPath, int lineNumber, char *input)
{
    struct dirent *entry;
    DIR *dir = opendir(dirPath);

    if (dir == NULL)
    {
	printf("Erreur lors de l'ouvertur du dossier\n");
	return;
    }

    int count = 0;
    int matches = 0;
    while ((entry = readdir(dir)) != NULL)
    {
	// Ignore les entrées spéciale "." et ".."
	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	    continue;
	
	char line[256];
	char filePath[256];
	snprintf(filePath, sizeof(filePath), "%s%s", dirPath, entry->d_name);
	
	// Suprimme le "\n" de line
	getLine(filePath, lineNumber, line);
	int len = strlen(line);
	if (len > 0 && line[len - 1] == '\n') 
	    line[len - 1] = '\0';

	if (strcmp(line, input) == 0)
	{
	    printf("Matche trouvé\n");
	    matches++;
	}
	count++;
    }
}

void search(char *dirPath)
{

    int typeSearch;
    printf("Avec quelle caractèristique veut tu rechercher: \n 1.nom \n 2. espèce 3. Type d'âge\n (1?/2?/3?) ");
    scanf("%d", &typeSearch);

    Animal searchResult[256][50];

    if (typeSearch == 1) 
    {
	char nom[10];
	printf("Nom : ");
	scanf("%s", nom);

	int lineNumber = 2;
	searchByLineInEachFile(dirPath, lineNumber, nom);
    }

}



int main()
{
    search(DIRPATH); 
    return 0;
}
