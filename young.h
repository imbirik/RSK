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
ostream& operator <<(ostream&, const vector<double>&);   //Output operator for vector
//class template <T>;
vector<double> operator +(
	const vector<double> &,
	const vector<double> &
	); 
void permutate(vector<double> &, const vector<int> &);   //Apply permutation to vector
int count_identity_points(vector<double>&);              //Count the number of identity points
int sum(const vector<double>&);
long double rand01();               //Return random number from [0, 1]
long randN(long N);
template <typename T>
inline void rand_permute_self_inverse(
	T*,	long, long *,
	long double *, bool);                                //Return involution of length n
void init_involution_branch_prob(long double*, long);    //Count branch probabilities for generating random involution 


//implementation

template <typename T>                                    //not finished yet, надо что-то с деструктором сделать
inline void rand_permute_self_inverse(T *f, long n,
	long *tr = 0,
	long double *tb = 0, bool bi = false)
	// Permute the elements of f by a random involution.
	// Set bi:=true to signal that the branch probabilities in tb[]
	// have been precomputed (via init_involution_branch_ratios()).
{
	long *r = tr;
	if (tr == 0) r = new long[n];
	for (long k = 0; k < n; ++k) r[k] = k;
	long nr = n;                                         // number of elements available
	                                                     // available positions are r[0], ..., r[nr-1]

	long double *b = tb;
	if (tb == 0) { b = new long double[n]; bi = false; }
	if (!bi) init_involution_branch_prob(b, n);

	while (nr >= 2)
	{
		const long x1 = nr - 1;                           // choose last element
		const long r1 = r[x1];                            // available position
		                                                  // remove from set:
		--nr;                                             // no swap needed if x1==last

		const long double rat = b[nr];                    // probability to choose fixed point

		const long double t = rand01();                   // 0 <= t < 1
		if (t > rat)                                      // 2-cycle
		{
			const long x2 = randN(nr);
			const long r2 = r[x2];                        // random available position != r1
			--nr; swap(r[x2], r[nr]);                     // remove from set
			swap(f[r1], f[r2]);                           // create a 2-cycle
		}
		                                                  // else fixed point, nothing to do
	}

	//if (tr == 0) delete[] r;
	//if (tb == 0) delete[] b;
}