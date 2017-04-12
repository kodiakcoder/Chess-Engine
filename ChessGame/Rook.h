//
// Created by Deejay on 1/16/2017.
//

#ifndef CHESSGAME_ROOK_H
#define CHESSGAME_ROOK_H


#include <cstdlib>
#include "Pieces.h"

class Rook: public Pieces   {

public:
    Rook(char pieceColor):Pieces(pieceColor){}

    virtual char getPieceType()
    {
        return 'R';
    }

    bool isPieceMoveAllowed(Pieces *gameboard[8][8],int startRow,int startCol,int endRow,int endCol)
    {
        Pieces *temp = gameboard[endRow][endCol];
        Pieces *knight = gameboard[startRow][startCol];



        if(((startCol !=endCol) && (startRow == endCol)) || ((startRow != endRow) && (startCol == endCol)))
        {
            int boxesToMove;
            if(startRow == endCol)
            {
                boxesToMove = abs(endCol-startCol);
                if(temp == 0)
                {
                    if(startCol < endCol)
                    {
                    for(int i = 0; i <boxesToMove;i ++)
                    {
                        Pieces *boxCheck = gameboard[startRow][startCol+i];
                        if(boxCheck == 0)
                        {
                            return false;
                        }
                    }
                     return false;
                    }
                    if(startCol > endCol)
                    {
                        for(int i = 0; i <boxesToMove;i ++)
                        {
                            Pieces *boxCheck = gameboard[startRow][startCol+i];
                            if(boxCheck == 0)
                            {
                                return false;
                            }
                        }
                        return false;
                    }
                }
                else
                {
                    if(temp->getPieceColor() != knight->getPieceColor())
                    {
                        if(startCol < endCol)
                        {
                            for(int i = 0; i <boxesToMove;i ++)
                            {
                                Pieces *boxCheck = gameboard[startRow][startCol+i];
                                if(boxCheck == 0)
                                {
                                    return false;
                                }
                            }
                            return false;
                        }
                        if(startCol > endCol)
                        {
                            for(int i = 0; i <boxesToMove;i ++)
                            {
                                Pieces *boxCheck = gameboard[startRow][startCol+i];
                                if(boxCheck == 0)
                                {
                                    return false;
                                }
                            }
                            return false;
                        }
                    }
                    else return false;
                }
            }
            else
            {
                boxesToMove = abs(endRow - startRow);
                if(temp == 0)
                {
                    if(startRow < endRow)
                    {
                        for(int i = 0; i <boxesToMove;i ++)
                        {
                            Pieces *boxCheck = gameboard[startRow+i][startCol];
                            if(boxCheck == 0)
                            {
                                return false;
                            }
                        }
                        return false;
                    }
                    if(startRow > endRow)
                    {
                        for(int i = 0; i <boxesToMove;i ++)
                        {
                            Pieces *boxCheck = gameboard[startRow-i][startCol];
                            if(boxCheck == 0)
                            {
                                return false;
                            }
                        }
                        return false;
                    }
                }
                else
                {
                    if(temp->getPieceColor() != knight->getPieceColor())
                    {
                        if(startRow < endRow)
                        {
                            for(int i = 0; i <boxesToMove;i ++)
                            {
                                Pieces *boxCheck = gameboard[startRow+i][startCol];
                                if(boxCheck == 0)
                                {
                                    return false;
                                }
                            }
                            return false;
                        }
                        if(startRow > endRow)
                        {
                            for(int i = 0; i <boxesToMove;i ++)
                            {
                                Pieces *boxCheck = gameboard[startRow-i][startCol];
                                if(boxCheck == 0)
                                {
                                    return false;
                                }
                            }
                            return false;
                        }
                    }
                    else return false;
                }
            }


        }

    }

};


#endif //CHESSGAME_ROOK_H
