#include "QueenMovementStrategy.h"

QueenMovementStrategy::QueenMovementStrategy(PieceColor pieceColor)
{
	this->pieceColor = pieceColor;
}

bool QueenMovementStrategy::canMove(const Board& board, const Position& from, const Position& to) const
{
	for (Position move : getPossibleMoves(from, board))
	{
		if (move == to)
			return true;
	}

	return false;
}

std::vector<Position> QueenMovementStrategy::getPossibleMoves(const Position& currentPosition, const Board& board) const
{
	std::vector<Position> possibleMoves = std::vector<Position>(); //Blank vector
	int currentRow = currentPosition.getRow();
	int currentCol = currentPosition.getCol();

	//Horizontal and vertical directions
	std::vector<std::vector<int>> directions = { {-1, -1}, { -1, 0 }, {-1, 1},
												 {0, -1},			  {0, 1},
												 {1, -1},  { 1, 0 },  {1, 1} };

	for (std::vector<int> direction : directions)
	{
		int rowDelta = direction[0];
		int colDelta = direction[1];

		for (int i = 1; i < 8; i++) //Start at 1 to avoid moving in the same spot
		{
			int newRow = currentRow + (i * rowDelta);
			int newCol = currentCol + (i * colDelta);

			if (!Position::isValidPosition(newRow, newCol)) //If not valid then stop
			{
				break;
			}

			Position newPosition = Position(newRow, newCol);

			if (board.isTileEmpty(newPosition))
			{
				possibleMoves.push_back(newPosition);
			}
			else if (board.tileHasEnemyPiece(newPosition, pieceColor))
			{
				possibleMoves.push_back(newPosition);
				break;
			}
			else
				break;

		}
	}

	return possibleMoves;
}

std::unique_ptr<MovementStrategy> QueenMovementStrategy::clone() const
{
	return std::make_unique<QueenMovementStrategy>(*this);
}
