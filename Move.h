#pragma once
#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Piece.h"
#include "Player.h"
#include <cmath>

class Player;
class Board;

class Move
{
private:
	Position from;
	Position to;
	Player* player;
	Piece movedPiece;
	Piece capturedPiece;
	bool executed;
	bool castling;

public:
	Move();
	Move(Position from, Position to);
	Move(Position from, Position to, Player* player);
	~Move();

	Position& getFrom();
	const Position& getFrom() const;
	Position& getTo();
	const Position& getTo() const;
	Piece& getMovedPiece();
	const Piece& getMovedPiece() const;
	Piece& getCapturedPiece();
	const Piece& getCapturedPiece() const;
	Player& getPlayer();
	const Player& getPlayer() const;

	bool isExecuted() const;
	bool isCastling() const;
	bool execute(Board& board);
	bool executeCastling(Board& board);
	bool undo(Board& board);
	bool undoCastling(Board& board);
};

#endif // !MOVE_H