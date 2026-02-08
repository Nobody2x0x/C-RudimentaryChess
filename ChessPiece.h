#pragma once
#include "ChessTile.h"
#include <vector>

class ChessPiece : public ChessTile
{
	static int moves;
	sf::Vector2i position;
	int color; // 0 = white, 1 = black
public:
	ChessPiece();
	ChessPiece(int x, int y, int color);
	virtual void movement();
};