#include "Piece.h"
#include "MovementStrategy.h"

Piece::Piece()
{
	this->pieceColor = BLANK;
	this->pieceType = NONE;
	hasMoved = false;
	this->movemenStrategy = nullptr;
}

Piece::Piece(PieceType type, PieceColor color)
{
	this->pieceColor = color;
	this->pieceType = type;
	hasMoved = false;
	this->movemenStrategy = nullptr;
}

Piece::Piece(PieceType type, PieceColor color, const MovementStrategy* movemenStrategy)
{
	this->pieceColor = color;
	this->pieceType = type;
	hasMoved = false;
	if (movemenStrategy)
		this->movemenStrategy = movemenStrategy->clone();
	else
		this->movemenStrategy = nullptr;
}

Piece::Piece(const Piece& left) : pieceColor(left.pieceColor), pieceType(left.pieceType), movemenStrategy(left.movemenStrategy ? left.movemenStrategy->clone() : nullptr)
{
	hasMoved = left.hasMoved;
}

Piece::~Piece()
{

}

PieceType Piece::getType() const
{
	return pieceType;
}

PieceColor Piece::getColor() const
{
	return pieceColor;
}

bool Piece::moved() const
{
	return hasMoved;
}

void Piece::setMoved()
{
	hasMoved = true;
}

MovementStrategy* Piece::getMovementStrategy()
{
	return movemenStrategy.get();
}

std::vector<Position> Piece::possibleMoves(const Position& position, const Board& board)
{
	if (!movemenStrategy)
		return std::vector<Position>();
	return movemenStrategy->getPossibleMoves(position, board);
}

bool Piece::isValidMove(const Position& from, const Position& to, const Board& board)
{
	if (!movemenStrategy)
		return false;
	return  movemenStrategy->canMove(board, from, to);
}

bool Piece::operator==(const Piece& left) const
{
	return (this->pieceColor == left.pieceColor && 
			this->pieceType == left.pieceType &&
			this->hasMoved == left.hasMoved);
}

bool Piece::operator!=(const Piece& left) const
{
	return !(*this == left);
}

Piece& Piece::operator=(const Piece& left)
{
	if (this != &left) 
	{
		this->pieceColor = left.pieceColor;
		this->pieceType = left.pieceType;
		this->hasMoved = left.hasMoved;
		this->movemenStrategy = left.movemenStrategy ? left.movemenStrategy->clone() : nullptr;
	}

	return *this;
}
