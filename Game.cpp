#include "Game.h"

Game::Game()
{
	this->moves = std::vector<Move>();
	this->whitePlayer = nullptr;
	this->blackPlayer = nullptr;
	this->currentPlayer = nullptr;
	this->board = Board();
	this->gameStatus = NOTSTARTED;
}

Game::Game(Player* whitePlayer, Player* blackPlayer, Board board)
{
	if (whitePlayer->getPlayerColor() != WHITE || blackPlayer->getPlayerColor() != BLACK)
	{
		throw std::invalid_argument("Invalid player color");
	}

	this->whitePlayer = whitePlayer;
	this->blackPlayer = blackPlayer;
	this->board = board;
	this->moves = std::vector<Move>();
	this->currentPlayer = whitePlayer; //White goes first
	this->gameStatus = ACTIVE;
}

Game::~Game()
{
}

Board& Game::getBoard()
{
	return board;
}

const Board& Game::getBoard() const
{
	return board;
}

Player& Game::getCurrentPlayer()
{
	return *currentPlayer;
}

const Player& Game::getCurrentPlayer() const
{
	return *currentPlayer;
}

Player& Game::getWhitePlayer()
{
	return *whitePlayer;
}

const Player& Game::getWhitePlayer() const
{
	return *whitePlayer;
}

Player& Game::getBlackPlayer()
{
	return *blackPlayer;
}

const Player& Game::getBlackPlayer() const
{
	return *blackPlayer;
}

GameStatus& Game::getGameStatus()
{
	return gameStatus;
}

const GameStatus& Game::getGameStatus() const
{
	return gameStatus;
}

std::vector<Move>& Game::getMoves()
{
	return moves;
}

const std::vector<Move>& Game::getMoves() const
{
	return moves;
}

bool Game::makeMove(Move& move)
{
	if (gameStatus != ACTIVE)
		return false;
	if (move.getPlayer() != *currentPlayer)
		return false;
	if (move.execute(board))
	{
		moves.push_back(move);
		switchTurn();

		//Add checking for winning condition

		return true;
	}

	return false;
}

bool Game::undoLastMove()
{
	if (moves.empty())
		return false;
	
	Move& lastMove = moves.back(); //If Move is not Move& it won't switch turn
	if (lastMove.undo(board)) //If undoing succeeds
	{
		switchTurn();
		return true;
	}

	return false;
}

void Game::switchTurn()
{
	currentPlayer = (currentPlayer == whitePlayer) ? blackPlayer : whitePlayer;
}

void Game::resign(const Player& player)
{
	if (player == *whitePlayer)
	{
		gameStatus = BLACK_WIN;
	}
	else
	{
		gameStatus = WHITE_WIN;
	}
}

void Game::forfeit(const Player& player)
{
	gameStatus = FORFEIT;
}

int Game::getMoveCount()
{
	return moves.size();
}

bool Game::isPlayerTurn(const Player& player)
{
	return *currentPlayer == player && gameStatus == ACTIVE;
}
