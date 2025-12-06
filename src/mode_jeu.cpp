#include<iostream>
#include"player.hpp"
#include"plateau.hpp"
#include"mode_jeu.hpp"
#include <array>



   




void mode_jeu(bool mode){
   
    if(Jeu::mode_duo()){
       Jeu::Player play1=Jeu::create_player();
       Jeu::Player play2=Jeu::create_player();
       while (play1.symbol==play2.symbol){ //conflit symbole
        std::cout<<"Veuillez choisir un autre symbole";
       play2=Jeu::create_player();
       }
       std::array<char, 9> tabvide = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
       Jeu::draw_game_board(tabvide); //affiche grille vide au début
       while (! Jeu::fin_partie){
        int case_choisie;
        std::cout<<"Veuillez choisir un numero de case"<<case_choisie;
        //VERIFIER SI LA ACSE EST LIBRE
       }
    }
    
}
