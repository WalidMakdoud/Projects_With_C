#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Produit{
    char Nom[50];
    char Categorie[50];
    int Code;
    int Prix;

}Produit;

bool CodeExiste(int Code) {
    Produit P;
    FILE *F;
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }

    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {
        if(Code == P.Code) {
            fclose(F);
            return true;
        }
    }
    fclose(F);
    return false;

}



void ajouter(char NomDeProduit[50], char CategorieDeProduit[50], int CodeDeProduit, int PrixDeProduit) {

    FILE *F;
    F = fopen("Stock.txt", "a");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    fprintf(F, "%s %s %i %i \n", NomDeProduit, CategorieDeProduit, CodeDeProduit, PrixDeProduit);
    fclose(F);

}


void ModifierNome(int Code) {

    Produit P;
    char nom[50];
    bool b = false;
    FILE *F;
    FILE *temp;
    temp = fopen("temp.txt", "w");
    F = fopen("Stock.txt", "r");
    if(temp == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    printf("Taper le nouveau nom de produit : ");
    scanf("%s", nom);
    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {


        if(P.Code == Code) {
            strcpy(P.Nom, nom);
            b = true;
        }
        fprintf(temp, "%s %s %i %i \n", P.Nom, P.Categorie, P.Code, P.Prix);



    }
    fclose(temp);
    fclose(F);
    if(b == false) {
            printf("Il y a pas de produit avec ce Code. \n");
            remove("temp.txt");
    }else {
        remove("Stock.txt");
        rename("temp.txt", "Stock.txt");
        printf("Le produit a ete modifier \n");
    }


}


void ModifierCat(int Code) {

    Produit P;
    char cat[50];
    bool b = false;
    FILE *F;
    FILE *temp;
    temp = fopen("temp.txt", "w");
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    if(temp == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    printf("Taper la nouvelle categorie de produit : ");
    scanf("%s", cat);
    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {


        if(P.Code == Code) {
            strcpy(P.Categorie, cat);
            b = true;
        }
        fprintf(temp, "%s %s %i %i \n", P.Nom, P.Categorie, P.Code, P.Prix);



    }
    fclose(temp);
    fclose(F);
    if(b == false) {
            printf("Il y a pas de produit avec ce Code. \n");
            remove("temp.txt");
    }else {
        remove("Stock.txt");
        rename("temp.txt", "Stock.txt");
        printf("Le produit a ete modifier \n");
    }


}


void ModifierPri(int Code) {

    Produit P;
    int Pri;
    bool b = false;
    FILE *F;
    FILE *temp;
    temp = fopen("temp.txt", "w");
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    if(temp == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    printf("Taper le nouveau prix de produit : ");
    scanf("%i", &Pri);
    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {


        if(P.Code == Code) {
            P.Prix = Pri;
            b = true;
        }
        fprintf(temp, "%s %s %i %i \n", P.Nom, P.Categorie, P.Code, P.Prix);



    }
    fclose(temp);
    fclose(F);
    if(b == false) {
            printf("Il y a pas de produit avec ce Code. \n");
            remove("temp.txt");
    }else {
        remove("Stock.txt");
        rename("temp.txt", "Stock.txt");
        printf("Le produit a ete modifier \n");
    }


}



void Supprimer(int Code) {
    Produit P;
    bool b = false;
    FILE *F;
    FILE *temp;
    F = fopen("Stock.txt", "r");
    temp = fopen("temp.txt", "w");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }

    if(temp == NULL) {
        printf("Error dans la ouvriture de Ficheier \n");
        exit(1);
    }
    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {
        if(P.Code == Code) {
             b = true;
        }else{
            fprintf(temp, "%s %s %i %i \n", P.Nom, P.Categorie, P.Code, P.Prix);
        }
    }


    fclose(temp);
    fclose(F);
    if(b == false) {
        printf("Il y a pas de prouit avec ce Code. \n");
        remove("temp.txt");
    }else {
        remove("Stock.txt");
        rename("temp.txt", "Stock.txt");
        printf("Le produit a ete supprimer \n");
    }


}

void ChercherParCode(int Code) {

	FILE *F;
	bool b = false;
	Produit P;

	F = fopen("Stock.txt", "r");
	if(F == NULL) {
        	printf("Error dans la ouvriture de Ficheier \n");
        	exit(1);
	}

	while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {
		if(P.Code == Code) {
			printf("Le Code : %d.  |   Le nom : %s.  |   La categorie : %s.  |   Le prix : %d.  \n", P.Code, P.Nom, P.Categorie, P.Prix);
			b = true;
		}
	}
	fclose(F);


	if(b == false) {

		printf("Il n'existe pas une produit avec ce code. \n");
	}


}


void AfficherStock() {
    Produit P;
    FILE *F;
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier. \n");
        exit(1);
    }


    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {

        printf("Le Code : %d.   |   Le nom : %s.   |   La categorie : %s.   |   Le prix : %d.   \n", P.Code, P.Nom, P.Categorie, P.Prix);
    }
    fclose(F);


}



void AfficherCatDePro(char CatP[50]) {
    Produit P;
    bool b = false;
    FILE *F;
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier. \n");
        exit(1);
    }

    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {
        if(strcmp(P.Categorie, CatP) == 0) {
            printf("Le Code : %d.   |   Le nom : %s.   |   La categorie : %s.   |   Le prix : %d.  \n", P.Code, P.Nom, P.Categorie, P.Prix);
            b = true;
        }
    }
    fclose(F);
    if(b == false) {
        printf("Il n'existe pas un produit dans cette categorie. \n");
    }

}


int QunatDeProduit(char Nom[50]) {
    Produit P;
    int cpt = 0;
    FILE *F;
    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Error dans la ouvriture de Ficheier. \n");
        exit(1);
    }

    while(fscanf(F, "%s %s %i %i", P.Nom, P.Categorie, &P.Code, &P.Prix) != EOF) {
        if(strcmp(Nom, P.Nom) == 0) {
            cpt++;
        }
    }

    fclose(F);
    return cpt;


}


int main () {
    FILE *F;
    F = fopen("Stock.txt", "a");
    if(F == NULL) {
	printf("Error dans la ouvriture de Ficheier \n");
        exit(1);

    }
    fclose(F);
    Produit P;
    int choix, choix2;



    while(true) {
        printf("************************************************************************************************************************\n");
        printf("Taper \"0\" pour quiter. \n");
        printf("Taper \"1\" pour ajouter un produit. \n");
        printf("Taper \"2\" pour modifier un produit. \n");
        printf("Taper \"3\" pour supprimer un produit. \n");
        printf("Taper \"4\" pour chercher un produit par son code. \n");
        printf("Taper \"5\" pour afficher le stock. \n");
        printf("Taper \"6\" pour afficher tous les produit d'une categorie. \n");
        printf("Taper \"7\" pour afficher la quantité d'un produit. \n");
        printf("************************************************************************************************************************\n");
        printf("Taper votre choix ici : ");
        scanf("%i", &choix);
        if(choix == 0) {
             printf("Merci d'avoir utilisé le programme. À bientôt !\n");
             break;
        }else if(choix == 1) {
            printf("Taper le nom de produit : ");
            scanf("%s", P.Nom);
            printf("Taper la categorie  de produit (alimentaire, électronique, textile, etc.) : ");
            scanf("%s", P.Categorie);
            do {
                printf("Taper le Code de produit : ");
            	scanf("%i", &P.Code);
            }while(CodeExiste(P.Code) == true);
            printf("Taper le prix de produit : ");
            scanf("%i", &P.Prix);
            ajouter(P.Nom, P.Categorie, P.Code, P.Prix);
        }else if(choix == 2) {
            printf("Taper le Code de produit : ");
            scanf("%i", &P.Code);

            printf("Pour modifier le nom de produit taper \"1\" et la categorie \"2\" ,  pour Le prix \"3\" et \"4\" pour quiter :  ");
            scanf("%i", &choix2);

            if(choix2 == 1) {

                ModifierNome(P.Code);
            }else if(choix2 == 2) {
                ModifierCat(P.Code);
            }else if(choix2 == 3) {
                ModifierPri(P.Code);
            }else if(choix2 == 4) {
	    	exit(1);

	    }else {

		printf("Taper un numero entre \"1\" et \"4\". \n");

            }
        }else if(choix == 3) {

            printf("Taper le code de produit : ");
            scanf("%i", &P.Code);
            Supprimer(P.Code);


        }else if(choix == 4) {
            printf("Taper le code ici : ");
	    scanf("%i", &P.Code);
	    ChercherParCode(P.Code);
        }else if(choix == 5) {

            AfficherStock();

        }else if(choix == 6) {
            printf("Taper le nom de la categorie : ");
            scanf("%s", P.Categorie);
            AfficherCatDePro(P.Categorie);

        }else if(choix == 7) {
            printf("Taper le nom de produit : ");
            scanf("%s", P.Nom);
            printf("La quantité de produit \"%s\" est : %d \n", P.Nom, QunatDeProduit(P.Nom));


        }else {
            printf("Svp choisis un nombre entre 0 et 7. \n");
        }




    }



	return 0;

}
