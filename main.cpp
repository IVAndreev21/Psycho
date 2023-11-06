#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <iomanip>
#include "slider.h"
#include <sstream>
struct Element {
    std::string symbol;
    std::string name;
    int atomicNumber;
    double weight;
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

struct Molecule
{
    std::string abberviation;
    std::string name;
};


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

//Constant variables
const int numElements = 118;
const int elementsPerRow = 18;
const int elementHeight = 60;
const int numLanthanoids = 14;
const int numActinoids = 14;
const int numberMolecules = 35;
const float gap = 1;

//Changable values
int value;
int energyLevels;
int row;
int col;

//Colors
    // Define colors for different groups
sf::Color reactiveNonMetalsColor(97, 130, 100);
sf::Color nobleGasesColor(217, 136, 185);
sf::Color metalloidsColor(53, 162, 159);
sf::Color postTransitionMetalsColor(137, 207, 243);
sf::Color transitionMetalsColor(249, 155, 125);
sf::Color allkalineEarthMetalsColor(233, 184, 36);
sf::Color allkaliMetalsColor(238, 147, 34);
sf::Color unknownColor(208, 212, 202);

sf::Color grey(208, 212, 202);
sf::Color white = sf::Color::White;
sf::Color black = sf::Color::Black;
sf::Color blue = sf::Color::Blue;
sf::Color red = sf::Color::Red;
sf::Color darkGrey(169, 169, 169);


//Fonts
sf::Font font;

//sf::Texts
sf::Text text("", font, 20);
sf::Text zoomViewText("", font, 35);
sf::Text test("", font, 18);
sf::Text sbText("", font, 30);
sf::Text qmText("", font, 30);
sf::Text optionsText("", font, 30);
sf::Text mainMenuH("", font, 40);
sf::Text selectedElementText("", font, 20);

//sf::RectangleShapes
sf::RectangleShape detailedView(sf::Vector2f(180, 180));
sf::RectangleShape infoView(sf::Vector2f(250, 500));
sf::RectangleShape block;
//Menu
sf::RectangleShape sandboxModeButton;
sf::RectangleShape questModeButton;
sf::RectangleShape optionsButton;

//Strings
std::string zoomstr;
std::string infoViewText;

//Integer vectors
sf::Vector2i mousePosition;

//booleans
bool window2IsOpen = false;
bool sandboxIsOpen = false;
bool questModeIsOpen = false;
bool optionsIsOpen = false;
bool periodicTableOpen = false;
bool settingsMenuOpen = false;
bool moleculesMenuOpen = false;
bool reactionsMenuOpen = false;


//sf::textures
sf::Texture logoTexture;
sf::Texture carbonTexture;
sf::Texture ptableIconTexture;
sf::Texture settingsIconTexture;
sf::Texture moleculesIconTexture;
sf::Texture reactionsIconTexture;

//sf::sprites
sf::Sprite logoSprite;
sf::Sprite carbonSprite;
sf::Sprite ptableIconSprite;
sf::Sprite settingsIconSprite;
sf::Sprite moleculesIconSprite;
sf::Sprite reactionsIconSprite;

//sf::RenderWindows
sf::RenderWindow periodicTableWindow;
sf::RenderWindow sandboxWindow;
sf::RenderWindow mainMenuWindow;

//counters
int counter = 0;

//vectors
std::vector<Element> selectedElement;
std::vector<sf::CircleShape> circles;


Element elements[numElements] = {
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
    {"Dy","Dysprosium", 66, 162.500, {2,8,18,28,8,2}, 1.22, 1412, 2567, 1886}, {"Ho", "Holmium", 67, 164.930329, {2,8,18,29,8,2}, 1.23, 1474, 27000, 1878}, {"Er", "Erbium", 68, 167.259, {2,8,18,30,8,2}, 1.24, 1497, 2868, 1842}, {"Tm", "Thulium", 69, 168.934219, {2,8,18,31,8,2}, 1.25, 1545, 1950 , 1879}, {"Yb", "Ytterbium", 70, 173.045, {2,8,18,32,8,2}, NULL, 818.9, 1196, 1878},
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

//Non Metals
const std::vector<int> reactiveNonMetals = { elements[-2].atomicNumber, elements[4].atomicNumber, elements[5].atomicNumber, elements[6].atomicNumber, elements[7].atomicNumber, elements[13].atomicNumber, elements[14].atomicNumber, elements[15].atomicNumber, elements[32].atomicNumber, elements[33].atomicNumber, elements[51].atomicNumber };
const std::vector<int> nobleGases = { elements[0].atomicNumber, elements[8].atomicNumber, elements[16].atomicNumber, elements[34].atomicNumber, elements[52].atomicNumber, elements[84].atomicNumber };

//Metaloids
const std::vector<int> metalloids = { elements[3].atomicNumber, elements[12].atomicNumber, elements[30].atomicNumber, elements[31].atomicNumber, elements[49].atomicNumber, elements[50].atomicNumber, elements[83].atomicNumber };

//Metals
const std::vector<int> postTransitionMetals = { elements[11].atomicNumber,elements[29].atomicNumber, elements[47].atomicNumber, elements[48].atomicNumber, elements[79].atomicNumber, elements[80].atomicNumber, elements[81].atomicNumber, elements[82].atomicNumber };
std::vector<int> transitionMetals;
const std::vector<int> allkalineEarthMetals = { elements[2].atomicNumber, elements[10].atomicNumber, elements[18].atomicNumber, elements[36].atomicNumber, elements[54].atomicNumber, elements[86].atomicNumber };
const std::vector<int> allkaliMetals = { elements[1].atomicNumber, elements[9].atomicNumber, elements[17].atomicNumber, elements[35].atomicNumber, elements[53].atomicNumber, elements[85].atomicNumber };
const std::vector<int> unknown = { elements[107].atomicNumber, elements[108].atomicNumber, elements[109].atomicNumber, elements[110].atomicNumber, elements[111].atomicNumber, elements[112].atomicNumber, elements[113].atomicNumber , elements[114].atomicNumber , elements[115].atomicNumber , elements[116].atomicNumber };

Molecule molecules[numberMolecules] = {
    {"H2O", "Water"}, {"O2", "Oxygen"}, {"CO2", "Carbon Dioxide"}, {"C6H1206", "Glucose"},{"C8H10N4O2","Caffeine"},{"CH4", "Methane"},{"C2H5OH", "Ethanol"}, {"NaCl", "Salt"}, {"N2", "Nitrogen"}, {"H2O2", "Hydrogen Peroxide"}, {"CO", "Carbon Monoxide"}, {"H2SO4", "Sulfuric Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Aci"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"}, {"CH3COOH", "Acetic Acid"},
};
int main() {
    mainMenuWindow.create(sf::VideoMode(1280, 1024), "Psycho");

    sandboxModeButton.setPosition(sf::Vector2f(50, 350.0f));
    sandboxModeButton.setSize(sf::Vector2f(450.0f, 150.0f));

    questModeButton.setPosition(sf::Vector2f(50.0f, 550.0f));
    questModeButton.setSize(sf::Vector2f(450.0f, 150.0f));


    optionsButton.setPosition(50.0f, 750.0f);
    optionsButton.setSize(sf::Vector2f(450.0f, 150.0f));

    mainMenuH.setString("Psycho");
    mainMenuH.setPosition(mainMenuWindow.getSize().x / 2, 10);
    mainMenuH.setFillColor(black);

    sbText.setString("Sandbox mode");
    sbText.setPosition(sandboxModeButton.getPosition().x + 120, sandboxModeButton.getPosition().y + 60);
    sbText.setFillColor(black);

    qmText.setString("Quest mode");
    qmText.setPosition(questModeButton.getPosition().x + 120, questModeButton.getPosition().y + 60);
    qmText.setFillColor(black);

    optionsText.setString("Options");
    optionsText.setPosition(optionsButton.getPosition().x + 120, optionsButton.getPosition().y + 60);
    optionsText.setFillColor(black);

    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        return 1;
    }

    if (!logoTexture.loadFromFile("resources/images/logo.png"))
    {
        return 1;
    }

    if (!carbonTexture.loadFromFile("resources/images/carbon.png"))
    {
        return 1;
    }
    logoSprite.setTexture(logoTexture);
    logoSprite.setPosition(sandboxModeButton.getPosition().x + 50, sandboxModeButton.getPosition().y - 300);
    logoSprite.setScale(0.25, 0.25);

    carbonTexture.setSmooth(true);
    carbonSprite.setTexture(carbonTexture);
    carbonSprite.setPosition(mainMenuWindow.getSize().x / 2 + 100, mainMenuWindow.getSize().y / 2 - 200);
    carbonSprite.setScale(1.5f, 1.5f);

    while (mainMenuWindow.isOpen())
    {
        sf::Event event;
        while (mainMenuWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainMenuWindow.close();


            mousePosition = sf::Mouse::getPosition(mainMenuWindow);

            //Sandbox button
            if (sandboxModeButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                sandboxModeButton.setFillColor(red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    mainMenuWindow.close();
                    sandboxIsOpen = true;
                }
            }
            else
            {
                sandboxModeButton.setFillColor(darkGrey);

            }

            //Quest mode button
            if (questModeButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                questModeButton.setFillColor(red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    mainMenuWindow.close();
                    questModeIsOpen = true;
                }
            }
            else
            {
                questModeButton.setFillColor(darkGrey);

            }

            if (optionsButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                optionsButton.setFillColor(red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    mainMenuWindow.close();
                    optionsIsOpen = true;
                }
            }
            else
            {
                optionsButton.setFillColor(darkGrey);

            }
        }
        mainMenuWindow.clear(white);
        mainMenuWindow.draw(mainMenuH);
        mainMenuWindow.draw(sandboxModeButton);
        mainMenuWindow.draw(questModeButton);
        mainMenuWindow.draw(optionsButton);
        mainMenuWindow.draw(sbText);
        mainMenuWindow.draw(qmText);
        mainMenuWindow.draw(optionsText);
        mainMenuWindow.draw(logoSprite);
        mainMenuWindow.draw(carbonSprite);
        mainMenuWindow.display();
    }
    if (sandboxIsOpen)
    {
        sandboxWindow.create(sf::VideoMode(1280, 1024), "Periodic Table");
    }
    const int elementWidth = (sandboxWindow.getSize().x - 330) / elementsPerRow;
    //Set transition metals
    for (int i = 19; i <= 28; i++)
    {
        transitionMetals.push_back(elements[i].atomicNumber);
    }
    for (int i = 37; i <= 46; i++)
    {
        transitionMetals.push_back(elements[i].atomicNumber);
    }
    for (int i = 70; i <= 78; i++)
    {
        transitionMetals.push_back(elements[i].atomicNumber);
    }
    for (int i = 102; i <= 106; i++)
    {
        transitionMetals.push_back(elements[i].atomicNumber);
    }


    Slider slider1(120, 105);

    slider1.create(-273, 5721);
    slider1.setSliderValue(235);


    for (int atomicNumber : reactiveNonMetals) {
        elements[atomicNumber].backgroundColor = reactiveNonMetalsColor;
        elements[atomicNumber].series = "Reactive nonmetals";
    }

    for (int atomicNumber : nobleGases) {
        elements[atomicNumber].backgroundColor = nobleGasesColor;
        elements[atomicNumber].series = "Noble gases";
    }

    for (int atomicNumber : metalloids) {
        elements[atomicNumber].backgroundColor = metalloidsColor;
        elements[atomicNumber].series = "Metalloids";
    }

    for (int atomicNumber : postTransitionMetals) {
        elements[atomicNumber].backgroundColor = postTransitionMetalsColor;
        elements[atomicNumber].series = "Post-transition metals";
    }

    for (int atomicNumber : transitionMetals) {
        elements[atomicNumber].backgroundColor = transitionMetalsColor;
        elements[atomicNumber].series = "Transition metals";
    }

    for (int atomicNumber : allkalineEarthMetals) {
        elements[atomicNumber].backgroundColor = allkalineEarthMetalsColor;
        elements[atomicNumber].series = "Allkaline earth metals";
    }

    for (int atomicNumber : allkaliMetals) {
        elements[atomicNumber].backgroundColor = allkaliMetalsColor;
        elements[atomicNumber].series = "Allkali metals";
    }
    for (int atomicNumber : unknown) {
        elements[atomicNumber].backgroundColor = unknownColor;
        elements[atomicNumber].series = "Unknown";
    }

    for (int i = 0; i < numElements; i++) {
        elements[i].period = getPeriod(i + 1);
        elements[i].group = getGroup(i + 1);
    }


    //Sandbox window

    sf::RectangleShape navbar;
    navbar.setSize(sf::Vector2f(sandboxWindow.getSize().x, 140));
    navbar.setPosition(sf::Vector2f(0, sandboxWindow.getSize().y - 120));
    navbar.setFillColor(darkGrey);
    if (!ptableIconTexture.loadFromFile("resources/images/ptable_icon.png"))
    {
        return 1;
    }
    if (!settingsIconTexture.loadFromFile("resources/images/settings_icon.png"))
    {
        return 1;
    }
    if (!moleculesIconTexture.loadFromFile("resources/images/molecules_icon.png"))
    {
        return 1;
    }
    if (!reactionsIconTexture.loadFromFile("resources/images/reactions_icon.png"))
    {
        return 1;
    }
    moleculesIconSprite.setTexture(moleculesIconTexture);
    moleculesIconSprite.setPosition(navbar.getPosition().x + 150, navbar.getPosition().y + 5);
    moleculesIconSprite.setScale(0.5f, 0.5f);

    settingsIconSprite.setTexture(settingsIconTexture);
    settingsIconSprite.setPosition(navbar.getPosition().x + 300, navbar.getPosition().y + 5);
    settingsIconSprite.setScale(0.5f, 0.5f);

    ptableIconSprite.setTexture(ptableIconTexture);
    ptableIconSprite.setPosition(navbar.getPosition().x + 450, navbar.getPosition().y + 5);
    ptableIconSprite.setScale(0.5f, 0.5f);

    reactionsIconSprite.setTexture(reactionsIconTexture);
    reactionsIconSprite.setPosition(navbar.getPosition().x + 600, navbar.getPosition().y + 5);
    reactionsIconSprite.setScale(0.5f, 0.5f);
    while (sandboxWindow.isOpen())
    {
        mousePosition = sf::Mouse::getPosition(sandboxWindow);
        sf::Event event;
        while (sandboxWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sandboxWindow.close();
        }
        if (ptableIconSprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            periodicTableOpen = true;
        }
        if (moleculesIconSprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            moleculesMenuOpen = true;
        }
        if (settingsIconSprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            settingsMenuOpen = true;
        }
        if (reactionsIconSprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            reactionsMenuOpen = true;
        }
        sf::CircleShape selectedElementCircle(30); // Adjust the radius as needed
        bool hasSelected = false;
        while (periodicTableOpen)
        {
            while (sandboxWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    periodicTableOpen = false;  // Close the periodic table
                }
            }
            // check all the window's events that were triggered since the last iteration of the loop
            sandboxWindow.clear(white);
            value = slider1.getSliderValue();

            mousePosition = sf::Mouse::getPosition(sandboxWindow);
            block.setSize(sf::Vector2f(elementWidth, elementHeight));
            detailedView.setPosition(sf::Vector2f(1030.f, 100.f));

            infoView.setPosition(sf::Vector2f(995.f, 290.f));
            infoView.setFillColor(grey);

            test.setFillColor(black);
            test.setPosition(1010, 295);

            zoomViewText.setPosition(detailedView.getPosition().x + 5, detailedView.getPosition().y + 10);
            zoomViewText.setFillColor(black);
            for (int i = 0; i < numElements; i++) {

                row = elements[i].period - 1;
                col = elements[i].group - 1;


                block.setPosition(col * (elementWidth + gap), row * (elementHeight + gap) + 200); // Add an offset based on the gap

                zoomstr = std::to_string(elements[i].atomicNumber) + "\n" + elements[i].symbol + "\n" + elements[i].name + "\n" + std::to_string(elements[i].weight);
                zoomViewText.setString(zoomstr);

                text.setString(elements[i].symbol);
                text.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);
                text.setFillColor(elements[i].textColor);

                block.setFillColor(elements[i].backgroundColor);
                detailedView.setFillColor(elements[i].backgroundColor);


                if (value <= elements[i].meltingPoint)
                {
                    elements[i].state = "Solid";
                    elements[i].textColor = black;
                }
                if (value >= elements[i].meltingPoint)
                {
                    elements[i].state = "Liquid";
                    elements[i].textColor = blue;
                }
                if (value >= elements[i].boilingPoint)
                {
                    elements[i].state = "Gas";
                    elements[i].textColor = red;
                }

                infoViewText = "Series\t" + elements[i].series +
                    "\n\n\nState at    " + std::to_string(value) + "°C\t" + elements[i].state +
                    "\n\n\nWeight\t" + std::to_string(elements[i].weight) +
                    "\n\n\nEnergy levels\t";

                energyLevels = elements[i].energyLevels.size();

                for (int j = 0; j < energyLevels; j++)
                {
                    infoViewText += std::to_string(elements[i].energyLevels[j]) + " ";
                }

                infoViewText += "\n\n\nElectronegativity \t" + std::to_string(elements[i].electronegativity) + "\n\n\nMelting point\t" + std::to_string(elements[i].meltingPoint) + "\n\n\nBoiling point\t" + std::to_string(elements[i].boilingPoint) + "\n\n\nDiscovered\t" + std::to_string(elements[i].yearDiscovery);

                test.setString(infoViewText);

                if (block.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {

                    block.setOutlineThickness(1);
                    block.setOutlineColor(blue);


                    sandboxWindow.draw(detailedView);
                    sandboxWindow.draw(zoomViewText);
                    sandboxWindow.draw(infoView);
                    sandboxWindow.draw(test);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        periodicTableOpen = false;
                        selectedElement.push_back(elements[i]);
                        sf::CircleShape circle(30); // Adjust the radius as needed
                        circle.setPosition(mousePosition.x, mousePosition.y); // Adjust position as needed
                        circle.setFillColor(elements[i].backgroundColor);
                        circles.push_back(circle);
                        
                    }

                }
                else {
                    block.setFillColor(elements[i].backgroundColor);
                    block.setOutlineThickness(0);
                }
                std::string selectedElements;
                for (const Element& element : selectedElement)
                {
                    selectedElements = element.symbol;
                }
                selectedElementText.setString(selectedElements);
                selectedElementText.setFillColor(black);
                slider1.draw(sandboxWindow);
                sandboxWindow.draw(block);
                sandboxWindow.draw(text);
            }
            sandboxWindow.display();
        }
        int columnCount = 5;  // Number of columns in the table
        int rowCount = (numberMolecules + columnCount - 1) / columnCount; // Calculate the number of rows
        while (moleculesMenuOpen)
        {
            sandboxWindow.clear(white);
            while (sandboxWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    moleculesMenuOpen = false;
                }
            }
            float cellWidth = sandboxWindow.getSize().x / columnCount;
            float cellHeight = sandboxWindow.getSize().y / rowCount;
            for (int i = 0; i < numberMolecules; i++)
            {
                row = i / columnCount;
                col = i % columnCount;
                sf::RectangleShape rectangle(sf::Vector2f(200, 100));
                rectangle.setFillColor(blue);
                rectangle.setPosition(col* cellWidth, row* cellHeight);

                sf::Text text;
                text.setFont(font);
                text.setString("Name: " + molecules[i].name + "\nAbbreviation: " + molecules[i].abberviation);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);
                text.setPosition(col* cellWidth + 10, row* cellHeight + 10);
                sandboxWindow.draw(rectangle);
                sandboxWindow.draw(text);

            }
            sandboxWindow.display();
        }

        sandboxWindow.clear(white);
        for (const sf::CircleShape& circle : circles)
        {
            sandboxWindow.draw(circle);
            selectedElementText.setPosition(circle.getPosition().x + 20, circle.getPosition().y + 20);
            sf::Vector2f direction = static_cast<sf::Vector2f>(mousePosition) - circles[0].getPosition();
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            if (length > 1.0) { // Avoid division by zero
                direction /= length;
            }
            circles[0].move(2.0f * direction); // Adjust the speed as needed

        }

        sandboxWindow.draw(navbar);
        sandboxWindow.draw(ptableIconSprite);
        sandboxWindow.draw(settingsIconSprite);
        sandboxWindow.draw(moleculesIconSprite);
        sandboxWindow.draw(reactionsIconSprite);
        sandboxWindow.draw(selectedElementCircle);
        sandboxWindow.draw(selectedElementText);
        sandboxWindow.display();
    }
    return 0;
}



/*
for (int i = 0; i < numLanthanoids; i++) {
    int col = i + 3; // Adjust the column to position the Lanthanoids
    sf::RectangleShape block(sf::Vector2f(elementWidth, elementHeight));
    block.setFillColor(sf::Color::Blue);
    block.setPosition(col * elementWidth, 7 * elementHeight); // Position below the main table

    // Draw the element symbol
    sf::Text text("", font, 20);
    text.setString(elements[57 + i].symbol); // Start from atomic number 57 (La)
    text.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);

    window.draw(block);
    window.draw(text);
}
// Draw the Actinoid series (below the Lanthanoids)
for (int i = 0; i < numActinoids; i++) {
    int col = i + 3; // Adjust the column to position the Actinoids
    sf::RectangleShape block(sf::Vector2f(elementWidth, elementHeight));
    block.setFillColor(sf::Color::Blue);
    block.setPosition(col * elementWidth, 8 * elementHeight); // Position below the Lanthanoids

    // Draw the element symbol
    sf::Text text("", font, 20);
    text.setString(elements[89 + i].symbol); // Start from atomic number 89 (Ac)
    text.setPosition(block.getPosition().x + 10, block.getPosition().y + 10);

    window.draw(block);
    window.draw(text);
}
*/