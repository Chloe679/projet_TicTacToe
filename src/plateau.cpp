#include "plateau.hpp"
#include <iostream>
#include <array>

namespace Jeu {
    void draw_game_board(std::array<char, 9>& tab_char) {
        for(int i = 0; i < 9; i++) {
            // Affiche X ou O si présent, sinon un espace
            char c = (tab_char[i] == ' ') ? ' ' : tab_char[i];
            std::cout << " | " << c;

            if ((i + 1) % 3 == 0) {
                std::cout << " | " << std::endl;
            }
        }
    }
}