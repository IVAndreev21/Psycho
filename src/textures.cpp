#include "textures.hpp"

void Textures::InitialiseTextures()
{
	logo.loadFromFile("resources/images/logo.png");
	carbon.loadFromFile("resources/images/carbon.png");
	molecules.loadFromFile("resources/images/molecules_icon.png");
	ptable.loadFromFile("resources/images/ptable_icon.png");
	reactions.loadFromFile("resources/images/reactions_icon.png");
	settings.loadFromFile("resources/images/settings_icon.png");
}