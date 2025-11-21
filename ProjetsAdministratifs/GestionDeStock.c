#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Produit{

	char nomProduit[30];
	char categorie[20];
	int code;
	float prix;

}Produit;


bool codeExiste(int code) {

	FILE *F;
	Produit P;
	bool exist = false;
	F = fopen("Stock.txt", "r");

	if(F == NULL) {
	
		printf("Error, dans la lecture de fichier. \n");
		exit(1);

	}
	
	while((fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) && exist == false) {
	
		if(P.code == code) {
		
			exist = true; 
		}
	}

	fclose(F);
	return exist;

} 

void ajouterProduit() {

	char nomProduit[30];
	char categorie[20];
	int code;
	float prix;
	FILE *F;

	F = fopen("Stock.txt", "a");

	if(F == NULL) {
	
		printf("Error, dans la ouverture de fichier. \n");
		exit(1);

	}

	printf("Taper le nom de produit : ");
	scanf("%s", nomProduit);
	printf("Taper la categorie du produit : ");
	scanf("%s", categorie);

	do {
	
		printf("Taper le code du produit : ");
		scanf("%d", &code);

	}while((codeExiste(code) == true) || (code < 0));

	do {

		printf("Taper le prix du produit : ");
		scanf("%f", &prix);

	}while(prix <= 0);


	fprintf(F, "%s %s %d %f\n", nomProduit, categorie, code, prix);
	
	fclose(F);

}


void modifierNomProduit() {


	int code;
	FILE *F;
	FILE *temp;
	char newNom[30];
	Produit P;

	F = fopen("Stock.txt", "r");
	temp = fopen("temp.txt", "w");

	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}

	if(temp == NULL) {
	
		printf("Error, dans la creation du fichier. \n");
		exit(1);

	}

	printf("Taper le code du produit : ");
        scanf("%d", &code);

	
	printf("Taper le nouveux nom du produit : ");
	scanf("%s", newNom);

	if(codeExiste(code)) {
		while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {
		
			if(P.code == code) {
				
				strcpy(P.nomProduit, newNom);
			
			}	
		
			fprintf(temp, "%s %s %d %f\n", P.nomProduit, P.categorie, P.code, P.prix);
		}
	
		fclose(F);
		fclose(temp);

		remove("Stock.txt");
		rename("temp.txt", "Stock.txt");
	
	}else {

		printf("Il n'existe pas un produit avec ce Code. \n");
		remove("temp.txt");
	}
}

void modifierCategorieProduit() {

	int code;
	FILE *F;
	FILE *temp;
	char newCategorie[20];
	Produit P;

	F = fopen("Stock.txt", "r");
	temp = fopen("temp.txt", "w");

	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}

	if(temp == NULL) {
	
		printf("Error, dans la creation du fichier. \n");
		exit(1);

	}

	printf("Taper le code du produit : ");
        scanf("%d", &code);

	if(codeExiste(code)) {
	
		printf("Taper le nouvelle categorie du produit : ");
		scanf("%s", newCategorie);

		while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {
		
			if(P.code == code) {
				
				strcpy(P.categorie, newCategorie);
			}	
		
			fprintf(temp, "%s %s %d %f\n", P.nomProduit, P.categorie, P.code, P.prix);
		}
		
		fclose(F);
		fclose(temp);

		remove("Stock.txt");
		rename("temp.txt", "Stock.txt");

	
	}else {
	
		printf("Il n'existe pas un produit avec ce Code. \n");
		
		fclose(F);
		fclose(temp);
		
		remove("temp.txt");

	}


}

void modifierPrixProduit() {

	int code;
	FILE *F;
	FILE *temp;
	float newPrix;
	Produit P;

	F = fopen("Stock.txt", "r");
	temp = fopen("temp.txt", "w");

	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}

	if(temp == NULL) {
	
		printf("Error, dans la creation du fichier. \n");
		exit(1);

	}

	printf("Taper le code du produit : ");
	scanf("%d", &code);

	if(codeExiste(code)) {
		
		do {

			printf("Taper le nouveux prix du produit : ");
			scanf("%f", &newPrix);

		}while(newPrix <= 0);


		while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {
		
			if(P.code == code) {
				
				P.prix = newPrix;
			}	
		
			fprintf(temp, "%s %s %d %f\n", P.nomProduit, P.categorie, P.code, P.prix);
		}
		
		fclose(F);
		fclose(temp);

		remove("Stock.txt");
		rename("temp.txt", "Stock.txt");
	

	}else {
	
		printf("Il n'existe pas un produit avec ce Code. \n");
		
		fclose(F);
		fclose(temp);

		remove("temp.txt");
	}

	
}

void chercheCodeProduit() {


	int code;
	Produit P;
	FILE *F;
	bool trouve = false;

	F = fopen("Stock.txt", "r");

	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}
	
	printf("Taper le code du produit : ");
	scanf("%d", &code);
	
	
	while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF && trouve == false) {
		
		if(P.code == code) {
			
			printf("Le code : %d.  |  Le nom : %s.  |  La categorie : %s.  |  Le prix : %f. \n", P.code, P.nomProduit, P.categorie, P.prix);
			trouve = true;

		}
	}

	if(!trouve) {
	
		printf("Il n'existe pas un produit avec ce code. \n");
	}


	fclose(F);



}

void supprimerProduit() {

	int code;
	FILE *F;
	FILE *temp;
	Produit P;

	F = fopen("Stock.txt", "r");
	
	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}

	temp = fopen("temp.txt", "w");

	if(temp == NULL) {
	
		printf("Error, dans la creation du fichier. \n");
		exit(1);
	}

	printf("Taper le code du produit : ");
	scanf("%d", &code);

	if(codeExiste(code)) {
		while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {
		
			if(P.code != code) {
			
				fprintf(temp, "%s %s %d %f\n", P.nomProduit, P.categorie, P.code, P.prix);
			

			}
		}

		fclose(F);
		fclose(temp);

	
		remove("Stock.txt");
		rename("temp.txt", "Stock.txt");

	}else {
	
		printf("Il n'existe pas un produit avec ce code. \n");

		fclose(F);
		fclose(temp);

		remove("temp.txt");
	}

}

void afficherStock() {
    FILE *F;
    Produit P;

    F = fopen("Stock.txt", "r");
    if(F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n"); // Corrected French
        exit(1);
    }

    	// Le format "%-10s" dans printf signifie :
	// %  est le début du format
	// -    c'est aligne le texte à gauche , Sans "-", le texte serait aligné à droite
	// 10  : largeur minimale du champ : le texte occupera au moins 10 caractères 
	//S'il est plus court, des espaces sont ajoutés pour remplir la largeur
	// s est le type du contenu : ici, une chaîne de caractères


    printf("|================================================================================================================|\n");
    printf("| %-10s | %-30s | %-20s | %-10s |\n", "Code", "Nom du Produit", "Categorie", "Prix");
    printf("|================================================================================================================|\n");


    while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {

	printf("| %-10d | %-30s | %-20s | %-10.2f |\n", P.code, P.nomProduit, P.categorie, P.prix);
    }

    printf("|================================================================================================================|\n");


    fclose(F);

}

void afficherProduitCategorie() {


	FILE *F;
	Produit P;
	char categorieT[20];
	bool trouve = false;

	F = fopen("Stock.txt", "r");

	if(F == NULL) {
	
		printf("Error, dans l'ouverture du fichier. \n");
		exit(1);

	}

	printf("Taper la categorie : ");
	scanf("%s", categorieT);


	printf("\n================= Produits de la catégorie : %s =================\n\n", categorieT);
	printf("|================================================================================================================|\n");
	printf("| %-10s | %-30s | %-20s | %-10s |\n", "Code", "Nom du Produit", "Categorie", "Prix");
	printf("|================================================================================================================|\n");

	while(fscanf(F, "%s %s %d %f", P.nomProduit, P.categorie, &P.code, &P.prix) != EOF) {
		
		if(strcmp(P.categorie, categorieT) == 0) {
			
			printf("| %-10d | %-30s | %-20s | %-10.2f |\n", P.code, P.nomProduit, P.categorie, P.prix);
			trouve = true;		
		}
		
	}	

	printf("|================================================================================================================|\n");

	fclose(F);
	if(!trouve) {
	
		printf("Il n'existe pas des produits sous cette categorie. \n");
	}


}

void menu() {

	int choix;
	int choixModifier;
	do{
	
		system("clear"); //clear pour Linux Ou cls pour Windows

		printf("===========================================================\n");
        	printf("       Bonjour au Gestion du Stock de Produits\n");
        	printf("===========================================================\n\n");

        	printf("Veuillez choisir une option :\n\n");
        	printf("1. Afficher tout le stock\n");
        	printf("2. Afficher les produits par catégorie\n");
        	printf("3. Ajouter un produit\n");
        	printf("4. Supprimer un produit\n");
        	printf("5. Modifier un produit\n");
        	printf("6. Rechercher un produit par son code\n");
        	printf("0. Quitter\n\n");

		do {
			printf("Taper votre choix : ");
			scanf("%d", &choix);
		
		}while((choix < 0) || (choix > 6));

		switch(choix) {
		
			case 1 : afficherStock(); break;
			case 2 : afficherProduitCategorie(); break;
			case 3 : ajouterProduit(); break;
			case 4 : supprimerProduit(); break;
			case 5 : 

				 do {
				 
					 printf("1. Pour modifier le nom du produit\n");
					 printf("2. Pour modifier la categorie d'un produit\n");
					 printf("3. Pour modifier le prix du produit\n");
					 printf("0. pour revenir en arraire\n");

					 printf("Taper votre choix ici : ");
					 scanf("%d", &choixModifier);

				 }while((choixModifier < 0) || (choixModifier > 3));

				 if(choixModifier == 1)
					 modifierNomProduit();
				 else if(choixModifier == 2)
					 modifierCategorieProduit();
				 else if(choixModifier == 3)
					 modifierPrixProduit();
				 break;

			case 6 : chercheCodeProduit(); break;
			case 0 : 
				 printf("Au revoir !\n");
				 break;

			default:
				 printf("\nChoix invalide. Veuillez réessayer.\n");
		
		}

		if(choix != 0) {
			
			printf("Appuyez sur une touche pour revenir au menu......");
			getchar(); // pour consommer le '\n' laissé par scanf
			getchar(); // attendre que l'utilisateur appuie sur entree
		}
	
	}while(choix != 0);

	



}

int main() {



	menu();


	return 0;

}
