#include "leveltwo.h"

void LevelTwo::nextMove(Colour c, Board &b) const {
    

    for (int i = 0; i < b.getGridSize(); ++i) {
        for (int j = 0; j < b.getGridSize(); ++j) {
            for (int k = 0; k < b.getGridSize(); ++k) {
                for (int l = 0; l < b.getGridSize(); ++l) {
                    if  (b.getBoard()[i][j]->getColour() == c && b.getBoard()[i][j]->isMoveValid(k, l, b)
                      && b.getBoard()[k][l]->getColour() != Colour::Empty && b.getBoard()[k][l]->getColour() != c) {
                        b.makeMove(i, j, k, l, c);
                        return;
                    } // NEED TO ADD CHECK LOGIC
                }
            }
        }
    }
    
    
    
    
    
    
    
    // Generate all random moves
    std::vector<std::vector<int>> randMoves;

    for (int i = 0; i < b.getGridSize(); ++i) {
        for (int j = 0; j < b.getGridSize(); ++j) {
            for (int k = 0; k < b.getGridSize(); ++k) {
                for (int l = 0; l < b.getGridSize(); ++l) {
                    if  (b.getBoard()[i][j]->getColour() == c && b.getBoard()[i][j]->isMoveValid(k, l, b)) {
                        std::vector<int> m = {i,j,k,l};
                        randMoves.emplace_back(m);
                    }
                }
            }
        }
    }




    // Call Board's make move
}

