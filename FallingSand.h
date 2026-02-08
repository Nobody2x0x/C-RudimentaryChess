#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>
class FallingSand
{
private:
	float width = 10.0f;

	static const int rows = 100; // Number of rows in the grid
	static const int cols = 100; // Number of columns in the grid

	std::vector<std::vector<int>> grid; // 2D vector to represent the grid
	std::vector<std::vector<int>> updateGrid; // 2D vector to represent the grid

	sf::RectangleShape rect;

public:
	FallingSand();
	~FallingSand();

	void AddParticle(sf::Vector2i& mousePos); // Adds a particle at the specified position
	void UpdateGrid(); // Updates the grid based on the rules of falling sand
	void Draw(sf::RenderWindow& window); // Draws the sand particles on the 
};