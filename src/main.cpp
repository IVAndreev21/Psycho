#include "game.hpp"

int main()
{
	Game* game = new Game(1280, 1024, "sdsf");

	game->Run();

	delete game;
}