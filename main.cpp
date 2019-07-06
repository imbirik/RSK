#include<vector>
#include<iostream>
#include "young.h"
#include <set>
#include<random>
using namespace std; 

int main() {
	int n = 60000;
	for (int my_try = 0; my_try < 100; my_try++) {
		vector <double> vec = rand_vec(n);
		PQ_tableaux PQ;
		PQ.push(vec);
		for (int i = 0; i < 1; i++)
			cout << vec[i] << " " << sqrt(PQ.find(vec[i])) / sqrt(n) << " " << vec[i] / ((PQ.find(vec[i]) + 1) / sqrt(n)) << endl;
	}
	return 0;
	/*
	PQ_tableaux PQ;
	PQ.push({ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 });
	cout << PQ;
	vector <double> per;
	for (int i = 0; i < PQ.size(); i++) {
		per.push_back(PQ.erase());
	}
	reverse(per.begin(),per.end());
	for (int i = 0; i < per.size(); i++)
		cout << per[i] <<" ";
	return 0;
	*/
}		