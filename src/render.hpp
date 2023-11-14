#pragma once
#include "pch.hpp"
#include "textures.hpp"

int getPeriod(int atomicNumber);

int getGroup(int i);

// Struct defining properties of a chemical element
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
// Struct defining properties of a draggable circle
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
// Struct defining properties of a molecule
struct Molecule
{
    std::string abberviation;
    std::string name;
};

// Struct defining a connection between two elements
struct Connection {
    int index1;
    int index2;
};
// Struct defining properties of a chemical reaction
struct Reaction
{
    std::string reactant1;
    std::string reactant2;
    std::string product;
};

// Class responsible for rendering the main game interface
class Render {
private:
    // Various graphical elements
    sf::RectangleShape sandboxModeButton;
    sf::RectangleShape questModeButton;
    sf::RectangleShape optionsButton;
    sf::RectangleShape navbar;
    sf::RectangleShape detailedView;
    sf::RectangleShape infoView;
    sf::RectangleShape block;
    Textures* textures;

    // Event handling variables
    sf::Event event;
    sf::Vector2i mousePos;

    // Variables for grid layout
    int energyLevels;
    int value;
    int row;
    int col;
    int elementWidth;

    // Constants for layout
    const int elementsPerRow;
    const int elementheight;
    const int numLanthanoids;
    const int numActinoids;
    const float gap;
    const int numElements;
    const int elementHeight;

    // Text objects for UI
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
    sf::Text noReactionText;

    // Icons for UI
    sf::Sprite molecules_icon;
    sf::Sprite ptable_icon;
    sf::Sprite reactions_icon;
    sf::Sprite settings_icon;

    // String variables for UI
    std::string zoomstr;
    std::string infoViewStr;
    std::string reactant1;
    std::string reactant2;
    // Vectors holding various game data
    std::vector<Element> selectedElement;
    std::vector<DraggableCircle> circles;
    std::vector<sf::Text> elementSymbols;
    std::vector<sf::Vertex> lines;
    std::vector<sf::Vector2f> singleCircles;
    std::vector<Molecule> molecules;
    std::vector<int> reactiveNonMetals;
    std::vector<int> nobleGases;
    std::vector<int> metalloids;
    std::vector<int> postTransitionMetals;
    std::vector<int> transitionMetals;
    std::vector<int> allkalineEarthMetals;
    std::vector<int> allkaliMetals;
    std::vector<int> unknown;
    std::vector<int> moleculesIndex2;
    std::vector<int> lanthanoids;
    std::vector<int> actinoids;
    std::vector<Connection> connections;
    bool periodicTableOpen, moleculesMenuOpen, settingsMenuOpen, reactionsMenuOpen, hasIndex2, reactionAvailable;

    // Helper functions to retrieve elements and reactions
    Element& getElement(int index);
    Reaction& getReaction(int index);
    sf::Font font;
public:
    //Constructor
    Render();

    void mainWindow(sf::RenderWindow& mainMenuWindow, bool& isWindowClosed, bool& sandboxIsOpen, bool& questtModeIsOpen, bool& optionsMenuIsOpen);
    void sandboxWindow(sf::RenderWindow& sandboxWindow, bool& isSandboxWindowOpen);
    void InitialiseTextures();
    void UnloadTextures();

};