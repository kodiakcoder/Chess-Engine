//
// Created by Deejay on 12/27/2016.
//

#ifndef CHESSGAME_PAWN_H
#define CHESSGAME_PAWN_H

#include "Pieces.h"

class Pawn: public Pieces {

public:
        Pawn(char pieceColor):Pieces(pieceColor) {}
        virtual ~Pawn() {}

        virtual char getPieceType()
        {
            return 'P';
        }
    bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
    {
        Pieces *temp = gameboard[endRow][endCol];
        Pieces *pawn = gameboard[startRow][startCol];
        if (temp == 0)
        {//check if destination point is empty and if the user just wants to move one row ahead or two no need for column
            if((endRow - startRow == 1) && (startCol == endCol))
            {
                firstMove = true;
                return true;
            }
            if((endRow - startCol == 2) && (startCol == endCol))
            {
                firstMove = true;
                return true;
            }


        }
        else
        {
            if((endRow - startRow == 1) && (endCol - endRow == 1))
            {//check if the destination piece is not of the same color as the user selected piece.
                if(temp->getPieceColor() != pawn->getPieceColor())
                {
                    firstMove = true;
                    return true;
                }
                else return false;
            }
        }
        return false;
    }

private:



    bool firstMove = false;
};


#endif //CHESSGAME_PAWN_H
