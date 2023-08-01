  #include<conio.h>
#include<graphics.h>
int main()
{
  int radius,Xc , Yc, x0,y0,p;
  int gd = DETECT , gm;

  printf("Enter the center co-ords: ");
  scanf("%d%d",&Xc,&Yc);
  printf("Enter the radius: ");
  scanf("%d",&radius);
  x0 = 0;
  y0 = radius;   //radius
  p = (int)(5/4) - (radius); //decision parameter

  initgraph(&gd,&gm,(char*)"");
  while(x0<=y0)
  {
   putpixel(Xc+x0,Yc+y0,YELLOW); //a,b
   putpixel(Xc+y0,Yc+x0,YELLOW); //b,a
   putpixel(Xc-y0,Yc+x0,YELLOW); //-b,a                                                                                                                                                                                                                                                                                                             
   putpixel(Xc+y0,Yc-x0,YELLOW); //b,-a
   putpixel(Xc-x0,Yc-y0,YELLOW);//-a,-b
   putpixel(Xc-y0,Yc-x0,YELLOW); //-b,-a
   putpixel(Xc+x0,Yc-y0,YELLOW);//a,-b
   putpixel(Xc-x0,Yc+y0,YELLOW); //-a,b

	if (p<0)
	{
	  x0 = x0 + 1;
	  p = p + (2*x0)+1;

	 }
	else
	{
	    x0 = x0 + 1;
	    y0 =y0 - 1;
	    p = p + (2*x0)+1 - (2*y0) ;
	 }

   }

 getch();
 closegraph();
 return 0;
}