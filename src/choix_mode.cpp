#include "mode_jeu.hpp"
#include <iostream>
#include"plateau.hpp"
#include"player.hpp"

namespace Jeu{
bool mode_duo(){
    int choix{};
    while (choix!=1 || choix!=2){
    std::cout<<"Mode : Solo (1), Duo(2) )"; std::cin>>choix;}
    return choix==2;


}
}