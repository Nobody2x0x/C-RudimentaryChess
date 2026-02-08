#include "Board.h"
#include <iostream>
void Board::initializeBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			tiles[i][j] = ChessTile(Position(i, j));
		}
	}
}

Board::Board()
{
}

Board::~Board()
{
}

void Board::movePiece(const Position& from, const Position& to)
{
	Piece piece = getPieceOnBoard(from);
	getTile(from).removePiece();
	piece.setMoved();
	setPieceOnBoard(to, piece);
}

ChessTile& Board::getTile(const Position& position)
{
	return tiles[position.getRow()][position.getCol()];
}

const ChessTile& Board::getTile(const Position& position) const
{
	return tiles[position.getRow()][position.getCol()];
}

ChessTile& Board::getTile(int x, int y)
{
	return tiles[x][y];
}

const ChessTile& Board::getTile(int x, int y) const
{
	return tiles[x][y];
}

void Board::setPieceOnBoard(const Position& position, const Piece& piece)
{
	getTile(position).setPiece(piece);
}

Piece& Board::getPieceOnBoard(const Position& position)
{
	return getTile(position).getPiece();
}

const Piece& Board::getPieceOnBoard(const Position& position) const
{
	return getTile(position).getPiece();
}

bool Board::isTileEmpty(const Position& position) const
{
	return getTile(position).isEmpty();
}

bool Board::tileHasFriendlyPiece(const Position& position, PieceColor playerColor) const
{
	return getTile(position).hasFriendlyPiece(playerColor);
}

bool Board::tileHasEnemyPiece(const Position& position, PieceColor playerColor) const
{
	return getTile(position).hasEnemyPiece(playerColor);
}

void Board::resetBoard()
{
	initializeBoard();
}

void Board::printBoard(sf::RenderWindow& window, const sf::Texture& texture)
{
	sf::RectangleShape boardRect;
	sf::Sprite sprite(texture);
	sf::IntRect rect = sf::IntRect({ 0, 0 }, { 1, 1 });

	float width = 120.0f;

	for (int i = 0; i < BOARD_SIZE; i++) // i == column -> idk I messed some shit up
	{
		for (int j = 0; j < BOARD_SIZE; j++) //j == rows -> Still fukced sth up
		{

			if ((i + j) % 2 == 0)
			{
				boardRect.setSize(sf::Vector2f(width, width));
				boardRect.setFillColor(sf::Color::White);
				boardRect.setPosition(sf::Vector2f({ i * width, j * width }));
			}
			else
			{
				boardRect.setSize(sf::Vector2f(width, width));
				boardRect.setFillColor(sf::Color(222, 184, 135));
				boardRect.setPosition(sf::Vector2f({ i * width, j * width }));
			}

			//Get the tiles' details
			ChessTile tile = tiles[j][i];
			Piece piece = tile.getPiece();
			PieceType type = piece.getType();
			PieceColor color = piece.getColor();

			//Check for symbol and color
			switch (type)
			{
			case KING:
				if (color == BLACK)
				{
					rect = sf::IntRect({60, 0}, {60, 60});
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 60, 60 }, { 60, 60 });
				}
				break;
			case QUEEN:
				if (color == BLACK)
				{
					rect = sf::IntRect({ 0, 0 }, { 60, 60 });
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 0, 60 }, { 60, 60 });
				}
				break;
			case KNIGHT:
				if (color == BLACK)
				{
					rect = sf::IntRect({ 180, 0 }, { 60, 60 });
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 180, 60 }, { 60, 60 });
				}
				break;
			case PAWN:
				if (color == BLACK)
				{
					rect = sf::IntRect({ 300, 0 }, { 60, 60 });
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 300, 60 }, { 60, 60 });
				}
				break;
			case BISHOP:
				if (color == BLACK)
				{
					rect = sf::IntRect({ 240, 0 }, { 60, 60 });
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 240, 60 }, { 60, 60 });
				}
				break;
			case ROOK:
				if (color == BLACK)
				{
					rect = sf::IntRect({ 120, 0 }, { 60, 60 });
				}
				else if (color == WHITE)
				{
					rect = sf::IntRect({ 120, 60 }, { 60, 60 });
				}
				break;
			case NONE:
				rect = sf::IntRect({ 0, 0 }, { 1, 1 });
				break;
			default:
				throw std::invalid_argument("Unknown piece type!!");
			}

			sprite.setTextureRect(rect);
			sprite.setScale({ 2.0f, 2.0f });
			sprite.setPosition(sf::Vector2f(i * width, j * width));

			window.draw(boardRect); //Draw the particle
			window.draw(sprite);
		}
	}
	/*std::cout << "a b c d e f g h" << std::endl;
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			ChessTile tile = tiles[row][col];
			if (tile.isEmpty()) {
				std::cout << ". ";
			}
			else {
				Piece piece = tile.getPiece();
				PieceType symbol = piece.getType();
				switch (symbol)
				{
				case KING:
					std::cout << "K ";
					break;
				case QUEEN:
					std::cout << "Q ";
					break;
				case KNIGHT:
					std::cout << "Kn";
					break;
				case PAWN:
					std::cout << "P ";
					break;
				case BISHOP:
					std::cout << "B ";
					break;
				case ROOK:
					std::cout << "R ";
					break;
				case NONE:
					std::cout << ". ";
					break;
				default:
					throw std::invalid_argument("Unknown piece type!!");
				}
			}
		}
		std::cout << (8 - row) << std::endl;
	}
	std::cout <<  "a b c d e f g h" << std::endl;*/
}
