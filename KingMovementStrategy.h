#pragma once
#include "MovementStrategy.h"
#include "PieceColor.h"
#include "PieceType.h"
#include <cmath>

class KingMovementStrategy : public MovementStrategy
{
private:
	PieceColor pieceColor;

	//King specialmove
	void addCastlingMove(std::vector<Position>& possibleMoves, const Position& currentPosition, const Board& board) const;
	bool canCastle(const Board& board, const Position& from, const Position& to) const;

public:
	KingMovementStrategy(PieceColor pieceColor);
	bool canMove(const Board& board, const Position& from, const Position& to) const override;
	std::vector<Position> getPossibleMoves(const Position& currentPosition, const Board& board) const override;
	std::unique_ptr<MovementStrategy> clone() const override;
};