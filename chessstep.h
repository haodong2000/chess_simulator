#ifndef CHESSSTEP_H
#define CHESSSTEP_H

struct chessStep {
    int _chessNum;
    int _chessNumber;
    bool _chessCamp;
    int _deltaX;
    int _deltaY;
    bool _isKill = false;
    int _chessKilledNum = -1;
    int _chessKilledNumber = -1;
    chessStep(int ChessNum, int ChessNumber, bool camp,
              int DeltaX, int DeltaY,
              bool Kill = false, int ChessKilledNum = -1, int ChessKilledNumber = -1):_chessNum(ChessNum),
                                                                    _chessNumber(ChessNumber),
                                                                    _chessCamp(camp),
                                                                    _deltaX(DeltaX),
                                                                    _deltaY(DeltaY),
                                                                    _isKill(Kill),
                                                                    _chessKilledNum(ChessKilledNum),
                                                                    _chessKilledNumber(ChessKilledNumber){};
    void initChessStep(int ChessNum, int ChessNumber, bool camp,
                       int DeltaX, int DeltaY,
                       bool Kill = false, int ChessKilledNum = -1, int ChessKilledNumber = -1) {
        this->_chessNum = ChessNum;
        this->_chessNumber = ChessNumber;
        this->_chessCamp = camp;
        this->_deltaX = DeltaX;
        this->_deltaY = DeltaY;
        this->_isKill = Kill;
        this->_chessKilledNum = ChessKilledNum;
        this->_chessKilledNumber = ChessKilledNumber;
    };
};

#endif // CHESSSTEP_H
