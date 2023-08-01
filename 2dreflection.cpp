#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle given the vertex coordinates
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform reflection across the x-axis
void reflectXAxis(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Reflect the coordinates across the x-axis
    int newY1 = getmaxy() - y1;
    int newY2 = getmaxy() - y2;
    int newY3 = getmaxy() - y3;

    // Draw the reflected triangle
    drawTriangle(x1, newY1, x2, newY2, x3, newY3);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Triangle coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;
    int x3 = 300, y3 = 100;

    // Original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Perform reflection across the x-axis
    reflectXAxis(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
