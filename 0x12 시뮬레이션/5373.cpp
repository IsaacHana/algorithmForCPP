#include <bits/stdc++.h>
using namespace std;

int cube[5][5][5];

const char WHITE = 'w';
const char GREEN = 'g';
const char YELLOW = 'y';
const char BLUE = 'b';
const char ORANGE = 'o';
const char RED = 'r';

void rotateClock() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[0][i][j] = cube[0][i][j];
            tmp[1][i][j] = cube[1][i][j];
        }
    }
    // 0, 0, 0 => 5, 0, 0
    // 0, 0, 1 => 4, 0, 0
    // 0, 0, 2 => 3, 0, 0
    // 0, 1, 1 => 4, 1, 0
    // 0, 3, 1 => 4, 3, 0

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cube[0][i][j] = tmp[0][5 - 1 - j][i];
            cube[1][i][j] = tmp[1][5 - 1 - j][i];
        }
    }
}

void rotateCClock() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[0][i][j] = cube[0][i][j];
            tmp[1][i][j] = cube[1][i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cube[0][5 - 1 - j][i] = tmp[0][i][j];
            cube[1][5 - 1 - j][i] = tmp[1][i][j];
        }
    }
}

void rotateCubeRight() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }
    // 0, 0, 0 => 4, 0, 0
    // 0, 0, 1 => 3, 0, 0
    // 0, 0, 2 => 2, 0, 0
    // 0, 1, 1 => 3, 1, 0
    // 0, 1, 3 => 1, 1, 0
    // 1, 1, 4 => 0, 1, 1

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cube[i][j][k] = tmp[5 - 1 - k][j][i];
            }
        }
    }
}

void rotateCubeLeft() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cube[5 - 1 - k][j][i] = tmp[i][j][k];
            }
        }
    }
}

void rotateCubeBack() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }
    // 0, 0, 0 => 4, 0, 0
    // 0, 2, 2 => 2, 0, 2
    // 0, 1, 1 => 3, 0, 1

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cube[i][j][k] = tmp[5 - 1 - j][i][k];
            }
        }
    }
}

void rotateCubeFront() {
    int tmp[5][5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cube[5 - 1 - j][i][k] = tmp[i][j][k];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // for (int j = 1; j <= 3; j++) {
    //     for (int k = 1; k <= 3; k++) {
    //         cube[0][j][k] = 1;
    //     }
    // }

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (i == 0) {
                    cube[0][j][k] = WHITE;
                } else if (i == 1) {
                    cube[0][j][k] = GREEN;
                } else if (i == 2) {
                    cube[0][j][k] = YELLOW;
                } else if (i == 3) {
                    cube[0][j][k] = BLUE;
                }
            }
        }
        rotateCubeRight();
    }

    rotateCubeBack();
    for (int j = 1; j <= 3; j++) {
        for (int k = 1; k <= 3; k++) {
            cube[0][j][k] = ORANGE;
        }
    }
    rotateCubeBack();
    rotateCubeBack();

    for (int j = 1; j <= 3; j++) {
        for (int k = 1; k <= 3; k++) {
            cube[0][j][k] = RED;
        }
    }
    rotateCubeBack();
    // rotateClock();

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         for (int k = 0; k < 5; k++) {
    //             cout << (char)cube[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    int origin_cube[5][5][5] = {};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                origin_cube[i][j][k] = cube[i][j][k];
            }
        }
    }

    int n, m;
    string cmd;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    cube[i][j][k] = origin_cube[i][j][k];
                }
            }
        }

        cin >> m;

        while (m--) {
            cin >> cmd;
            int dir = cmd[0];
            int rodir = cmd[1];

            if (dir == 'L') {
                rotateCubeRight();
            } else if (dir == 'R') {
                rotateCubeLeft();
            } else if (dir == 'F') {
                rotateCubeFront();
            } else if (dir == 'B') {
                rotateCubeBack();
            } else if (dir == 'U') {
            } else if (dir == 'D') {
                rotateCubeBack();
                rotateCubeBack();
            }

            if (rodir == '+') {
                rotateClock();
            } else if (rodir == '-') {
                rotateCClock();
            }

            if (dir == 'L') {
                rotateCubeLeft();
            } else if (dir == 'R') {
                rotateCubeRight();
            } else if (dir == 'F') {
                rotateCubeBack();
            } else if (dir == 'B') {
                rotateCubeFront();
            } else if (dir == 'U') {
            } else if (dir == 'D') {
                rotateCubeBack();
                rotateCubeBack();
            }
        }
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                cout << (char)cube[0][j][k];
            }
            cout << '\n';
        }
    }
}
