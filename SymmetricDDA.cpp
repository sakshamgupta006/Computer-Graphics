#include<iostream>
#include<graphics.h>

using namespace std;

int main(int argc, char const *argv[]) {

  int x1=0,y1=0,x2=0,y2=0;

  std::cout << "Enter first endpoint (x,y) : ";
  cin>>x1>>y1;

  std::cout << "Enter second endpoint (x,y) : ";
  cin>>x2>>y2;

  // Initialize graphics mode
  int gd = DETECT,gm;
  initgraph(&gd,&gm,NULL);

  int delX = (x2-x1),delY= (y2-y1);

  long factor = 1;
  while(factor < max(abs(delX),abs(delY))){
    factor = factor*2;
  }

  float incFactor = 1.0/(float)factor;


  double xInc = delX*incFactor;
  double yInc = delY*incFactor;

  float currentX = x1,currentY= y1;

  // Plot the initial point
  putpixel(currentX,currentY,255);

  // Plot the line
  while (floor(currentX)!=x2 && floor(currentY)!=y2) {
    currentX = currentX+xInc;
    currentY = currentY+yInc;

    putpixel(floor(currentX+0.5),floor(currentY+0.5),255);
  }

  delay(5000);
  closegraph();
  return 0;
}
