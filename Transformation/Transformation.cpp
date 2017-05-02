#include "Matrix.h"
#include <cmath>
#include <iostream>

using namespace std;

const double PI  =3.141592653589793238463;

void translate(double x , double y, double delX , double delY , double result[][1]) {

	double translation_matrix[3][3] = {
		{1,0,delX},
		{0,1,delY},
		{0,0,1}
	};

	double vertex_matrix[3][1] = {
		{x},
		{y},
		{1}
	};
	multiply(translation_matrix , vertex_matrix , 3,3,3,1 , result);
}

void rotate(double x , double y , double phi , double result[][1]){

	double rotation_matrix[3][3] = {
		{cos(phi),-sin(phi),0},
		{sin(phi),cos(phi),0},
		{0,0,1}
	};

	double vertex_matrix[3][1] = {
		{x},
		{y},
		{1}
	};

	multiply(rotation_matrix , vertex_matrix , 3,3,3,1 , result);

}

void scale(double x , double y , double fx, double fy , double result[][1]){

	double scaling_matrix[3][3] = {
		{fx,0,0},
		{0,fy,0},
		{0,0,1}
	};

	double vertex_matrix[3][1] = {
		{x},
		{y},
		{1}
	};

	multiply(scaling_matrix , vertex_matrix , 3,3,3,1 , result);
	
}