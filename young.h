#pragma once
#include <set>
#include <vector>

using namespace std;

class Row {                                             //Row of Young tableau consisting of real numbers
public:
	Row() {}
	Row(vector <double>);
	int size();
	double reverse_Shensted_insert(double);             //Reverse bumping
	friend ostream& operator<<(ostream&, Row&);         //Printing the row
	double Shensted_insert(double);                     //Classical row bumping
	double pop();                                       //Delete the bigest element and return it 
	bool find(double x);                                //Return is there such an element
private:
	multiset <double> _row;
};


class Tableau                                           // Young Tableau
{
public:
	Tableau() : _size(0) {}
	int push(double);                                          //Insert an element in the tableau
	void insert(int, double);                                  //Tnsert an element in the row of the tableau
	void push(vector<double>);                                 //Insert several elements in given order
	friend ostream& operator<<(ostream&, Tableau&);            //Print the tableau
	friend void print_collection_of_Tableau(vector<Tableau>);  //Print the collection of tableaux
	int size();
	double pop(int);                                           //Delete the bigest an element from the row
	double erase(int);                                         //Reverse bumping from the tableau
	int find(double);                                          //Return the minimal number of a row which contains the element or -1 if there is not such a row 
	vector<int> type();
private:
	vector<Row> _tableau;
	int _size;
};


class PQ_tableaux                                       //Pair of inserting and recording Young tableaux
{
public:
	void push(double);                                  //Insert the element in inserting tableau and its counting number in recording tableau
	void push(vector <double>);                         //Insert several elements in given order in the way describing ...
	double pop();                                       //Delete the element and its pair from the given row 
	double erase();                                     //Reverse bumping from the pair of tableaux
	friend ostream& operator<<(ostream&, PQ_tableaux&); //Print the pair of tableaux 
	void showQ();                                       //Print only recording tableau
	void showP();
	int size();
	int find(double);
	vector<int> type();
private:
	Tableau _P, _Q;
	vector <int> _row_number;
};
double rand_num();
vector <double> rand_vec(int);


ostream& operator <<(ostream&, const vector<int>&);      //Output operator for vector
ostream& operator <<(ostream&, const vector<double>&);      //Output operator for vector
//class template <T>;
vector<double> operator +(const vector<double>& vec1, const vector<double>& vec2); 
void permutate(vector<double>&, const vector<int>&);     //Apply permutation to vector
int count_identity_points(vector<double>&);              //Count the number of identity points
int sum(const vector<double>&);
long double get_rand_from_unit_interval();
template <typename T>
inline void rand_permute_self_inverse(T*, long);
void init_involution_branch_prob(long double*, long);
