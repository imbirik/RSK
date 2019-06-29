#pragma once
#include <set>
using namespace std;
class Row {
public:
	Row(){}
	Row(vector <double>);
	int size();
	double Shensted_insert();
	friend ostream& operator<<(ostream&, Row&);
	double Shensted_insert(double x);
private:
	multiset <double> _row;
};
class Tableaux
{
public:
	Tableaux() : _size(0) {}
	int push(double);
	void insert(int,double);
	void push(vector<double>);
	friend ostream& operator<<(ostream&, Tableaux&);
	int size();

private:
	vector<Row> _tableaux;
	int _size;
};

class PQ_tableaux
{
public:
	void push(double);
	void push(vector <double>);
	friend ostream& operator<<(ostream&, PQ_tableaux&);
private:
	Tableaux _P, _Q;
};

