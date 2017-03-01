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

  cout<<m<<" "<<b;

  float dy = y2-y1;
  float dx = x2-x1;
  int length = 0;

  if (abs(m) <= 1) {

    dx = 1;
    dy = m*dx;
    length = abs(x2-x1);
  }
  // Slope is the greater than 1
  else{
    dy = 1;
    dx = dy/m;
    length = abs(y2-y1);
  }

  if(x1 > x2){
    dx = -dx;
    dy = -dy;
  }

  float currentX = x1+0.5, currentY = y1+0.5;

  for (size_t i = 0; i < length; i++) {
    putpixel(floor(currentX), floor(currentY) , 255);
    currentX += dx;
    currentY += dy;
  }

  // Using this to hold the graphics window for 5 seconds
  delay(5000);
  closegraph();
}
