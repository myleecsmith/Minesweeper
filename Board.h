#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Board{
    int width=0;
    int height=0;
    int tileCount;
public:
    int mineCount;
    bool lost;
    bool win;
    vector<vector<int>> TotalBoard;
    vector<int> boardAcross;
    Board();
    Board(string filename);
    int getWidth();
    int getHeight();
    int getMineCount();
    int getTileCount();
    int flagCount = 0;
    int bombCount = 0;
    int tilesRevealed = 0;
    vector<vector<int>> getTotalBoard();
    vector<int> getboardAcross();
};
