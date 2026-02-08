#pragma once
#ifndef CHESSTILE_H
#define CHESSTILE_H
#include "SFML/Graphics.hpp"
#include "Piece.h"
#include "Position.h"

class ChessTile //add graphics here?
{
private:
	Position position;
	Piece piece;
	sf::Texture pieceTexture;

public:
	ChessTile();
	ChessTile(Position position);
	ChessTile(Position position, Piece piece);
	~ChessTile();

	const Position& getPosition() const;
	Piece& getPiece();
	const Piece& getPiece() const;
	void setPiece(const Piece& piece);

	//Graphics
	void setTexture(sf::Texture& texture);
	sf::Texture& getTexture();
	const sf::Texture& getTexture() const;

	bool isEmpty() const;
	bool hasEnemyPiece(PieceColor playerColor) const;
	bool hasFriendlyPiece(PieceColor playerColor) const;
	void removePiece();
};

#endif // !CHESSTILE_H
