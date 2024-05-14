#include <iostream>

class GamePiece {
public:
    GamePiece(char PieceColor) : m_PieceColor(PieceColor) {}
    virtual ~GamePiece() {}
    virtual char GetPiece() = 0;
    virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) = 0;
protected:
    char m_PieceColor;
};

class KnightPiece : public GamePiece {
public:
    KnightPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~KnightPiece() {}
private:
    char GetPiece() override {
        return 'N';
    }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) override {
        // Destination square is unoccupied or occupied by opposite color
        if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
            if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) {
                return true;
            }
        }
        if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) {
            if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) {
                return true;
            }
        }
        return false;
    }
};

class BishopPiece : public GamePiece {
public:
    BishopPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~BishopPiece() {}
private:
    char GetPiece() override {
        return 'B';
    }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) override {
        if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) {
            // Make sure that all intervening squares are empty
            int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
            int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
            int iCheckRow;
            int iCheckCol;
            for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
                iCheckRow !=  iDestRow;
                iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
            {
                if (GameBoard[iCheckRow][iCheckCol] != NULL) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

int main() {
    // Sample usage
    GamePiece* board[8][8];
    board[0][0] = new KnightPiece('W');
    board[1][2] = new BishopPiece('B');

    // Example of calling methods
    if (board[0][0]->AreSquaresLegal(0, 0, 1, 2, board)) {
        std::cout << "Legal move for knight" << std::endl;
    } else {
        std::cout << "Illegal move for knight" << std::endl;
    }

    if (board[1][2]->AreSquaresLegal(1, 2, 4, 5, board)) {
        std::cout << "Legal move for bishop" << std::endl;
    } else {
        std::cout << "Illegal move for bishop" << std::endl;
    }

    // Don't forget to free memory
    delete board[0][0];
    delete board[1][2];

    return 0;
}

