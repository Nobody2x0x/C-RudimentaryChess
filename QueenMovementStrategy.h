#pragma once

#include "MovementStrategy.h"
#include "PieceColor.h"
#include "PieceType.h"

class QueenMovementStrategy : public MovementStrategy
{
private:
	PieceColor pieceColor;

public:
	QueenMovementStrategy(PieceColor pieceColor);
	bool canMove(const Board& board, const Position& from, const Position& to) const override;
	std::vector<Position> getPossibleMoves(const Position& currentPosition, const Board& board) const override;
	std::unique_ptr<MovementStrategy> clone() const override;
};