#include "game.hpp"

//Constructor
Game::Game(int width, int height, const char* title)
    : mainMenu(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close),  //Init window
    sandboxWindow(nullptr)
{
    mainMenu.setFramerateLimit(60);
    isPlaying = false;
    exit = false;
    isWindowClosed = false;
    optionsMenuIsOpen = false;
    questtModeIsOpen = false;
    sandboxIsOpen = false;
    isSandboxWindowClosed = false;
    isPeriodicTableWindowClosed = false;
    moleculesMenuOpen = false;
    periodicTableWindow = nullptr;
    periodicTableIsOpen = false;
    reactionsMenu = false;
    settingMenuOpen = false;

}
//Start of the game
void Game::Run()
{
    Render* render = new Render();

    render->InitialiseTextures();
    // Main game loop

    while (!isWindowClosed)
    {
        render->mainWindow(mainMenu, isWindowClosed, sandboxIsOpen, questtModeIsOpen, optionsMenuIsOpen);

        // If sandbox is open and sandbox window is not created yet
        if (sandboxIsOpen && sandboxWindow == nullptr)
        {
            // Create a new sandbox window
            sandboxWindow = new sf::RenderWindow(sf::VideoMode(1280, 1024), "Sandbox Window", sf::Style::Titlebar | sf::Style::Close);
            sandboxWindow->setFramerateLimit(60);
        }
    }
    // Second loop for the sandbox window
    while (!isSandboxWindowClosed)
    {
        // Render the sandbox window
        render->sandboxWindow(*sandboxWindow, isSandboxWindowClosed);
    }
    // Clean up and delete the Render object
    delete render;
}
// Destructor
Game::~Game()
{
    if (sandboxWindow != nullptr)
    {
        sandboxWindow->close();
        delete sandboxWindow;
    }
}