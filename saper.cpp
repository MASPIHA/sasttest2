// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// saper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct Shift {
    int x = 0;
    int y = 0;
};

const std::vector<Shift> SHIFTS = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0,  1},
    { 1,  1},
    { 1,  0},
    { 1, -1},
    { 0, -1},
};

int main() {
    size_t rows = 0;
    size_t columns = 0;
    size_t mines = 0;
    
    if (!(std::cin >> rows) || !(std::cin >> columns) || !(std::cin >> mines)) {
        std::cerr << "Error, type correct integer\n";
        return 1; // Завершение программы с ошибкой
    }

    const int mineLabel = -1;

    std::vector<std::vector<int>> field(rows + 2, std::vector<int>(columns + 2, 0));

    for (size_t index = 0; index != mines; ++index) {
        int row, column;
        std::cin >> row >> column;

        if (row <= rows && column <= columns) {
            field[row][column] = mineLabel;
        }
        else {
            std::cout << "Wrong usage: row or column of bomb is bigger than rows or columns of all board";
            break;
        }
        

        for (auto shift : SHIFTS) {
            auto& cell = field[row + shift.x][column + shift.y];
            if (cell != mineLabel) {
                ++cell;
            }
        }
    }

    for (size_t row = 1; row <= rows; ++row) {
        for (size_t column = 1; column <= columns; ++column) {
            if (column > 1) {
                std::cout << " ";
            }
            if (field[row][column] == mineLabel) {
                std::cout << "*";
            }
            else {
                std::cout << field[row][column];
            }
        }
        std::cout << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
