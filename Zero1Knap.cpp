//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>
#include <string>

int zeroOneKnap(int v[], int w[], int I, int W);

int main(int argc, char** argv){
	int v[6] = {40,35,18,4,10,2};
	int w[6] = {100,50,45,20,10,5};
	int vMax = zeroOneKnap(v,w,6, 100);
	std::cout << "Max value: " << vMax << std::endl;
}

int zeroOneKnap(int v[], int w[], int I, int W){
	int maxVTable[I+1][W+1];
	maxVTable[0][0] = 0; //No iteams, no value
	//int sTable[I+1][W+1];//Tells us the first item to pick
	//sTable[0][0] = 0; //No iteams, first pick is nothing
	//If we have no weight, we can have any number of items it doesnt matter
	for (int p = 1; p < I+1; p++){
		maxVTable[p][0] = 0;
		//sTable[p][0] = 0;
	}
	//If we have no items, we can have all the weight in the bag it doesn't matter
	for (int q = 1; q < W+1; q++){
		maxVTable[0][q] = 0;
		//sTable[0][q] = 0;
	}
	for (int i = 1; i < I+1; i++){
		for (int j = 1; j < W+1; j++){
			if (w[i-1] > j){
				maxVTable[i][j] = maxVTable[i-1][j];
				//if too heavy fill s table in same way as when m1 >= m2
				//If you look it element I,W in the s table, it should tell
				//fuck s table for now
			}
			else{
				int m1 = maxVTable[i-1][j];
				int m2 = maxVTable[i-1][j-w[i-1]] + v[i-1];
				if (m1 >= m2){
					maxVTable[i][j] = m1;
					//sTable[i][j] = 
				}
				else{
					maxVTable[i][j] = m2;
				}
			}
		}
	}
	for (int d = 0; d <= I; d++){
		std::cout << "[";
		for (int e = 0; e <= W; e++){
			std::cout << maxVTable[d][e] << ", ";
		}
		std::cout << "]" << std::endl;
	}
	return maxVTable[I][W];
}