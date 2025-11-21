#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int main() {

        srand(time(NULL));
        char liste[3][10] = {"pierre", "feuille", "ciseaux"};
        int partiesJouees = 0;
        int perdu = 0;
        int victoire = 0;
        int matchNull = 0;
        char rejouer;
        int choix;
        do{
                int indisePc = rand() % 3;
                printf("=============================================================== \n");
                printf("        BIENVENUE DANS LE JEU DU PIERRE FEUILLE CISEAUX         \n");
                printf("=============================================================== \n");
                printf("Choisissez votre coup (0 pour Pierre, 1 pour Feuille, 2 pour Ciseaux) : \n");
                printf("Arriveras-tu à gagner ?\n");
                printf("Ton destin est entre tes mains !\n\n.");
                printf("Bonne chance, joueur !\n\n");

                do{

                        printf("Taper votre choix ici : ");
                        scanf("%d", &choix);

                }while((choix < 0) || (choix > 2));

                if(choix == indisePc) {

                        printf("Le match est NULL.\n");
                        matchNull++;

                }else if((choix == 0 && indisePc == 2) || (choix == 1 && indisePc == 0) || (choix == 2) && indisePc == 1) {

                        printf("Félicitations, tu as gagné !\n");
                        victoire++;

                }else {

                         printf("Vous avez perdu. \n");
                         printf("Dommage, essaie encore !\n");
                         perdu++;

                }

                partiesJouees++;

                printf("\n\n");

                printf("Statistiques Parties jouées : %d, Les Match Perdu : %d ,Les Matchs NULL :  %d,Victoires : %d\n", partiesJouees, perdu,matchNull, victoire);

                printf("\n\n");

                printf("Voulez-vous rejouer ? Taper(o/n) : ");
                scanf(" %c", &rejouer);

        }while((rejouer == 'o') || (rejouer == 'O'));

        printf("\n\n");
        printf("Merci d'avoir joué ! À bientôt !\n");
        printf("=============================================================== \n");


        return 0;

}
