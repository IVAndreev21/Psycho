#include "game.hpp"

int main()
{
	// Create a new Game object 
	Game* game = new Game(1280, 1024, "Psycho");

	// Start the game by calling the Run method
	game->Run();

	// Clean up and delete the Game object
	delete game;
}