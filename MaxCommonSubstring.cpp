//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>
#include <string>

int MCS(std::string x, std::string y);

int main (int argc, char** argv){
	std::string x = "algorithm";
	std::string y = "logarithm";
	int max = MCS(x,y);
	std::cout << "Max substring of " << x << " and " << y << " is " << max << std::endl;
}

int MCS(std::string x, std::string y){
	int curMax = 0;
	int maxXIndex = -1;
	int mTable[x.size()+1][y.size()+1];
	for (int p = 0; p < x.size()+1; p++){
		mTable[p][0] = 0;
	}
	for (int q = 0; q < y.size()+1; q++){
		mTable[0][q] = 0;
	}
	for (int i = 1; i < x.size()+1; i++){
		for (int j = 1; j < y.size()+1; j++){
			if(x[i-1] == y[j-1]){
				mTable[i][j] = mTable[i-1][j-1]+1;
				if (mTable[i][j] > curMax){
					curMax = mTable[i][j];
					maxXIndex = i;//After the loops, maxXIndex will the terminating index of max substr
				}
			}	
			else{
				mTable[i][j] = 0;
			}
		}
	}
	for (int k = 0; k < x.size()+1; k++){
		std::cout << "[";
		for (int l = 0; l < y.size()+1; l++){
			std::cout << mTable[k][l] << ", ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "Max Substring is: " << x.substr(maxXIndex-curMax, curMax) << std::endl;
	return curMax;
}