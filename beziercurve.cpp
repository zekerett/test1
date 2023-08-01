#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
int factorial(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int main()
{
    int x[4], y[4], i, n;
    double put_x, put_y, t;
    int gr = DETECT, gm;
    initgraph(&gr, &gm, (char *)"");
    printf("Enter the number of control points :");
    scanf("%d", &n);
    printf("\n Please enter x and y coordinates :");

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 15 );
    }

    for (t = 0.0; t <= 1.0; t = t + 0.00001)
    {
        put_x = 0;
        put_y = 0;
        for (i = 0; i < n; i++)
        {
            put_x += x[i] * nCr(n-1, i) * pow(t, i) * pow((1 - t), (n -1 - i)) ;
            put_y += y[i] * nCr(n-1, i) * pow(t, i) * pow((1 - t), (n -1 - i)) ;
        }
         putpixel(put_x, put_y, WHITE);
       //  printf("%lf,%lf\n",put_x,put_y);
    }
    getch();
    closegraph();
    return 0;
}