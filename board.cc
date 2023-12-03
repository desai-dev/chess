#include <vector>
#include "board.h"
#include "king.h"
#include "empty.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "pawn.h"
#include "knight.h"

using namespace std;

Board::Board() : theBoard{vector<vector<Piece*>>(8, vector<Piece*>(8))}, td{nullptr}, gd{nullptr}, win{} {}

Board::~Board() {
    // delete text and graphics displays
    delete td;
    delete gd;

    // delete pieces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            delete theBoard[i][j];
        }
    }
}

bool Board::makeMove(int fromRow, int fromCol, int toRow, int toCol, Colour c) {
    // if its a valid move, then make the move
    if (c == theBoard[fromRow][fromCol]->getColour() && theBoard[fromRow][fromCol]->isMoveValid(toRow, toCol, *this)) {
        // save piece in case you need to undo move
        Piece* tmp = theBoard[toRow][toCol];

        theBoard[toRow][toCol] = theBoard[fromRow][fromCol];
        theBoard[fromRow][fromCol] = new Empty(Colour::Empty);
        theBoard[fromRow][fromCol]->attach(td);
        theBoard[fromRow][fromCol]->attach(gd);

        // update locations
        theBoard[fromRow][fromCol]->setLocation(fromRow, fromCol);
        theBoard[toRow][toCol]->setLocation(toRow, toCol);

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (theBoard[i][j]->getType() == PType::King && theBoard[i][j]->getColour() == c && theBoard[i][j]->IsInCheck(i, j, *this)) {
                    delete theBoard[fromRow][fromCol];
                    theBoard[fromRow][fromCol] = theBoard[toRow][toCol];
                    theBoard[toRow][toCol] = tmp;
                    tmp = nullptr;

                    // update locations
                    theBoard[fromRow][fromCol]->setLocation(fromRow, fromCol);
                    theBoard[toRow][toCol]->setLocation(toRow, toCol);
                    return false;
                }
            }
        }

        delete tmp;
        
        if (theBoard[toRow][toCol]->getType() == PType::King || theBoard[toRow][toCol]->getType() == PType::Rook) {
            theBoard[toRow][toCol]->setHasMoved();
        }

        // kingside castle
        if (theBoard[toRow][toCol]->getType() == PType::King && (toCol - fromCol == 2)) {
            // move rook
            delete theBoard[toRow][toCol - 1];
            theBoard[toRow][toCol - 1] = theBoard[toRow][toCol + 1];
            theBoard[toRow][toCol + 1] = new Empty(Colour::Empty);
            theBoard[toRow][toCol + 1]->attach(td);
            theBoard[toRow][toCol + 1]->attach(gd);

            theBoard[toRow][toCol - 1]->setLocation(toRow, toCol - 1);
            theBoard[toRow][toCol + 1]->setLocation(toRow, toCol + 1);
            theBoard[toRow][toCol + 1]->notifyObservers();
            theBoard[toRow][toCol - 1]->notifyObservers();
        }

        // queenside castle
        if (theBoard[toRow][toCol]->getType() == PType::King && (toCol - fromCol == -2)) {
            // move rook
            delete theBoard[toRow][toCol + 1];
            theBoard[toRow][toCol + 1] = theBoard[toRow][toCol - 2];
            theBoard[toRow][toCol - 2] = new Empty(Colour::Empty);
            theBoard[toRow][toCol - 2]->attach(td);
            theBoard[toRow][toCol - 2]->attach(gd);

            theBoard[toRow][toCol + 1]->setLocation(toRow, toCol + 1);
            theBoard[toRow][toCol - 2]->setLocation(toRow, toCol - 2);
            theBoard[toRow][toCol + 1]->notifyObservers();
            theBoard[toRow][toCol - 2]->notifyObservers();
        }

        // notify observers
        theBoard[fromRow][fromCol]->notifyObservers();
        theBoard[toRow][toCol]->notifyObservers();
        return true;
    }

    return false;
};

std::vector<std::vector<Piece*>> Board::getBoard() {
    return theBoard;
}

int Board::getGridSize() {
    return gridSize;
}


void Board::init() {
    // initialize members
    td = new TextDisplay{};
    gd = new GraphicsDisplay{win};

    // set empty squares
    for (int i = 2; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j] = new Empty(Colour::Empty);
        }
    }

    // set the black pieces
    theBoard[0][0] = new Rook(Colour::Black);
    theBoard[0][1] = new Knight(Colour::Black);
    theBoard[0][2] = new Bishop(Colour::Black);
    theBoard[0][3] = new Queen(Colour::Black);
    theBoard[0][4] = new King(Colour::Black);
    theBoard[0][5] = new Bishop(Colour::Black);
    theBoard[0][6] = new Knight(Colour::Black);
    theBoard[0][7] = new Rook(Colour::Black);

    for (int i = 0; i < gridSize; i++) {
        theBoard[1][i] = new Pawn(Colour::Black);
    }

    // set the white pieces
    theBoard[7][0] = new Rook(Colour::White);
    theBoard[7][1] = new Knight(Colour::White);
    theBoard[7][2] = new Bishop(Colour::White);
    theBoard[7][3] = new Queen(Colour::White);
    theBoard[7][4] = new King(Colour::White);
    theBoard[7][5] = new Bishop(Colour::White);
    theBoard[7][6] = new Knight(Colour::White);
    theBoard[7][7] = new Rook(Colour::White);

    for (int i = 0; i < gridSize; i++) {
        theBoard[6][i] = new Pawn(Colour::White);
    }

    // attatch observers and set location of pieces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j]->setLocation(i, j);
            theBoard[i][j]->attach(td);
            theBoard[i][j]->attach(gd);
        }
    }
};

void Board::set(int row, int col, PType p, Colour c) {
    // Delete old piece at [row][col]
    delete theBoard[row][col];    
    
    // Create new piece at [row][col]
    switch (p) {
        case PType::King:
            theBoard[row][col] = new King(c);
            break;
        case PType::Queen:
            theBoard[row][col] = new Queen(c);
            break;
        case PType::Rook:
            theBoard[row][col] = new Rook(c);
            break;
        case PType::Bishop:
            theBoard[row][col] = new Bishop(c);
            break;
        case PType::Knight:
            theBoard[row][col] = new Knight(c);
            break;
        case PType::Pawn:
            theBoard[row][col] = new Pawn(c);
            break;
        default:
            theBoard[row][col] = new Empty(c);
            break;
    }

    // Add observer, update location, notify observer
        theBoard[row][col]->attach(td);
        theBoard[row][col]->attach(gd);
        theBoard[row][col]->setLocation(row, col);
        theBoard[row][col]->notifyObservers();
}

bool Board::checkValid() const {
    // Need to check 1 white king, 1 black king
    // No pawns on first and last row
    // Neither king is in check
    int whiteKingNum = 0;
    int blackKingNum = 0;
    bool pawnEndRows = false;
    bool whiteKingCheck = false;
    bool blackKingCheck = false;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (theBoard[i][j]->getType() == PType::King) {
                if (theBoard[i][j]->getColour() == Colour::White) {
                    whiteKingNum++;
                } else if (theBoard[i][j]->getColour() == Colour::Black) {
                    blackKingNum++;
                }
            }
        }
    }

    for (int i = 0; i < gridSize; ++i) {
        if (theBoard[0][i]->getType() == PType::Pawn) {
            pawnEndRows = true;
        } else if (theBoard[gridSize - 1][i]->getType() == PType::Pawn) {
            pawnEndRows = true;
        }
    }

    if (pawnEndRows || whiteKingNum != 1 || blackKingNum != 1) {
        return false;
    }

    return true;
}

void Board::clear() {
    // set empty squares
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            delete theBoard[i][j];
            theBoard[i][j] = new Empty(Colour::Empty);
        }
    }
    // Set kings
    delete theBoard[0][4];
    delete theBoard[7][4];
    theBoard[0][4] = new King(Colour::Black);
    theBoard[7][4] = new King(Colour::White);

    // attatch observers and set location of pieces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j]->setLocation(i, j);
            theBoard[i][j]->attach(td);
            theBoard[i][j]->attach(gd);
            theBoard[i][j]->notifyObservers();
        }
    }
    

}

int Board::getGameState(Colour c) {
    bool stalemate = false;
    bool inCheck = false;
    bool blockCheck = false;

    // Generate all possible moves
    std::vector<std::vector<int>> moves;

    for (int i = 0; i < getGridSize(); ++i) {
        for (int j = 0; j < getGridSize(); ++j) {
            for (int k = 0; k < getGridSize(); ++k) {
                for (int l = 0; l < getGridSize(); ++l) {
                    if  (theBoard[i][j]->getColour() == c && theBoard[i][j]->isMoveValid(k, l, *this)) {
                        std::vector<int> m = {i,j,k,l};
                        moves.emplace_back(m);
                    }
                }
            }
        }
    }
    // If no moves can be made, stalemate
    if (moves.size() == 0) {
        stalemate = true;
    }

    // If king in current position is in check
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (theBoard[i][j]->getType() == PType::King && theBoard[i][j]->getColour() == c && theBoard[i][j]->IsInCheck(i, j, *this)) {
                inCheck = true;
                break;
            }
        }
    }

    for (int i = 0; i < moves.size(); ++i) {
        int currentRow = moves[i][0];
        int currentCol = moves[i][1];
        int row = moves[i][2];
        int col = moves[i][3];

        // make sure king does not move into check (including the case that the king captures into a check) excluding opposite king check
        Piece* tmp = theBoard[row][col];
        theBoard[row][col] = theBoard[currentRow][currentCol];
        theBoard[currentRow][currentCol] = new Empty(Colour::Empty);
        theBoard[row][col]->setLocation(row, col);
        theBoard[currentRow][currentCol]->setLocation(currentRow, currentCol);
        for (int j = 0; j < gridSize; j++) {
            for (int k = 0; k < gridSize; k++) {
                if (theBoard[j][k]->getType() == PType::King && theBoard[j][k]->getColour() == c && !theBoard[j][k]->IsInCheck(j, k, *this)) {
                    blockCheck = true;
                    //cout << currentRow << currentCol << row << col << endl;
                }
            }
        }
        delete theBoard[currentRow][currentCol];
        theBoard[currentRow][currentCol] = theBoard[row][col];
        theBoard[row][col] = tmp;
        theBoard[currentRow][currentCol]->setLocation(currentRow, currentCol);
        tmp = nullptr;
        
    }
    if ((inCheck && !blockCheck) || (stalemate && inCheck)) {
        return 1;
    } else if (stalemate && !inCheck) {
        return 2;
    } else if (inCheck) {
        return 3;
    }
    return 0;
};

ostream &operator<<(ostream &out, const Board &b) {
    out << *b.td;
    return out;
}
