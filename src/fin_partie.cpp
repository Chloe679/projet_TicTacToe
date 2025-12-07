#include<iostream>
#include"mode_jeu.hpp"
#include"player.hpp"
#include"plateau.hpp"
#include<array>


const int tab_victoire[8][6] ={
    {0,1,2},{3,4,5},{6,7,8}, // lignes
    {0,3,6},{1,4,7},{2,5,8}, // colonnes
    {0,4,8},{2,4,6}           // diagonales
    };

bool fin_partie(std::array<char, 9> grille){ //on prends le tab de la grille en cours
 for(auto &v : tab_victoire){
    if (grille[v[0]]==grille[v[1]] && grille[v[1]]==grille[v[2]] ){
        return true;
    }
 }
}
