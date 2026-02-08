#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#include "KnightMovementStrategy.h"
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight();
	Knight(PieceColor color);
	~Knight();
};

#endif // !KNIGHT_H