#ifndef __PIECE_H__
#define __PIECE_H__

enum class PType { Knight, Bishop, Rook, King, Queen, Pawn };

class Piece : public Observor {
    // Alert observors that there has been a change in state
    void notifyObservors();
    // Attach an observor to the piece
    void attach(Observor *o);
    // Dettach an observor to the piece
    void dettach(Observor * o);
};

#endif