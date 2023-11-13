#pragma once 
#include "pch.hpp"
#include "render.hpp"
class Game
{
private:
	bool isPlaying;
	bool exit;

	bool sandboxIsOpen;
	bool questtModeIsOpen;
	bool optionsMenuIsOpen;
	bool periodicTableIsOpen;
	bool settingMenuOpen;
	bool moleculesMenuOpen;
	bool reactionsMenu;

	bool isSandboxWindowClosed;
	bool isPeriodicTableWindowClosed;
	bool isWindowClosed;
	sf::RenderWindow mainMenu;
	sf::RenderWindow* sandboxWindow;
	sf::RenderWindow* periodicTableWindow;

public:
	Game(int width, int height, const char* title);
	void Run();
	~Game();
};