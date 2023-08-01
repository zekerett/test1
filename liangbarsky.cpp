#include <graphics.h>
#include <conio.h>
#include <math.h>

// function to clip a line using Liang-Barsky algorithm
void LiangBarsky(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax) {
  float u1 = 0.0, u2 = 1.0, u3 = 0.0, u4 = 0.0;
  float dx = x2 - x1;
  float dy = y2 - y1;

  if (clipTest(-dx, x1 - xmin, &u1, &u2)) {
    if (clipTest(dx, xmax - x1, &u1, &u2)) {
      if (clipTest(-dy, y1 - ymin, &u3, &u4)) {
        if (clipTest(dy, ymax - y1, &u3, &u4)) {
          if (u4 < 1.0) {
            x2 = x1 + u4 * dx;
            y2 = y1 + u4 * dy;
          }
          if (u3 > 0.0) {
            x1 = x1 + u3 * dx;
            y1 = y1 + u3 * dy;
          }

          line(x1, y1, x2, y2);
        }
      }
    }
  }
}

// function to test if a line segment is outside the clipping window
bool clipTest(float p, float q, float* u1, float* u2) {
  float r = q / p;

  if (p < 0.0) {
    if (r > *u2) {
      return false;
    } else if (r > *u1) {
      *u1 = r;
    }
  } else if (p > 0.0) {
    if (r < *u1) {
      return false;
    } else if (r < *u2) {
      *u2 = r;
    }
  } else if (q < 0.0) {
    return false;
  }

  return true;
}

// main function
int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm,(char*)"");

  float xmin, xmax, ymin, ymax;
  float x1, y1, x2, y2;

  printf("Enter the coordintes of line\n");
  printf("x1 : ");
  scanf("%f", &x1);
  printf("y1 : ");
  scanf("%f", &y1);
  printf("x2 : ");
  scanf("%f", &x2);
  printf("y2 : ");
  scanf("%f", &y2); 
 
  printf("Enter the coordinates of clipping rectangle\n");
  printf("xmin : ");
  scanf("%f", &xmin);
  printf("ymin : ");
  scanf("%f", &ymin);
  printf("xmax : ");
  scanf("%f", &xmax);
  printf("ymax : ");
  scanf("%f", &ymax);


  setcolor(RED);
  rectangle(xmin, ymin, xmax, ymax);

  setcolor(GREEN);
  line(x1, y1, x2, y2);

  setcolor(WHITE);
  LiangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

  getch();
  closegraph();

  return 0;
}

