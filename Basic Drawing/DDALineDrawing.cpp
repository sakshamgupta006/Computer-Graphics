#include<iostream>
#include<graphics.h>

using namespace std;

int main(int argc, char const *argv[]) {

  // Input the 2 end points
  int x1=0,x2=0,y1=0,y2=0;

  cout<<"Enter first endpoint (x,y) : ";
  cin>>x1>>y1;

  cout<<"Enter second endpoint (x,y) : ";
  cin>>x2>>y2;

  // Initialize graphics mode
  int gd = DETECT,gm;
  initgraph(&gd,&gm,NULL);

  // Find the slope and intercept
  float m = (float)(y2-y1)/(float)(x2-x1);
  float b = y1 - (m*x1);

  float dely = y2-y1;
  float delx = x2-x1;

  float l = max(abs(delx),abs(dely));

  float dx = delx/l,dy=dely/l;

  float currentX = x1+0.5, currentY = y1+0.5;

  while (floor(currentX)!=x2 && floor(currentY)!=y2) {
    putpixel(floor(currentX), floor(currentY) , 255);
    currentX += dx;
    currentY += dy;
  }

  // Using this to hold the graphics window for 5 seconds
  delay(5000);
  closegraph();
}
