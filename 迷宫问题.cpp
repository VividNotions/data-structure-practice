#include <stdio.h>

int maze[105][105];
int visited[105][105];
int px[10005];
int py[10005];
int pd[10005];

int main()
{
    int n, m, i, j, top, found, d, tx, ty;
    int dx[4], dy[4];

    dx[0] = 1;
    dy[0] = 0;
    dx[1] = 0;
    dy[1] = 1;
    dx[2] = -1;
    dy[2] = 0;
    dx[3] = 0;
    dy[3] = -1;

    if (scanf("%d%d", &n, &m) != 2) {
        return 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (maze[1][1] == 1 || maze[n][n] == 1) {
        printf("There is no solution!\n");
        return 0;
    }

    top = 0;
    px[0] = 1;
    py[0] = 1;
    pd[0] = 0;
    visited[1][1] = 1;
    found = (n == 1);

    while (top >= 0 && !found) {
        if (px[top] == n && py[top] == n) {
            found = 1;
            break;
        }

        if (pd[top] < 4) {
            d = pd[top];
            pd[top]++;
            tx = px[top] + dx[d];
            ty = py[top] + dy[d];

            if (tx >= 1 && tx <= n && ty >= 1 && ty <= n &&
                maze[tx][ty] == 0 && visited[tx][ty] == 0) {
                visited[tx][ty] = 1;
                top++;
                px[top] = tx;
                py[top] = ty;
                pd[top] = 0;
            }
        } else {
            top--;
        }
    }

    if (!found) {
        printf("There is no solution!\n");
    } else {
        for (i = 0; i <= top; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("<%d,%d>", px[i], py[i]);
        }
        printf("\n");
    }

    return 0;
}
