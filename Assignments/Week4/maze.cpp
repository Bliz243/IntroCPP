// This is a solution for both "maze" exercises: see the comments in main()
#include <iostream>

using namespace std;

enum material { wood, stone };

struct tile {
    int x, y;
    bool isWall;
    material type;
};

// Display the playground, showing the player at coordinate (x,y)
void display(tile **playground, int rows, int cols, int x, int y) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == y && j == x) {
                cout << "O";
            } else {
                switch(playground[i][j].type) {
                    case stone:
                        cout << "*";
                        break;
                    case wood:
                        cout << " ";
                        break;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    // Set to 'false' to have a 12x16 playground (first exercise)
    // Set to 'true' to read rows & cols from user (second exercise)
    bool userSize = false;

    int rows, cols;

    if (userSize) {
        cin >> rows;
        cin >> cols;
    } else {
        rows = 12;
        cols = 16;
    }

    // 'playground' is a pointer to a dynamically-allocated array of pointers
    // to 'tile' structures (one per row)
    tile **playground = new tile*[rows];
    for (int i = 0; i < rows; i++) {
        // Each pointer in the 'playground' array points to a
        // dynamically-allocated array of tiles
        playground[i] = new tile[cols];
    }

    // Set up the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(rows-1) || (i==0 && j!=3) || j==(cols-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    // Set up initial positions of the player
    int x = userSize ? (cols / 2) : 5;
    int y = userSize ? (rows / 2) : 5;

    // Display the initial maze
    display(playground, rows, cols, x , y);

    char c; // Will contain the user's input

    // Keep asking and processing player input until user provides 'q'
    while (true) {
        cin >> c;
        if (c == 'q') break;
        if (c == 'l' && x > 0      && !playground[y][x-1].isWall) x--;
        if (c == 'r' && x < cols-1 && !playground[y][x+1].isWall) x++;
        if (c == 'u' && y > 0      && !playground[y-1][x].isWall) y--;
        if (c == 'd' && y < rows-1 && !playground[y+1][x].isWall) y++;
        display(playground, rows, cols, x, y);
    }

    // Remember: everything that was created with 'new' must be 'delete'd!
    for (int i = 0; i < rows; i++) {
        delete[] playground[i];
    }
    delete[] playground;

    return 0;
}
