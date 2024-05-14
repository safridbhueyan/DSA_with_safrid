#include <iostream>
#include <cmath>

using namespace std;

class GamePiece {
public:
    virtual ~GamePiece() {}
    virtual char GetPiece() const = 0;
    virtual bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol) const = 0;
};

class KnightPiece : public GamePiece {
public:
    char GetPiece() const override {
        return 'N';
    }
    bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol) const override {
        int rowDelta = abs(destRow - srcRow);
        int colDelta = abs(destCol - srcCol);
        return (rowDelta == 2 && colDelta == 1) || (rowDelta == 1 && colDelta == 2);
    }
};

class BishopPiece : public GamePiece {
public:
    char GetPiece() const override {
        return 'B';
    }
    bool AreSquaresLegal(int srcRow, int srcCol, int destRow, int destCol) const override {
        int rowDelta = abs(destRow - srcRow);
        int colDelta = abs(destCol - srcCol);
        return rowDelta == colDelta;
    }
};

int main() {
    // Example usage
    GamePiece* knight = new KnightPiece();
    GamePiece* bishop = new BishopPiece();

    // User input for source and destination coordinates
    int srcRow, srcCol, destRow, destCol;
    cout << "Enter source row: ";
    cin >> srcRow;
    cout << "Enter source column: ";
    cin >> srcCol;
    cout << "Enter destination row: ";
    cin >> destRow;
    cout << "Enter destination column: ";
    cin >> destCol;

    // Testing KnightPiece
    cout << "\nKnight Piece Legal Move:" << endl;
    cout << "From (" << srcRow << ", " << srcCol << ") to (" << destRow << ", " << destCol << "): ";
    cout << (knight->AreSquaresLegal(srcRow, srcCol, destRow, destCol) ? "Legal" : "Illegal") << endl;

    // Testing BishopPiece
    cout << "\nBishop Piece Legal Move:" << endl;
    cout << "From (" << srcRow << ", " << srcCol << ") to (" << destRow << ", " << destCol << "): ";
    cout << (bishop->AreSquaresLegal(srcRow, srcCol, destRow, destCol) ? "Legal" : "Illegal") << endl;

    delete knight;
    delete bishop;

    return 0;
}
