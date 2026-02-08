#include "GameController.h"

GameController::GameController()
{
	this->game = nullptr;
}

GameController::GameController(Game* game)
{
	this->game = game;
}

GameController::~GameController()
{
}

Game& GameController::getGame()
{
	return *game;
}

const Game& GameController::getGame() const
{
	return *game;
}

bool GameController::playMove(Position from, Position to)
{
	try
	{
		Move newMove = Move(from, to, &game->getCurrentPlayer());
		return game->makeMove(newMove);
	}
	catch (std::invalid_argument exception)
	{
		std::cout << "Invalid move position";
		return false;
	}
}

bool GameController::playMove(Move& move)
{
	return game->makeMove(move);
}

bool GameController::undoGameMove()
{
	return game->undoLastMove();
}

void GameController::displayBoard(sf::RenderWindow& window, sf::Texture& texture)
{
	game->getBoard().printBoard(window, texture);
}

void GameController::displayGameStatus()
{
	std::cout << "Current player: " + game->getCurrentPlayer().getName() << std::endl;
	std::cout <<  "Game status: " + game->getGameStatus() << std::endl;
	std::cout <<  "Move count: " + game->getMoveCount() << std::endl;
}

bool GameController::isGameActive()
{
	return game->getGameStatus() == ACTIVE;
}

void GameController::resignCurrentPlayer()
{
	game->resign(game->getCurrentPlayer());
	std::cout << game->getCurrentPlayer().getName() + " has resign" << std::endl;
}

void GameController::startGame()
{
	std:: cout << "=== Chess Game Started ===" << std::endl;
	std::cout << "White: " + game->getWhitePlayer().getName() << std::endl;
	std::cout << "Black: " + game->getBlackPlayer().getName() << std::endl;
}

void GameController::endGame()
{
	std::cout << "=== Game Ended ===" << std::endl;
	displayGameStatus();

	switch (game->getGameStatus()) {
	case WHITE_WIN:
		std::cout <<  "White wins!" << std::endl;
		break;
	case BLACK_WIN:
		std::cout <<  "Black wins!" << std::endl;
		break;
	case STALEMATE:
		std::cout << "Game ended in stalemate!" << std::endl;
		break;
	case FORFEIT:
		std::cout <<  "Game forfeited!" << std::endl;
		break;
	case RESIGNATION:
		std::cout <<  "Game ended by resignation!" << std::endl;
		break;
	default:
		std::cout <<  "Game ended!" <<std::endl;
	}
}
