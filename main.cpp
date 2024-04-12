#include <iostream>

void printField(char field[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool canAddSymbolHere(char field[3][3], int x, int y) {
    return (!(field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o'));
}

bool checkInput(char xInput, char yInput) {
    return (!((xInput <= '0' || xInput > '3') || (yInput <= '0' || yInput > '3')));
}

bool isWinner(char field[3][3], char symbol) {
    return (
            (field[0][0] == symbol && field[0][1] == symbol && field[0][2] == symbol)
            || (field[1][0] == symbol && field[1][1] == symbol && field[1][2] == symbol)
            || (field[2][0] == symbol && field[2][1] == symbol && field[2][2] == symbol)
            || (field[0][0] == symbol && field[1][1] == symbol && field[2][2] == symbol)
            || (field[2][0] == symbol && field[1][1] == symbol && field[0][2] == symbol)
            || (field[0][0] == symbol && field[1][0] == symbol && field[2][0] == symbol)
            || (field[0][1] == symbol && field[1][1] == symbol && field[2][1] == symbol)
            || (field[0][2] == symbol && field[1][2] == symbol && field[2][2] == symbol)
    );
}


int main() {
    char field[3][3] = {{'.', '.', '.'},
                        {'.', '.', '.'},
                        {'.', '.', '.'}};
    int x = 0, y = 0;
    char gamerName = 'x';
    int count = 0;
    char xInput, yInput;

    while (count < 9) {
        std::cout << "Please, enter coordinates:" << std::endl;
        std::cin >> xInput;
        std::cin >> yInput;

        if (checkInput(xInput, yInput)) {
            x = xInput - '0';
            y = yInput - '0';
            if (canAddSymbolHere(field, x, y)) {
                field[x - 1][y - 1] = gamerName;
                count++;
                printField(field);
                if (isWinner(field, gamerName)) {
                    std::cout << "Congratulations! " << gamerName << " is winner!";
                    break;
                }
                gamerName = gamerName == 'x' ? 'o' : 'x';
            } else {
                std::cout << "It's already busy here. Try again." << std::endl;
            }
        } else {
            std::cout << "Wrong input, you can enter from 1 to 3." << std::endl;
        }
    }
    if (count == 9 && !isWinner(field,gamerName)) {
        std::cout << "It's a draw!";
    }
}
