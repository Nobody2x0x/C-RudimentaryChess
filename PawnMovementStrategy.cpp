#include "PawnMovementStrategy.h"

PawnMovementStrategy::PawnMovementStrategy(PieceColor pieceColor)
{
	this->pieceColor = pieceColor;
}

bool PawnMovementStrategy::canMove(const Board& board, const Position& from, const Position& to) const
{
	for (Position move : getPossibleMoves(from, board))
	{
		if (move == to)
			return true;
	}

	return false;
}

std::vector<Position> PawnMovementStrategy::getPossibleMoves(const Position& currentPosition, const Board& board) const
{
	std::vector<Position> possibleMoves = std::vector<Position>(); //Blank vector

	int direction = (pieceColor == WHITE) ? -1 : 1;
	int currentRow = currentPosition.getRow();
	int currentCol = currentPosition.getCol();

	bool pawnHasMoved = (pieceColor == WHITE && currentRow != 6) || (pieceColor == BLACK && currentRow != 1);

	int oneStepRow = currentRow + direction;
	
	if (Position::isValidPosition(oneStepRow, currentCol))
	{
		Position oneStepPos = Position(oneStepRow, currentCol);

		if (board.isTileEmpty(oneStepPos))
		{
			possibleMoves.push_back(oneStepPos);

			//If hasn't moved then it can go 2 step
			if (!pawnHasMoved)
			{
				int twoStepRow = currentRow + (direction * 2);

				if (Position::isValidPosition(twoStepRow, currentCol))
				{
					Position twoStepPos = Position(twoStepRow, currentCol);

					if (board.isTileEmpty(twoStepPos))
					{
						possibleMoves.push_back(twoStepPos);
					}
				}
			}
		}
	}

	//Diagonal capture
	std::vector<int> captureCols = { currentCol - 1, currentCol + 1 };

	for (int captureCol : captureCols)
	{
		if (Position::isValidPosition(oneStepRow, captureCol))
		{
			Position capturePos = Position(oneStepRow, captureCol);

			if (board.tileHasEnemyPiece(capturePos, pieceColor))
			{
				possibleMoves.push_back(capturePos);
			}
		}
	}

	return possibleMoves;
}

std::unique_ptr<MovementStrategy> PawnMovementStrategy::clone() const
{
	return std::make_unique<PawnMovementStrategy>(*this);
}
