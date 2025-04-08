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



}

void searchByLigne(char *path, int line, char *c) {
  DIR *dir = opendir(path); // Ouvre le répertoire
 
  if (dir == NULL) {
	  exit(1);
  }

  struct dirent* entity; // Structure pour lire les entrées du dossier
  entity = readdir(dir); // Lit l'entrée suivante
  entity = readdir(dir); // Lit l'entrée suivante
  entity = readdir(dir); // Lit l'entrée suivante

  
  // Parcourt toutes les entrées du répertoire
  while (entity != NULL) {


    printf("%s \n", entity->d_name);
    entity = readdir(dir); // Lit l'entrée suivante

  }

   closedir(dir); // Ferme le répertoire
}

void searchAnimals(char *path) {

  // AJOUTER SECURITER 
  int ctx;
  printf("Avec quelle caractèristique veut tu rechercher: \n 1.nom \n 2. espèce 3. Type d'âge\n (1?/2?/3?)");
  scanf("%d", &ctx);

  if (ctx == 1) {
    char nom[10];
    printf("Nom de l'animal recherché :");
    scanf("%s", nom);
    searchByLigne(path, 2, nom);
  }


}

int main(int argc, char *argv[]) {
  searchAnimals(PATH);
  
  return 0;
}
