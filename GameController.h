#pragma once
#include "Game.h"
#include "Position.h"
#include "GameStatus.h"
#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>

class Game;

class GameController
{
private:
	Game* game;

public:
	GameController();
	GameController(Game* game);
	~GameController();

	Game& getGame();
	const Game& getGame() const;

	bool playMove(Position from, Position to);
	bool playMove(Move& move);
	bool undoGameMove();

	void displayBoard(sf::RenderWindow& window, sf::Texture& texture);
	void displayGameStatus();

	bool isGameActive();
	void resignCurrentPlayer();
	void startGame();
	void endGame();
};