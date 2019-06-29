#include<vector>
#include<iostream>
#include "young.h"
using namespace std;

int main() {
	PQ_tableaux PQ;
	PQ.push({ 5, 4, 8, 2, 3,4,1,7,5,3,1 });
	cout << PQ;
	return 0;
}