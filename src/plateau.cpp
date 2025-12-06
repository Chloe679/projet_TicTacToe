#include"plateau.hpp"
#include<iostream>
#include<array>
namespace Jeu {
    void draw_game_board(const std::array<char, 9>&tab_char){
        for(int i=0;i<=8;i++){
            std::cout<<" | " <<tab_char[i];
            if ((i+1)%3==0){
                std::cout<<" | "<< std::endl;
            }
    }
}

    }