#include <graphics.h>

void boundary(int x, int y, int bdcolour, int new_col)
{
	 
	
	if (getpixel(x,y) != bdcolour&& getpixel(x,y) != new_col)
	{
		putpixel(x, y, new_col);

		boundary(x + 1, y,bdcolour, new_col);
		boundary(x - 1, y,bdcolour, new_col);
		boundary(x, y + 1,bdcolour, new_col);
		boundary(x, y - 1, bdcolour,new_col);
	}
}

int main()
{
     int newcolour = 14, bdcolour=15;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
     rectangle(100,100,300,300);
     boundary(101, 101,bdcolour , newcolour);
    getch();
    closegraph();
    return 0;
}
