cmake_minimum_required(VERSION 3.6)
project(ChessGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pieces.h Pawn.h Board.h Game.h Bishop.h Knight.h Rook.h King.h Queen.h Players.h)
add_executable(ChessGame ${SOURCE_FILES})