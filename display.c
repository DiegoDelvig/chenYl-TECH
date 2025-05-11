#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "utils.h"
#include "search.h"
#include "variantes.h"

void printLogo()
{
    printf("       .__                 _____.___.__          _______________________________   ___ ___  \n");
    printf("  ____ |  |__   ____   ____\\__  |   |  |         \\__    ___/\\_   _____/\\_   ___ \\ /   |   \\ \n");
    printf("_/ ___\\|  |  \\_/ __ \\ /    \\/   |   |  |    ______ |    |    |    __)_ /    \\  \\//    ~    \\\n");
    printf("\\  \\___|   |  \\  ___/|   |  \\____   |  |__ /_____/ |    |    |        \\\\     \\___\\    |    /\n");
    printf(" \\___  |___|  /\\___  |___|  / ______|____/         |____|   /_______  / \\______  /\\___|_  / \n");
    printf("     \\/     \\/     \\/     \\/\\/                                      \\/         \\/       \\/  \n");
    printf("  _______________________________________________________________________________________\n");
}

void menu(char *dirPath) //affiche le menu
{ 

    int animalCount = countFiles(dirPath);
    Animal *animals = getEachAnimals(dirPath, animalCount);
    if (animals == NULL)
    {
        printf("Erreur lors de la récupération des animaux.\n");
        return;
    }

    while (1) //boucle infini
    {
        clear_screen();
        printLogo();
        printf("Animaux:\n");
        printAnimalsShorted(animals, animalCount);

        printf("Choisissez une option:\n");
        printf("1. Afficher les animaux en détaille\n");
        printf("2. Ajouter un animal\n");
        printf("3. Supprimer un animal\n");
        printf("4. Rechercher un animal\n");
        printf("5. Temps de nettoyage par semaine\n");
        printf("6. Afficher les animaux triés par âge\n");
        printf("7. Quitter\n");
        printf("Choix: ");
        
        int choice;
        scanf("%d", &choice);
        fgetc(stdin); //vide le buffer (/n)

        switch (choice)
        {
            case 1:
                clear_screen();
                printAnimals(animals, animalCount);
                break;
            case 2:
                clear_screen();
                printAnimalsShorted(animals, animalCount);

                if (animalCount >= 50)
                {
                    printf("Le nombre maximum d'animaux a été atteint.\n");
                    break;
                }

                animalCount = addAnimal(dirPath, &animals, animalCount);  
                break;
            case 3:
                clear_screen();
                printAnimalsShorted(animals, animalCount);
                if (animalCount == 0)
                {
                    printf("Aucun animal à supprimer.\n");
                    break;
                }
                animalCount = removeAnimal(dirPath, &animals, animalCount);  
                break;
            case 4:
                clear_screen();
                printf("Comment voulez-vous rechercher l'animal?\n");
                printf("1. Par nom\n");
                printf("2. Par espèce\n");
                printf("3. Par type d'âge (<= 2 ans, ou sénior >= 10 ans)\n");
                printf("Autre chose: Quitter\n");

                int searchChoice;
                scanf("%d", &searchChoice);

                if (searchChoice == 1)
                {
                    char name[256];
                    printf("Entrez le nom de l'animal: ");
                    scanf("%s", name);
                    strlwr(name);
                    int resultCount;
                    Animal *result = searchByName(animals, animalCount, &resultCount, name);
                    if (result == NULL)
                    {
                        printf("Aucun animal trouvé avec ce nom.\n");
                        getchar(); //attendre une touche
                        break;
                    }
                    printAnimals(result, resultCount);
                    free(result);
                    getchar(); 
                }
                else if (searchChoice == 2)
                {
                    printf("Choississez l'espèce:\n");
                    printf("1. Chien\n");
                    printf("2. Chat\n");
                    printf("3. Hamster\n");
                    printf("4. Autruche\n");
                    int speciesChoice;
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
                            getchar(); 
                            break;
                    }
                    
                    int resultCount;
                    Animal *result = searchBySpecies(animals, animalCount, &resultCount, species);
                    if (result == NULL)
                    {
                        printf("Aucun animal de cette espèce.\n");
                        getchar();
                        break;
                    }
                    printAnimals(result, resultCount);  
                    free(result); 
                    getchar(); 
                }
                else if (searchChoice == 3)
                {
                    int ageType;
                    printf("Choisissez le type d'âge:\n");
                    printf("1. Jeune (<= 2 ans)\n");
                    printf("2. Senior (>= 10 ans)\n");
                    scanf("%d", &ageType);

                    if (ageType == 1 || ageType == 2)
                    {
                        int resultCount;
                        Animal *result = searchByAge(animals, animalCount, &resultCount, ageType);
                        if (result == NULL)
                        {
                            printf("Aucun animal de ce type d'age.\n");
                            getchar(); 
                            break;
                        }
                        printAnimals(result, resultCount);
                        free(result); 
                        getchar(); 
                    }
                    else
                    {
                        printf("Choix invalide.\n");
                        getchar(); 
                    }

                }
                else
                {
                    printf("Choix invalide.\n");
                    getchar();
                }
                break;
            case 5:
                clear_screen();
                DAY_CLEAN(animals, animalCount);
                break;
            case 6:
                clear_screen();
                INV_AGE_ASC(animals, animalCount);
                break;
            case 7:
                clear_screen();
                exit(0);
            default:
                clear_screen();
                break;
        }
        printf("Appuyez sur Entrée pour continuer...\n");
        getchar(); 
    }


}
