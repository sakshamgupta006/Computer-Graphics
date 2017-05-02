
void multiply (double a[][3],double b[][1], int a_rows, int a_cols,int b_rows, int b_cols,double res[][1]){
	
	if (a_cols != b_rows)		
		return;

	// Matrix Multiplication
	for (int i = 0; i < a_rows; ++i){
		for (int j = 0; j < b_cols; ++j){
			double sum = 0;
			for (int k = 0; k < a_cols; ++k){
				sum += (a[i][k]*b[k][j]);
			}
			res[i][j] = sum;
		}
	}
}