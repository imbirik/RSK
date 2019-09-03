#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include "young.h"
#include <set>
#include <random>
#include <algorithm>
#include <map>
#include <ctime>

using namespace std; 

const long MAXN = 1e4;
long long factorial[20];
//const unsigned int N = 5;
long double branch_prob[MAXN];


int main() {
	//freopen("out.txt", "w", stdout);
	freopen("err.txt", "w", stderr);

	long b[10];
	for (int i = 0; i < 10; ++i)
	{
		b[i] = i;
		cout << i << ' ';
	}
	cout << "\n";
	rand_permute_self_inverse<long>(b, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << "\n";

	/*
	int n = 6000;
	for (int my_try = 0; my_try < 100; my_try++) {
		vector <double> vec = rand_vec(n);
		PQ_tableaux PQ;
		PQ.push(vec);
		for (int i = 0; i < 1; i++)
			cout << vec[i] << " " << sqrt(PQ.find(vec[i])) / sqrt(n) << " " << vec[i] / ((PQ.find(vec[i]) + 1) / sqrt(n)) << endl;
	}
	*/


	/*
	factorial[0] = 1;                                                //Trying to count some statistics on small sizes of YT
	for (int i = 1; i < 20; ++i)                                     //Firstly, some precounting
	{
		factorial[i] = factorial[i - 1] * i;                         
	}

	for (int N = 1; N < 5; ++N)
	{
		//vector<double> vec = { 5, 2, 4, 3, 1, 7, 6 };
		vector<double> vec = rand_vec(N);
		vector<double> vec_copy = vec;
		cout << "random vector: " << vec << "\n";
		vector<int> permutation(N);
		map<vector<int>, vector<double>> identity_points;                   //Map contains info about each type of YT
		for (int i = 0; i < N; ++i)                                      //For each type: an array with numbers of 
		{
			permutation[i] = i;                                          //the permutation number which contains
		}                                                                //this number of identity points
		for (int i = 0; i < factorial[N]; ++i)
		{
			permutate(vec, permutation);
			PQ_tableaux PQ;
			PQ.push(vec);
			if (identity_points.find(PQ.type()) == identity_points.end())
			{
				identity_points[PQ.type()] = vector<double>(N + 1);
			}
			identity_points[PQ.type()][count_identity_points(vec)]++;
			next_permutation(permutation.begin(), permutation.end());
			vec = vec_copy;
		}

		vector<double> measure(N + 1, 0);
		for (auto i : identity_points)
		{
			cout << i.first << "\n" << i.second << "\n";
			measure = measure + i.second;
		}
		int total = 0;
		cout << "Plancherel measure: ";
		for (auto i : identity_points)
		{
			cout << sum(i.second) << " ";
			total += sum(i.second);
		}
		cout << "\n" << "total: " << total << "\n";
		cout << "id_points statistics for all permutation: " << measure << "\n" << "\n";
	}
	*/
	system("pause");
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