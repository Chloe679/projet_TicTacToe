#include<iostream>
#include"player.hpp"

namespace Jeu{

Player create_player(){
    Player player;
    std::cout<<"Quel est votre nom ?"<<std::endl;
    std::cin>>player.name;
    std::cout<<"Choissiez un symbole 'X' ou 'O'"<<std::endl;
    std::cin>>player.symbol;
    return player;
}
}