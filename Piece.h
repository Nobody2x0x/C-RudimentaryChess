#pragma once

#include <vector>
#include <memory>
#include "PieceColor.h"
#include "PieceType.h"
#include "Position.h"
#include <stdexcept>

class MovementStrategy;
class Board;

class Piece
{
private:
	PieceColor pieceColor;
	PieceType pieceType;
	bool hasMoved;
	std::unique_ptr<MovementStrategy> movemenStrategy;

public:
	Piece();
	Piece(PieceType type, PieceColor color);
	Piece(PieceType type, PieceColor color, const MovementStrategy* movemenStrategy);
	Piece(const Piece& left);
	~Piece();

	PieceType getType() const;
	PieceColor getColor() const;
	bool moved() const;
	void setMoved();

	MovementStrategy* getMovementStrategy();
	std::vector<Position> possibleMoves(const Position& position, const Board& board);
	bool isValidMove(const Position& from, const Position& to, const Board& board);

	//Operator overload
	bool operator==(const Piece& left) const;
	bool operator!=(const Piece& left) const;
	Piece& operator= (const Piece& left);
};