#include "textures.hpp"

// Function to initialize textures for the Textures class
void Textures::InitialiseTextures()
{
	// Load textures from image files
	logo.loadFromFile("resources/images/logo.png");                // Load logo texture
	carbon.loadFromFile("resources/images/carbon.png");            // Load carbon texture
	molecules.loadFromFile("resources/images/molecules_icon.png"); // Load molecules icon texture
	ptable.loadFromFile("resources/images/ptable_icon.png");       // Load periodic table icon texture
	reactions.loadFromFile("resources/images/reactions_icon.png"); // Load reactions icon texture
	settings.loadFromFile("resources/images/settings_icon.png");   // Load settings icon texture
}
