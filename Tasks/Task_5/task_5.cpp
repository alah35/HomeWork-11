#include "task_5.h"

void task5() {
    std::string line1, line2, line3;
    std::cout << "Enter the playing field state:\n";
    std::cin >> line1 >> line2 >> line3;
    const int SIZE_FIELD = 3;
    std::string field[SIZE_FIELD] = {line1, line2, line3};
    outputField(field);
    if (!isValidField(field))
        std::cout << "Incorrect";
    else
        std::cout << getWinner(field);
}

void outputField(std::string *s) {
    for (int i = 0; i < s->length(); i++) {
        for (int j = 0; j < s[i].length(); j++) {
            std::cout << s[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

char getElem(std::string *s, int x, int y) {
    return s[x][y];
}

std::string getLine(std::string *s, int x) {
    std::string line;
    for (int j = 0; j < s[x].length(); j++) {
        line += s[x][j];
    }
    return line;
}

std::string getColumn(std::string *s, int x) {
    std::string column;
    for (int i = 0; i < s->length(); i++) {
        column += s[i][x];
    }
    return column;
}

bool isWinnerInLine(std::string s) {
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1])
            continue;
        else
            return false;
    }
    return true;
}

bool isWinnerInDiagonal1(std::string *s) {
    for (int i = 1; i < s->length(); i++) {
        if (s[i][i] == s[i - 1][i - 1])
            continue;
        else
            return false;
    }
    return true;
}

bool isWinnerInDiagonal2(std::string *s) {
    for (int i = 0, j = s[i].length() - 1; i < s->length() - 1 && j > 0; i++, j--) {
        if (s[i][j] == s[i + 1][j - 1])
            continue;
        else
            return false;
    }
    return true;
}

int getAmountOfSym(std::string *s, char ch) {
    int counter = 0;
    for (int i = 0; i < s->length(); i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == ch)
                counter++;
        }
    }
    return counter;
}

std::string getWinner(std::string *s) {
    char winner = ' ';
    for (int i = 0; i < s->length(); i++) {
        if (isWinnerInLine(getLine(s, i)) || isWinnerInLine(getColumn(s, i)))
            winner = getElem(s, i, i);
    }
    if (isWinnerInDiagonal1(s))
        winner = s[0][0];
    if (isWinnerInDiagonal2(s))
        winner = s[0][s[0].length() - 1];

    if (winner == 'X')
        return "Petya won";
    else if (winner == 'O')
        return "Vanya won";
    else
        return "Nobody";
}

bool isValidField(std::string *s) {
    for (int i = 0; i < s->length(); i++){
        for (int j = 0; j < s[i].length(); j++){
            if (s[i][j] != 'O' && s[i][j] != 'X' && s[i][j] != '.')
                return false;
        }
    }

    int amountWinsX = 0, amountWinsO = 0;
    for (int i = 0; i < s->length(); i++) {
        if (isWinnerInLine(getLine(s, i))) {
            if (getElem(s, i, i) == 'X')
                amountWinsX++;
            if (getElem(s, i, i) == 'O')
                amountWinsO++;
        }
        if (isWinnerInLine(getColumn(s, i))) {
            if (getElem(s, i, i) == 'X')
                amountWinsX++;
            if (getElem(s, i, i) == 'O')
                amountWinsO++;
        }
    }

    if (isWinnerInDiagonal1(s)) {
        if (getElem(s, 0, 0) == 'X')
            amountWinsX++;
        if (getElem(s, 0, 0) == 'O')
            amountWinsO++;
    }
    if (isWinnerInDiagonal2(s)) {
        if (getElem(s, s->length(), s->length()) == 'X')
            amountWinsX++;
        if (getElem(s, s->length(), s->length()) == 'O')
            amountWinsO++;
    }

    if ( (amountWinsX > 0 && amountWinsO != 0) || (amountWinsO > 0 && amountWinsX != 0)
        || amountWinsX >=3 || amountWinsO >= 3)
        return false;

    if (amountWinsX > 0 && (getAmountOfSym(s, 'O') >= getAmountOfSym(s, 'X')))
        return false;
    if (amountWinsO > 0 && (getAmountOfSym(s, 'X') > getAmountOfSym(s, 'O')))
        return false;
    if (getAmountOfSym(s, 'O') > getAmountOfSym(s, 'X'))
        return false;

    return true;
}