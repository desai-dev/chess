#include <iostream>
#include "textdisplay.h"
#include "board.h"

using namespace std;

int main() {
    // sample makeMove
    Board b;
    b.init();
    b.makeMove(1, 0, 3, 0, Colour::Black);
}