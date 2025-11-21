#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

        char rejouer;
        int partiesJouees = 0;
        int victoire = 0;
        srand(time(NULL));

        do{
                int choix;
                int chances = 3;
                int nombreMystere = 1 + rand() % 10;

                printf("======================================================= \n");
                printf("        BIENVENUE DANS LE JEU DU NOMBRE MYSTÈRE         \n");
                printf("======================================================= \n");
                printf("Un nombre entre 1 et 10 a été généré............. \n");
                printf("Arriveras-tu à le deviner ? \n");
                printf("Tu as 3 chances pour deviner le nombre.\n");
                printf("Bonne chance, joueur !\n\n");


                while(chances > 0) {

                        do {
                                printf("Taper votre choix : ");
                                scanf("%d", &choix);

                        }while((choix <= 0) || (choix > 10));

                        if(choix == nombreMystere) {

                                printf("Bravo ! Vous avez gagné !\n");
                                break;

                        }else if(choix > nombreMystere) {

                                printf("Trop grand ! Essayez un nombre plus petit.\n");

                        }else {

                                printf("Trop petit ! Essayez un nombre plus grand.\n");

                        }

                        chances--;
                        printf("Il vous reste %d chance(s).\n", chances);

                }

                printf("\n\n");

                partiesJouees++;
                if(chances == 0) {

                        printf("Désolé, vous avez perdu !\n");
                        printf("Le nombre mystère était %d.\n", nombreMystere);

                }else {

                        victoire++;

                }

                printf("\n\n");

                printf("Parties jouées : %d, Victoires : %d\n", partiesJouees, victoire);

                printf("\n\n");

                printf("Voulez-vous rejouer ? Taper(o/n) : ");
                scanf(" %c", &rejouer);

        }while((rejouer == 'o') || (rejouer == 'O'));

        printf("\n\n");
        printf("Merci d'avoir joué ! À bientôt !\n");
        printf("======================================================= \n");


        return 0;

}
