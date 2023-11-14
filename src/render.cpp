#include "render.hpp"


int getPeriod(int atomicNumber) {
    if (atomicNumber >= 1 && atomicNumber <= 2) {
        return 1;
    }
    else if (atomicNumber >= 3 && atomicNumber <= 10) {
        return 2;
    }
    else if (atomicNumber >= 11 && atomicNumber <= 18) {
        return 3;
    }
    else if (atomicNumber >= 19 && atomicNumber <= 36) {
        return 4;
    }
    else if (atomicNumber >= 37 && atomicNumber <= 54) {
        return 5;
    }
    else if (atomicNumber >= 55 && atomicNumber <= 86) {
        return 6;
    }
    else if (atomicNumber >= 87 && atomicNumber <= 118) {
        return 7;
    }
    return 0;
}

int getGroup(int i) {
    if (i == 1 || i == 3 || i == 11 || i == 19 || i == 37 || i == 55 || i == 87)
    {
        return 1;
    }
    else if (i == 4 || i == 12 || i == 20 || i == 38 || i == 56 || i == 88)
    {
        return 2;
    }
    else if (i == 21 || i == 39)
    {
        return 3;
    }
    else if (i == 22 || i == 40 || i == 72 || i == 104)
    {
        return 4;
    }
    else if (i == 23 || i == 41 || i == 73 || i == 105)
    {
        return 5;
    }
    else if (i == 24 || i == 42 || i == 74 || i == 106)
    {
        return 6;
    }
    else if (i == 25 || i == 43 || i == 75 || i == 107)
    {
        return 7;
    }
    else if (i == 26 || i == 44 || i == 76 || i == 108)
    {
        return 8;
    }
    else if (i == 27 || i == 45 || i == 77 || i == 109)
    {
        return 9;
    }
    else if (i == 28 || i == 46 || i == 78 || i == 110)
    {
        return 10;
    }
    else if (i == 29 || i == 47 || i == 79 || i == 111)
    {
        return 11;
    }
    else if (i == 30 || i == 48 || i == 80 || i == 112)
    {
        return 12;
    }
    else if (i == 5 || i == 13 || i == 31 || i == 49 || i == 81 || i == 113)
    {
        return 13;
    }
    else if (i == 6 || i == 14 || i == 32 || i == 50 || i == 82 || i == 114)
    {
        return 14;
    }
    else if (i == 7 || i == 15 || i == 33 || i == 51 || i == 83 || i == 115)
    {
        return 15;
    }
    else if (i == 8 || i == 16 || i == 34 || i == 52 || i == 84 || i == 116)
    {
        return 16;
    }
    else if (i == 9 || i == 17 || i == 35 || i == 53 || i == 85 || i == 117)
    {
        return 17;
    }
    else if (i == 2 || i == 10 || i == 18 || i == 36 || i == 54 || i == 86 || i == 118)
    {
        return 18;
    }
    else if (i <= 57 && i >= 71)
    {
        return 19;
    }
    else if (i <= 89 && i >= 103)
    {
        return 20;
    }
}


Element& Render::getElement(int index)
{
    static Element getElement[118] = {
    {"H", "Hydrogen", 1, 1.008, {1}, 2.20, -259.1, -252.9, 1766}, {"He", "Helium", 2, 4.002602, {2}, NULL, NULL, -269, 1895}, {"Li", "Lithium", 3, 6.94, {2,1}, 0.98, 180.54, 1342, 1817}, {"Be", "Beryllium", 4, 9.0121831, {2,2}, 1.57, 1287, 2470, 1797}, {"B", "Boron", 5, 10.81, {2,3}, 2.04, 2075, 4000, 1808},
    {"C","Carbon", 6, 12.011, {2,4}, 2.55, 3642, 3642, 3750}, {"N", "Nitrogen", 7, 14.007, {2,5}, 3.04, -210.1, -195.8, 1772}, {"O", "Oxygen", 8, 15.999, {2,6}, 3.44, -218, -183, 1774}, {"F", "Fluorine", 9, 18.998403162, {2,7}, 3.98, -220, -188.1, 1879}, {"Ne", "Neon", 10, 20.1797, {2,8}, NULL, -248.6, -246.1, 1898},
    {"Na","Sodium", 11, 22.98976928, {2,8,1}, 0.93, 97.720, 882.9, 1939}, {"Mg", "Magnesium", 12, 24.305, {2,8,2}, 1.31, 650, 1090, 1755}, {"Al", "Aluminium", 13, 26.9815384, {2,8,3}, 1.61, 660.32, 2519, 1825}, {"Si", "Silicon", 14, 28.085, {2,8,4}, 1.90, 1414, 2900, 1824}, {"P", "Phosphorus", 15, 30.973761998, {2,8,5}, 2.19, 44.15, 280.5, 1669},
    {"S","Sulfur", 16, 32.06, {2,8,6}, 2.58, 115.21, 444.72, 500}, {"Cl", "Chlorne", 17, 36.45, {2,8,7}, 3.16, -101.5, -34.040, 1774}, {"Ar", "Argon", 18, 39.948, {2,8,8}, NULL, -189, -186, 1894}, {"K", "Potassium", 19, 39.0983, {2,8,8,1}, 0.82, 63.380, 758.9 , 1807}, {"Ca", "Calcium", 20, 40.078, {2,8,8,2}, 1.0, 841.9, 1484, 1808},
    {"Sc","Scandium", 21, 44.955907, {2,8,9,2}, 1.36, 1541, 2830, 1879}, {"Ti", "Titanium", 22, 47.867, {2,8,10,2}, 1.54, 1668, 3287, 1791}, {"V", "Vandium", 23, 50.9415, {2,8,11,2}, 1.63, 1910, 3407, 1801}, {"Cr", "Chromium", 24, 51.9961, {2,8,13,1}, 1.66, 1907, 2671 , 1797}, {"Mn", "Manganese", 25, 54.938043, {2,8,13,2}, 1.55, 1246, 2061, 1774},
    {"Fe","Iron", 26, 55.845, {2,8,14,2}, 1.83, 1538, 2861, 2000}, {"Co", "Cobalt", 27, 58.933194, {2,8,15,2}, 1.88, 1495, 2900, 1735}, {"Ni", "Nickel", 28, 58.6934, {2,8,16,2}, 1.91, 1455, 2913, 1751}, {"Cu", "Copper", 29, 63.546, {2,8,18,1}, 1.90, 1804.62, 2562 , 8000}, {"Zn", "Zinc", 30, 65.38, {2,8,18,2}, 1.65, 419.53, 906.9, 1500},
    {"Ga","Gallium", 31, 69.723, {2,8,18,3}, 1.81, 29.760, 2204, 1875}, {"Ge", "Germanium", 32, 72.630, {2,8,18,4}, 2.01, 938.25, 2820, 1886}, {"As", "Arsenic", 33, 74.921595, {2,8,18,5}, 2.18, 816.9, 614, 1250}, {"Se", "Selenium", 34, 78.971, {2,8,18,6}, 2.55, 221, 685 , 1817}, {"Br", "Bromine", 35, 79.904, {2,8,18,7}, 2.96, -7350, 58.9, 1826},
    {"Kr","Krypton", 36, 83.798, {2,8,18,8}, 3.0, -157.36, -153.22, 1898}, {"Rb", "Rubidium", 37, 85.4678, {2,8,18,8,1}, 0.82, 39.310, 688, 1861}, {"Sr", "Strontium", 38, 87.62, {2,8,18,8,2}, 0.95, 776.9, 1382, 1790}, {"Y", "Yttrium", 39, 88.905838, {2,8,18,9,2}, 1.22, 1526, 3345 , 1794}, {"Zr", "Zirconium", 40, 91.224, {2,8,18,10,2}, 1.33, 1855, 4409, 1789},
    {"Nb","Niobium", 41, 92.90637, {2,8,12,1}, 1.6, 2477, 4744, 1801}, {"Mo", "Molybdenum", 42, 95.95, {2,8,18,13,1}, 2.16, 2623, 4639, 1781}, {"Tc", "Techenitum", 43, 98, {2,8,18,13,2}, 1.9, 2157, 4265, 1937}, {"Ru", "Ruthenium", 44, 101.07, {2,8,18,15,1}, 2.2, 2334, 4150 , 1844}, {"Rh", "Rhodium", 45, 102.91, {2,8,18,16,1}, 2.88, 1964, 3695, 1803},
    {"Pd","Palladium", 46, 106.42, {2,8,18,18}, 2.20, 1554.90, 2963, 1803}, {"Ag", "Silver", 47, 107.8682, {2,8,18,18,1}, 1.93, 961.780, 2162, 300}, {"Cd", "Cadmium", 48, 112.414, {2,8,18,18,2}, 1.69, 321.07, 766.9, 1817}, {"In", "Indium", 49, 114.818, {2,8,18,18,3}, 1.78, 156.60, 2072 , 1863}, {"Sn", "Tin", 50, 118.710, {2,8,18,18,4}, 1.96, 231.93, 2602, 3000},
    {"Sb","Antimony", 51, 121.760, {2,8,18,18,5}, 2.05, 630.63, 1587, 3000}, {"Te", "Tellurium", 52, 127.60, {2,8,18,18,6}, 2.1, 449.51, 987.9, 1783}, {"I", "Iodine", 53, 126.90447, {2,8,18,18,7}, 2.66, 113.70, 184.3, 1811}, {"Xe", "Xenon", 54, 131.293, {2,8,18,18,8}, 2.6, -111.8, -108.0 , 1898}, {"Cs", "Caesium", 55, 132.90545196, {2,8,18,18,8,1}, 0.79, 28.440, 641, 1860},
    {"Ba","Barium", 56, 137.327, {2,8,18,18,8,2}, 0.89, 730, 1870, 1808}, {"La", "Lanthaum", 57, 138.90547, {2,8,18,18,9,2}, 1.10, 919.9, 3464, 1839}, {"Ce", "Cerium", 58, 140.116, {2,8,18,19,9,2}, 1.12, 797.9, 3360, 1803}, {"Pr", "Praseodymium", 59, 140.90766, {2,8,18,21,8,2}, 1.13, 930.9, 3290 , 1885}, {"Nd", "Neodymium", 60, 144.242, {2,8,18,22,8,2}, 1.14, 1021, 3100, 1885},
    {"Pm","Promethium", 61, 145, {2,8,18,23,8,2}, NULL, 1100, 3000, 1945}, {"Sm", "Samarium", 62, 150.36, {2,8,18,24,8,2}, 1.17, 1072, 1803, 1879}, {"Eu", "Europium", 63, 151.964, {2,8,18,25,8,2}, NULL, 821.9, 1500, 1901}, {"Gd", "Gadollinium", 64, 157.25, {2,8,18,25,9,2}, 1.20, 1313, 3250 , 1880}, {"Tb", "Terbium", 65, 158.925354, {2,8,18,27,8,2}, NULL, 1356, 3230, 1843},
    {"Dy","Dysprosium", 66, 162.500, {2,8,18,28,8,2}, 1.22, 1412, 2567, 1886}, {"Ho", "Holmium", 67, 164.930329, {2,8,18,29,8,2}, 1.23, 1474, 2700, 1878}, {"Er", "Erbium", 68, 167.259, {2,8,18,30,8,2}, 1.24, 1497, 2868, 1842}, {"Tm", "Thulium", 69, 168.934219, {2,8,18,31,8,2}, 1.25, 1545, 1950 , 1879}, {"Yb", "Ytterbium", 70, 173.045, {2,8,18,32,8,2}, NULL, 818.9, 1196, 1878},
    {"Lu","Luteium", 71, 174.9668, {2,8,18,32,9,2}, 1.27, 1663, 3402, 1907}, {"Hf", "Hafnium", 72, 178.486, {2,8,18,32,10,2}, 1.3, 2233, 4603, 1923}, {"Ta", "Tantalum", 73, 180.94788, {2,8,18,32,11,2}, 1.5, 3017, 5458, 1802}, {"W", "Tungsten", 74, 183.84, {2,8,18,32,12,2}, 2.36, 3422, 5555 , 1879}, {"Re", "Rhenium", 75, 173.045, {2,8,18,32,13,2}, 1.9, 3186, 5596, 1925},
    {"Os","Osmium", 76, 190.23, {2,8,18,32,14,2}, 2.2, 3033, 5012, 1803}, {"Ir", "Iridium", 77, 192.217, {2,8,18,32,15,2}, 2.20, 2466, 4428, 1803}, {"Pt", "Platinum", 78, 195.084, {2,8,18,32,17,1}, 2.28, 1768.3, 3825, 1735}, {"Au", "Gold", 79, 196.966570, {2,8,18,32,18,1}, 2.54, 2856, 890.1 , 2500}, {"Hg", "Mercury", 80, 200.59, {2,8,18,32,18,2}, 2.0, -38.830, 356.73, 1500},
    {"Ti","Thalium", 81, 204.38, {2,8,18,32,18,3}, 1.62, 304, 1473, 1861}, {"Pb", "Lead", 82, 207.2, {2,8,18,32,18,4}, 2.33, 327.46, 1749, 4000}, {"Bi", "Bismuth", 83, 208.98040, {2,8,18,32,18,5}, 2.02, 271.3, 1564, 1400}, {"Po", "Polonium", 84, 209, {2,8,18,32,18,6}, 2.0, 255, 961.9 , 1898}, {"At", "Astatine", 85, 210, {2,8,18,32,18,7}, 2.2, 302, 350, 1940},
    {"Rn","Radon", 86, 222, {2,8,18,32,18,8}, NULL, -71.1, -61.85, 1900}, {"Fr", "Francium", 87, 223, {2,8,18,32,18,8,1}, 0.7, 20.9, 650, 1939}, {"Ra", "Radium", 88, 226, {2,8,18,32,18,8,2}, 0.9, 700, 1737, 1898}, {"Ac", "Actinium", 89, 277, {2,8,18,32,18,6}, 2.0, 255, 961.9 , 1898}, {"Th","Thorium", 90, 232.0377, {2,8,18,32,18,10,2}, 1.3, 1750, 4820, 1829},
    {"Pa", "Protactinium", 91, 231.03588, {2,8,18,32,20,9,2}, 1.5, 1572, 4000, 1913}, {"U", "Uranium", 92, 238.02891, {2,8,18,32,21,9,2}, 1.38, 1135, 3900, 1789}, {"Np", "Neptunium", 93, 237, {2,8,18,32,22,9,2}, 1.36, 644, 4000 , 1940}, {"Pu", "Plutonium", 94, 244, {2,8,18,32,24,8,2}, 1.28, 640, 3230, 1940},
    {"Am","Americium", 95, 243, {2,8,18,32,25,8,2}, 1.3, 1176, 2011, 1944}, {"Cm", "Curium", 96, 247, {2,8,18,32,25,9,2}, 1.3, 1345, 3110, 1944}, {"Bk", "Berkelium", 97, 247, {2,8,18,32,27,8,2}, 1.3, 1050, NULL, 1949}, {"Cf", "Californium", 98, 241, {2,8,18,32,28,8,2}, 1.3, 899.9, NULL , 1950}, {"Es", "Einsteinium", 99, 252, {2,8,18,32,29,8,2}, 1.3, 859.9, NULL, 1952},
    {"Fm","Fermium", 100, 257, {2,8,18,32,30,8,2}, 1.3, 1500, NULL, 1952}, {"Md", "Mendelevium", 101, 258, {2,8,18,32,31,8,2}, NULL , 1600, NULL, 1961}, {"No", "Nobelium", 102, 259, {2,8,18,32,32,8,2}, 1.3, 830, NULL, 1958}, {"Lr", "Lawrencium", 103, 266, {2,8,18,32,32,8,3}, NULL, 1600, NULL , 1950}, {"Rf", "Rutherfordium", 104, 267, {2,8,18,32,32,10,2}, NULL, NULL, NULL, 1964},
    {"Db","Dubnium", 105, 268, {2,8,18,32,30,11,2}, NULL, NULL, NULL, 1967}, {"Sg", "Seaborgium", 106, 269, {2,8,18,32,32,12,2}, NULL , NULL, NULL, 1974}, {"Bh", "Bohrium", 107, 270, {2,8,18,32,32,13,2}, NULL, NULL, NULL, 1981}, {"Hs", "Hassium", 108, 277, {2,8,18,32,32,14,2}, NULL, NULL, NULL , 1984}, {"Mt", "Meitnerium", 109, 278, {2,8,18,32,32,15,2}, NULL, NULL, NULL, 1982},
    {"Ds","Darmstadium", 110, 281, {2,8,18,32,32,17,1}, NULL, NULL, NULL, 1994}, {"Rg", "Roentgenium", 111, 282, {2,8,18,32,32,17,2}, NULL , NULL, NULL, 1994}, {"Cn", "Copernicium", 112, 285, {2,8,18,32,32,18,2}, NULL, NULL, NULL, 1996}, {"Nh", "Nihonium", 113, 286, {2,8,18,32,32,18,3}, NULL, NULL, NULL , 2004}, {"Fl", "Flevorium", 114, 289, {2,8,18,32,32,18,4}, NULL, NULL, NULL, 1998},
    {"Mc","Moscovium", 115, 290, {2,8,18,32,32,18,5}, NULL, NULL, NULL, 2004}, {"Lv", "Livermorium", 116, 293, {2,8,18,32,32,18,6}, NULL , NULL, NULL, 2000}, {"Ts", "Tennessine", 117, 294, {2,8,18,32,32,18,7}, NULL, NULL, NULL, 2010}, {"Og", "Oganesson", 118, 294, {2,8,18,32,32,18,8}, NULL, NULL, NULL , 2006}
    };
    return getElement[index];
}


Reaction& Render::getReaction(int index)
{
    static Reaction getReaction[8] = {
        {"H","H","2H"},{"O","O","O2"},{"N","N","2N"},{"Cl","Cl","Cl2"},{"Br","Br","Br2"},{"I","I","I2"},{"F","F","F2"}, {"2H2", "O2", "2H2O"}
    };
}

Render::Render()
{
    textures = new Textures;
    energyLevels = 0;
    value = 0;
    row = 0;
    col = 0;
    hasIndex2 = false;
    moleculesMenuOpen = false;
    settingsMenuOpen = false;
    reactionsMenuOpen = false;
    periodicTableOpen = false;
    moleculesMenuOpen = false;

}

void Render::InitialiseTextures()
{
    textures->InitialiseTextures();
}
void Render::mainWindow(sf::RenderWindow& mainMenuWindow, bool& isWindowClosed, bool& sandboxIsOpen, bool& questtModeIsOpen, bool& optionsMenuIsOpen)
{
    sf::Font font;

    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        mainMenuWindow.close();
        std::cout << "Unable to find font";
    }
    sf::Sprite logoSprite(textures->logo);
    logoSprite.setPosition(sandboxModeButton.getPosition().x + 50, sandboxModeButton.getPosition().y - 300);
    logoSprite.setScale(0.25, 0.25);

    sf::Sprite carbonSprite(textures->carbon);
    carbonSprite.setPosition(mainMenuWindow.getSize().x / 2 + 100, mainMenuWindow.getSize().y / 2 - 200);
    carbonSprite.setScale(1.5f, 1.5f);


    sandboxModeButton.setPosition(sf::Vector2f(50.0f, 350.0f));
    sandboxModeButton.setSize(sf::Vector2f(450.0f, 150.0f));

    questModeButton.setPosition(sf::Vector2f(50.0f, 550.0f));
    questModeButton.setSize(sf::Vector2f(450.0f, 150.0f));

    optionsButton.setPosition(50.0f, 750.0f);
    optionsButton.setSize(sf::Vector2f(450.0f, 150.0f));

    mainMenuH.setFont(font);
    mainMenuH.setCharacterSize(40);
    mainMenuH.setString("Psycho");
    mainMenuH.setPosition(mainMenuWindow.getSize().x / 2, 10);
    mainMenuH.setFillColor(sf::Color::Black);

    qmText.setFont(font);
    qmText.setCharacterSize(30);
    qmText.setString("Quest mode");
    qmText.setPosition(questModeButton.getPosition().x + 120, questModeButton.getPosition().y + 60);
    qmText.setFillColor(sf::Color::Black);

    sbText.setFont(font);
    sbText.setCharacterSize(30);
    sbText.setString("Sandbox mode");
    sbText.setPosition(sandboxModeButton.getPosition().x + 120, sandboxModeButton.getPosition().y + 60);
    sbText.setFillColor(sf::Color::Black);

    optionsText.setFont(font);
    optionsText.setCharacterSize(30);
    optionsText.setString("Options");
    optionsText.setPosition(optionsButton.getPosition().x + 120, optionsButton.getPosition().y + 60);
    optionsText.setFillColor(sf::Color::Black);

    while (mainMenuWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mainMenuWindow.close();
            isWindowClosed = true;

        }


        mousePos = sf::Mouse::getPosition(mainMenuWindow);

        //Sandbox button
        if (sandboxModeButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            sandboxModeButton.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mainMenuWindow.close();
                sandboxIsOpen = true;
                isWindowClosed = true;
            }
        }
        else
        {
            sandboxModeButton.setFillColor(sf::Color(169, 169, 169));

        }

        //Quest mode button
        if (questModeButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            questModeButton.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mainMenuWindow.close();
                questtModeIsOpen = true;
                isWindowClosed = true;
            }
        }
        else
        {
            questModeButton.setFillColor(sf::Color(169, 169, 169));

        }

        if (optionsButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            optionsButton.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mainMenuWindow.close();
                optionsMenuIsOpen = true;
                isWindowClosed = true;
            }
        }
        else
        {
            optionsButton.setFillColor(sf::Color(169, 169, 169));

        }
    }
    mainMenuWindow.clear(sf::Color::White);
    mainMenuWindow.draw(sandboxModeButton);
    mainMenuWindow.draw(questModeButton);
    mainMenuWindow.draw(optionsButton);
    mainMenuWindow.draw(mainMenuH);
    mainMenuWindow.draw(sbText);
    mainMenuWindow.draw(qmText);
    mainMenuWindow.draw(optionsText);
    mainMenuWindow.draw(logoSprite);
    mainMenuWindow.draw(carbonSprite);
    mainMenuWindow.display();
}

void::Render::sandboxWindow(sf::RenderWindow& sandboxWindow, bool& sandboxWindowIsOpen)
{
    const int elementsPerRow = 18;
    const int elementHeight = 60;
    const int numLanthanoids = 14;
    const int numActinoids = 14;
    const float gap = 1.0f;
    const int numElements = 118;
    const int elementWidth = (sandboxWindow.getSize().x - 330) / elementsPerRow;

    detailedView.setSize(sf::Vector2f(180.0f, 180.0f));
    infoView.setSize(sf::Vector2f(250.0f, 500.0f));

    navbar.setSize(sf::Vector2f(sandboxWindow.getSize().x, 140));
    navbar.setPosition(sf::Vector2f(0, sandboxWindow.getSize().y - 120));
    navbar.setFillColor(sf::Color(169, 169, 169));

    molecules_icon.setTexture(textures->molecules);
    ptable_icon.setTexture(textures->ptable);
    reactions_icon.setTexture(textures->reactions);
    settings_icon.setTexture(textures->settings);

    molecules_icon.setPosition(navbar.getPosition().x + 150, navbar.getPosition().y + 5);
    molecules_icon.setScale(0.5f, 0.5f);

    settings_icon.setPosition(navbar.getPosition().x + 300, navbar.getPosition().y + 5);
    settings_icon.setScale(0.5f, 0.5f);

    ptable_icon.setPosition(navbar.getPosition().x + 450, navbar.getPosition().y + 5);
    ptable_icon.setScale(0.5f, 0.5f);

    reactions_icon.setPosition(navbar.getPosition().x + 600, navbar.getPosition().y + 5);
    reactions_icon.setScale(0.5f, 0.5f);


    Slider slider1(120, 105);

    slider1.create(-273, 5721);
    slider1.setSliderValue(235);

    sf::Font font;

    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        sandboxWindow.close();
        std::cout << "Unable to find font";
    }

    selectedElementInfo.setString("");
    selectedElementInfo.setFont(font);
    selectedElementInfo.setCharacterSize(18);

    elementSymbol2Text.setString("");
    elementSymbol2Text.setFont(font);
    elementSymbol2Text.setCharacterSize(20);

    elementSymbolText.setString("");
    elementSymbolText.setFont(font);
    elementSymbolText.setCharacterSize(20);

    circleText.setString("");
    circleText.setFont(font);
    circleText.setCharacterSize(20);

    elementSymbol3Text.setString("");
    elementSymbol3Text.setFont(font);
    elementSymbol3Text.setCharacterSize(20);


    const std::vector<int> reactiveNonMetals = { getElement(-2).atomicNumber, getElement(4).atomicNumber, getElement(5).atomicNumber, getElement(6).atomicNumber, getElement(7).atomicNumber, getElement(13).atomicNumber, getElement(14).atomicNumber, getElement(15).atomicNumber, getElement(32).atomicNumber, getElement(33).atomicNumber, getElement(51).atomicNumber };
    const std::vector<int> nobleGases = { getElement(0).atomicNumber, getElement(8).atomicNumber, getElement(16).atomicNumber, getElement(34).atomicNumber, getElement(52).atomicNumber, getElement(84).atomicNumber };

    //Metaloids
    const std::vector<int> metalloids = { getElement(3).atomicNumber, getElement(12).atomicNumber, getElement(30).atomicNumber, getElement(31).atomicNumber, getElement(49).atomicNumber, getElement(50).atomicNumber, getElement(83).atomicNumber };

    //Metals
    const std::vector<int> postTransitionMetals = { getElement(11).atomicNumber,getElement(29).atomicNumber, getElement(47).atomicNumber, getElement(48).atomicNumber, getElement(79).atomicNumber, getElement(80).atomicNumber, getElement(81).atomicNumber, getElement(82).atomicNumber };
    std::vector<int> transitionMetals;
    const std::vector<int> allkalineEarthMetals = { getElement(2).atomicNumber, getElement(10).atomicNumber, getElement(18).atomicNumber, getElement(36).atomicNumber, getElement(54).atomicNumber, getElement(86).atomicNumber };
    const std::vector<int> allkaliMetals = { getElement(1).atomicNumber, getElement(9).atomicNumber, getElement(17).atomicNumber, getElement(35).atomicNumber, getElement(53).atomicNumber, getElement(85).atomicNumber };
    const std::vector<int> unknown = { getElement(107).atomicNumber, getElement(108).atomicNumber, getElement(109).atomicNumber, getElement(110).atomicNumber, getElement(111).atomicNumber, getElement(112).atomicNumber, getElement(113).atomicNumber , getElement(114).atomicNumber , getElement(115).atomicNumber , getElement(116).atomicNumber };
    const std::vector<int> moleculesIndex2 = { getElement(0).atomicNumber, getElement(6).atomicNumber, getElement(7).atomicNumber, getElement(8).atomicNumber, getElement(16).atomicNumber, getElement(34).atomicNumber, getElement(52).atomicNumber };
    std::vector<int> lanthanoids;
    std::vector<int> actinoids;


    while (sandboxWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            sandboxWindow.close();
            sandboxWindowIsOpen = true;

        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (size_t i = 0; i < circles.size(); i++) {
                    if (circles[i].shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        circles[i].isDragging = true;
                    }
                }
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (size_t i = 0; i < circles.size(); i++) {
                    circles[i].isDragging = false;
                }
            }
        }
    }
    mousePos = sf::Mouse::getPosition(sandboxWindow);
    if (ptable_icon.getGlobalBounds().contains(mousePos.x, mousePos.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        periodicTableOpen = true;
    }
    if (molecules_icon.getGlobalBounds().contains(mousePos.x, mousePos.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        moleculesMenuOpen = true;
    }
    if (settings_icon.getGlobalBounds().contains(mousePos.x, mousePos.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        settingsMenuOpen = true;
    }
    if (reactions_icon.getGlobalBounds().contains(mousePos.x, mousePos.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        reactionsMenuOpen = true;
    }
    //Open periodic table

    while (periodicTableOpen)
    {
        for (int i = 19; i <= 28; i++)
        {
            transitionMetals.push_back(getElement(i).atomicNumber);
        }
        for (int i = 37; i <= 46; i++)
        {
            transitionMetals.push_back(getElement(i).atomicNumber);
        }
        for (int i = 70; i <= 78; i++)
        {
            transitionMetals.push_back(getElement(i).atomicNumber);
        }
        for (int i = 102; i <= 106; i++)
        {
            transitionMetals.push_back(getElement(i).atomicNumber);
        }
        for (int i = 55; i <= 69; i++)
        {
            lanthanoids.push_back(getElement(i).atomicNumber);
        }
        for (int i = 87; i <= 101; i++)
        {
            actinoids.push_back(getElement(i).atomicNumber);
        }

        for (int atomicNumber : reactiveNonMetals) {
            getElement(atomicNumber).backgroundColor = sf::Color(97, 130, 100);
            getElement(atomicNumber).series = "Reactive nonmetals";
        }

        for (int atomicNumber : nobleGases) {
            getElement(atomicNumber).backgroundColor = sf::Color(217, 136, 185);
            getElement(atomicNumber).series = "Noble gases";
        }

        for (int atomicNumber : metalloids) {
            getElement(atomicNumber).backgroundColor = sf::Color(53, 162, 159);
            getElement(atomicNumber).series = "Metalloids";
        }

        for (int atomicNumber : postTransitionMetals) {
            getElement(atomicNumber).backgroundColor = sf::Color(137, 207, 243);
            getElement(atomicNumber).series = "Post-transition metals";
        }

        for (int atomicNumber : transitionMetals) {
            getElement(atomicNumber).backgroundColor = sf::Color(249, 155, 125);
            getElement(atomicNumber).series = "Transition metals";
        }

        for (int atomicNumber : allkalineEarthMetals) {
            getElement(atomicNumber).backgroundColor = sf::Color(233, 184, 36);
            getElement(atomicNumber).series = "Allkaline earth metals";
        }

        for (int atomicNumber : allkaliMetals) {
            getElement(atomicNumber).backgroundColor = sf::Color(238, 147, 34);
            getElement(atomicNumber).series = "Allkali metals";
        }
        for (int atomicNumber : lanthanoids) {
            getElement(atomicNumber).backgroundColor = sf::Color(255, 196, 54);
            getElement(atomicNumber).series = "Lanthanoids";
        }
        for (int atomicNumber : lanthanoids) {
            getElement(atomicNumber).backgroundColor = sf::Color(176, 146, 106);
            getElement(atomicNumber).series = "Actinoids";
        }
        for (int atomicNumber : unknown) {
            getElement(atomicNumber).backgroundColor = sf::Color(208, 212, 202);
            getElement(atomicNumber).series = "Unknown";
        }

        for (int i = 0; i < numElements; i++) {
            getElement(i).period = getPeriod(i + 1);
            getElement(i).group = getGroup(i + 1);
        }
        sandboxWindow.clear(sf::Color::White);
        value = slider1.getSliderValue();
        while (sandboxWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                periodicTableOpen = false;
            }
        }
        mousePos = sf::Mouse::getPosition(sandboxWindow);
        detailedView.setPosition(sf::Vector2f(1030.f, 100.f));

        infoView.setPosition(sf::Vector2f(995.f, 290.f));
        infoView.setFillColor(sf::Color(208, 212, 202));

        selectedElementInfo.setFillColor(sf::Color::Black);
        selectedElementInfo.setPosition(1010, 295);

        zoomViewText.setPosition(detailedView.getPosition().x + 5, detailedView.getPosition().y + 10);
        zoomViewText.setFillColor(sf::Color::Black);
        zoomViewText.setFont(font);
        for (int i = 0; i < numElements; i++) {
            block.setSize(sf::Vector2f(elementWidth, elementHeight));
            row = getElement(i).period - 1;
            col = getElement(i).group - 1;


            block.setPosition(col * (elementWidth + gap), row * (elementHeight + gap) + 200); // Add an offset based on the gap

            zoomstr = std::to_string(getElement(i).atomicNumber) + "\n" + getElement(i).symbol + "\n" + getElement(i).name + "\n" + std::to_string(getElement(i).weight);
            zoomViewText.setString(zoomstr);

            elementSymbolText.setString(getElement(i).symbol);
            elementSymbolText.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);
            elementSymbolText.setFillColor(getElement(i).textColor);

            block.setFillColor(getElement(i).backgroundColor);
            detailedView.setFillColor(getElement(i).backgroundColor);


            if (value <= getElement(i).meltingPoint)
            {
                getElement(i).state = "Solid";
                getElement(i).textColor = sf::Color::Black;
            }
            if (value >= getElement(i).meltingPoint)
            {
                getElement(i).state = "Liquid";
                getElement(i).textColor = sf::Color::Blue;
            }
            if (value >= getElement(i).boilingPoint)
            {
                getElement(i).state = "Gas";
                getElement(i).textColor = sf::Color::Red;
            }

            infoViewStr = "Series\t" + getElement(i).series +
                "\n\n\nState at    " + std::to_string(value) + "°C\t" + getElement(i).state +
                "\n\n\nWeight\t" + std::to_string(getElement(i).weight) +
                "\n\n\nEnergy levels\t";

            energyLevels = getElement(i).energyLevels.size();

            for (int j = 0; j < energyLevels; j++)
            {
                infoViewStr += std::to_string(getElement(i).energyLevels[j]) + " ";
            }

            infoViewStr += "\n\n\nElectronegativity \t" + std::to_string(getElement(i).electronegativity) + "\n\n\nMelting point\t" + std::to_string(getElement(i).meltingPoint) + "\n\n\nBoiling point\t" + std::to_string(getElement(i).boilingPoint) + "\n\n\nDiscovered\t" + std::to_string(getElement(i).yearDiscovery);

            selectedElementInfo.setString(infoViewStr);

            if (block.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                block.setOutlineThickness(1);
                block.setOutlineColor(sf::Color::Blue);


                sandboxWindow.draw(detailedView);
                sandboxWindow.draw(zoomViewText);
                sandboxWindow.draw(infoView);
                sandboxWindow.draw(selectedElementInfo);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    periodicTableOpen = false;
                    selectedElement.push_back(getElement(i));
                    circles.emplace_back(100, 100, 30, getElement(i).backgroundColor);
                    circleText.setString(getElement(i).symbol);
                    elementSymbols.push_back(circleText);
                    if (selectedElement.size() >= 2) {
                        if (selectedElement[selectedElement.size() - 1].symbol == selectedElement[selectedElement.size() - 2].symbol) {
                            for (int k = 0; k < moleculesIndex2.size(); k++)
                            {
                                if (selectedElement[selectedElement.size() - 1].atomicNumber == moleculesIndex2[k])
                                {
                                    Molecule newMolecule;
                                    newMolecule.abberviation = getElement(i).symbol + "2\t";
                                    molecules.push_back(newMolecule);
                                    hasIndex2 = true;

                                }
                            }
                        }
                    }
                }

            }
            else {
                block.setFillColor(getElement(i).backgroundColor);
                block.setOutlineThickness(0);
            }
            slider1.draw(sandboxWindow);
            sandboxWindow.draw(block);
            sandboxWindow.draw(elementSymbolText);
        }
        for (int i = 0; i < numLanthanoids; i++) {
            int col = i + 3;
            sf::RectangleShape block(sf::Vector2f(elementWidth, elementHeight));
            block.setFillColor(sf::Color(255, 196, 54));
            block.setPosition(col * (elementWidth + gap), block.getSize().y + 600);

            elementSymbol2Text.setString(getElement(56 + i).symbol);
            elementSymbol2Text.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);
            elementSymbol2Text.setFillColor(getElement(i + 56).textColor);

            zoomstr = std::to_string(getElement(56 + i).atomicNumber) + "\n" + getElement(56 + i).symbol + "\n" + getElement(56 + i).name + "\n" + std::to_string(getElement(56 + i).weight);
            zoomViewText.setString(zoomstr);

            infoViewStr = "Series\t" + getElement(56 + i).series +
                "\n\n\nState at    " + std::to_string(value) + "°C\t" + getElement(56 + i).state +
                "\n\n\nWeight\t" + std::to_string(getElement(56 + i).weight) +
                "\n\n\nEnergy levels\t";

            energyLevels = getElement(56 + i).energyLevels.size();

            for (int j = 0; j < energyLevels; j++)
            {
                infoViewStr += std::to_string(getElement(56 + i).energyLevels[j]) + " ";
            }

            infoViewStr += "\n\n\nElectronegativity \t" + std::to_string(getElement(56 + i).electronegativity) + "\n\n\nMelting point\t" + std::to_string(getElement(56 + i).meltingPoint) + "\n\n\nBoiling point\t" + std::to_string(getElement(56 + i).boilingPoint) + "\n\n\nDiscovered\t" + std::to_string(getElement(56 + i).yearDiscovery);

            selectedElementInfo.setString(infoViewStr);
            if (block.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                block.setOutlineThickness(1);
                block.setOutlineColor(sf::Color::Blue);
                sandboxWindow.draw(detailedView);
                sandboxWindow.draw(zoomViewText);
                sandboxWindow.draw(infoView);
                sandboxWindow.draw(selectedElementInfo);
            }
            else
            {
                block.setFillColor(sf::Color(255, 196, 54));
                block.setOutlineThickness(0);
            }
            if (value <= getElement(i + 56).meltingPoint)
            {
                getElement(i + 56).state = "Solid";
                getElement(i + 56).textColor = sf::Color::Black;
            }
            if (value >= getElement(i + 56).meltingPoint)
            {
                getElement(i + 56).state = "Liquid";
                getElement(i + 56).textColor = sf::Color::Blue;
            }
            if (value >= getElement(i + 56).boilingPoint)
            {
                getElement(i + 56).state = "Gas";
                getElement(i + 56).textColor = sf::Color::Red;
            }
            sandboxWindow.draw(block);
            sandboxWindow.draw(elementSymbol2Text);
        }

        for (int i = 0; i < numActinoids; i++) {
            int col = i + 3;
            sf::RectangleShape block(sf::Vector2f(elementWidth, elementHeight));
            block.setFillColor(sf::Color(176, 146, 106));
            block.setPosition(col * (elementWidth + gap), block.getSize().y + 670);

            elementSymbol3Text.setString(getElement(88 + i).symbol);
            elementSymbol3Text.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);
            elementSymbol3Text.setFillColor(getElement(88 + i).textColor);

            zoomstr = std::to_string(getElement(88 + i).atomicNumber) + "\n" + getElement(88 + i).symbol + "\n" + getElement(88 + i).name + "\n" + std::to_string(getElement(88 + i).weight);
            zoomViewText.setString(zoomstr);

            infoViewStr = "Series\t" + getElement(88 + i).series +
                "\n\n\nState at    " + std::to_string(value) + "°C\t" + getElement(88 + i).state +
                "\n\n\nWeight\t" + std::to_string(getElement(88 + i).weight) +
                "\n\n\nEnergy levels\t";

            energyLevels = getElement(88 + i).energyLevels.size();

            for (int j = 0; j < energyLevels; j++)
            {
                infoViewStr += std::to_string(getElement(88 + i).energyLevels[j]) + " ";
            }

            infoViewStr += "\n\n\nElectronegativity \t" + std::to_string(getElement(88 + i).electronegativity) + "\n\n\nMelting point\t" + std::to_string(getElement(88 + i).meltingPoint) + "\n\n\nBoiling point\t" + std::to_string(getElement(88 + i).boilingPoint) + "\n\n\nDiscovered\t" + std::to_string(getElement(88 + i).yearDiscovery);

            selectedElementInfo.setString(infoViewStr);
            if (block.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                block.setOutlineThickness(1);
                block.setOutlineColor(sf::Color::Blue);
                sandboxWindow.draw(detailedView);
                sandboxWindow.draw(zoomViewText);
                sandboxWindow.draw(infoView);
                sandboxWindow.draw(selectedElementInfo);
            }
            else
            {
                block.setFillColor(sf::Color(176, 146, 106));
                block.setOutlineThickness(0);
            }
            if (value <= getElement(i + 88).meltingPoint)
            {
                getElement(i + 88).state = "Solid";
                getElement(i + 88).textColor = sf::Color::Black;
            }
            if (value >= getElement(i + 88).meltingPoint)
            {
                getElement(i + 88).state = "Liquid";
                getElement(i + 88).textColor = sf::Color::Blue;
            }
            if (value >= getElement(i + 88).boilingPoint)
            {
                getElement(i + 88).state = "Gas";
                getElement(i + 88).textColor = sf::Color::Red;
            }
            sandboxWindow.draw(block);
            sandboxWindow.draw(elementSymbol3Text);
        }
        sandboxWindow.display();
    }

    sandboxWindow.clear(sf::Color::White);
    for (size_t i = 0; i < circles.size(); i++) {
        if (circles[i].isDragging) {
            circles[i].shape.setPosition(mousePos.x, mousePos.y);
        }
    }


    for (size_t i = 0; i < circles.size(); i++) {
        sf::FloatRect textBounds = elementSymbols[i].getLocalBounds();
        elementSymbols[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        elementSymbols[i].setPosition(circles[i].shape.getPosition());

        sandboxWindow.draw(circles[i].shape);
        sandboxWindow.draw(elementSymbols[i]);
        std::cout << "ds";
    }

    float lineThickness = 5.0f;
    bool connected = false;

    float distanceBetweenElements = 100.0f;
    std::vector<bool> isElementConnected(selectedElement.size(), false);

    if (selectedElement.size() >= 2) {
        for (int i = 0; i < selectedElement.size() - 1; ++i) {
            if (!isElementConnected[i]) {
                for (int j = i + 1; j < selectedElement.size(); ++j) {
                    if (!isElementConnected[j] &&
                        selectedElement[i].symbol == selectedElement[j].symbol &&
                        std::find(moleculesIndex2.begin(), moleculesIndex2.end(), selectedElement[i].atomicNumber) != moleculesIndex2.end() &&
                        std::find(moleculesIndex2.begin(), moleculesIndex2.end(), selectedElement[j].atomicNumber) != moleculesIndex2.end()) {


                        connections.push_back({ i, j });
                        isElementConnected[i] = true;
                        isElementConnected[j] = true;


                        float xOffset = distanceBetweenElements * (j - i);
                        circles[j].shape.setPosition(circles[i].shape.getPosition().x + xOffset, circles[i].shape.getPosition().y);

                        break;
                    }
                }
            }
        }


        for (const auto& connection : connections) {
            int i = connection.index1;
            int j = connection.index2;


            sf::Vector2f delta = circles[j].shape.getPosition() - circles[i].shape.getPosition();

            float length = std::sqrt(delta.x * delta.x + delta.y * delta.y);


            float rotation = std::atan2(delta.y, delta.x) * 180.0f / 3.14159265f;

            sf::RectangleShape line;
            line.setSize(sf::Vector2f(length, lineThickness));
            line.setOrigin(0, lineThickness / 2.0f);
            line.setPosition(circles[i].shape.getPosition());
            line.setRotation(rotation);
            line.setFillColor(sf::Color::Black);
            sandboxWindow.draw(line);
        }
    }


    sandboxWindow.clear(sf::Color::White);
    sandboxWindow.draw(navbar);
    sandboxWindow.draw(molecules_icon);
    sandboxWindow.draw(settings_icon);
    sandboxWindow.draw(ptable_icon);
    sandboxWindow.draw(reactions_icon);
    sandboxWindow.display();
}


void Render::UnloadTextures()
{
    delete textures;
}