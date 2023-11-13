#pragma once
#include "pch.hpp"
#include "textures.hpp"

struct Element {
    std::string symbol;
    std::string name;
    int atomicNumber;
    float weight;
    std::vector<int> energyLevels;
    float electronegativity;
    float meltingPoint;
    float boilingPoint;
    int yearDiscovery;
    int group;
    int period;
    sf::Color backgroundColor;
    sf::Color textColor;
    std::string state;
    std::string series;
};

struct DraggableCircle {
    sf::CircleShape shape;
    bool isDragging;

    DraggableCircle(float x, float y, float radius, sf::Color color)
        : isDragging(false) {
        shape.setPosition(x, y);
        shape.setRadius(radius);
        shape.setFillColor(color);
        shape.setOrigin(radius, radius);
    }
};

struct Molecule
{
    std::string abberviation;
    std::string name;
};
struct Connection {
    int index1;
    int index2;
};

struct Reaction
{
    std::string reactant1;
    std::string reactant2;
    std::string product;
};

class Render {
public:
private:
    sf::RectangleShape sandboxModeButton;
    sf::RectangleShape questModeButton;
    sf::RectangleShape optionsButton;
    sf::RectangleShape navbar;
    sf::RectangleShape detailedView;
    sf::RectangleShape infoView;
    bool periodicTableOpen, moleculesMenuOpen, settingsMenuOpen, reactionsMenuOpen;
    Textures* textures;

    sf::Event event;
    sf::Vector2i mousePos;

    int energyLevels;
    int value;
    int row;
    int col;

    sf::Text mainMenuH;
    sf::Text qmText;
    sf::Text sbText;
    sf::Text optionsText;
    sf::Text zoomViewText;
    sf::Text selectedElementInfo;
    sf::Text elementSymbol2Text;
    sf::Text elementSymbolText;
    sf::Text circleText;
    sf::Text elementSymbol3Text;


    sf::Sprite molecules_icon;
    sf::Sprite ptable_icon;
    sf::Sprite reactions_icon;
    sf::Sprite settings_icon;

    std::string zoomstr;
    std::string infoViewStr;

    std::vector<Element> selectedElement;
    std::vector<DraggableCircle> circles;
    std::vector<sf::Text> elementSymbols;
    std::vector<sf::Vertex> lines;
    std::vector<sf::Vector2f> singleCircles;
    std::vector<Molecule> molecules;
    sf::RectangleShape block;
    bool hasIndex2;

public:
    Render();

    void mainWindow(sf::RenderWindow& mainMenuWindow, bool& isWindowClosed, bool& sandboxIsOpen, bool& questtModeIsOpen, bool& optionsMenuIsOpen);
    void sandboxWindow(sf::RenderWindow& sandboxWindow, bool& isSandboxWindowOpen);
    void InitialiseTextures();
    void UnloadTextures();
    Element& getElement(int index);

};

int getPeriod(int atomicNumber);
int getGroup(int i);