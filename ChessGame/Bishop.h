//
// Created by Deejay on 12/31/2016.
//

#ifndef CHESSGAME_BISHOP_H
#define CHESSGAME_BISHOP_H


#include "Pieces.h"
#include <stdlib.h>

class Bishop: public Pieces {

public:

    Bishop(char pieceColor):Pieces(pieceColor){}
    virtual char getPieceType()
    {
        return 'B';
    }
    bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
    {
        Pieces *temp = gameboard[endRow][endCol];
        Pieces *bishop = gameboard[startRow][startCol];
        if(startCol > endCol) //piece is moving towards the left diagonal
        {
            int boxesToMove = abs(startCol - endCol);

            if(temp == 0)
            {

                for(int i = 0; i < boxesToMove;i ++)
                {
                    Pieces *boxCheck = gameboard[startRow+i][startCol-i];
                    if(boxCheck == 0)
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(temp->getPieceColor() != bishop->getPieceColor())
                {
                    for(int i = 0; i < boxesToMove;i ++)
                    {
                        Pieces *boxCheck = gameboard[startRow+i][startCol-i];
                        if(boxCheck == 0)
                        {
                            return false;
                        }
                    }
                }
                else return false;
            }
        }
        else // piece if moving towards the right diagonal
        {
            int boxesToMove = abs(endRow - startRow);

            if(temp == 0)
            {
                for(int i = 0; i < boxesToMove;i ++)
                {
                    Pieces *boxCheck = gameboard[startRow+i][startCol-i];
                    if(boxCheck == 0)
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(temp->getPieceColor() != bishop->getPieceColor())
                {
                    for(int i = 0; i < boxesToMove;i ++)
                    {
                        Pieces *boxCheck = gameboard[startRow+i][startCol-i];
                        if(boxCheck == 0)
                        {
                            return false;
                        }
                    }
                }
                else return false;
            }
        }




    }
};


#endif //CHESSGAME_BISHOP_H
