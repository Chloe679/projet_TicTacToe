#pragma once
#include<array>
#include "player.hpp"

namespace Jeu{
int amelioration(std::array<char, 9>&grille, Jeu::Player IA);


bool mode_duo();

bool fin_partie_victoire(std::array<char, 9>& grille);

bool grille_remplie(std::array<char, 9>& grille);

void mode_jeu();
}