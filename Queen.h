#pragma once
#ifndef QUEEN_H
#define QUEEN_H

#include "QueenMovementStrategy.h"
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();
	Queen(PieceColor color);
	~Queen();
};

#endif //QUEEN_H