# Projet TicTacToe

### Description

## organisation du code :

-src

         - demarage.cpp : Choix du mode de jeu (duo ou non) avec `mode_duo()`.
         Retourne `true` si oui, en demandant à l’utilisateur s’il souhaite jouer en duo (1) ou en solo (2).

         - player.cpp : Création de la structure joueur : demande du nom et du choix du signe.

         - plateau.cpp : À partir d’un tableau, affiche une grille de jeu avec la fonction `draw_game_board(tab)`.
         Chaque élément du tableau correspond au contenu d’une case de la grille (vide initialement).

         - fin_partie.cpp : Vérifie les 2 possibilités de fin de jeu en fonction de l’état de la grille passée en paramètre des fonctions
         (égalité → `grille_remplie()` OU victoire → `fin_partie_victoire()`) → RETURN TRUE SI FIN DE PARTIE.

         CAS VICTOIRE : on définit un tableau `TAB_VICTOIRE[8][3]` qui répertorie les 8 triplets des indices des cases gagnantes.
         Ex : (1,5,9) pour la diagonale droite. On vérifie, pour chaque triplet, si les cases associées dans notre grille ont le même symbole.
         Si oui → VICTOIRE.

         CAS ÉGALITÉ : la grille est remplie, sans victoire.

         - amelioration.cpp : Retourne un indice de case si une amélioration est possible, sinon -1.
         Parcourt le tableau `TAB_VICTOIRE[8][3]`. Si 2 cases parmi le triplet ont le même symbole → une amélioration est possible → renvoie le 3e numéro du triplet, correspondant à la 3e case à compléter.

         - mode_jeu.cpp : Lance la partie (démarrage + jeu tour à tour en fonction du mode + vérification des conditions de fin de jeu à chaque boucle).

amélioration de l'ia : se fait automatiquement.

## difficultés rencontrées :

Gérer le cas d’égalité (grille remplie SANS victoire)

Problème avec le choix du mode de jeu : que doit retourner la fonction de choix ?

Empêcher les joueurs d’avoir le même symbole

Condition de victoire sans parcourir toute la grille et sans multiplier les boucles for.
Utilisation d’un tableau qui répertorie les combinaisons de victoire, utile ensuite pour l’amélioration

Coup de l’IA sans amélioration : générer un nombre aléatoire correspondant à une case libre, avec beaucoup de conditions à vérifier

Gérer les cas où l’utilisateur rentre n’importe quoi (pas un chiffre)

```

```
