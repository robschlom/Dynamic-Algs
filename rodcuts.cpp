//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <limits>

int rods(int p[], int n);
int rodsC(int p[], int n, int c);

int main(int argc, char** argv){
	int p[] = {1,4,5,9,10,12,15,18,19,20};
	std::cout << p[0] << std::endl;
	int n = 10;
	//int r = rods(p,n);
	int c = 1;
	//std::cout << " r = " << r << std::endl;
	int rC = rodsC(p,n,c);
	std::cout << " rC = " << rC<< std::endl;
}

int rods(int p[], int n){
	int r[n+1];
	r[0] = 0;
	int s[n+1];
	s[0] = 0;
	for (int j = 1; j <= n; j++){
		int q = 0; //only gonna put in positive test cases
		for (int i = 1; i <= j; i++){
			if (q < p[i-1]+r[j-i]){
				q = p[i-1]+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	std::cout << "{";
	for (int i = 1; i < n+1; i++){
		std::cout << s[i] << ", ";
	}
	std::cout << "}";
	return r[n];
}

int rodsC(int p[], int n, int c){
	int r[n+1];
	r[0] = 0;
	int s[n+1];
	s[0] = 0;
	for (int j = 1; j <= n; j++){
		int q = p[j-1]; //only gonna put in positive test cases
		s[j] = j;
		for (int i = 1; i <= j; i++){
			if (q < p[i-1]-c+r[j-i]){
				q = p[i-1]-c+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	std::cout << "{";
	for (int i = 1; i < n+1; i++){
		std::cout << s[i] << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "r[] = {";
	for (int i = 1; i < n+1; i++){
		std::cout << r[i] << ", ";
	}
	std::cout << "}" << std::endl;
	return r[n];
}