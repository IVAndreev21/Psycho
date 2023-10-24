#include "slider.h"


Slider::Slider(int x, int y)
{
	xCord = x;
	yCord = y;
	axisHeight = 10;
	axisWidth = 700;
	sliderWidth = 20;
	sliderHeight = 30;

	if (!font.loadFromFile("resources/fonts/arial.ttf"))
		std::cout << "Error loading font\n";

	text.setFont(font);
	text.setFillColor(sf::Color::White);

	axis.setPosition(x, y);
	axis.setOrigin(0, axisHeight / 2);
	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
	axis.setFillColor(sf::Color(63, 63, 63));
	slider.setPosition(x, y);
	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
	slider.setFillColor(sf::Color(192, 192, 192));
}

sf::Text Slider::returnText(int x, int y, std::string z, int fontSize)
{
	sf::Color Black = sf::Color::Black;
	text.setCharacterSize(fontSize);
	text.setPosition(x, y);
	text.setString(z);
	text.setFillColor(Black);
	return text;
}

void Slider::create(int min, int max)
{
	sliderValue = min;
	minValue = min;
	maxValue = max;
}

void Slider::logic(sf::RenderWindow& window)
{
	if (slider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
		&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth)
		{
			slider.setPosition(sf::Mouse::getPosition(window).x, yCord);
			sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
		}
	}
}

float Slider::getSliderValue()
{
	return sliderValue;
}

void Slider::setSliderValue(float newValue)
{
	if (newValue >= minValue && newValue <= maxValue)
	{
		sliderValue = newValue;
		float diff = maxValue - minValue;
		float diff2 = newValue - minValue;
		float zzz = axisWidth / diff;
		float posX = zzz * diff2;
		posX += xCord;
		slider.setPosition(posX, yCord);
	}
}

void Slider::setSliderPercentValue(float newPercentValue)
{
	if (newPercentValue >= 0 && newPercentValue <= 100)
	{
		sliderValue = newPercentValue / 100 * maxValue;
		slider.setPosition(xCord + (axisWidth * newPercentValue / 100), yCord);
	}
}

void Slider::draw(sf::RenderWindow& window)
{
	int Fahrenheit = (9 * sliderValue) / 5;
	int kelvin = sliderValue + 273;
	Fahrenheit += 32;
	logic(window);
	window.draw(axis);
	window.draw(slider);
	window.draw(returnText(850, 95, std::to_string((int)sliderValue), 15));
	window.draw(returnText(900, 95, std::to_string(Fahrenheit), 15));
	window.draw(returnText(950, 95, std::to_string(kelvin), 15));
}