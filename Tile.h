#include "TextureManager.h"
#include "Board.h"
#pragma once
#include <vector>
using namespace std;
struct Tile{
    sf::Texture hiddenTileTex;
    sf::Sprite hiddenTile;
    sf::Texture flagTex;
    sf::Sprite flag;
    sf::Texture bombTex;
    sf::Sprite bomb;
    sf::Texture revealed_tileTex;
    sf::Sprite revealed_tile;
    sf::Texture _1Tex;
    sf::Sprite _1;
    sf::Texture _2Tex;
    sf::Sprite _2;
    sf::Texture _3Tex;
    sf::Sprite _3;
    sf::Texture _4Tex;
    sf::Sprite _4;
    sf::Texture _5Tex;
    sf::Sprite _5;
    sf::Texture _6Tex;
    sf::Sprite _6;
    sf::Texture _7Tex;
    sf::Sprite _7;
    sf::Texture _8Tex;
    sf::Sprite _8;

    Tile(int _height, int  _length);
    vector <Tile*> adjacent;
    int bombTrack = 0;
    bool hidden;
    bool flagg;
    bool isItABomb;
    bool debug;
};

