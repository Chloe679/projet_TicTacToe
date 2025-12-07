#include<iostream>
#include"player.hpp"
#include"plateau.hpp"
#include"mode_jeu.hpp"
#include <array>
#include<cstdlib>
#include<ctime>



   




void mode_jeu(bool mode){
      char gagnant{};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //MODE DUO
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
      int case_choisie;
       //DEBUT JEU
       while (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // TOUR JOUEUR 1
        std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;
        std::cin>>case_choisie;

        //VERIFIER SI LA CASE EST LIBRE

        while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
         std::cout<<"La case est invalide ";
         std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;}
         std::cin>>case_choisie;}
        grille[case_choisie]=play1.symbol; //prends symbole

        // AFFICHE NV GRILLE
         Jeu::draw_game_board(grille);
         if (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
            gagnant='1';
         }
         
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // TOUR JOUEUR 2

        if(! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){// on fait jouer l'autre joueur
          std::cout<<"Joueur 2, veuillez choisir un numero de case: "<<std::endl;
          std::cin>>case_choisie;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //VERIFIER SI LA CASE EST LIBRE

         while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
            std::cout<<"La case est invalide";
            std::cout<<"Joueur 2, veuillez choisir autre numero de case: "<<std::endl;
         std::cin>>case_choisie;}
            grille[case_choisie]=play2.symbol; //prends symbole
            Jeu::draw_game_board(grille);
            if (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
            gagnant='2';

        }
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      }
      //FIN PARTIE
      if (gagnant == ' '){
         std::cout<<"Il y a égalité";
      }
      else{
      std::cout<<"La partie est terminée, Joueur "<< gagnant << "a gagné"<<std::endl;
       }
      }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //MODE SOLOS AVEC IA
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   else{
      int case_choisie;
      Jeu::Player play1=Jeu::create_player();
      Jeu::Player ia;
      ia.name='IA';
      ia.symbol = (play1.symbol == 'O') ? 'X' : 'O';
      std::array<char, 9> grille = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
      Jeu::draw_game_board(grille); //affiche grille vide au début

       //DEBUT JEU
         std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;
        std::cin>>case_choisie;
       while (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
         while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
         std::cout<<"La case est invalide ";
         std::cout<<"Joueur 1, veuillez choisir un numero de case: "<<std::endl;
         std::cin>>case_choisie;}
        grille[case_choisie]=play1.symbol; //prends symbole

        // AFFICHE NV GRILLE
         Jeu::draw_game_board(grille);
         if (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
            std::cout<<"Bravo, vous avez gagné"<<std::endl;
            break;
         }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TOUR IA
  if (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
         while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' '){
            std::srand(std::time(nullptr));
            case_choisie=std::rand() % 9;
         }
         grille[case_choisie]=ia.symbol; 
         Jeu::draw_game_board(grille);
          if (! Jeu::fin_partie_victoire(grille)&& ! Jeu::fin_partie_egalite(grille)){
            std::cout<<"Vous avez perdu"<<std::endl;

        }
      }
   }
}
}
