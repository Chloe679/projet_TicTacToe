#pragma once
#include<array>
namespace Jeu{

bool mode_duo();

bool fin_partie_victoire(std::array<char, 9>& grille);

bool fin_partie_egalite(std::array<char, 9>& grille);
}