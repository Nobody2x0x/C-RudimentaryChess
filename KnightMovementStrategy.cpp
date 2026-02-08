#include "KnightMovementStrategy.h"

KnightMovementStrategy::KnightMovementStrategy(PieceColor pieceColor)
{
	this->pieceColor = pieceColor;
}

bool KnightMovementStrategy::canMove(const Board& board, const Position& from, const Position& to) const
{
	for (Position move : getPossibleMoves(from, board))
	{
		if (move == to)
			return true;
	}

	return false;
}

std::vector<Position> KnightMovementStrategy::getPossibleMoves(const Position& currentPosition, const Board& board) const
{
	std::vector<Position> possibleMoves = std::vector<Position>(); //Blank vector
	int currentRow = currentPosition.getRow();
	int currentCol = currentPosition.getCol();

	//Horizontal and vertical directions
	std::vector<std::vector<int>> directions = { {-2, -1},		      { -2, 1 },
										{-1, -2},							    {-1, 2},

										{1, -2},								{1, 2},
												 {2, -1},			  {2, 1} };

	for (std::vector<int> direction : directions)
	{
		int newRow = currentRow + direction[0];
		int newCol = currentCol + direction[1];

		if (Position::isValidPosition(newRow, newCol))
		{
			Position newPosition = Position(newRow, newCol);

			if (board.isTileEmpty(newPosition) || board.tileHasEnemyPiece(newPosition, pieceColor))
			{
				possibleMoves.push_back(newPosition);
			}
		}
	}

	return possibleMoves;
}

std::unique_ptr<MovementStrategy> KnightMovementStrategy::clone() const
{
	return std::make_unique<KnightMovementStrategy>(*this);
}
