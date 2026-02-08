#pragma once
#include <string>
#include <stdexcept>

class Position
{
private:
	int row;
	int col;
public:
	Position();
	Position(int row, int col);
	~Position();

	static bool isValidPosition(int row, int col);
	std::string toChessNotation() const;
	static Position fromChessNotation(const std::string& notation);

	int getRow() const;
	int getCol() const;

	//Operator overload
	bool operator==(const Position& left) const;
	bool operator!=(const Position& left) const;
	Position& operator= (const Position& left);
};