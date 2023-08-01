#include <stdio.h>
#include <graphics.h>

// Function to draw a 2D object (polygon) given the vertex coordinates
void drawObject(float arr[][3], int n) {
    int i;
    for (i = 0; i < n; i++) {
        line(arr[i][0], arr[i][1], arr[(i + 1) % n][0], arr[(i + 1) % n][1]);
    }
}

// Function to perform 2D scaling
void scale(float arr[][3], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        arr[i][0] *= sx * arr[i][2];
        arr[i][1] *= sy * arr[i][2];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Define the 2D object (a polygon) as a 2D array with homogeneous coordinates
    int num_points = 4;
    float object[4][3] = { {200, 100, 1}, {300, 100, 1}, {300, 200, 1}, {200, 200, 1} };

    // Draw the original object (polygon)
    
    drawObject(object, num_points);


    // Perform 2D scaling with separate scaling factors sx and sy
    float sx =2;
    float sy =1.5;
    scale(object, num_points, sx, sy);

    // After scaling
    drawObject(object, num_points);
    getch();

    closegraph();
    return 0;
}
