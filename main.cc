#include <iostream>
#include "textdisplay.h"
#include "board.h"
#include "abstractcomputer.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"

using namespace std;

pair<int, int> getCoord(string loc) {
    // If loc is not a string a length 2, return error value
    if(loc.length() != 2) return {-1, -1};
    int row, col;
    if (isupper(loc[0])) { // Check if first letter is upper/lowercase
        col = loc[0] - 'A';
    } else {
        col = loc[0] - 'a';
    }
    
    // Extra -1 since chess board coords are 1-8
    row = loc[1] - '0' - 1;
    row = abs(loc[1] - '0' - 8);

    return {row, col};
}

PType getPType(string p) {
    char c = tolower(p[0]);
    switch (c) {
        case 'k':
            return PType::King;
        case 'q':
            return PType::Queen;
        case 'r':
            return PType::Rook;
        case 'b':
            return PType::Bishop;
        case 'n':
            return PType::Knight;
        case 'p':
            return PType::Pawn;
        default:
            return PType::Empty;
    }
    return PType::Empty;
}

int main() {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Board b;
    bool whiteTurn = true;
    int whitePlayer, blackPlayer; // 0 = human, 1-4 = computer 1-4
    double whiteScore = 0;
    double blackScore = 0;
    b.init();
    LevelOne c1{};
    LevelTwo c2{};
    LevelThree c3{};

    while (true) {
        cin >> cmd;
        if (cmd == "game") {
            // Setup players
            string wPlayer, bPlayer;
            cin >> wPlayer;
            if (wPlayer == "computer") {
                int level = -1;
                cin >> level;
                whitePlayer = level;
            } else if (wPlayer == "human") {
                whitePlayer = 0;
            }
            cin >> bPlayer;
            if (bPlayer == "computer") {
                int level = -1;
                cin >> level;
                blackPlayer = level;
            } else if (bPlayer == "human") {
                blackPlayer = 0;
            }
            
            // Start playing
            while (true) {
                cin >> cmd;
                bool validMove = true;
                if (cmd == "resign") {
                    if (whiteTurn) {
                        ++blackScore;
                    } else {
                        ++whiteScore;
                    }
                    b.init();
                    whiteTurn = true;
                    break;
                } else if (cmd == "move") {
                    if (whiteTurn) {
                        if (whitePlayer == 0) {
                            string l1, l2;
                            cin >> l1 >> l2;
                            pair<int, int> loc1 = getCoord(l1);
                            pair<int, int> loc2 = getCoord(l2);

                            validMove = b.makeMove(loc1.first, loc1.second, loc2.first, loc2.second, Colour::White);
                        } else if (whitePlayer == 1) {
                            c1.nextMove(Colour::White, b);
                        } else if (whitePlayer == 2) {
                            c2.nextMove(Colour::White, b);
                        } else if (whitePlayer == 3) {
                            c3.nextMove(Colour::White, b);
                        }
                    } else {
                        if (blackPlayer == 0) {
                            string l1, l2;
                            cin >> l1 >> l2;
                            pair<int, int> loc1 = getCoord(l1);
                            pair<int, int> loc2 = getCoord(l2);

                            validMove = b.makeMove(loc1.first, loc1.second, loc2.first, loc2.second, Colour::Black);
                        } else if (blackPlayer == 1) {
                            c1.nextMove(Colour::Black, b);
                        } else if (blackPlayer == 2) {
                            c2.nextMove(Colour::Black, b);
                        } else if (blackPlayer == 3) {
                            c3.nextMove(Colour::Black, b);
                        }
                    }
                }
                cout << b;

                if (!validMove) { // If the move is invalid, don't do any checks and don't change the colour
                    cout << "Move was invalid, please try again" << endl;
                    continue;
                }
                

                // After a move, check if won and switch colours
                int gameState;
                if (whiteTurn) {
                    gameState = b.getGameState(Colour::White);
                } else {
                    gameState = b.getGameState(Colour::Black);
                }
                
                if (gameState == 1) { // Game is won
                    if (whiteTurn) {
                        whiteScore++;
                    } else {
                        blackScore++;
                    }
                    b.init();
                    whiteTurn = true;
                    break;
                } else if (gameState == 2) { // Game is stalemate
                    whiteScore += 0.5;
                    blackScore += 0.5;
                    b.init();
                    whiteTurn = true;
                    break;
                }

                whiteTurn = !whiteTurn;


            }
            





        } else if (cmd == "setup") {
            string option;
            string secondArg;
            while (option != "done") {
                cin >> option;
                if (option == "+") {
                    string location;
                    cin >> secondArg >> location;
                    pair<int, int> loc = getCoord(location);
                    if (isupper(secondArg[0])) {
                        b.set(loc.first, loc.second, getPType(secondArg), Colour::White);
                    } else {
                        b.set(loc.first, loc.second, getPType(secondArg), Colour::Black);
                    }
                    cout << b;
                } else if (option == "-") { // Delete piece (set to empty)
                    cin >> secondArg;
                    pair<int, int> loc = getCoord(secondArg);
                    b.set(loc.first, loc.second, PType::Empty, Colour::Empty);
                    cout << b;
                } else if (option == "=") { // Set colour to make next move
                    cin >> secondArg;
                    if (secondArg == "black") {
                        whiteTurn = false;
                    } else {
                        whiteTurn = true;
                    }

                } else if (option == "done") { // Exit setup mode [NEED TO CHECK IF VALID StATE OR NOT]
                    cout << b;
                    if (b.checkValid()) {
                        break;
                    } else {
                        cout << "Board is in invalid state. Board must contain exactly one white king and exactly one black king, " <<
                        "that no pawns are on the first or last row of the board, and that neither king is in check" << endl;
                    }
                    
                } else { // Invalid command, get the line to clear buffer and restart (not sure if buffer needs to be cleared)
                    getline(cin, option);
                    cout << "Please re-enter a command in setup mode:" << endl;
                }
            }
            
        }


    }









    // sample makeMove
    // Board b;
    b.init();
    b.makeMove(1, 0, 3, 0, Colour::Black);

    // sample Set
    b.set(4, 4, PType::Bishop, Colour::Black);

    pair<int, int> loc = getCoord("h8");

    cout << loc.first << " " << loc.second << endl;


    cin >> cmd;

    // SETUP COMMAND
    if (cmd == "setup") {
        string option;
        string secondArg;
        while (option != "done") {
            cin >> option;
            if (option == "+") {
                string location;
                cin >> secondArg >> location;
                pair<int, int> loc = getCoord(location);
                if (isupper(secondArg[0])) {
                    b.set(loc.first, loc.second, getPType(secondArg), Colour::White);
                } else {
                    b.set(loc.first, loc.second, getPType(secondArg), Colour::Black);
                }
            } else if (option == "-") { // Delete piece (set to empty)
                cin >> secondArg;
                pair<int, int> loc = getCoord(secondArg);
                b.set(loc.first, loc.second, PType::Empty, Colour::Empty);
            } else if (option == "=") { // Set colour to make next move
                cin >> secondArg;
                // SET COLOUR TO GO NEXT TURN HERE

            } else if (option == "done") { // Exit setup mode [NEED TO CHECK IF VALID StATE OR NOT]
                break;
            } else { // Invalid command, get the line to clear buffer and restart (not sure if buffer needs to be cleared)
                getline(cin, option);
                cout << "Please re-enter a command in setup mode:" << endl;
            }
        }
        
    }
}