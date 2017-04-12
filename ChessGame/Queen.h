//
// Created by Deejay on 1/16/2017.
//

#ifndef CHESSGAME_QUEEN_H
#define CHESSGAME_QUEEN_H


#include "Pieces.h"

class Queen: public Pieces {

public:
    Queen(char piececolor):Pieces(piececolor){}

    virtual char getPieceType()
    {
        return 'Q';
    }

    bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
    {
        Pieces *temp = gameboard[endRow][endCol];
        Pieces *queen = gameboard[startRow][startCol];


    }
};


#endif //CHESSGAME_QUEEN_H
