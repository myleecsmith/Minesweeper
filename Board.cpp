#include "Board.h"
#include <fstream>
#include <sstream>
#include <vector>

Board::Board() {
    ifstream File("boards/config.cfg");
    if(File.is_open()){
        string _columns;
        getline(File, _columns);
        int columns = stoi(_columns);

        string _rows;
        getline(File, _rows);
        int rows = stoi(_rows);

        string _mines;
        getline(File, _mines);

        width = columns * 32;
        height = rows * 32 + 100;
        mineCount = stoi(_mines);
        tileCount = columns * rows;


        for(int i = 0; i < columns; i++)
            boardAcross.push_back(0);

        for(int y = 0; y < rows; y++)
            TotalBoard.push_back(boardAcross);
    }
    lost = false;
    win = false;
    tilesRevealed = 0;
}

Board::Board(string filename) {
    ifstream File(filename);

    if(File.is_open()) {
        string line;
        while (getline(File, line)) {
            boardAcross.clear();
            for (int i = 0; i < line.size(); i++) {
                string charNum = line.substr(i, 1);
                int num = stoi(charNum);
                boardAcross.push_back(num);
            }
            TotalBoard.push_back(boardAcross);
        }
    }
    int mineTracker = 0;
    for(int i = 0; i < TotalBoard.size(); i++){
        for(int y = 0; y < TotalBoard[i].size(); y++)
            if(TotalBoard[i][y] == 1)
                mineTracker++;

    width = boardAcross.size() * 32;
    height = TotalBoard.size() * 32 + 100;
    mineCount = mineTracker;
    tileCount = boardAcross.size() * TotalBoard.size();
    }

    lost = false;
    win = false;
    tilesRevealed = 0;
}

int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
}

int Board::getMineCount() {
    return mineCount;
}

int Board::getTileCount() {
    return tileCount;
}

vector<int> Board::getboardAcross() {
    return boardAcross;
}

vector<vector<int>> Board::getTotalBoard() {
    return TotalBoard;
}