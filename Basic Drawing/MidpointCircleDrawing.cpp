#include<iostream>
#include<graphics.h>

using namespace std;

void drawCirclePoints(int xk,int yk,int x0,int y0){

  pair<int,int> pixelArr[8];


  pixelArr[0] = pair<int,int>(xk,yk);
  pixelArr[1] = pair<int,int>(yk,xk);
  pixelArr[2] = pair<int,int>(xk,-yk);
  pixelArr[3] = pair<int,int>(yk,-xk);
  pixelArr[4] = pair<int,int>(-yk,xk);
  pixelArr[5] = pair<int,int>(-xk,yk);
  pixelArr[6] = pair<int,int>(-xk,-yk);
  pixelArr[7] = pair<int,int>(-yk,-xk);

  for (size_t i = 0; i < 8; i++) {
    putpixel(pixelArr[i].first + x0 , pixelArr[i].second + y0 , 255);
  }
}

int main(int argc, char const *argv[]) {

  int x0=0,y0=0,r=0;

  // Get the center and the radius of the circle
  cout<<"Enter the center point of the circle (x,y) : ";
  cin>>x0>>y0;

  cout<<"Enter the radius of the circle : " ;
  cin>>r;

  // Initialize the graphics mode
  int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
  initgraph(&gd,&gm,NULL);

  // Start at x = 0 , y = +r
  int xk = 0 , yk = r;

  // Decision Varaible
  int pk = (float)(5/4) - r;

  while (xk <= yk) {

    drawCirclePoints(xk,yk , x0, y0);

    if (pk <= 0) {
      pk = pk + (2*xk) + 3;
    }
    else{
      pk = pk + (2*xk + 3) - (2*yk - 2);
      yk--;
    }
    xk++;
  }

  // Hold the libgraph window for 5 seconds
  delay(5000);
  closegraph();

  return 0;
}
