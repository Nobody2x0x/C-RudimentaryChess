#include "ChessTile.h"

ChessTile::ChessTile()
{
	this->position = Position();
	this->piece = Piece();
}

ChessTile::ChessTile(Position position)
{
	this->position = position;
	this->piece = Piece();
}

ChessTile::ChessTile(Position position, Piece piece)
{
	this->position = position;
	this->piece = piece;
}

ChessTile::~ChessTile()
{

}

const Position& ChessTile::getPosition() const
{
	return position;
}

Piece& ChessTile::getPiece()
{
	return piece;
}

const Piece& ChessTile::getPiece() const
{
	return piece;
}

void ChessTile::setPiece(const Piece& piece)
{
	this->piece = piece;
}

void ChessTile::setTexture(sf::Texture& texture)
{
	this->pieceTexture = texture;
}

sf::Texture& ChessTile::getTexture()
{
	return pieceTexture;
}

const sf::Texture& ChessTile::getTexture() const
{
	return pieceTexture;
}

bool ChessTile::isEmpty() const
{
	return this->piece == Piece();
}

bool ChessTile::hasEnemyPiece(PieceColor playerColor) const
{
	return piece != Piece() && piece.getColor() != playerColor;
}

bool ChessTile::hasFriendlyPiece(PieceColor playerColor) const
{
	return piece != Piece() && piece.getColor() == playerColor;
}

void ChessTile::removePiece()
{
	this->piece = Piece();
}