#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        current_player = 'X';
    }

    void display_board() {
        cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << '|';
            }
            cout << '\n';
            if (i < 2) cout << "  -----\n";
        }
    }

    void player_input() {
        int row, col;
        while (true) {
            cout << "Player " << current_player << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = current_player;
                break;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    }

    bool check_win() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) ||
                (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
            (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)) {
            return true;
        }
        return false;
    }

    bool check_draw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switch_player() {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    void play_game() {
        while (true) {
            display_board();
            player_input();
            if (check_win()) {
                display_board();
                cout << "Player " << current_player << " wins!\n";
                break;
            }
            if (check_draw()) {
                display_board();
                cout << "The game is a draw.\n";
                break;
            }
            switch_player();
        }
    }

    bool play_again() {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }

private:
    vector<vector<char>> board;
    char current_player;
};

int main() {
    TicTacToe game;
    do {
        game = TicTacToe();  // Reset the game
        game.play_game();
    } while (game.play_again());

    return 0;
}

