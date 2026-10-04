#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>

constexpr char elements[15] = {' ', '.', 'o', '+', '=', '*', 'B', 'O', 'X', '@', '%', '&', '#', '/', '^'};
constexpr uint32_t WIDTH = 17;
constexpr uint32_t HEIGHT = 17;

int main(int argc, char** argv) {
    std::string input;
    if(argc < 2) {
        input.assign(
            std::istreambuf_iterator<char>(std::cin),
            std::istreambuf_iterator<char>()
        );
    } else {
        input = argv[1];
    }
    std::array<std::array<int32_t, WIDTH>, HEIGHT> board{0};
    const int s_x = WIDTH / 2;
    const int s_y = HEIGHT / 2;
    int x = s_x;
    int y = s_y;
    for(unsigned char c : input) {
        for(int i = 0; i < 4; i++) {
            int direction = c & 0b11;
            c >>= 2;

            switch(direction) {
                // top-left
                case 0b00:
                    if(x > 0) --x;
                    if(y > 0) --y;
                    break;
                // up-right
                case 0b01:
                    if(x < WIDTH - 1) ++x;
                    if(y > 0) --y;
                    break;
                // down-left
                case 0b10:
                    if(x > 0) --x;
                    if(y < (HEIGHT - 1)) ++y;
                    break;
                // down-right
                case 0b11:
                    if(x < WIDTH - 1) ++x;
                    if(y < (HEIGHT - 1)) ++y;
                    break;
            }
            ++board[y][x];
        }
    }

    std::cout << "+" << std::string(WIDTH, '-') << "+" << std::endl;
    for(int row_index = 0; row_index < board.size(); ++row_index) {
        std::cout << "|";
        for(int col_index = 0; col_index < board[row_index].size(); ++col_index) {
            if(row_index == s_y && col_index == s_x) {
                std::cout << "S";
                continue;
            }

            if(row_index == y && col_index == x) {
                std::cout << "E";
                continue;
            }
            auto count = board[row_index][col_index];
            auto index = std::min<std::size_t>(count, std::size(elements) - 1);
            std::cout << elements[index];
        }
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << "+" << std::string(WIDTH, '-') << "+" << std::endl;
}
