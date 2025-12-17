# Projet TicTacToe

## Description

## organisation du code :

```
-src
        - demarage.cpp : Choix mode duo ou pas ? avec mode_duo(). Return true si oui en demandant à l'utilsateur si il souhaite jouer duo (1) ou solo (2).

        - player.cpp : création structure joueur: demande du nom et du choix du signe

        - plateau.cpp : à partir d'un tableau ,affiche une grille de jeu avec fonction: draw_game_board(tab) . Chaque élement du tableau correspond au contenu de la case de le grille (vide initialement).

        - fin_partie.cpp : verifie les 2 possibilitées d'une fin de jeu en fonction de l'état de la grille mis en parametre des fonctions. (égalité--> grille_remplie() OU une victoire --> fin_partie_victoire())--> RETURN TRUE SI FIN PARTIE.
        CAS VICTOIRE : on définit un tabeau TAB_VICTOIRE[8][3] qui répertorit les 8 triplets des indices des cases gagnantes
        ex: (1,5,9) pour diagonale droite. On vérifie pr chaque triplet, si les cases associées dans notre grille ont le même symbole. Si oui --> VICTOIRE
        CAS EGALITE: la grille est remplie, sans victoire.

        - amélioration.cpp: retourne un indice de case si une amélioration est possible, sinon -1.
        Parcourt le tableau TAB_VICTOIRE[8][3]. Si 2 cases parmis le triplet ont le même symbole --> une amélioration est possible--> renvoie le 3 ème num du triplet = 3 ème case à completer.


```

##

amélioration de l'ia : se fait automatiquement.

## difficultés rencontrées :

Gérer le cas d'égalité (grille remplie SANS victoire)
Problème avec le choix du mode de jeu
Empecher les joueurs d'avoir le même symbole
Condition de victoire sans parcourir toutes la grille et avoir une mutliplicité de boulce for. Utilisation d'un tableau qui répertorit les composition de victoire. Utile ensuite pour amélioration
Coup de l'ia sans amélioration, generer un nombre aléatoire et qui est une case libre beaucoup de condition à verifier
Gérer les cas ou utilisateur rentrent n'impprte quoi (pas un chiffre)

```

```
