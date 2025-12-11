#include<iostream>
#include"player.hpp"
#include"plateau.hpp"
#include"mode_jeu.hpp"
#include <array>
#include<cstdlib>
#include<ctime>
#

namespace Jeu {

void mode_jeu() {
    char gagnant =' ';

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // MODE DUO
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (Jeu::mode_duo() == 0) {

        // CREA 2 JOUEURS
        std::cout << "joueur 1 demande::::";
        Jeu::Player play1 = Jeu::create_player();

        std::cout << "joueur 2 demande::::";
        Jeu::Player play2 = Jeu::create_player();

        // CONFLIT SYMB
        while (play1.symbol == play2.symbol) {
            std::cout << "Veuillez choisir un autre symbole \n";
            std::cin >> play2.symbol;
        }

        std::array<char, 9> grille = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        Jeu::draw_game_board(grille); //affiche grille vide au début
        int case_choisie;

        // DEBUT JEU
        while (!Jeu::fin_partie_victoire(grille) && !Jeu::grille_remplie(grille)) {

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // TOUR JOUEUR 1
            std::cout << play1.name << " (" << play1.symbol << ") - choisissez une case (1-9) : ";
            std::cin >> case_choisie;
            case_choisie--;

            // VERIFIER SI LA CASE EST LIBRE
            while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' ') {
                std::cout << "La case est invalide ";
                std::cout << "Joueur 1, veuillez choisir un numero de case: " << std::endl;
                std::cin >> case_choisie;
            }

            grille[case_choisie] = play1.symbol; //prends symbole

            // AFFICHE NV GRILLE
            Jeu::draw_game_board(grille);

            // STOP SI GAGNE
            if (fin_partie_victoire(grille)) {
                gagnant = '1';
                break;
            }
            if (grille_remplie(grille)) {
                std::cout << "égalite";
                break;
            }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // TOUR JOUEUR 2
            if (!Jeu::fin_partie_victoire(grille) && !Jeu::grille_remplie(grille)) {

                std::cout << play2.name << " (" << play2.symbol << ") - choisissez une case (1-9) : ";
                std::cin >> case_choisie;
                case_choisie--;

                /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // VERIFIER SI LA CASE EST LIBRE
                while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' ') {
                    std::cout << "La case est invalide";
                    std::cout << "Joueur 2, veuillez choisir autre numero de case: " << std::endl;
                    std::cin >> case_choisie;
                }

                grille[case_choisie] = play2.symbol; //prends symbole
                Jeu::draw_game_board(grille);

                if (Jeu::fin_partie_victoire(grille)) {
                    gagnant = '2';
                }
            }
        }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // FIN PARTIE
            if (!Jeu::fin_partie_victoire(grille)){
                if (grille_remplie) {
                    std::cout << "Fin du jeu, Il y a égalité";
                }
            }
            else {
                std::cout << "La partie est terminée, " << gagnant << " a gagné" << std::endl;
            }
        
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // MODE SOLO AVEC IA
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else {

        int case_choisie;
        Jeu::Player play1 = Jeu::create_player();
        Jeu::Player ia;
        ia.name = "IA";
        ia.symbol = (play1.symbol == 'O') ? 'X' : 'O';

        std::array<char, 9> grille = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        Jeu::draw_game_board(grille); //affiche grille vide au début

        // DEBUT JEU

        while (!Jeu::fin_partie_victoire(grille) && !Jeu::grille_remplie(grille)) {
            std::cout << play1.name << " (" << play1.symbol << ") - choisissez une case (1-9) : ";
            std::cin >> case_choisie;
            case_choisie--;

            while (case_choisie < 0 || case_choisie >= 9 || grille[case_choisie] != ' ') {
                std::cout << "La case est invalide ";
                std::cout <<play1.name <<"veuillez choisir un autre numero de case: " << std::endl;
                std::cin >> case_choisie;
            }

            grille[case_choisie] = play1.symbol;
            Jeu::draw_game_board(grille);

            if (Jeu::fin_partie_victoire(grille)) {
                std::cout << "Bravo, vous avez gagné " << std::endl;
                break;
            }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // TOUR IA
            if (!Jeu::fin_partie_victoire(grille) && !Jeu::grille_remplie(grille)) {
                std::cout<<"Tour de l'IA"<<std::endl;
                case_choisie = std::rand() % 9;

                while ( grille[case_choisie] != ' ') {
                    std::srand(std::time(nullptr));
                    case_choisie = std::rand() % 9;
                }

                grille[case_choisie] = ia.symbol;
                Jeu::draw_game_board(grille);

                if (Jeu::fin_partie_victoire(grille)) {
                    std::cout << "Vous avez perdu" << std::endl;
                }
            }
            // REGARDE SI GRILLE REMPLIE
            if (!Jeu::fin_partie_victoire(grille)){
                if (Jeu::grille_remplie(grille)) {
                    std::cout << "Fin du jeu, Il y a égalité";
                }
            }

        }
    }
}

} // namespace Jeu
