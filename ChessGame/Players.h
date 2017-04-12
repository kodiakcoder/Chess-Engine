//
// Created by Deejay on 1/16/2017.
//

#ifndef CHESSGAME_PLAYERS_H
#define CHESSGAME_PLAYERS_H

#include <string>

using namespace std;

class Players {
public:
        Players(){}

        Players(char pieceColor,string playerName)
        {
            color = pieceColor;
            name = playerName;
        }

private:

    string name;
    char color;


};


#endif //CHESSGAME_PLAYERS_H
