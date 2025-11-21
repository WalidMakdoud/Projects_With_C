#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void initionalisation(char matrice[3][3]) {

        for(int i = 0; i < 3; i++) {

                for(int j = 0; j < 3; j++) {

                        matrice[i][j] = ' ';
                }
        }

}

void afficherMatrice(char matrice[3][3]) {

        printf("\n");
        printf("---+---+---\n");
        for(int i = 0; i < 3; i++) {

                printf(" %c | %c | %c \n", matrice[i][0], matrice[i][1], matrice[i][2]);

                printf("---+---+---\n");
        }


}

bool verificationDeMatrice(char matrice[3][3], char jeu) {

        for(int i = 0; i < 3; i++) {

                if((matrice[i][0] == jeu && matrice[i][1] == jeu && matrice[i][2] == jeu) || (matrice[0][i]) == jeu && matrice[1][i] == jeu && matrice[2][i] == jeu) {
                        return true;

                }
        }

        if((matrice[0][0] == jeu && matrice[1][1] == jeu && matrice[2][2] == jeu) || (matrice[0][2] == jeu && matrice[1][1] == jeu && matrice[2][0] == jeu)) {

                return true;
        }


        return false;


}

bool palinMatrice(char matrice[3][3]) {

        for(int i = 0; i < 3; i++) {

                for(int j = 0; j < 3; j++) {

                        if(matrice[i][j] == ' ') {

                                return false;
                        }
                }
        }

        return true;

}

int main() {

        char matrice[3][3];
        char rejouer;
        char jeu;
        int lines, colones;

        do{

                printf("==================================================== \n");
                printf("        BIENVENUE DANS LE JEU DU TIK TAC TOE         \n");
                printf("==================================================== \n");
                printf("Arriveras-tu à battre ton adversaire ?");
                printf("Le premier qui aligne 3 symboles gagne !\n");
                printf("Bonne chance, joueur !\n\n");
                initionalisation(matrice);
                char joueur = 'X';
                bool finPartie = false;

                while(!finPartie) {

                        afficherMatrice(matrice);

                        do{
                                printf("Joueur %c, entrez ligne (1-3) et colonne (1-3) : ", joueur);
                                scanf("%d %d", &lines, &colones);
                                lines--;
                                colones--;

                        }while(lines < 0 || lines > 2 || colones < 0 || colones > 2 || matrice[lines][colones] != ' ');

                        matrice[lines][colones] = joueur;

                        if(verificationDeMatrice(matrice, joueur)) {

                                printf("Félicitations! Joueur %c a gagné!\n", joueur);
                                finPartie = true;

                        }else if(palinMatrice(matrice)) {

                                printf("Match NIL!\n");
                                finPartie = true;

                        }else {

                                joueur = (joueur == 'X') ? 'O' : 'X';
                        }
                }

                afficherMatrice(matrice);

                printf("\n\n");

                printf("Voulez-vous rejouer ? Taper(o/n) : ");
                scanf(" %c", &rejouer);

        }while(rejouer == 'o' || rejouer == 'O');

        printf("\n\n");
        printf("Merci d'avoir joué ! À bientôt !\n");
        printf("==================================================== \n");





        return 0;
}
