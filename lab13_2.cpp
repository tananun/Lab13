#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool B[][N]){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	{
			cout << B[i][j] << " ";
				
			}	
		cout << endl;
		}	
}

void inputMatrix(double A[][N]){
	for (int i = 0; i < N; i++){
		cout << "Row " << i+1 <<": ";
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
}

void findLocalMax(const double inp[][N], bool outp[][N]){
	for (int i = 0; i < N; i++){
		outp[0][i] = 0;
		outp[N-1][i] = 0;
	}
	for (int i = 0; i < N; i++){
		outp[i][0] = 0;
		outp[i][N-1] = 0;
	}
	for (int i = 1; i < N-1; i++){
		for (int j = 1; j < N-1; j++){
			if ((inp[i][j] >= inp[i-1][j]) && (inp[i][j] >= inp[i+1][j]) && (inp[i][j] >= inp[i][j-1]) && (inp[i][j] >= inp[i][j+1]))
				outp[i][j] = 1;
			else outp[i][j] = 0;
		}
	}

}