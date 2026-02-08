#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Block
{
private:
	sf::Vector2f blockPosition; // Returns the position of the block as a vector
	sf::Vector2f blockVelocity; // Returns the velocity of the block as a vector
	sf::Vector2f blockAcceleration; // Returns the acceleration of the block as a vector
	float gravity = 9.8f; //Gravity

	float width = 100.f; // Width of the block
	float height = 100.f; // Height of the block

	sf::RectangleShape blockShape;

public:
	Block();
	Block(float b_width, float b_height);
	~Block();
	
	void SetVelocity(const sf::Vector2f& velocity);
	void SetAcceleration(const sf::Vector2f& acceleration); // Sets the acceleration of the block
	void SetPosition(const sf::Vector2f& position); // Sets the position of the block
	void SetGravity();

	void GetPosition(); // Get the position of the block
	void GetAcceleration(); // Get the acceleration of the block
	void GetVelocity(); // Get the acceleration of the block

	bool CheckOverlap(Block& block); // Later

	void UpdatePosition(float deltaTime); // Updates the position of the block
	void DrawBlock(sf::RenderWindow& window); // Draws the block on the window
};