#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "young.h"
#include <random>
#include <ctime>

using namespace std;

int Row::size() {
	return _row.size();
}
double Row::reverse_Shensted_insert(double x)
{	
	auto y = (--_row.lower_bound(x));
	double new_x = *y;
	_row.erase(y);
	_row.insert(x);
	return new_x;
}
double Row::Shensted_insert(double x)
{
	auto y = _row.upper_bound(x);
	if (y == _row.end()) {
		_row.insert(x);
		return -1;
	}
	double new_x = *y;
	_row.erase(y);
	_row.insert(x);
	return new_x;
}
double Row::pop()
{
	int elem = *(--_row.end());
	_row.erase((--_row.end()));
	return elem;
}
bool Row::find(double x)
{
	return (_row.find(x) != _row.end());
}
ostream& operator<<(ostream& out, Row& obj) {
	for (auto it : obj._row)
		out << it << ' ';
	return out;
}
ostream & operator<<(ostream & out, Tableau & T)
{
	for (auto it : T._tableau)
		if (it.size() != 0)
			out << it << "\n";
	return out;
	// TODO: âñòàâüòå çäåñü îïåðàòîð return
}
void print_collection_of_Tableau(vector<Tableau> vect_T)
{
	int max_height = 0;
	for (auto it : vect_T)
	{
		max_height = max(max_height, it.size());
	}
	for (int tmp_row = 0; tmp_row < max_height; ++tmp_row)
	{
		for (auto it : vect_T)
		{

		}
	}
}
ostream & operator<<(ostream & out, PQ_tableaux & PQ)
{
	out << "P:\n" << PQ._P << "Q:\n" << PQ._Q;
	return out;
	// TODO: âñòàâüòå çäåñü îïåðàòîð return
}
Row::Row(vector <double> row) {
	for (auto it : row)
		this->_row.insert(it);
}

int Tableau::push(double elem)
{
	int count = 0;
	for (auto & it : _tableau)
	{
		auto new_elem = it.Shensted_insert(elem);
		elem = new_elem;
		if (new_elem == -1)
			break;
		count++;
	}
	if (elem != -1)
	{
		_tableau.push_back(Row({ elem }));
	}
	_size++;
	return count;
}

void Tableau::insert(int row, double x)
{
	if (row >= _tableau.size())
		_tableau.push_back(Row());
	_tableau[row].Shensted_insert(x);
}

void Tableau::push(vector<double> elems)
{
	for (auto it : elems)
		push(it);
}

int Tableau::size()
{
	return _size;
}

double Tableau::pop(int row)
{
	return _tableau[row].pop();
}

double Tableau::erase(int tmp_row)
{
	double tmp_x = pop(tmp_row);
	for (int i = tmp_row - 1; i >= 0; --i)
	{
		tmp_x = _tableau[i].reverse_Shensted_insert(tmp_x);
	}
	return tmp_x;
}

int Tableau::find(double x)
{
	for (int i = 0; i < _tableau.size(); i++)
		if (_tableau[i].find(x))
			return i;
	return -1;
}

vector<int> Tableau::type()
{
	vector<int> type;
	for (int i = 0; i < _tableau.size(); ++i)
	{
		type.push_back(_tableau[i].size());
	}
	return type;
}

void PQ_tableaux::push(double elem)
{
	int changed_row = _P.push(elem);
	int size = _P.size();
	_Q.insert(changed_row, size);
	_row_number.push_back(changed_row);
}

void PQ_tableaux::push(vector<double> elems)
{
	for (auto it : elems)
		push(it);
}

double PQ_tableaux::pop()
{
	int row = _row_number[_row_number.size() - 1];
	_row_number.pop_back();
	_Q.pop(row);
	return _P.pop(row);
}

double PQ_tableaux::erase()
{
	int tmp_row = _row_number[_row_number.size() - 1];
	double new_x = _P.erase(tmp_row);
	_Q.pop(tmp_row);
	_row_number.pop_back();
	return new_x;
}

void PQ_tableaux::showQ()
{

	cout << "Q:\n" << _Q;
}

void PQ_tableaux::showP()
{
	cout << "P:\n" << _P;
}

int PQ_tableaux::size()
{
	return _P.size();
	return 0;
}
int PQ_tableaux::find(double x)
{
	return(_P.find(x));
}
vector<int> PQ_tableaux::type()
{
	return _P.type();
}
double rand_num() {
	double x = ((rand() ^ (rand() << 16)) % 1000000) / 1000000.0;
	return x;
}
vector <double> rand_vec(int n){
	vector <double> vec;
	for (int i = 0; i < n; i++)
		vec.push_back(rand_num());
	return vec;
}


void permutate(vector<double>& value, const vector<int>& permutation)
{
	auto new_value = value;
	for (int i = 0; i < (int)value.size(); ++i)
	{
		new_value[permutation[i]] = value[i];
	}
	for (int i = 0; i < (int)value.size(); ++i)
	{
		value[i] = new_value[i];
	}
	return;
}

int count_identity_points(vector<double>& vec)
{
	vector<pair<double, int>> new_vec(vec.size());
	for (int i = 0; i < (int)vec.size(); ++i)
	{
		new_vec[i] = { vec[i], i };
	}
	sort(new_vec.begin(), new_vec.end());
	int identity_points = 0;
	for (int i = 0; i < (int)vec.size(); ++i)
	{
		identity_points += new_vec[i].second == i;
	}
	return identity_points;
}
int sum(const vector<double>& vec)
{
	double sum = 0;
	for (auto i : vec)
	{
		sum += i;
	}
	return sum;
}
long randN(long N)
{
	long tmp = rand() ^ (rand() << 16);
	return tmp % N;
}
long double rand01()  
{
	static bool f = false;
	if (!f)
	{
		double tme = time(NULL);
		srand(tme);
		f = true;
	}
	double rand_num = ((rand() ^ (rand() << 16)) % 100000) / 100000.0;
	return rand_num;
}
void init_involution_branch_prob(long double * b, long n)  //count branch prob. for involutions
{
	b[1] = 1;
	for (int i = 1; i < n; ++i)
	{
		b[i + 1] = 1 / (1 + i * b[i]);
	}
	return;
}
ostream& operator <<(ostream& os, const vector<int>& out)  
{
	for (auto i : out)
	{
		os << i << ' ';
	}
	return os;
}
ostream& operator <<(ostream& os, const vector<double>& out)
{
	for (auto i : out)
	{
		os << i << ' ';
	}
	return os;
}

vector<double> operator+(const vector<double> & vec1, const vector<double> & vec2)
{
	vector<double> vec_res(max(vec1.size(), vec2.size()));
	for (int i = 0; i < (int)min(vec1.size(), vec2.size()); ++i)
	{
		vec_res[i] = vec1[i] + vec2[i];
	}
	return vec_res;
}


