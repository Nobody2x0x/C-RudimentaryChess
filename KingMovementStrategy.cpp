#include "KingMovementStrategy.h"

void KingMovementStrategy::addCastlingMove(std::vector<Position>& possibleMoves, const Position& currentPosition, const Board& board) const
{
	int row = currentPosition.getRow();
	int col = currentPosition.getCol();

	if ((pieceColor == WHITE && row == 7 && col == 4) || (pieceColor == BLACK && row == 0 && col == 4))
	{
		Position kingSideCastle = Position(row, 6);

		if (canCastle(board, currentPosition, kingSideCastle))
		{
			possibleMoves.push_back(kingSideCastle);
		}

		Position queenSideCastle = Position(row, 2);

		if (canCastle(board, currentPosition, queenSideCastle))
		{
			possibleMoves.push_back(queenSideCastle);
		}
	}
}

bool KingMovementStrategy::canCastle(const Board& board, const Position& from, const Position& to) const
{
	//Remind to check check castling move to rely on IF king and rook have moved
	//Current row
	int row = from.getRow();

	bool hasKingMoved = (pieceColor == WHITE && row == 7 && from.getCol() == 4) ||
					    (pieceColor == BLACK && row == 0 && from.getCol() == 4);

	if (!hasKingMoved) return false;

	bool isKingSide = to.getCol() == 6;
	bool isQueenSide = to.getCol() == 2;

	if (!isKingSide && !isQueenSide) return false;

	int rookCol = isKingSide ? 7 : 0;

	Position rookPos = Position(row, rookCol);

	//If rook exists, if it doesn't exists -> false, if not rook -> false, if not right color -> false
	if (board.getPieceOnBoard(rookPos) == Piece() ||
		board.getPieceOnBoard(rookPos).getType() != ROOK ||
		board.getPieceOnBoard(rookPos).getColor() != pieceColor) {
		return false;
	}

	//Check if there are any pieces in the way
	int startCol = std::min(from.getCol(), rookCol) + 1;
	int endCol = std::max(from.getCol(), rookCol) - 1;

	for (int col = startCol; col <= endCol; col++)
	{
		if (!board.isTileEmpty(Position(row, col)))
		{
			return false;
		}
	}

	return true;
}

KingMovementStrategy::KingMovementStrategy(PieceColor pieceColor)
{
	this->pieceColor = pieceColor;
}

bool KingMovementStrategy::canMove(const Board& board, const Position& from, const Position& to) const
{
    int rowDiff = std::abs(to.getRow() - from.getRow());
    int colDiff = std::abs(to.getCol() - from.getCol());

    if (rowDiff <= 1 && colDiff <= 1 && (rowDiff != 0 || colDiff != 0)) {
        // Check if destination is empty or has enemy piece
        return board.isTileEmpty(to) || board.tileHasEnemyPiece(to, pieceColor);
    }

    // Check for castling
    if (rowDiff == 0 && colDiff == 2) {
        return canCastle(board, from, to);
    }

    return false;
}

std::vector<Position> KingMovementStrategy::getPossibleMoves(const Position& currentPosition, const Board& board) const
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

	addCastlingMove(possibleMoves, currentPosition, board);

	return possibleMoves;
}

std::unique_ptr<MovementStrategy> KingMovementStrategy::clone() const
{
	return std::make_unique<KingMovementStrategy>(*this);
}
