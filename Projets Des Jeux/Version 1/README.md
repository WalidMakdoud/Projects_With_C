# Jeux en C – Version 1 (V1)

Ce dossier contient les versions initiales de chaque mini-jeu.
Chaque section ci-dessous décrit exactement comment la partie se déroule lorsque le joueur lance le jeu.

## 🔢 Jeu du Nombre Mystère

*****1.***** Le programme génère un nombre aléatoire entre 1 et 10.

*****2.***** Le joueur doit entrer un nombre.

*****3.***** Le programme compare la réponse du joueur avec le nombre mystère.

*****4.***** Il affiche une indication :

&nbsp;&nbsp;&nbsp;&nbsp; « Trop petit » si le nombre entré est inférieur.

&nbsp;&nbsp;&nbsp;&nbsp; « Trop grand » si le nombre entré est supérieur.

*****5.***** Le joueur recommence tant qu’il lui reste des essais.

*****6.***** La partie se termine :

&nbsp;&nbsp;&nbsp;&nbsp; Victoire → si le joueur trouve le bon nombre.

&nbsp;&nbsp;&nbsp;&nbsp; Défaite → si toutes les chances sont utilisées.

*****7.***** Le programme affiche le résultat final.

## ✊📄✂️ Pierre – Feuille – Ciseaux

*****1.***** Le jeu affiche les choix possibles :

&nbsp;&nbsp;&nbsp;&nbsp; 0 = Pierre

&nbsp;&nbsp;&nbsp;&nbsp; 1 = Feuille

&nbsp;&nbsp;&nbsp;&nbsp; 2 = Ciseaux

*****2.***** Le joueur entre son choix.

*****3.***** L’ordinateur choisit au hasard entre les 3 options.

*****4.***** Le programme compare les choix :

&nbsp;&nbsp;&nbsp;&nbsp; Pierre bat Ciseaux

&nbsp;&nbsp;&nbsp;&nbsp; Ciseaux bat Feuille

&nbsp;&nbsp;&nbsp;&nbsp; Feuille bat Pierre

*****5.***** Plusieurs cas possibles :

&nbsp;&nbsp;&nbsp;&nbsp; Même choix → match nul

&nbsp;&nbsp;&nbsp;&nbsp; Règle gagnante → victoire du joueur

&nbsp;&nbsp;&nbsp;&nbsp; Sinon → défaite

*****5.***** Le résultat est affiché immédiatement.


## ❌⭕ Tic Tac Toe

*****1.***** Une Matrice 3×3 vide est affichée.

*****2.***** Le jeu commence avec le joueur X.

*****3.***** Le joueur saisit :

&nbsp;&nbsp;&nbsp;&nbsp; un numéro de ligne (1 à 3)

&nbsp;&nbsp;&nbsp;&nbsp; un numéro de colonne (1 à 3)

*****4.***** Le programme vérifie :

&nbsp;&nbsp;&nbsp;&nbsp; si les valeurs sont dans les limites

&nbsp;&nbsp;&nbsp;&nbsp; si la case est libre

*****5.***** Si tout est correct :

&nbsp;&nbsp;&nbsp;&nbsp; la case est remplie par X ou O

*****6.***** Le programme vérifie :

&nbsp;&nbsp;&nbsp;&nbsp; si une ligne complète appartient au joueur

&nbsp;&nbsp;&nbsp;&nbsp; si une colonne complète appartient au joueur

&nbsp;&nbsp;&nbsp;&nbsp; si une diagonale complète appartient au joueur

*****7.***** Si aucune victoire :

&nbsp;&nbsp;&nbsp;&nbsp; le tour passe au deuxième joueur (O ou X)

*****8.***** La partie continue jusqu’à :

&nbsp;&nbsp;&nbsp;&nbsp; Victoire → 3 symboles alignés

&nbsp;&nbsp;&nbsp;&nbsp; Match nul → toutes les cases sont remplies

*****9.***** Le résultat est affiché.

## 🔤 Jeu du Pendu

*****1.***** Le programme choisit un mot dans mot.txt.

*****2.***** Il remplace chaque lettre par un _ pour cacher le mot.

*****3.***** Le joueur propose une lettre.

*****4.***** Le programme vérifie si la lettre existe dans le mot.

*****5.***** Deux possibilités :

&nbsp;&nbsp;&nbsp;&nbsp; Lettre trouvée → elle apparaît dans le mot affiché

&nbsp;&nbsp;&nbsp;&nbsp; Lettre absente → le joueur perd une tentative

*****6.***** Le joueur recommence tant que :

&nbsp;&nbsp;&nbsp;&nbsp; il n’a pas trouvé toutes les lettres

&nbsp;&nbsp;&nbsp;&nbsp; il n’a pas utilisé toutes ses tentatives

*****7.***** La partie se termine :

&nbsp;&nbsp;&nbsp;&nbsp; Victoire → le mot est totalement révélé

&nbsp;&nbsp;&nbsp;&nbsp; Défaite → plus de tentatives, le mot s’affiche en clair

# ▶️ Compilation & Exécution
Compiler :
```c
gcc Nom_Du_Jeu.c -o jeu
```

Exécuter :
```c
./jeu
```
# 👨‍💻 Auteur
******WALID MAKDOUD******
