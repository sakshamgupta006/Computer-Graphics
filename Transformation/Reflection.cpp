#include <iostream>
#include <cmath>

#include "Transformation.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int x=0,y=0,m=0,c=0;
	
	cout<<"Enter (x,y) coordinates of the vertex : ";
	cin>>x>>y;

	cout<<"Enter the slope and intercept of reflection line (m , c) : ";
	cin>>m>>c;

	double result[3][1];

	// Translate the line to origin
	translate(x,y,0,-c,result);

	// Rotate by the slope
	double phi = atan(m);
	
	rotate(result[0][0],result[1][0],-1*phi,result);

	// Scale by factor of -1 in x and 1 in y
	scale(result[0][0],result[1][0],1,-1,result);

	// Now rotate back
	rotate(result[0][0],result[1][0],phi,result);
	
	// Translate back
	translate(result[0][0],result[1][0] , 0 , c , result);

	cout<<"New X : "<<result[0][0]<<" New Y : "<<result[1][0]<<endl;
	return 0;
}