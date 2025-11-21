#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int main () {

        srand(time(NULL));
        char rejouer;
        int partiesJouees = 0;
        int victoire = 0;
        int perdu = 0;
        do {
                bool trouveMot = false;
                bool trouveCaractaire;
                int i = 0;
                int j;
                int chanse = 7;
                int indiceMot = 1 +rand() % 20;
                FILE *F;
                char MotSecret[50];
                char Reponse;
                F = fopen("mot.txt", "r");
                if(F == NULL) {

                        printf("Error, dans la lecture de fichier. \n");
                        exit(1);
                }

                printf("======================================================= \n");
                printf("        BIENVENUE DANS LE JEU DU PENDU                  \n");
                printf("======================================================= \n");
                printf("Un mot mystère a été choisi............................ \n");
                printf("Arriveras-tu à le deviner lettre par lettre ?\n");
                printf("Attention : chaque erreur te rapproche de la potence ! Vous avez 7 tentatives.... \n");
                printf("Bonne chance, joueur !\n\n");

                while(fscanf(F, "%s", MotSecret) != EOF && i != indiceMot) {

                        i++;
                }

                fclose(F);
                int n = strlen(MotSecret);
                char temp[n + 1];
                for(j = 0; j < n; j++) {

                        temp[j] = '_';
                }

                //Pour ne pas afficher �� dans la fin du chaîne
                temp[n] = '\0';


                while(chanse > 0 && trouveMot == false) {

                        printf("Vous avez %d Chanse(s). \n", chanse);
                        printf("\n");
                        printf("********** Le Progrès : %s. **********\n", temp);
                        printf("\n");

                        printf("Taper une caractère : ");
                        scanf(" %c", &Reponse);
                        trouveCaractaire = false;
                        j = 0;
                        while(j < n) {

                                if(MotSecret[j] == Reponse) {

                                        if(!trouveCaractaire) {
                                                printf("Bravo ! La lettre '%c' est dans le mot.\n\n", Reponse);
                                        }
                                        temp[j] = Reponse;
                                        trouveCaractaire = true;

                                }
                                j++;
                        }

                        if(trouveCaractaire == false) {

                                 printf("Dommage ! La lettre '%c' n'est pas dans le mot.\n", Reponse);
                                 chanse--;
                        }


                        if(strcmp(MotSecret, temp) == 0) {

                                victoire++;
                                trouveMot = true;
                                printf("\nFélicitations ! Vous avez trouvé le mot : %s\n", MotSecret);
                        }



                }
                if(trouveMot == false) {

                        perdu++;
                        printf("\nGame Over ! Vous n'avez pas trouvé le mot.\n");
                        printf("Le mot secret était : %s\n", MotSecret);
                }
                partiesJouees++;

                printf("\n\n");

                printf("Parties jouées : %d, Victoires : %d, Perdu : %d\n", partiesJouees, victoire, perdu);


                printf("\n\n");

                printf("Voulez-vous rejouer ? Taper(o/n) : ");
                scanf(" %c", &rejouer);



        }while(rejouer == 'o' || rejouer == 'O');


        printf("\n\n");
        printf("Merci d'avoir joué ! À bientôt !\n");
        printf("======================================================= \n");


        return 0;
}
