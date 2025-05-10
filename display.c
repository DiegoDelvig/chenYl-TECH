#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "utils.h"
#include "search.h"
#include "variantes.h"


void menu(char *dirPath)
{ 
    int animalCount = countFiles(dirPath);
    Animal *animals = getEachAnimals(dirPath, animalCount);
    if (animals == NULL)
    {
        printf("Erreur lors de la récupération des animaux.\n");
        return;
    }

    while (1)
    {
        clear_screen();

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
        printf("Choisissez une option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                clear_screen();
                printAnimals(animals, animalCount);
                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche
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

                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche
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
                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche   
                break;
            case 4:
                clear_screen();
                printf("Comment voulez-vous rechercher l'animal?\n");
                printf("1. Par nom\n");
                printf("2. Par espèce\n");
                printf("3. Par type d'âge (<= 2 ans, ou sénior >= 10 ans)\n");

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
                        break;
                    }
                    printAnimals(result, resultCount);
                    free(result); // Libérer la mémoire allouée pour le résultat
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
                            break;
                    }
                    
                    int resultCount;
                    Animal *result = searchBySpecies(animals, animalCount, &resultCount, species);
                    if (result == NULL)
                    {
                        printf("Aucun animal trouvé avec ce nom.\n");
                        break;
                    }
                    printAnimals(result, resultCount);  
                    free(result); // Libérer la mémoire allouée pour le résultat

                }
                else if (searchChoice == 3)
                {
                    int ageType;
                    printf("Choisissez le type d'âge:\n");
                    printf("1. Jeune (<= 2 ans)\n");
                    printf("2. Senior (>= 10 ans)\n");
                    scanf("%d", &ageType);

                    if (ageType != 1 && ageType != 2)
                    {
                        printf("Choix invalide.\n");
                        break;
                    }
                    int resultCount;
                    Animal *result = searchByAge(animals, animalCount, &resultCount, ageType);
                    if (result == NULL)
                    {
                        printf("Aucun animal trouvé avec ce nom.\n");
                        break;
                    }
                    printAnimals(result, resultCount);
                    free(result); // Libérer la mémoire allouée pour le résultat
                }
                else
                {
                    printf("Choix invalide.\n");
                }
                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche
                break;
            case 5:
                clear_screen();
                DAY_CLEAN(animals, animalCount);
                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche
                break;
            case 6:
                clear_screen();
                INV_AGE_ASC(animals, animalCount);
                printf("Appuyez sur Entrée pour continuer...\n");
                getchar(); // Pour consommer le '\n' restant dans le buffer
                getchar(); // Attendre une touche
                break;
            case 7:
                clear_screen();
                exit(0);
            default:
                clear_screen();
                break;
        }
    }


}