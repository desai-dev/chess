#include "levelthree.h"

void LevelThree::nextMove(Colour c, Board &b, bool inCheck) const {
    // Generate all random moves
    std::vector<std::vector<int>> randMoves;
    std::vector<std::vector<int>> checkCaptureMoves;
    std::vector<std::vector<int>> avoidCaptureGoodMoves;
    std::vector<std::vector<int>> avoidCaptureMoves;

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
    checkCaptureMoves = b.getCheckMoves(randMoves, c);
    // Can capture Logic
    for (int i = 0; i < b.getGridSize(); ++i) {
        for (int j = 0; j < b.getGridSize(); ++j) {
            for (int k = 0; k < b.getGridSize(); ++k) {
                for (int l = 0; l < b.getGridSize(); ++l) {
                    if  (b.getBoard()[i][j]->getColour() == c && b.getBoard()[i][j]->isMoveValid(k, l, b)
                      && b.getBoard()[k][l]->getColour() != Colour::Empty && b.getBoard()[k][l]->getColour() != c) {
                        std::vector<int> m = {i,j,k,l};
                        checkCaptureMoves.emplace_back(m);
                    }
                }
            }
        }
    }

    // Pick a good move that avoids capture

    avoidCaptureGoodMoves = b.getAvoidCaptureMoves(checkCaptureMoves, c);

    if (inCheck) {
        avoidCaptureGoodMoves = b.filterCheck(avoidCaptureGoodMoves, c);
    }
        

    if (avoidCaptureGoodMoves.size() > 0) {
        int random = std::rand() % avoidCaptureGoodMoves.size();

        b.makeMove(avoidCaptureGoodMoves[random][0], avoidCaptureGoodMoves[random][1], avoidCaptureGoodMoves[random][2], avoidCaptureGoodMoves[random][3], c);
        return;
    }

    avoidCaptureMoves = b.getAvoidCaptureMoves(randMoves, c);

    if (inCheck) {
        avoidCaptureMoves = b.filterCheck(avoidCaptureMoves, c);
    }

    if (avoidCaptureMoves.size() > 0) {
        int random = std::rand() % avoidCaptureMoves.size();

        b.makeMove(avoidCaptureMoves[random][0], avoidCaptureMoves[random][1], avoidCaptureMoves[random][2], avoidCaptureMoves[random][3], c);
        return;
    }

    if (inCheck) {
        checkCaptureMoves = b.filterCheck(checkCaptureMoves, c);
        randMoves = b.filterCheck(randMoves, c);
    }

    if (checkCaptureMoves.size() > 0) {
        int random = std::rand() % checkCaptureMoves.size();

        b.makeMove(checkCaptureMoves[random][0], checkCaptureMoves[random][1], checkCaptureMoves[random][2], checkCaptureMoves[random][3], c);
    } else {
        // Random logic
        int random = std::rand() % randMoves.size();

        b.makeMove(randMoves[random][0], randMoves[random][1], randMoves[random][2], randMoves[random][3], c);
    }
}

