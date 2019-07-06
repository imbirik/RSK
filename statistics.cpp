#include <vector>
#include "statistics.h"
#include <algorithm>

vector<int> tightness(vector<double> input_data, int q)
{
	double min_elem = 1e9, max_elem = -1e9;
	for (auto it : input_data)
	{
		min_elem = min(min_elem, it);
		max_elem = max(max_elem, it);
	}
	double range = (max_elem - min_elem) / q;
	vector<int> output_data(q);
	for (auto it : input_data)
	{
		for (int i = 0; i < q; ++i)
		{
			if ((it >= min_elem + i * range) && (it < min_elem + (i + 1) * range))
			{
				output_data[i]++;
			}
		}
	}
	return output_data;
}
double rand_num() {
	double x = ((rand() ^ (rand() << 16)) % 1000000) / 1000000.0;
	return x;
}
vector <double> rand_vec(int n) {
	vector <double> vec;
	for (int i = 0; i < n; i++)
		vec.push_back(rand_num());
	return vec;
}
vector <int> rand_inv(int n) {
	vector <int> tmp(n);
	for (int i = 0; i < n; i++)
		tmp[i] = i;
	vector <int> inv(n);
	int it = n - 1;
	while (true) {
		if (it == -1)
			break;
		int pos = (rand()) % (it+1);
		if (pos == it) {
			inv[tmp[it]] = tmp[it];
			it--;
		}
		else {
			inv[tmp[it]] = tmp[pos];
			inv[tmp[pos]] = tmp[it];
			tmp[pos] = tmp[it - 1];
			it = it - 2;
		}
	}
	return inv;
}


