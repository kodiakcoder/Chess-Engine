//
// Created by Deejay on 12/27/2016.
//

#ifndef CHESSGAME_PIECES_H
#define CHESSGAME_PIECES_H

#include <string>

using namespace std;

class Pieces {
public:

    Pieces(char playerColor)
    {
        color = playerColor;
    }
    virtual ~Pieces() {}
    char getPieceColor()
    {
        return color;
    }



    virtual char getPieceType() = 0;
   virtual bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol) = 0;

private:

    char piecetype;
    char color;
};


#endif //CHESSGAME_PIECES_H
