#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Slider
{
private:
	// Slider components
	sf::RectangleShape slider;
	sf::RectangleShape axis;
	sf::Font font;
	sf::Text text;
	int minValue;
	int maxValue;
	int xCord;
	int yCord;
	int axisWidth;
	int axisHeight;
	int sliderWidth;
	int sliderHeight;
	float sliderValue;
public:
	// Constructor
	Slider(int x, int y); 

	// Function to return text object with specified properties
	sf::Text returnText(int x, int y, std::string z, int fontSize); 

	// Function to create and initialize the slider
	void create(int min, int max);

	// Function to handle logic for slider interaction
	void logic(sf::RenderWindow& window);

	// Function to get the current value of the slider
	float getSliderValue();

	// Function to set the value of the slider
	void setSliderValue(float newValue);

	// Function to set the value of the slider based on a percentage
	void setSliderPercentValue(float newPercentValue);

	// Function to draw the slider components on the window
	void draw(sf::RenderWindow& window);
};
