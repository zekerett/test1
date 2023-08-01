#include <stdio.h>
#include <graphics.h>

// Function to draw a 2D object (polygon) given the homogeneous coordinates
void drawObject(float arr[][3], int n) {
    for (int i = 0; i < n - 1; i++) {
        line(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
    }
    // Draw the last line connecting the last point to the first point
    line(arr[n - 1][0], arr[n - 1][1], arr[0][0], arr[0][1]);
}

// Function to perform 2D translation using homogeneous coordinates
void translate(float arr[][3], int n, int dx, int dy) {
    for (int i = 0; i < n; i++) {
        arr[i][0] += dx * arr[i][2];
        arr[i][1] += dy * arr[i][2];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Define the 2D object (a polygon) as a 2D array with homogeneous coordinates
    int num_points = 4;
    float object[4][3];

    // Ask the user to enter the coordinates of the rectangle
    printf("Enter the coordinates of the rectangle (x1 y1 x2 y2 x3 y3 x4 y4):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%f %f", &object[i][0], &object[i][1]);
        object[i][2] = 1; // Set homogeneous coordinate to 1
    }

    // Draw the original object (polygon)
    drawObject(object, num_points);

    // Ask the user for the translation factors
    int dx, dy;
    printf("Enter the translation factors (dx dy):\n");
    scanf("%d %d", &dx, &dy);

    // Perform translation
    translate(object, num_points, dx, dy);

    // Draw the translated object (polygon)
    drawObject(object, num_points);
    getch();

    closegraph();
    return 0;
}
