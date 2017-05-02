#include <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;

const double PI  =3.141592653589793238463;

int main(int argc, char const *argv[])
{
	int x=0,y=0;
	float phi;
	
	cout<<"Enter (x,y) coordinates of the vertex : ";
	cin>>x>>y;

	cout<<"Enter rotation amount (phi) in degrees : ";
	cin>>phi;

	double phi_radians = (PI/180)*phi;

	double rotation_matrix[3][3] = {
		{cos(phi_radians),-sin(phi_radians),0},
		{sin(phi_radians),cos(phi_radians),0},
		{0,0,1}
	};

	double vertex_matrix[3][1] = {
		{x},
		{y},
		1
	};

	double rotated_vertex[3][1];

	multiply(rotation_matrix , vertex_matrix , 3,3,3,1 , rotated_vertex);
	
	cout<<"New X : "<<rotated_vertex[0][0]<<" New Y : "<<rotated_vertex[1][0]<<endl;
	return 0;
}