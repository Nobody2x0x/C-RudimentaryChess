#pragma once
#ifndef ROOK_H
#define ROOK_H

#include "RookMovementStrategy.h"
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook();
	Rook(PieceColor color);
	~Rook();
};

#endif //ROOK_H