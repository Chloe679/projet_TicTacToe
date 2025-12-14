#include <iostream>
#include <array>
#include "player.hpp"
#include "plateau.hpp"
#include"mode_jeu.hpp"
#include <windows.h>
const int tab_victoire[8][3] ={
    {0,1,2},{3,4,5},{6,7,8}, // lignes
    {0,3,6},{1,4,7},{2,5,8}, // colonnes
    {0,4,8},{2,4,6}           // diagonales
    };

//VERSION PAS OPTI // RETOURNE TRUE SI IL Y A UTILISATIONAMELIORATION
namespace Jeu{
    int amelioration(std::array<char, 9>&grille, Jeu::Player IA){
        for(const auto &v : tab_victoire){
            if (grille[v[0]]==grille[v[1]] && grille[v[1]]!=' '&& grille[v[2]]==' '){
                 
                return v[2];
            }  
            if(grille[v[1]]==grille[v[2]]&& grille[v[1]]!=' '&& grille[v[0]]==' ') 
            {
                return v[0]; 
                
            }
            if (grille[v[0]]==grille[v[2]]&& grille[v[2]]!=' '&& grille[v[1]]==' ')
                {
                return v[1];
            }
        }
        return -1;
    }
}
//INCLURE DEPLACER CURSEUR VOIR TP 
// lettre pr rentrer une case
// choix autre que 1 ou 2 pr démarrage 