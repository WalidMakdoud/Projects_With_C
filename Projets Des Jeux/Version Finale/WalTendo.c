#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



void Jeu_Du_Pendu() {

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


}



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


void Tik_Tac_Toe() {

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


}




void Pierre_Feuille_Ciseaux() {

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

                        printf("Le match est NIL.\n");
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




}




void Jeu_Du_Nombre_Mystere() {

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


}




void menu1() {

        int choix;
        while(true) {
                printf("\n\n");
                printf("|===============================================================================|\n");
                printf("|                               **WALTENDO**                                    |\n");
                printf("|===============================================================================|\n");
                printf("|1-Jeu Du Nombre Mystere                                                        |\n");
                printf("|2-Jeu Du Pierre Feuille Ciseaux                                                |\n");
                printf("|3-Jeu Du Tic Tac Toe                                                           |\n");
                printf("|4-Jeu Du Pendu                                                                 |\n");
                printf("|0-Quiter                                                                       |\n");
                printf("|===============================================================================|\n");
                printf("\n");
                do{
                        printf("Taper votre choix ici : ");
                        scanf("%d", &choix);

                }while(choix < 0 || choix > 4);


                switch(choix) {

                        case 0:
                                printf("\n\n");
                                printf("|Merci d'avoir joué ! À bientôt !                                              |\n");
                                printf("|===============================================================================|\n");
                                exit(1);
                                break;
                        case 1 : Jeu_Du_Nombre_Mystere(); break;
                        case 2 : Pierre_Feuille_Ciseaux(); break;
                        case 3 : Tik_Tac_Toe(); break;
                        case 4 : Jeu_Du_Pendu(); break;
                        default : printf("SVP! choisi un nombre entre 0 et 3. \n");
                }
        }
}




int main() {


        srand(time(NULL));
        menu1();


        return 0;
}
