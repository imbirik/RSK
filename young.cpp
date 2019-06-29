#include <set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include"young.h"
using namespace std;

int Row::size() {
	return _row.size();
}
double Row::Shensted_insert(double x)
{
	auto y = upper_bound(_row.begin(), _row.end(), x);
	if (y == _row.end()) {
		_row.insert(x);
		return -1;
	}
	double new_x = *y;
	_row.erase(new_x);
	_row.insert(x);
	return new_x;
}
ostream& operator<<(ostream& out, Row& obj) {
	for (auto it : obj._row)
		out << it << ' ';
	return out;
}
ostream & operator<<(ostream & out, Tableaux & T)
{
	for (auto it : T._tableaux)
		out << it << "\n";
	return out;
	// TODO: вставьте здесь оператор return
}
ostream & operator<<(ostream & out, PQ_tableaux & PQ)
{
	out << "P:\n" << PQ._P << "Q:\n" << PQ._Q;
	return out;
	// TODO: вставьте здесь оператор return
}
Row::Row(vector <double> row) {
	for (auto it : row)
		this->_row.insert(it);
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

void PQ_tableaux::push(double elem)
{
	int tmp_row = _P.push(elem);
	int size = _P.size();
	_Q.insert(tmp_row, size);
}

void PQ_tableaux::push(vector<double> elems)
{
	for (auto it : elems)
		push(it);
}
