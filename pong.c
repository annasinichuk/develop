#include <stdio.h>
#include <math.h>

void table(int sizeX, int sizeY, int player1_score, int player2_score,
           int pl1, int pl2, int pl3, int pr1, int pr2, int pr3, int ball_x, int ball_y);
int ball_up(int ball_y);
int ball_down(int ball_y);
int ball_right(int ball_x);
int ball_left(int ball_x);
void clrscr(void);

int main() {
    int sizeX = 82, sizeY = 27;
    int player1_score = 0, player2_score = 0;
    int pl1 = 12, pl2 = 13, pl3 = 14, pr1 = 12, pr2 = 13, pr3 = 14;  // Начальные координаты ракеток
    int ball_x = 10, ball_y = 13;  // Начальные координаты мяча
    char key;
    char dir_x = 'R', dir_y = 'U';
    clrscr();
    table(sizeX, sizeY, player1_score, player2_score, pl1, pl2, pl3, pr1, pr2, pr3, ball_x, ball_y);
    do {
        key = getchar();  // Обработка нажатия клавиш
     if (key == 'z' && pl3 != 26) {
         pl1 = pl1 + 1, pl2 = pl2 + 1, pl3 = pl3 + 1;
     } else if (key == 'a' && pl1 != 2) {
         pl1 = pl1 - 1, pl2 = pl2 - 1, pl3 = pl3 - 1;
         } else if (key == 'm' && pr3 != 26) {
             pr1 = pr1 + 1, pr2 = pr2 + 1, pr3 = pr3 + 1;
         } else {
            if (key == 'k' && pr1 != 2) {
                 pr1 = pr1 - 1, pr2 = pr2 - 1, pr3 = pr3 - 1;
                 }
     }
        // Описываем движение мяча по оси X
        if (dir_x == 'R') {
            if (ball_x < (sizeX - 1)) {
                ball_x = ball_right(ball_x);
            } else {
                dir_x = 'L';
                ball_x = ball_left(ball_x);
            }
        } else {
            if (ball_x > 2) {
                ball_x = ball_left(ball_x);
            } else {
                dir_x = 'R';
                ball_x = ball_right(ball_x);
            }
        }
        // То же самое для оси Y
        if (dir_y == 'U') {
            if (ball_y > 2) {
                ball_y = ball_up(ball_y);
            } else {
                dir_y = 'D';
                ball_y = ball_down(ball_y);
            }
        } else {
            if (ball_y < (sizeY - 1)) {
                ball_y = ball_down(ball_y);
            } else {
                dir_y = 'U';
                ball_y = ball_up(ball_y);
            }
        }
        // Now we gotta check for the goal
        if (ball_x == 77 && (pr1 == ball_y || pr2 == ball_y || pr3 == ball_y)) {
            dir_x = 'L';
        } else if (ball_x == 77 && (pr1 != ball_y && pr2 != ball_y && pr3 != ball_y)) {
            player1_score += 1;
            ball_x = 62;
            ball_y = 13;
            dir_x = 'L';
        }
        if (ball_x == 6 && (pl1 == ball_y || pl2 == ball_y || pl3 == ball_y)) {
            dir_x = 'R';
        } else if (ball_x == 6 && (pl1 != ball_y && pl2 != ball_y && pl3 != ball_y)) {
            player2_score += 1;
            ball_x = 20;
            ball_y = 13;
            dir_x = 'R';
        }
        clrscr();
        table(sizeX, sizeY, player1_score, player2_score, pl1, pl2, pl3, pr1, pr2, pr3, ball_x, ball_y);
    if (player1_score == 21) {
            printf("PLAYER 1 WINS!!!");
            key = 'q';
        } else if (player2_score == 21) {
            printf("PLAYER 2 WINS!!!");
            key = 'q';
    }
} while (key !='q');
    return 0;
}
// Функция для вывода игрового поля
void table(int sizeX, int sizeY, int player1_score, int player2_score,
           int pl1, int pl2, int pl3, int pr1, int pr2, int pr3, int ball_x, int ball_y) {
    int x, y;
    int sc1_1 = 0, sc1_2 = 0, sc2_1 = 0, sc2_2 = 0;
    // for внутри for для имитации двухмерного массива (x, y)
    sc1_1 = player1_score / 10;
    sc1_2 = player1_score % 10;
    sc2_1 = player2_score / 10;
    sc2_2 = player2_score % 10;
    for (int i = 1; i <= sizeY; i++) {
        y = i;
        for (int i = 1; i <= sizeX; i++) {
            x = i;
            if (y == 1 || y == sizeY) {  // Создаем рамку по краям
                printf("█");
            } else if (x == 1 || x == sizeX) {
                printf("█");
            } else if ((x == 40 || x == 41) && (y != 1 || y != sizeY)) {
                printf("|");
            } else if ((x == 36) && y == 2) {
                printf("%d", sc1_1);
            } else if ((x == 37) && y == 2) {
                printf("%d", sc1_2);
            } else if ((x == 44) && y == 2) {
                printf("%d", sc2_1);
            } else if ((x == 45) && y == 2) {
                printf("%d", sc2_2);
            } else if ((x == 5)  && (y == pl1 || y == pl2 || y == pl3)) {
                printf("|");
            } else if (x == ball_x && y == ball_y) {
                printf("*");
            } else {
                if ((x == 78) && (y == pr1 || y == pr2 || y == pr3)) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int ball_up(int ball_y) {
    ball_y = ball_y - 1;
    return ball_y;
}

int ball_down(int ball_y) {
    ball_y = ball_y + 1;
    return ball_y;
}

int ball_right(int ball_x) {
    ball_x = ball_x + 1;
    return ball_x;
}

int ball_left(int ball_x) {
    ball_x = ball_x - 1;
    return ball_x;
}

void clrscr(void) {
    printf("\033[2J");
    printf("\033[0;0f");
    }

