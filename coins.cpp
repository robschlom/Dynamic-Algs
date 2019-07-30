//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>

int coins(int d[], int ds, int M);

int main(int argc, char** argv){
	int d[] = {1,10,25};
	int M = 30;
	int C = coins(d,3,M);
	std::cout << " C = " << C<< std::endl;
}

//We're assuming d comes in ascending order
//ds is the number of denominations
//M is money to give change for
int coins(int d[], int ds, int M){
	if (d[0] != 1){
		std::cout << "Canada does it, but I don't" << std::endl;
		return -1;
	}
	int C[M+1];
	C[0] = 0; //No change due, no coins given
	int s[M+1];//will store i, meaning take ith denomination first
	s[0] = 0;
	for (int j = 1; j <= M; j++){
		//find q = min{1+C[M-d[i-1]]} for 1 <= i <= j
		int q = std::numeric_limits<int>::max();
		for (int i = 0; i < ds; i++){
			if (d[i] > j){
				//can't pick this denomination or any above
				i = ds+1;
			}
			else{ 
				if (q > 1+C[j-d[i]]){
					q = 1 + C[j-d[i]];
					s[j] = i+1;
				}
			}
		}
		C[j] = q;
	}
	std::cout << "{";
	for (int i = 1; i <= M; i++){
		std::cout << C[i] << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "S: {";
	for (int i = 1; i <= M; i++){
		std::cout << s[i] << ", ";
	}
	std::cout << "}" << std::endl;
	return C[M];
}
