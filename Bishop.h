#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include "BishopMovementStrategy.h"
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(PieceColor color);
	~Bishop();
};

#endif // !BISHOP_H