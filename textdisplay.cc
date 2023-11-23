#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay() : theBoard{vector<vector<char>>(8, vector<char>(8))} {
    string whitePieces = "rnbqkbnr";
    string blackPieces = "RNBQKBNR";

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if ((i + j) % 2 == 0) {
                theBoard[i][j] = ' ';
            } else {
                theBoard[i][j] = '_';
            }

            if (i == 0) {
                theBoard[i][j] = whitePieces[j];
            } else if (i == 1) {
                theBoard[i][j] = 'P';
            } else if (i == boardSize - 1) {
                theBoard[i][j] = blackPieces[j];
            } else if (i == boardSize - 2) {
                theBoard[i][j] = 'p';
            }
        }
    }
}

void TextDisplay::notify(Piece &p) {
    pair<int, int> loc = p.getLocation();
    PType t = p.getType();

    // MAKE A SPECIAL CASE FOR CASTLING

    if (t == PType::Knight) {
        theBoard[loc.first][loc.second] = 'n';
    } else if (t == PType::Bishop) {
        theBoard[loc.first][loc.second] = 'b';
    } else if (t == PType::Rook) {
        theBoard[loc.first][loc.second] = 'r';
    } else if (t == PType::King) {
        theBoard[loc.first][loc.second] = 'k';
    } else if (t == PType::Queen) {
        theBoard[loc.first][loc.second] = 'q';
    } else if (t == PType::Pawn) {
        theBoard[loc.first][loc.second] = 'p';
    } else {
        if ((loc.first + loc.second) % 2 == 0) {
            theBoard[loc.first][loc.second] = ' ';
        } else {
            theBoard[loc.first][loc.second] = '_';
        }
    }

    if (p.getColour() == Colour::White) {
        theBoard[loc.first][loc.second] -= 32;
    }
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int i = 0; i < td.boardSize; ++i) {
    for (int j = 0; j < td.boardSize; ++j) {
      out << td.theBoard[i][j];
      if (j == td.boardSize - 1) out << endl;
    }
  }
  
  return out;
}
