#include "leveltwo.h"

void LevelTwo::nextMove(Colour c, Board &b) const {
    
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
    std::cout << "BAD" << std::endl;
    // Can Check logic
    for (int i = 0; i < randMoves.size(); ++i) {
        int currentRow = randMoves[i][0];
        int currentCol = randMoves[i][1];
        int row = randMoves[i][2];
        int col = randMoves[i][3];
        bool canCheck = false;

        // make sure king does not move into check (including the case that the king captures into a check) excluding opposite king check
        Piece* tmp = b.getBoard()[row][col];
        b.getBoard()[row][col] = b.getBoard()[currentRow][currentCol];
        b.getBoard()[currentRow][currentCol] = new Empty(Colour::Empty);
        b.getBoard()[row][col]->setLocation(row, col);
        b.getBoard()[currentRow][currentCol]->setLocation(currentRow, currentCol);
        for (int j = 0; j < b.getGridSize(); j++) {
            for (int k = 0; k < b.getGridSize(); k++) {
                if (b.getBoard()[j][k]->getType() == PType::King && b.getBoard()[j][k]->IsInCheck(j, k, b) 
                 && b.getBoard()[j][k]->getColour() != c && b.getBoard()[j][k]->getColour() != Colour::Empty) {
                    canCheck = true;
                }
            }
        }
        delete b.getBoard()[currentRow][currentCol];
        b.getBoard()[currentRow][currentCol] = b.getBoard()[row][col];
        b.getBoard()[row][col] = tmp;
        b.getBoard()[currentRow][currentCol]->setLocation(currentRow, currentCol);
        tmp = nullptr;
        if (canCheck) {
            b.makeMove(currentRow, currentCol, row, col, c);
            return;
        }
        
    }
    std::cout << "ZAD" << std::endl;
    // Can capture Logic
    for (int i = 0; i < b.getGridSize(); ++i) {
        for (int j = 0; j < b.getGridSize(); ++j) {
            for (int k = 0; k < b.getGridSize(); ++k) {
                for (int l = 0; l < b.getGridSize(); ++l) {
                    if  (b.getBoard()[i][j]->getColour() == c && b.getBoard()[i][j]->isMoveValid(k, l, b)
                      && b.getBoard()[k][l]->getColour() != Colour::Empty && b.getBoard()[k][l]->getColour() != c) {
                        std::cout << i << j << k << l << b.getBoard()[i][j]->isMoveValid(k, l, b) << std::endl;
                        b.makeMove(i, j, k, l, c);
                        //return;
                    }
                }
            }
        }
    }

    // Random logic
    int random = std::rand() % randMoves.size();

    b.makeMove(randMoves[random][0], randMoves[random][1], randMoves[random][2], randMoves[random][3], c);

}

