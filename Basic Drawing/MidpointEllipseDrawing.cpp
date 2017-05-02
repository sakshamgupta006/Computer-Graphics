#include<iostream>
#include<graphics.h>

using namespace std;

void drawEllipsePoints(int xk,int yk,int x0,int y0){

  pair<int,int> pixelArr[4];

  pixelArr[0] = pair<int,int>(xk,yk);
  pixelArr[1] = pair<int,int>(xk,-yk);
  pixelArr[2] = pair<int,int>(-xk,yk);
  pixelArr[3] = pair<int,int>(-xk,-yk);

  for (size_t i = 0; i < 4; i++) {
    putpixel(pixelArr[i].first + x0 , pixelArr[i].second + y0 , 255);
  }
}

int main(int argc, char const *argv[]) {

  int x0=0,y0=0,a=0,b=0;

  // Get the center and the length of major and minor axis
  cout<<"Enter the center point of the ellipse (x,y) : ";
  cin>>x0>>y0;

  cout<<"Enter the length of major and minor axis respectively (a,b) : ";
  cin>>a>>b;

  int gd = DETECT,gm;
  initgraph(&gd,&gm,NULL);

  // Dividing the ellipse into 2 regions
  int xk = 0 , yk = (b);
  float pk1 = (b*b) + ((a*a)/4) - (a*a*b) ,pk2 = 0;


  // Region 1 Calculations
  while ((b*b*xk) < (a*a*yk)) {
    drawEllipsePoints(xk,yk,x0,y0);

    if (pk1 < 0) {
      pk1 = pk1 + (b*b*(2*xk + 3));
    }
    else{
      pk1 = pk1 + (b*b*(2*xk + 3)) - (a*a*(2*yk - 2));
      yk--;
    }
    xk++;
  }

  // Region 2 Calculations
  pk2 = (b*b*(xk+0.5)*(xk+0.5)) + (a*a*(yk-1)*(yk-1)) - (a*a*b*b);
  while (yk > 0) {
    drawEllipsePoints(xk,yk,x0,y0);
    if (pk2 > 0) {
      pk2 = pk2 - (a*a*(2*yk - 3));
    }
    else{
      pk2 = pk2 + (b*b*(2*xk + 2)) - (a*a*(2*yk - 3));
      xk++;
    }
    yk--;
  }

  delay(5000);
  closegraph();

  return 0;
}
