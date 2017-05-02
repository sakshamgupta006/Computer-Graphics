#include<iostream>
#include<graphics.h>

using namespace std;

int compute_abrl(int x,int y , int minX , int minY , int maxX , int maxY){

	int abrl = 0;

	// if left of left
	if(x < minX){
		abrl = abrl | 1;
	}
	// if right of right
	if(x > maxX){
		abrl = abrl | 2;
	}
	// if below the bottom
	if(y < minY){
		abrl = abrl | 4;
	}
	// if above the top
	if(y > maxY){
		abrl = abrl | 8;
	}

	return abrl;
}

pair<int,int> clip(int x,int y, float m , float c , int minX, int minY , int maxX , int maxY){

	int abrl = compute_abrl(x,y,minX,minY,maxX,maxY);

	// clip to left plane if needed
	if ((abrl & 1) != 0){
		x = minX;
		y = (x*m + c);
		abrl = compute_abrl(x,y,minX, minY,maxX,maxY);
		if (abrl == 0){
			return make_pair(x,y);
		}
	}

	// Clip to right plane if needed
	if ((abrl & 2) != 0){
		x = maxX;
		y = (x*m) + c;
		abrl = compute_abrl(x,y,minX, minY,maxX,maxY);
		if (abrl == 0){
			return make_pair(x,y);
		}
	}

	// Clip to bottom plane if needed
	if ((abrl & 4)!=0){
		y = minY;
		x = (y - c)/m;
		abrl = compute_abrl(x,y,minX, minY,maxX,maxY);
		if (abrl == 0){
			return make_pair(x,y);
		}
	}

	// Clip to top plane if needed
	if ((abrl & 8)!=0){
		y = maxY;
		x = (y - c)/m;
		abrl = compute_abrl(x,y,minX,minY,maxX,maxY);
		if (abrl == 0){
			return make_pair(x,y);
		}
	}

	return make_pair(x,y);
}

int main(int argc, char const *argv[])
{
	int minX=0,minY=0,maxX=0,maxY=0;
	int line_min_X = 0, line_min_Y= 0 , line_max_X = 0 , line_max_Y=0;

	cout<<"Enter coordinates of viewing window :-"<<endl;
	
	cout<<"MinX and MinY : ";
	cin>>minX>>minY;
	
	cout<<"MaxX and MaxY : ";
	cin>>maxX>>maxY;

	cout<<"Enter coordinates of line :-"<<endl;
	
	cout<<"MinX and MinY : ";
	cin>>line_min_X>>line_min_Y;
	
	cout<<"MaxX and MaxY : ";
	cin>>line_max_X>>line_max_Y;

	int abrl_left = compute_abrl(line_min_X,line_min_Y,minX,minY,maxX,maxY);
	int abrl_right = compute_abrl(line_max_X,line_max_Y,minX,minY,maxX,maxY);

	if ((abrl_left | abrl_right) == 0){
		// trivially accept 
		cout<<"Entire line is within viewing area\n";
	}

	else if ((abrl_left & abrl_right) != 0){
		// trivially reject
		cout<<"The line is completely outside viewing area\n";
	}

	else {
		// we will have to clip

		// Compute m and c
		float m = (float)(line_max_Y - line_min_Y)/(float)(line_max_X- line_min_X);
		float c = line_max_Y - (line_max_X * m);

		// Clip left point
		pair<int,int> left = clip(line_min_X,line_min_Y,m,c,minX,minY,maxX,maxY);
		pair<int,int> right = clip(line_max_X,line_max_Y,m,c,minX,minY,maxX,maxY);

		cout<<"Clipped line : "<<"("<<left.first<<","<<left.second<<") , ("<<right.first<<","<<right.second<<")\n";
	}
	return 0;
}