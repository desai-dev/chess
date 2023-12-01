#include <iostream>
#include "textdisplay.h"
#include "board.h"

using namespace std;

pair<int, int> getCoord(string loc) {
    // If loc is not a string a length 2, return error value
    if(loc.length() != 2) return {-1, -1};
    int row, col;
    if (isupper(loc[0])) { // Check if first letter is upper/lowercase
        row = loc[0] - 'A';
    } else {
        row = loc[0] - 'a';
    }
    
    // Extra -1 since chess board coords are 1-8
    col = loc[1] - '0' - 1;

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
    string cmd;
    // sample makeMove
    Board b;
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