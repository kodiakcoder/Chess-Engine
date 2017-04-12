//
// Created by Deejay on 12/30/2016.
//

#ifndef CHESSGAME_BOARD_H
#define CHESSGAME_BOARD_H


#include <iostream>
#include "Pieces.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"

using namespace std;
class Board {


public:
    Board()
    {
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                board[iRow][iCol] = 0;
            }
        }
        //for black pawns
        for(int i = 0; i <8;i++)
        {
            board[1][i] = new Pawn('W');
        }
        board[0][0] = new Rook('W');
        board[0][1] = new Knight('W');
        board[0][2] = new Bishop('W');
        board[0][3] = new Queen('W');
        board[0][4] = new King('W');
        board[0][5] = new Bishop('W');
        board[0][6] = new Knight('W');
        board[0][7] = new Rook('W');

        //for black pawns
        for(int i = 0; i < 8;i++)
        {
            board[6][i] = new Pawn('B');
        }

        board[7][0] = new Rook('W');
        board[7][1] = new Knight('W');
        board[7][2] = new Bishop('W');
        board[7][3] = new Queen('W');
        board[7][4] = new King('W');
        board[7][5] = new Bishop('W');
        board[7][6] = new Knight('W');
        board[7][7] = new Rook('W');




    }

    virtual ~Board() {
    }

    void Print() {

        const int kiSquareWidth = 4;
        const int kiSquareHeight = 3;
        for (int iRow = 0; iRow < 8*kiSquareHeight; ++iRow) {
            int iSquareRow = iRow/kiSquareHeight;
            // Print side border with numbering
            if (iRow % 3 == 1) {
                cout << '-' << (char)('1' + 7 - iSquareRow) << '-';
            } else {
                cout << "---";
            }
            // Print the chess board
            for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol) {
                int iSquareCol = iCol/kiSquareWidth;
                if (((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2) && board[7-iSquareRow][iSquareCol] != 0) {
                    if ((iCol % 4) == 1) {
                        cout << board[7-iSquareRow][iSquareCol]->getPieceColor();
                    } else {
                        cout << board[7-iSquareRow][iSquareCol]->getPieceType();
                    }
                } else {
                    if ((iSquareRow + iSquareCol) % 2 == 1) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
        // Print the bottom border with numbers
        for (int iRow = 0; iRow < kiSquareHeight; ++iRow) {
            if (iRow % 3 == 1) {
                cout << "---";
                for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol) {
                    int iSquareCol = iCol/kiSquareWidth;
                    if ((iCol % 4) == 1) {
                        cout << (iSquareCol + 1);
                    } else {
                        cout << '-';
                    }
                }
                cout << endl;
            } else {
                for (int iCol = 1; iCol < 9*kiSquareWidth; ++iCol) {
                    cout << '-';
                }
                cout << endl;
            }
        }
    }

    bool kinginCheck(char pieceColor) {
        int kingRow,kingCol;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (board[row][col] != 0) {
                    if (board[row][col]->getPieceColor() == pieceColor) {
                        if (board[row][col]->getPieceType() == 'K') {
                            kingRow = row;
                            kingCol = col;
                        }
                    }
                }
            }
        }
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (board[row][col] != 0) {
                    if (board[row][col]->getPieceColor() != pieceColor) {
                        if (board[row][col]->isPieceMoveAllowed(board,row, col, kingRow, kingCol)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
    void playerMove(int srow,int scol,int erow,int ecol)
    {
        Pieces *temp = board[srow][scol];
        board[srow][scol] = 0;
        board[erow][ecol] = temp;
    }

    Pieces *board[8][8];

};


#endif //CHESSGAME_BOARD_H
