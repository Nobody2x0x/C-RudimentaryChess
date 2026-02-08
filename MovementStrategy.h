#pragma once
#ifndef MOVEMENTSTRAT_H
#define MOVEMENTSTRAT_HMOVEMENTSTRAT_H

#include <vector>
#include <memory>
#include "Position.h"
#include "Board.h"

class Board;
class Position;

class MovementStrategy
{
public:
	virtual bool canMove(const Board& board, const Position& from, const Position& to) const = 0;
	virtual std::vector<Position> getPossibleMoves(const Position& currentPosition, const Board& board) const = 0;
	virtual std::unique_ptr<MovementStrategy> clone() const = 0;
	virtual ~MovementStrategy() = default;
};

#endif // !MOVEMENTSTRAT_H
