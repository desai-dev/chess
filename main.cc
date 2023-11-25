#include <iostream>
#include "textdisplay.h"
#include "board.h"

using namespace std;

int main() {
    TextDisplay td;
    Board b;
    b.init();
    cout << td;
}