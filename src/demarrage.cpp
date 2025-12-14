#include "mode_jeu.hpp"
#include <iostream>
#include"plateau.hpp"
#include"player.hpp"

namespace Jeu{ // MENUE DEMARAGE
bool mode_duo(){
    int choix{};
    while (choix!=1 && choix!=2){
        std::cout<<"Bienvenue dans le jeu du TicTacToe\n Veuillez choisir un mode de jeu :\n 1. Deux joueurs \n 2. Un joueur contre l'IA \n"; 
        if (std::cin>>choix && (choix==1 || choix ==2)) break;
        std::cout<<"Entrée invalide\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return choix==2;
    }};
