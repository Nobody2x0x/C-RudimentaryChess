#include "Move.h"
#include "Board.h"

Move::Move()
{
	this->from = Position();
	this->to = Position();
	this->player = nullptr;
	movedPiece = Piece();
	capturedPiece = Piece();
	executed = false;
	castling = false;
}

Move::Move(Position from, Position to)
{
	this->from = from;
	this->to = to;
	this->player = nullptr;
	movedPiece = Piece();
	capturedPiece = Piece();
	executed = false;
	castling = false;
}

Move::Move(Position from, Position to, Player* player)
{
	this->from = from;
	this->to = to;
	this->player = player;
	movedPiece = Piece();
	capturedPiece = Piece();
	executed = false;
	castling = false;
}

Move::~Move()
{
}

Position& Move::getFrom()
{
	return from;
}

const Position& Move::getFrom() const
{
	return from;
}

Position& Move::getTo()
{
	return to;
}

const Position& Move::getTo() const
{
	return to;
}

Piece& Move::getMovedPiece()
{
	return movedPiece;
}

const Piece& Move::getMovedPiece() const
{
	return movedPiece;
}

Piece& Move::getCapturedPiece()
{
	return capturedPiece;
}

const Piece& Move::getCapturedPiece() const
{
	return capturedPiece;
}

Player& Move::getPlayer()
{
	return *player;
}

const Player& Move::getPlayer() const
{
	return *player;
}

bool Move::isExecuted() const
{
	return executed;
}

bool Move::isCastling() const
{
	return castling;
}

bool Move::execute(Board& board)
{
	if (executed)
		return false;

	Piece piece = board.getPieceOnBoard(from);
	if (piece == Piece() )// || piece.getColor() != player.getColor())
	{
		return false;
	}
	if (!piece.isValidMove(from, to, board))
	{
		return false;
	}

	//Store moved piece for undoing
	movedPiece = piece;
	
	//Check for castling move
	if (piece.getType() == KING && std::abs(to.getCol() - from.getCol()) == 2)
	{
		return executeCastling(board);
	}

	//Get captured piece
	capturedPiece = board.getPieceOnBoard(to);

	//Execute move
	board.movePiece(from, to);
	executed = true;

	return true;
}

bool Move::executeCastling(Board& board)
{
	castling = true;
	int row = from.getRow();
	bool isKingSide = to.getCol() == 6;

	//Move the king
	board.movePiece(from, to);

	//Move the rook
	if (isKingSide)
	{
		Position rookFrom = Position(row, 7);
		Position rookTo = Position(row, 5);
		board.movePiece(rookFrom, rookTo);
	}
	else //Black side
	{
		Position rookFrom = Position(row, 0);
		Position rookTo = Position(row, 3);
		board.movePiece(rookFrom, rookTo);
	}

	executed = true;
	return true;
}

bool Move::undo(Board& board)
{
	if (!executed)
	{
		return false;
	}

	//if already castled then undo castling
	if (castling)
	{
		return undoCastling(board);
	}

	board.getTile(to).removePiece();
	board.setPieceOnBoard(from, movedPiece);

	if (capturedPiece != Piece())
	{
		board.setPieceOnBoard(to, capturedPiece);
	}

	executed = false;
	return true;
}

bool Move::undoCastling(Board& board)
{
	int row = from.getRow();
	bool isKingSide = to.getCol() == 6;

	//Move the king back
	board.movePiece(to, from);
	
	if (isKingSide)
	{
		Position rookFrom = Position(row, 5);
		Position rookTo = Position(row, 7);
		board.movePiece(rookFrom, rookTo);
	}
	else
	{
		Position rookFrom = Position(row, 3);
		Position rookTo = Position(row, 0);
		board.movePiece(rookFrom, rookTo);
	}

	executed = false;
	castling = false;

	return true;
}
