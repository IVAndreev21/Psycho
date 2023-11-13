#include "game.hpp"

Game::Game(int width, int height, const char* title)
    : mainMenu(sf::VideoMode(width, height), title),
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
}

void Game::Run()
{
    Render* render = new Render();

    render->InitialiseTextures();

    while (!isWindowClosed)
    {
        render->mainWindow(mainMenu, isWindowClosed, sandboxIsOpen, questtModeIsOpen, optionsMenuIsOpen);

        if (sandboxIsOpen && sandboxWindow == nullptr)
        {
            sandboxWindow = new sf::RenderWindow(sf::VideoMode(1280, 1024), "Sandbox Window");
            sandboxWindow->setFramerateLimit(60);
        }
    }
    while (!isSandboxWindowClosed)
    {
        render->sandboxWindow(*sandboxWindow, isSandboxWindowClosed);
    }
    delete render;
}

Game::~Game()
{
    if (sandboxWindow != nullptr)
    {
        sandboxWindow->close();
        delete sandboxWindow;
    }
}