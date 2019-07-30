//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>
#include <string>

int DED(std::string x, std::string y, int dTable[5][5]);
int translate(char c);

int main (int argc, char** argv){
	std::string x = "ATGCC";
	std::string y = "TACGCA";
	int dTable[5][5];
	std::cout << "Delta Table" << std::endl;
	for (int i = 0; i < 5; i++){
		std::cout << "[";
		for (int j = 0; j < 5; j++){
			dTable[i][j] = 0;
			if (j == 4){
				dTable[i][j] = 1;
			}
			if (i == 4){
				dTable[i][j] = 2;
			}
			std::cout << dTable[i][j] << ", ";
		}
		std::cout << "]" << std::endl;
	}
	int max = DED(x,y,dTable);
	std::cout << "Max delta score of " << x << " and " << y << " is " << max << std::endl;
}

int translate(char c){
	if( c == 'A'){
		return 0;
	}
	else if( c == 'C'){
		return 1;
	}
	else if( c == 'G'){
		return 2;
	}
	else if( c == 'T'){
		return 3;
	}
	else{
		std::cout << c << " isn't in DNA" << std::endl;
		return -1;
	}
}

int DED(std::string x, std::string y, int dTable[5][5]){
/*	A = 0;
	C = 1;
	G = 2;
	T = 3;*/
	int dash = 4;
	int mTable[x.size()+1][y.size()+1];
	mTable[0][0] = 0;
	int sTable[x.size()+1][y.size()+1];
	sTable[0][0] = 0;
	for (int p = 1; p < x.size()+1; p++){
		mTable[p][0] = dTable[translate(x[p-1])][dash];
		sTable[p][0] = 0;
	}
	for (int q = 1; q < y.size()+1; q++){
		mTable[0][q] = dTable[dash][translate(y[q-1])];
		sTable[0][q] = 0;
	}
	for (int i = 1; i < x.size()+1; i++){
		for (int j = 1; j < y.size()+1; j++){
			int m1 = dTable[translate(x[i-1])][translate(y[j-1])] + mTable[i-1][j-1];
			int m2 = dTable[translate(x[i-1])][dash] + mTable[i-1][j];
			int m3 = dTable[dash][translate(y[j-1])] + mTable[i][j-1];
			if (m1 >= m2 && m1 >= m3){
				mTable[i][j] = m1;
				sTable[i][j] = 2; //2 means allign those letters
			}
			else if (m2 >= m1 && m2 >= m3){
				mTable[i][j] = m2;
				sTable[i][j] = 3; //3 means up, allign x[i] with -
			}
			else{
				mTable[i][j] = m3;
				sTable[i][j] = 1; //1 means left, allign y[j] with -
			}
		}
	}
	for (int k = 0; k < x.size()+1; k++){
		std::cout << std::endl << "[";
		for (int l = 0; l < y.size()+1; l++){
			std::cout << mTable[k][l] << ", ";
		}
		std::cout << "]" << std::endl;
	}
	return mTable[x.size()][y.size()];
}