#include "Tile.h"
#include "Random.h"
using namespace std;
void drawBoard();
void revealTile(Board &board, Tile &tile);
void setParm(int num, Board &board, vector<vector<Tile>> &totTileArray);
void digitsDraw(Board &board, sf::Sprite &digits0, sf::Sprite &digits1,  sf::Sprite &digits2, sf::Sprite &digits3);
void clearBoard(Board &board, vector<vector<Tile>> &totTileArray);
int main(){
    drawBoard();
    return 0;
}

void drawBoard() {
    Board board;

    sf::Texture test1Tex;
    test1Tex.loadFromFile("images/test_1.png");
    sf::Sprite test1Sprite(test1Tex);
    test1Sprite.setPosition(board.getWidth()/2 + 32*6, board.getHeight() - 100);

    sf::Texture test2Tex;
    test2Tex.loadFromFile("images/test_2.png");
    sf::Sprite test2Sprite(test2Tex);
    test2Sprite.setPosition(board.getWidth()/2 + 32*8, board.getHeight() - 100);

    sf::Texture test3Tex;
    test3Tex.loadFromFile("images/test_3.png");
    sf::Sprite test3Sprite(test3Tex);
    test3Sprite.setPosition(board.getWidth()/2 + 32*10, board.getHeight() - 100);

    sf::Texture digitsTex;
    digitsTex.loadFromFile("images/digits.png");
    sf::Sprite digits0(digitsTex);
    sf::Sprite digits1(digitsTex);
    sf::Sprite digits2(digitsTex);
    sf::Sprite digits3(digitsTex);
    digitsDraw(board, digits0, digits1, digits2, digits3);

    sf::Texture debugTex;
    debugTex.loadFromFile("images/debug.png");
    sf::Sprite debugSprite(debugTex);
    debugSprite.setPosition(board.getWidth()/2 + 32*4, board.getHeight() - 100);

    sf::Texture face_happyTex;
    face_happyTex.loadFromFile("images/face_happy.png");
    sf::Sprite face_happy(face_happyTex);
    face_happy.setPosition(board.getWidth()/2 - 32, board.getHeight() - 100);

    sf::Texture face_loseTex;
    face_loseTex.loadFromFile("images/face_lose.png");
    sf::Sprite face_lose(face_loseTex);
    face_lose.setPosition(board.getWidth()/2 - 32, board.getHeight() - 100);

    sf::Texture face_winTex;
    face_winTex.loadFromFile("images/face_win.png");
    sf::Sprite face_win(face_winTex);
    face_win.setPosition(board.getWidth()/2 - 32, board.getHeight() - 100);


    //////////////////////////////////// CREATE WINDOW ///////////////////////////////////////////


    sf::RenderWindow window(sf::VideoMode(board.getWidth(), board.getHeight()), "MineSweeper");


    //////////////////////////////////////// TILE ASSIGNMENT /////////////////////////////////////

    vector<vector<Tile>> totTileArray;
    vector<Tile> tileArray;

    for (int boardHeight = 0; boardHeight < board.getHeight() - 100; boardHeight += 32) {
        for (int boardLength = 0; boardLength < board.getWidth(); boardLength += 32) {
            Tile tile(boardLength, boardHeight);
            tileArray.push_back(tile);
        }
        totTileArray.push_back(tileArray);
        tileArray.clear();
    }
    setParm(0, board, totTileArray);

////////////////// START OF WINDOW /////////////////
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();


////////////////// DRAWING FUNCTION ////////////////
            if(board.getMineCount() < board.flagCount){
                window.draw(digits0);
            }
            window.draw(digits1);
            window.draw(digits2);
            window.draw(digits3);
            window.draw(debugSprite);
            window.draw(test1Sprite);
            window.draw(test2Sprite);
            window.draw(test3Sprite);
            window.draw(face_happy);

            for (int boardHeight = 0; boardHeight < totTileArray.size(); boardHeight++)
                for (int boardLength = 0; boardLength < totTileArray[boardHeight].size(); boardLength++) {

                    Tile &tile = totTileArray[boardHeight][boardLength];

                    window.draw(tile.hiddenTile);
                    if (tile.debug == true)
                        if (tile.isItABomb == true)
                            window.draw(tile.bomb);

                    ////////// TILE REVELAED == FALSE ///////////
                    if (tile.hidden == true /*&& tile.debug == false*/) {
                        if (tile.flagg == true)
                            window.draw(tile.flag);


                        ///////// REVEALED TILE DRAW ////////
                    } else if (tile.hidden == false) {
                        window.draw(tile.revealed_tile);

                        ///////// BOMB DRAW /////////
                        if (tile.isItABomb)
                            window.draw(tile.bomb);
                        else {
                            if (tile.bombTrack == 1)
                                window.draw(tile._1);

                            else if (tile.bombTrack == 2)
                                window.draw(tile._2);

                            else if (tile.bombTrack == 3)
                                window.draw(tile._3);

                            else if (tile.bombTrack == 4)
                                window.draw(tile._4);

                            else if (tile.bombTrack == 5)
                                window.draw(tile._5);

                            else if (tile.bombTrack == 6)
                                window.draw(tile._6);

                            else if (tile.bombTrack == 7)
                                window.draw(tile._7);

                            else if (tile.bombTrack == 8)
                                window.draw(tile._8);
                        }
                    }
                    if (board.lost){
                        window.draw(face_lose);
                        if(tile.isItABomb) {
                            tile.hidden = false;
                            board.flagCount++;
                        }
                    }else if (board.win){
                        window.draw(face_win);
                        if(tile.isItABomb){
                            tile.flagg = true;
                            digits1.setPosition(21, board.getHeight() - 100);
                            digits1.setTextureRect(sf::IntRect(0 * 21, 0, 21, 32));
                            digits2.setPosition(42, board.getHeight() - 100);
                            digits2.setTextureRect(sf::IntRect(0 * 21, 0, 21, 32));
                            digits3.setPosition(63, board.getHeight() - 100);
                            digits3.setTextureRect(sf::IntRect(0 * 21, 0, 21, 32));
                            window.draw(digits1);
                            window.draw(digits2);
                            window.draw(digits3);
                            window.draw(tile.flag);
                        }
                    }

                }

            for (int boardHeight = 0; boardHeight < totTileArray.size(); boardHeight++)
                for (int boardLength = 0; boardLength < totTileArray[boardHeight].size(); boardLength++) {
                    Tile &tile = totTileArray[boardHeight][boardLength];

                    if (event.type == sf::Event::MouseButtonPressed) {
                        sf::Vector2f MousePos(sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y);
                        if (!board.lost) {
                            if ((tile.hidden == true && tile.isItABomb == true) || tile.isItABomb == false) {

//////////////////////////////////////// FLAGGING ////////////////////////////////////////////

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                                    if (tile.hiddenTile.getGlobalBounds().contains(MousePos)) {
                                        if (tile.flagg == true && tile.hidden) {
                                            tile.flagg = false;
                                            board.flagCount--;
                                        } else if(tile.flagg == false && tile.hidden) {
                                            tile.flagg = true;
                                            board.flagCount++;
                                        }
                                    }
                                }
                                digitsDraw(board, digits0, digits1, digits2, digits3);
////////////////////////////////////////// RECURSION /////////////////////////////////////////
                                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                    if (tile.hiddenTile.getGlobalBounds().contains(MousePos)) {
                                        revealTile(board, tile);
                                    }
                                }
                            }
                            ////////////////////// END OF MOUSE PRESSING, WHILE NOT LOSING /////////////
                        }

                /////////////////////////////////// DEBUG //////////////////////////////////////////////////
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (debugSprite.getGlobalBounds().contains(MousePos)) {
                            if (tile.debug == true)
                                tile.debug = false;
                            else
                                tile.debug = true;
                        }
                    }


////////////////////////////////////////////// GAME RESTART /////////////////////////////////////////////////
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            if (face_lose.getGlobalBounds().contains(MousePos) || face_happy.getGlobalBounds().contains(MousePos) || face_win.getGlobalBounds().contains(MousePos)) {
                                clearBoard(board, totTileArray);
                                Board newBoard;
                                board = newBoard;
                                setParm(0, board, totTileArray);
                                digitsDraw(board, digits0, digits1, digits2, digits3);
                            }
                        }
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            if (test1Sprite.getGlobalBounds().contains(MousePos)) {
                                clearBoard(board, totTileArray);
                                Board board1("boards/testboard1.brd");
                                board = board1;
                                setParm(1, board, totTileArray);
                                digitsDraw(board1, digits0, digits1, digits2, digits3);
                            }
                        }

                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            if (test2Sprite.getGlobalBounds().contains(MousePos)) {
                                clearBoard(board, totTileArray);
                                Board board2("boards/testboard2.brd");
                                board = board2;
                                setParm(2, board, totTileArray);
                                digitsDraw(board2, digits0, digits1, digits2, digits3);
                            }
                        }
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            if (test3Sprite.getGlobalBounds().contains(MousePos)) {
                                clearBoard(board, totTileArray);
                                Board board3("boards/testboard3.brd");
                                board = board3;
                                setParm(3, board, totTileArray);
                                digitsDraw(board3, digits0, digits1, digits2, digits3);
                            }
                        }
                    }
                }
            window.display();
                ////////////////////////////////// END OF MOUSE PRESSING ////////////////////////////////////
        }
        //window.display();
        //////////////////////////////// EVENT CLOSED /////////////////////////////////////
    }
    /////////////////////////////////////// WHILE WINDOW OPEN ^} ///////////////////////////////////////////
}
/////////////////////////////////////////// DRAW BOARD CLOSED //////////////////////////////////////////


void revealTile(Board &board, Tile &tile){
    if (tile.hidden && !tile.flagg) {
        tile.hidden = false;
        board.tilesRevealed++;
        if (tile.isItABomb) {
            board.lost = true;
            return;
        }
        if ((board.tilesRevealed + board.getMineCount()) == board.getTileCount()) {
            board.win = true;
            return;
        }
        if (tile.bombTrack == 0) {
            for (int i = 0; i < tile.adjacent.size(); i++)
                revealTile(board, *tile.adjacent[i]);
        }
    }
}

void setParm(int num, Board &board, vector<vector<Tile>> &totTileArray){
    cout << "set parm being called  " << num << endl;

    //////////// try to toggle between boards //////////////

    //////////////////////// CONFIG ///////////////////////////
    int mines = board.getMineCount();
    if(num == 0) {
        //Board board;
        for (int i = 0; i < mines; i++) {
            int boardHeight = (board.getHeight() - 100) / 32;
            int boardLength = board.getWidth() / 32;

            int height = Random::Int(0, boardHeight - 1);
            int width = Random::Int(0, boardLength - 1);

            if (totTileArray[height][width].isItABomb)
                i--;
            else
                totTileArray[height][width].isItABomb = true;
        }
    }

    ////////////////////////// TEST 1 //////////////////////////////

    if(num == 1) {
        Board test1 = Board("boards/testboard1.brd");
        for (int boardHeight = 0; boardHeight < test1.TotalBoard.size(); boardHeight++) {
            for (int boardLength = 0; boardLength < test1.boardAcross.size(); boardLength++) {
                if (test1.TotalBoard[boardHeight][boardLength] == 1) {
                    totTileArray[boardHeight][boardLength].isItABomb = true;
                }
            }
        }
    }

    /////////////////////////////// TEST 2 /////////////////////////////

    if(num == 2) {
        Board test2 = Board("boards/testboard2.brd");
        for (int boardHeight = 0; boardHeight < test2.TotalBoard.size(); boardHeight++) {
            for (int boardLength = 0; boardLength < test2.boardAcross.size(); boardLength++) {
                if (test2.TotalBoard[boardHeight][boardLength] == 1) {
                    totTileArray[boardHeight][boardLength].isItABomb = true;
                }
            }
        }
    }

    /////////////////////////////// TEST 3 ///////////////////////////

    if(num == 3) {
        Board test3 = Board("boards/testboard3.brd");
        for (int boardHeight = 0; boardHeight < test3.TotalBoard.size(); boardHeight++) {
            for (int boardLength = 0; boardLength < test3.boardAcross.size(); boardLength++) {
                if (test3.TotalBoard[boardHeight][boardLength] == 1) {
                    totTileArray[boardHeight][boardLength].isItABomb = true;
                }
            }
        }
    }
    //////////////////////////////////////////// PUSHBACK TILE-NEIGHBOR VEC OF POINTERS //////////////////////////////////////
    for (int boardHeight = 0; boardHeight < totTileArray.size(); boardHeight++) {
        for (int boardLength = 0; boardLength < totTileArray[boardHeight].size(); boardLength++) {
            Tile &tile = totTileArray[boardHeight][boardLength];
            int bombTrackingNumber = 0; // for num generating
            if (!totTileArray[boardHeight][boardLength].isItABomb) { //only needed for non-bomb tiles

                ///////////// UPPER EDGE CASE /////////////
                if (boardHeight != 0) {
                    if (boardLength != 0) {
                        //push back tile pointers
                        tile.adjacent.push_back(&totTileArray[boardHeight - 1][boardLength - 1]);
                        if (totTileArray[boardHeight - 1][boardLength - 1].isItABomb) {
                            bombTrackingNumber++;
                            //upperLeft
                        }
                    }
                    tile.adjacent.push_back(&totTileArray[boardHeight - 1][boardLength]);
                    if (totTileArray[boardHeight - 1][boardLength].isItABomb) {
                        bombTrackingNumber++;
                        //upperMiddle
                    }
                    if (boardLength < totTileArray[boardHeight].size() - 1) {
                        tile.adjacent.push_back(&totTileArray[boardHeight - 1][boardLength + 1]);
                        if (totTileArray[boardHeight - 1][boardLength + 1].isItABomb) {
                            bombTrackingNumber++;
                            //upperRight
                        }
                    }
                }

                //////////// LOWER EDGE CASE ////////////
                if (boardHeight < totTileArray.size() - 1) {
                    if (boardLength != 0) {
                        tile.adjacent.push_back(&totTileArray[boardHeight + 1][boardLength - 1]);
                        if (totTileArray[boardHeight + 1][boardLength - 1].isItABomb) {
                            bombTrackingNumber++;
                            //lowerLeft
                        }
                    }
                    tile.adjacent.push_back(&totTileArray[boardHeight + 1][boardLength]);
                    if (totTileArray[boardHeight + 1][boardLength].isItABomb) {
                        bombTrackingNumber++;
                        //lowerMiddle
                    }

                    if (boardLength < totTileArray[boardHeight].size() - 1) {
                        tile.adjacent.push_back(&totTileArray[boardHeight + 1][boardLength + 1]);
                        if (totTileArray[boardHeight + 1][boardLength + 1].isItABomb) {
                            bombTrackingNumber++;
                            //lowerRight
                        }
                    }
                }

                ///////////// MIDDLE EDGE CASE ////////////
                if (boardLength != 0) {
                    tile.adjacent.push_back(&totTileArray[boardHeight][boardLength - 1]);
                    if (totTileArray[boardHeight][boardLength - 1].isItABomb) {
                        bombTrackingNumber++;
                        //MiddleLeft
                    }
                }
                if (boardLength < totTileArray[boardHeight].size() - 1) {
                    tile.adjacent.push_back(&totTileArray[boardHeight][boardLength + 1]);
                    if (totTileArray[boardHeight][boardLength + 1].isItABomb) {
                        bombTrackingNumber++;
                        //MiddleRight
                    }
                }
            }
            ////////////// END OF EDGE CASES //////////////
            tile.bombTrack = bombTrackingNumber;
        }
    }
}

void digitsDraw(Board &board, sf::Sprite &digits0, sf::Sprite &digits1,  sf::Sprite &digits2, sf::Sprite &digits3){
    int digitsNum = abs(board.getMineCount() - board.flagCount);
    if (board.getMineCount() < board.flagCount) {
        digits0.setPosition(0, board.getHeight() - 100);
        digits0.setTextureRect(sf::IntRect(10 * 21, 0, 21, 32));
    }
    digits1.setPosition(21, board.getHeight() - 100);
    digits1.setTextureRect(sf::IntRect((digitsNum / 100) % 10 * 21, 0, 21, 32));
    digits2.setPosition(42, board.getHeight() - 100);
    digits2.setTextureRect(sf::IntRect((digitsNum / 10) % 10 * 21, 0, 21, 32));
    digits3.setPosition(63, board.getHeight() - 100);
    digits3.setTextureRect(sf::IntRect(digitsNum % 10 * 21, 0, 21, 32));
}
void clearBoard(Board &board, vector<vector<Tile>> &totTileArray){
    board.win = false;
    board.lost = false;
    board.mineCount = 0;
    board.flagCount = 0;
    for (auto &x: totTileArray) {
        for (auto &y: x) {
            y.isItABomb = false;
            y.bombTrack = 0;
            y.hidden = true;
            y.flagg = false;
        }
    }
}
