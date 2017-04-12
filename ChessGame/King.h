//
// Created by Deejay on 1/16/2017.
//

#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H


#include "Pieces.h"

class King: public Pieces  {

public:

        King(char pieceColor):Pieces(pieceColor){}
        virtual char getPieceType()
        {
            return 'K';
        }

        bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
        {
            int rowMove = endRow - startRow;
            int colMove = endCol - startCol;
            if (((rowMove >= -1) && (rowMove <= 1)) && ((colMove >= -1) && (colMove <= 1)))
            {
                return true;
            }
            return false;
        }


};


#endif //CHESSGAME_KING_H
