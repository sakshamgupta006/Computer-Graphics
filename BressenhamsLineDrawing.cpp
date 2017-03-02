#include<iostream>
#include<graphics.h>

using namespace std;

int main(int argc, char const *argv[]) {

  int x1=0,y1=0,x2=0,y2=0;

  // Get the endpoints
  cout<<"Enter first endpoint (x,y) : ";
  cin>>x1>>y1;

  cout<<"Enter second endpoint (x,y) : ";
  cin>>x2>>y2;

  int gd = DETECT,gm;
  initgraph(&gd,&gm,NULL);
  // Calculate slope and intercept
  float m = (float)(y2-y1)/(float)(x2-x1);
  float b = y2 - (m*x2);

  // Get absolute values of vertical and horizontal differences
  int delX = abs(x2-x1), delY = abs(y2-y1);

  // Using bressenham's algorithm

  // Initialize xk,yk to left coordinate
  float xk = -1,yk = -1;

  int length = 0;

  if (x1 <= x2) {
    xk = x1;
    yk = y1;
  }
  else{
    xk = x2;
    yk = y2;
  }

  int dX = 0 , dY = 0;

  if (abs(m) <= 1) {
    dX = 1;
    dY = 1;
    length = max(abs(x1-xk) , abs(x2-xk));
  }
  else{
    dX = 1;
    dY = -1;
    length = max(abs(y1-yk) , abs(y2-yk));
  }

  // Decision Varaible
  int pk = 2*delY - delX;

  for (size_t i = 0; i < length; i++) {

    putpixel(xk,yk,255);

    if (abs(m) <= 1) {

      if(m >= 0){
        dY = pk <= 0 ? 0 : 1;
        pk = pk + (2*delY) - (2*delX*dY);
        xk += dX;
        yk += pk <= 0 ? 0 : 1;
      }
      else{
        dY = pk <= 0 ? 0 : -1;
        pk = pk + (2*delY) - (2*delX*dY);
        xk += dX;
        yk += (pk <= 0 ? 0 : -1);
      }

    }else{

      if(m >= 0){
        dX = pk <= 0 ? 0 : -1;
        pk = pk + (2*delX) - (2*delY*dX);
        xk += pk <= 0 ? 0 : 1;
        yk += dY;
      }
      else{
        dX = pk <= 0 ? 0 : 1;
        pk = pk + (2*delX) - (2*delY*dX);
        xk += pk <= 0 ? 0 : 1;;
        yk += dY;
      }
    }
  }


  // Hold the libgraph window
  delay(5000);
  closegraph();

  return 0;
}
