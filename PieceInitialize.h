#pragma once
#include "Piece.h"
#include <stdexcept>

class PieceInitialize
{
public:
	static Piece createPiece(PieceType pieceType, PieceColor pieceColor);
};