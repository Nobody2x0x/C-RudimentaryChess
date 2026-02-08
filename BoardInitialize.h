#pragma once
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

class BoardInitialize
{
public:
	static Board createStandardBoard();
	static Board createTestBoard();
	static Board createEmptyBoard();
	static void setupPieces(Board& board);
	static void setupBackRank(Board& board, int row, PieceColor color);
	static void setupPawns(Board& board, int row, PieceColor color);
};