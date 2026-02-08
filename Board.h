#pragma once
#include "ChessTile.h"
#include "SFML/Graphics.hpp"
#include <vector>
class Board
{
private:
	static const int BOARD_SIZE = 8;
	std::vector<std::vector<ChessTile>> tiles = std::vector<std::vector<ChessTile>>(BOARD_SIZE, std::vector<ChessTile>(BOARD_SIZE));

	void initializeBoard();
public:
	Board();
	~Board();

	void movePiece(const Position& from, const Position& to);

	ChessTile& getTile(const Position& position);
	const ChessTile& getTile(const Position& position) const;
	ChessTile& getTile(int x, int y);
	const ChessTile& getTile(int x, int y) const;
	Piece& getPieceOnBoard(const Position& position);
	const Piece& getPieceOnBoard(const Position& position) const;

	void setPieceOnBoard(const Position& position, const Piece& piece);
	bool isTileEmpty(const Position& position) const;
	bool tileHasFriendlyPiece(const Position& position, PieceColor playerColor) const;
	bool tileHasEnemyPiece(const Position& position, PieceColor playerColor) const;
	void resetBoard();
    void printBoard(sf::RenderWindow& window, const sf::Texture& texure);
};