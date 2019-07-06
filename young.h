#pragma once
#include <vector>
using namespace std;
int my_lower_bound(const vector<double> &, double);
int my_upper_bound(const vector<double> &, double);
bool my_find(const vector<double> &, double);

class Row {
public:
	Row(){}
	Row(vector <double>);
	int size();
	double reverse_Shensted_insert(double);
	friend ostream& operator<<(ostream&, Row&);
	double Shensted_insert(double);
	double pop();
	bool find(double x);
private:
	vector <double> _row;
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
	double pop(int);
	double erase(int);
	int find(double);
private:
	vector<Row> _tableaux;
	int _size;
};

class PQ_tableaux
{
public:
    void push(double);
	void push(vector <double>);
	double pop();
	double erase();
	friend ostream& operator<<(ostream&, PQ_tableaux&);
	void showQ();
	void showP();
	int size();
	int find(double);
private:
	Tableaux _P, _Q, _link;
	vector <int> _row_number;
};
