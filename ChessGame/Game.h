//
// Created by Deejay on 12/31/2016.
//

#ifndef CHESSGAME_GAME_H
#define CHESSGAME_GAME_H


#include "Board.h"
#include "Players.h"
#include <iostream>

using namespace std;

class Game {
public:

    void StartGame() {
        cout << "                CHESS               " << endl;
        cout << "          2 Player Chess Game       " << endl;
        cout << "                                    " << endl;
        cout << "                                    " << endl;
        cout << "                                    " << endl;
        cout << "                                    " << endl;
        cout << "        Made By: Muhammad Karim     " << endl;
        cout << "              BCSF15001             " << endl;

        string player_name1, player_name2;
        cout << "Player 1 enter your name: " << endl;
        getline(cin, player_name1);
        cout << "Player 2 enter your name: " << endl;
        getline(cin, player_name2);
        Players player1('W', player_name1);
        Players player2('B', player_name2);
        int sRow, sCol, eRow, eCol;
        bool p1InputCheck = false, p2InputCheck = false, p1moved = false, p2moved = false;
        chessboard.Print();


        do {
            while (p1moved != true) {
                while (p1InputCheck != true) {
                    cout
                            << "Player 1 enter the coordinates of the piece you want to move,the row followed by the column (row,col)"
                            << endl;
                    cin >> sRow;
                    cin >> sCol;
                    sRow--;
                    sCol--;
                    if (sRow > 7 || sRow < 0 || sCol > 7 || sCol < 0) {
                        cout << "Incorrect inputs please try again" << endl;
                    } else {
                        p1InputCheck = true;
                    }
                }
                p1InputCheck = false;
                while (p1InputCheck != true) {
                    cout
                            << "Player 1 enter the coordinates to the destination you want to move,the row followed by the column (row,col)"
                            << endl;
                    cin >> eRow;
                    cin >> eCol;
                    eRow--;
                    eCol--;
                    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
                        cout << "Incorrect inputs please try again" << endl;
                    } else {
                        p1InputCheck = true;
                    }
                }

                if (chessboard.board[sRow][sCol]->isPieceMoveAllowed(chessboard.board, sRow, sCol, eRow, eCol) ==
                    true) {
                    chessboard.playerMove(sRow, sCol, eRow, eCol);
                    p1moved = true;
                } else {
                    cout << "move not legal. try again" << endl;

                }


            }
            chessboard.Print();
            while (p2moved != true) {
                while (p2InputCheck != true) {
                    cout
                            << "Player 2 enter the coordinates of the piece you want to move,the row followed by the column (row,col)"
                            << endl;
                    cin >> sRow;
                    cin >> sCol;
                    sRow--;
                    sCol--;
                    if (sRow > 7 || sRow < 0 || sCol > 7 || sCol < 0) {
                        cout << "Incorrect inputs please try again" << endl;
                    } else {
                        p2InputCheck = true;
                    }
                }
                p2InputCheck = false;
                while (p2InputCheck != true) {
                    cout
                            << "Player 2 enter the coordinates to the destination you want to move,the row followed by the column (row,col)"
                            << endl;
                    cin >> eRow;
                    cin >> eCol;
                    eRow--;
                    eCol--;
                    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
                        cout << "Incorrect inputs please try again" << endl;
                    } else {
                        p2InputCheck = true;
                    }
                }

                if (chessboard.board[sRow][sCol]->isPieceMoveAllowed(chessboard.board, sRow, sCol, eRow, eCol) == true) {
                    chessboard.playerMove(sRow, sCol, eRow, eCol);
                    p2moved = true;
                } else {
                    cout << "move not legal. try again" << endl;

                }


            }


        } while (!chessboard.kinginCheck('W') || !chessboard.kinginCheck('B'));
    }
private:
    Board chessboard;
};


#endif //CHESSGAME_GAME_H
