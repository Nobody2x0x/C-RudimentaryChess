#pragma once
#ifndef KING_H
#define KING_H

#include "KingMovementStrategy.h"
#include "Piece.h"

class King : public Piece
{
public:
	King();
	King(PieceColor color);
	~King();
};

#endif // !KING_H