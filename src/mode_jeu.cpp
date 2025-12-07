#include<iostream>
#include"player.hpp"
#include"plateau.hpp"
#include"mode_jeu.hpp"
#include <array>



   




void mode_jeu(bool mode){
      char gagnant{};
    if(Jeu::mode_duo()){
      //CREA 2 JOUEURS

       Jeu::Player play1=Jeu::create_player();
       Jeu::Player play2=Jeu::create_player();

       //CONFLIT SYMB
       while (play1.symbol==play2.symbol){ 
        std::cout<<"Veuillez choisir un autre symbole";
       play2=Jeu::create_player();
       }

       std::array<char, 9> grille = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
       Jeu::draw_game_board(grille); //affiche grille vide au début

       //DEBUT JEU
       while (! Jeu::fin_partie){
        int case_choisie;

        // TOUR JOUEUR 1
        std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;
        std::cin>>case_choisie;

        //VERIFIER SI LA CASE EST LIBRE

        while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
         std::cout<<"La case est invalide ";
         std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;
         std::cin>>case_choisie;}
        grille[case_choisie]=play1.symbol; //prends symbole

        // AFFICHE NV GRILLE
         Jeu::draw_game_board(grille);
         if (Jeu::fin_partie){
            gagnant='1';
         }

         // TOUR JOUEUR 2

        if(!Jeu::fin_partie){// on fait jouer l'autre joueur
          std::cout<<"Joueur 2, veuillez choisir un numero de case: "<<std::endl;
          std::cin>>case_choisie;


        //VERIFIER SI LA CASE EST LIBRE

         while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
            std::cout<<"La case est invalide";
            std::cout<<"Joueur 2, veuillez choisir autre numero de case: "<<std::endl;
         std::cin>>case_choisie;}
            grille[case_choisie]=play2.symbol; //prends symbole
            Jeu::draw_game_board(grille);
            if (Jeu::fin_partie){
            gagnant='2';

        }
      
      }
      //FIN PARTIE
      if (gagnant == ' '){
         std::cout<<"Il y a égalité";
      }
      else{
      std::cout<<"La partie est terminée, Joueur "<< gagnant << "a gagné"<<std::endl;
       }
      }
   }
}

