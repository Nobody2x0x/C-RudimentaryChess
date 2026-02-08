#include "Position.h"
#include <cctype>

Position::Position()
{
	row = 0;
	col = 0;
}

Position::Position(int row, int col)
{
	this->row = row;
	this->col = col;
}

Position::~Position() = default;

bool Position::isValidPosition(int row, int col)
{
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}

std::string Position::toChessNotation() const
{
	std::string s = std::string(1, static_cast<char>('a' + col));
	s += static_cast<char>('0' + (8 - row));
	return s;
}

Position Position::fromChessNotation(const std::string& notation)
{
	if (notation.length() != 2) {
		throw std::invalid_argument("Invalid chess notation: " + notation);
	}

	char file = static_cast<char>(std::tolower(static_cast<unsigned char>(notation[0])));
	char rank = notation[1];

	if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
		throw std::invalid_argument("Invalid chess notation: " + notation);
	}

	int col = file - 'a';
	int row = 8 - (rank - '0');

	return Position(row, col);
}

int Position::getRow() const
{
	return row;
}

int Position::getCol() const
{
	return col;
}

bool Position::operator==(const Position& left) const
{
	return (this->row == left.row && this->col == left.col);
}

bool Position::operator!=(const Position& left) const
{
	return !(*this == left);
}

Position& Position::operator=(const Position& left)
{
	if (*this != left)
	{
		this->row = left.row;
		this->col = left.col;
	}

	return *this;
}
