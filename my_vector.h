#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator <<(ostream&, const vector<T>&);        //Output operator for vector
template<typename T>
vector<double> operator +(
	const vector<T> &,
	const vector<T> &
	);
template<typename T>
T sum(const vector<T> &);



//implementation

template<typename T>
ostream& operator <<(ostream& os, const vector<T>& out)
{
	for (auto i : out)
	{
		os << i << ' ';
	}
	return os;
}
template<typename T>
vector<double> operator+(const vector<T> & vec1, const vector<T> & vec2)
{
	vector<double> vec_res(max(vec1.size(), vec2.size()));
	for (int i = 0; i < (int)min(vec1.size(), vec2.size()); ++i)
	{
		vec_res[i] = vec1[i] + vec2[i];
	}
	return vec_res;
}
template<typename T>
T sum(const vector<T>& vec)
{
	T sum = 0;
	for (auto i : vec)
	{
		sum += i;
	}
	return sum;
}