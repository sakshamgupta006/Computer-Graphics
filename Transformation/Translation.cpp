#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int x=0,y=0,delX=0,delY=0;
	
	cout<<"Enter (x,y) coordinates of the vertex : ";
	cin>>x>>y;

	cout<<"Enter translation amounts of x and y (delta-X and delta-Y) : ";
	cin>>delX>>delY;


	int translation_matrix[3][3] = {
		{1,0,delX},
		{0,1,delY},
		{0,0,1}
	};

	int vertex_matrix[3][1] = {
		{x},
		{y},
		1
	};

	int translated_vertex[3][1];

	multiply(translation_matrix , vertex_matrix , 3,3,3,1 , translated_vertex);
	
	cout<<"New X : "<<translated_vertex[0][0]<<" New Y : "<<translated_vertex[1][0]<<endl;
	return 0;
}