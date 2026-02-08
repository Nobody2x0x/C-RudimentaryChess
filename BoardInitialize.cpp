#include "BoardInitialize.h"

Board BoardInitialize::createStandardBoard()
{
    Board newBoard = Board();
    setupPieces(newBoard);

    return newBoard;
}

Board BoardInitialize::createTestBoard()
{
    Board newBoard = Board();
    
    newBoard.setPieceOnBoard(Position(0, 0), Rook(BLACK));
    newBoard.setPieceOnBoard(Position(1, 2), Rook(BLACK));

    return newBoard;;
}

Board BoardInitialize::createEmptyBoard()
{
    return Board();
}

void BoardInitialize::setupPieces(Board& board)
{
    //White side
    setupBackRank(board, 7, WHITE);
    setupPawns(board, 6, WHITE);

    //Black side
    setupBackRank(board, 0, BLACK);
    setupPawns(board, 1, BLACK);
}

void BoardInitialize::setupBackRank(Board& board, int row, PieceColor color)
{
    //Rooks
    board.setPieceOnBoard(Position(row, 0), Rook(color));
    board.setPieceOnBoard(Position(row, 7), Rook(color));

    //Knights
    board.setPieceOnBoard(Position(row, 1), Knight(color));
    board.setPieceOnBoard(Position(row, 6), Knight(color));

    //Bishops
    board.setPieceOnBoard(Position(row, 2), Bishop(color));
    board.setPieceOnBoard(Position(row, 5), Bishop(color));

    //Queen and King
    board.setPieceOnBoard(Position(row, 3), Queen(color));
    board.setPieceOnBoard(Position(row, 4), King(color));
}

void BoardInitialize::setupPawns(Board& board, int row, PieceColor color)
{
    for (int col = 0; col < 8; col++)
    {
        board.setPieceOnBoard(Position(row, col), Pawn(color));
    }
}
