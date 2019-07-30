//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>
#include <string>


int matChainMult(int n, int p[]);

int main(int argc, char** argv){
	int p[5] = {3,1,4,5,4};
	int n = 4;
	int min = matChainMult(n,p);
	std::cout << "Min mults: " << min << std::endl;
}




//Inputs: n - number of matricies to multiply
//p[] - the p array holding the dimentions
int matChainMult(int n, int p[]){
	int m[n][n];
	int s[n][n];
	for (int i = 0; i < n; i++){
		m[i][i] = 0;
	}
	for (int d = 1; d < n; d++){
		for (int i = 0; i < n-d; i++){
			int j = i + d;
			m[i][j] = std::numeric_limits<int>::max();
			for (int k = i; k < j; k++){
				int q = m[i][k] + m[k+1][j]+ p[i]*p[k+1]*p[j+1];
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k+1;
				}
			}
		}
	}
	for (int e = 0; e < n; e++){
		std::cout << "[";
		for (int f = 0; f < n; f++){
			if (f < e){
				std::cout << "0, ";
			}
			else{
				std::cout << m[e][f] << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;
	for (int g = 0; g < n; g++){
		std::cout << "[";
		for (int h = 0; h < n; h++){
			if (h < g){
				std::cout << "0, ";
			}
			else{
				std::cout << s[g][h] << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
	return m[0][n-1];
}