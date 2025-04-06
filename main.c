#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define PATH "animals/"

int countFiles(char *path) {
  int dirCount = 0;
  DIR *dir = opendir(path); // Ouvre le répertoire
 
  if (dir == NULL) {
	  exit(1);
  }

  struct dirent* entity; // Structure pour lire les entrées du dossier
  entity = readdir(dir);
  
  // Parcourt toutes les entrées du répertoire
  while (entity != NULL) {
    dirCount++;
    entity = readdir(dir); // Lit l'entrée suivante
  }

   closedir(dir); // Ferme le répertoire
  
  // Retourne le total moins 2 (pour exclure . et ..)
  return dirCount - 2;
}

void addAnimal(char *path) {
  int numId = countFiles(path) + 1; 

  // Vérifie si le nombre d'animaux dépasse la limite
  if (numId >= 50) {
    printf("Le refuge est plein.\n");
    exit(1);
  }

  // Crée le nom de fichier (le numéro d'identification de l'animal + .txt)
  char fileName[16] = ".txt";
  snprintf(fileName, sizeof(fileName), "%d%s", numId, ".txt");
  if (fileName == NULL) {
    exit(1);
  }

}

int main(int argc, char *argv) {
  addAnimal(PATH);
  return 0;
}
