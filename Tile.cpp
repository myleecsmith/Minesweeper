#include "Tile.h"

Tile::Tile(int _height, int  _length){
    hiddenTileTex.loadFromFile("images/tile_hidden.png");
    hiddenTile.setTexture(hiddenTileTex);
    hiddenTile.setPosition(_height, _length);
    flagTex.loadFromFile("images/flag.png");
    flag.setTexture(flagTex);
    flag.setPosition(_height, _length);
    bombTex.loadFromFile("images/mine.png");
    bomb.setTexture(bombTex);
    bomb.setPosition(_height, _length);
    revealed_tileTex.loadFromFile("images/tile_revealed.png");
    revealed_tile.setTexture(revealed_tileTex);
    revealed_tile.setPosition(_height, _length);
    _1Tex.loadFromFile("images/number_1.png");
    _1.setTexture(_1Tex);
    _1.setPosition(_height,_length);
    _2Tex.loadFromFile("images/number_2.png");
    _2.setTexture(_2Tex);
    _2.setPosition(_height, _length);
    _3Tex.loadFromFile("images/number_3.png");
    _3.setTexture(_3Tex);
    _3.setPosition(_height, _length);
    _4Tex.loadFromFile("images/number_4.png");
    _4.setTexture(_4Tex);
    _4.setPosition(_height, _length);
    _5Tex.loadFromFile("images/number_5.png");
    _5.setTexture(_5Tex);
    _5.setPosition(_height, _length);
    _6Tex.loadFromFile("images/number_6.png");
    _6.setTexture(_6Tex);
    _6.setPosition(_height, _length);
    _7Tex.loadFromFile("images/number_7.png");
    _7.setTexture(_7Tex);
    _7.setPosition(_height, _length);
    _8Tex.loadFromFile("images/number_8.png");
    _8.setTexture(_8Tex);
    _8.setPosition(_height, _length);

    bombTrack = 0;
    hidden = true;
    flagg = false;
    isItABomb = false;
    debug = false;
};




