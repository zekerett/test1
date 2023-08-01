#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a polygon given the vertex coordinates in homogeneous form
void draw(float arr[3][4], int c) {
    int i;
    for (i = 0; i < c; i++) {
        line(arr[0][i], arr[1][i], arr[0][(i + 1) % c], arr[1][(i + 1) % c]);
    }
}

// Function to multiply two matrices
void mul(float arr1[3][3], float arr[3][4], float arr2[3][4], int c) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < c; j++) {
            arr2[i][j] = 0;
            for (k = 0; k < 3; k++) {
                arr2[i][j] += arr1[i][k] * arr[k][j];
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    float arr[3][4] = { {200, 300, 300, 200}, {100, 100, 200, 200}, {1, 1, 1, 1} };
    int ang = 45;

    initgraph(&gd, &gm, (char*)"");

    // Original square
    draw(arr, 4);

    // 2D rotation matrix in homogeneous form
    float arr1[3][3] = {
        {cos(ang * 3.141 / 180), -sin(ang * 3.141 / 180), 0},
        {sin(ang * 3.141 / 180), cos(ang * 3.141 / 180), 0},
        {0, 0, 1}
    };

    float arr2[3][4];
    mul(arr1, arr, arr2, 4);

    // Rotated square
    draw(arr2, 4);

    getch();
    closegraph();
    return 0;
}
