#include<conio.h>
#include<math.h>
#include<graphics.h>
int main()
{
 int x1,y1,x2,y2,dx,dy,step;
 double x,y,xinc,yinc;
 int gd = DETECT , gm;

 printf("Enter the value of x1 , y1:");
 scanf("%d%d",&x1,&y1);
 printf("Enter the value of x2 , y2:");
 scanf("%d%d",&x2,&y2);
 dx=(x2-x1);
 printf("\nvalue of dx is %d",dx);
 dy=(y2-y1);
  printf("\nvalue of dy is %d",dy);
initgraph(&gd,&gm,(char*)"");
if(dx>dy){
step =abs(dx);
}
else{
step =abs(dy);
}
xinc = (double)dx/step;
yinc = (double)dy/step;
for(x=x1,y=y1;x!=x2&&y!=y2;x+=xinc,y+=yinc)
 {
  putpixel((int)(x+0.5),(int)(y+0.5),15);
 }
 putpixel(x2,y2,15);
 getch();
 closegraph();
 return 0;
 }
  