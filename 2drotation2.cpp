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
    float arr[3][4];
    int c = 4;
    int ang;

    printf("Enter the coordinates of the rectangle (x1 y1 x2 y2 x3 y3 x4 y4):\n");
    for (int i = 0; i < c; i++) {
        scanf("%f %f", &arr[0][i], &arr[1][i]);
        arr[2][i] = 1; // Set homogeneous coordinate to 1
    }

    printf("Enter the angle of rotation in degrees:\n");
    scanf("%d", &ang);

    initgraph(&gd, &gm, (char*)"");

    // Original rectangle
    draw(arr, c);

    // 2D rotation matrix in homogeneous form
    float ang_rad = ang * 3.141 / 180.0;
    float arr1[3][3] = {
        {cos(ang_rad), -sin(ang_rad), 0},
        {sin(ang_rad), cos(ang_rad), 0},
        {0, 0, 1}
    };

    float arr2[3][4];
    mul(arr1, arr, arr2, c);

    // Rotated rectangle
    draw(arr2, c);

    getch();
    closegraph();
    return 0;
}
