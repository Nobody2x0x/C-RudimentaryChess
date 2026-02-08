#pragma once
#ifndef PAWN_H
#define PAWN_H

#include "PawnMovementStrategy.h"
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	Pawn(PieceColor color);
	~Pawn();
};

#endif //PAWN_H