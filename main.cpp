#include<vector>
#include<iostream>
#include "young.h"
#include "statistics.h"
#include <set>
#include<random>
using namespace std; 

int main() {
	int n = 10;
	for (int i = 0; i < 10; i++)
		cout << i << " ";
	cout << endl;
	vector <int> inv = rand_inv(10);
	for (int i = 0; i < 10; i++)
		cout << inv[i] << " ";
	return 0;
	/*
	vector<double> stat;
	for (int my_try = 0; my_try < 200; my_try++) {
		vector <double> vec = rand_vec(n);
		PQ_tableaux PQ;
		PQ.push(vec);
		for (int i = 0; i < 1; i++)
		{
			//cout << vec[i] << " " << PQ.find(vec[i]) / sqrt(n);
			stat.push_back(PQ.find(vec[i]) / sqrt(n));
		}
	}
	cout << "\n";
	for (auto it : tightness(stat, 40))
	{
		cout << it << ' ';
	}
	cout << "\n";
	return 0;
	*/
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