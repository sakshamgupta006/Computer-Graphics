#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int x=0,y=0,fx=0,fy=0;
	
	cout<<"Enter (x,y) coordinates of the vertex : ";
	cin>>x>>y;

	cout<<"Enter scale factors of x and y (fx and fy) : ";
	cin>>fx>>fy;


	double scaling_matrix[3][3] = {
		{fx,0,0},
		{0,fy,0},
		{0,0,1}
	};

	double vertex_matrix[3][1] = {
		{x},
		{y},
		1
	};

	double scaled_vertex[3][1];

	multiply(scaling_matrix , vertex_matrix , 3,3,3,1 , scaled_vertex);
	
	cout<<"New X : "<<scaled_vertex[0][0]<<" New Y : "<<scaled_vertex[1][0]<<endl;
	return 0;
}