#include <set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include"young.h"
#include<random>
using namespace std;

int my_lower_bound(const vector<double> & v, double x)
{
	int left = 0, right = int(v.size());
	while (left < right - 1)
	{
		int mid = (left + right) / 2;
		if (x >= v[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int my_upper_bound(const vector<double> & v, double x)
{
	int left = 0, right = int(v.size());
	while (left < right - 1)
	{
		int mid = (left + right) / 2;
		if (x > v[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	if (!v.empty() && v[left] <= x)
	{
		return left + 1;
	}
	return left;
}

int Row::size() {
	return _row.size();
}
double Row::reverse_Shensted_insert(double x)
{	
	auto y = (my_lower_bound(_row, x) - 1);
	double new_x = _row[y];
	_row[y] = x;
	return new_x;
}
double Row::Shensted_insert(double x)
{
	auto y = my_upper_bound(_row, x);
	if (y == _row.size()) {
		_row.push_back(x);
		return -1;
	}
	double new_x = _row[y];
	_row[y] = x;
	return new_x;
}
double Row::pop()
{
	int elem = *(--_row.end());
	_row.erase((--_row.end()));
	return elem;
}
bool my_find(const vector<double> & v, double x)
{
	int left = 0, right = int(v.size());
	while (left < right - 1)
	{
		int mid = (left + right) / 2;
		if (x >= v[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return v[left] == x;
}
bool Row::find(double x)
{
	return my_find(_row, x);
}
ostream& operator<<(ostream& out, Row& obj) {
	for (auto it : obj._row)
		out << it << ' ';
	return out;
}
ostream & operator<<(ostream & out, Tableaux & T)
{
	for (auto it : T._tableaux)
		if (it.size() != 0)
			out << it << "\n";
	return out;
	// TODO: �������� ����� �������� return
}
ostream & operator<<(ostream & out, PQ_tableaux & PQ)
{
	out << "P:\n" << PQ._P << "Q:\n" << PQ._Q;
	return out;
	// TODO: �������� ����� �������� return
}
Row::Row(vector <double> row) {
	sort(row.begin(), row.end());
	for (auto it : row)
		this->_row.push_back(it);
}

int Tableaux::push(double elem)
{
	int count = 0;
	for (auto & it : _tableaux)
	{
		auto new_elem = it.Shensted_insert(elem);
		elem = new_elem;
		if (new_elem == -1)
			break;
		count++;
	}
	if (elem != -1)
	{
		_tableaux.push_back(Row({ elem }));
	}
	_size++;
	return count;
}

void Tableaux::insert(int row, double x)
{
	if (row >= _tableaux.size())
		_tableaux.push_back(Row());
	_tableaux[row].Shensted_insert(x);
}

void Tableaux::push(vector<double> elems)
{
	for (auto it : elems)
		push(it);
}

int Tableaux::size()
{
	return _size;
}

double Tableaux::pop(int row)
{
	return _tableaux[row].pop();
}

double Tableaux::erase(int tmp_row)
{
	double tmp_x = pop(tmp_row);
	for (int i = tmp_row - 1; i >= 0; --i)
	{
		tmp_x = _tableaux[i].reverse_Shensted_insert(tmp_x);
	}
	return tmp_x;
}

int Tableaux::find(double x)
{
	for (int i = 0; i < _tableaux.size(); i++)
		if (_tableaux[i].find(x))
			return i;
	return -1;
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
