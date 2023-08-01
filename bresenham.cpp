#include<conio.h>
#include<graphics.h>
int main()
{
 int x1,y1,x2,y2,dx,dy,p,x,y,m;
 int gd = DETECT , gm;
 printf("Enter the value of x1 , y1:");
 scanf("%d%d",&x1,&y1);
 printf("Enter the value of x2 , y2:");
 scanf("%d %d",&x2,&y2);
 initgraph(&gd,&gm,(char*)"");
 dx = x2-x1;
 dy = y2 - y1;
 printf("value of dx and dy is %d, %d",dx,dy);
 m =(dy/dx);
 printf("\t value of m: %d",m);
 if(m<1)
 {
	p = (2*dy) - dx;
	x=x1;
	y = y1;
	if(dx<0)
	{
	  x = x2;
	  y = y2;
	  x2 = x1;
	}
	while(x<=x2)
	{
	   putpixel(x,y,15);
	   if(p<0)
	   {
	    x = x+1;
	    p = p+2*(dy);
	   }
	   else
	  {
	     x =x+1;
	     y = y+1;
	     p = p+2*(dy)-2*(dx);
	  }
	}
 }
 else if(m>1)
 {
    p = (2*dx) - dy;
    x = x1;
    y = y1;
    if(dy < 0)
    {
    x = x2;
    y = y2;
    y2 = y1;
    }
    while(y<=y2)
    {
       putpixel(x,y,15);
       if(p<0)
       {
	 y = y+1;
	 p = p+2*(dx);
       }
       else
       {
	 x=x+1;
	 y = y+1;
	 p = p+2*(dx)-2*(dy);
       }

    }
 }
 else if(m == 1)
 {
  x = x1;
  y = y1;
	if(dx<0)
	{
	  x = x2;
	  y = y2;
	  x2 = x1;
	}
       else if(dy<0)
       {
	  x = x2;
	  y = y2;
	  y2 = y1;
       }
       while( x<=x2 )
      {
	putpixel(x,y,15);
	x = x+1;
	y = y+1;
      }
 }
getch();
closegraph();
return 0;
}
