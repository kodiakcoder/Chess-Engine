//
// Created by Deejay on 1/16/2017.
//

#ifndef CHESSGAME_KNIGHT_H
#define CHESSGAME_KNIGHT_H


#include "Pieces.h"

class Knight: public Pieces  {

public:

    Knight(char pieceColor):Pieces(pieceColor){}
    virtual char getPieceType()
    {
        return 'N';
    }

    bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
    {
        Pieces *temp = gameboard[endRow][endCol];
        Pieces *knight = gameboard[startRow][startCol];
        if(((startRow+2) == endRow && (startCol+1) == endCol) || ((startRow+1) == endRow && (startCol+2) == endCol))
        {
            if(temp == 0)
            {
                return true;
            }
            else
            {
                if(temp->getPieceColor() != knight->getPieceColor())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }


        }
        return false;
    }

};


#endif //CHESSGAME_KNIGHT_H
