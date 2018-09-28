/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task3.cpp
 */

/*
  MIT License

  Copyright (c) 2018 Tyler Gearing, Mei Williams

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in 
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <algorithm>  

using namespace std;

// Function prototypes
vector<unsigned long> sieve (unsigned long);
vector<unsigned long> msp(vector<unsigned long>, vector<unsigned long>);
vector<unsigned long> createVect(unsigned long);

int main () {

	srand(time(NULL));

	unsigned long m = 300;
	unsigned long n = 40;
	vector<unsigned long> mvect = createVect(m);
	vector<unsigned long> nvect = createVect(n);

	vector<unsigned long> c = msp(mvect, nvect);

	cout << "c.size()" << c.size() << endl;

	for(unsigned long i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	
	return 0;
}

vector<unsigned long> sieve (unsigned long n) {

	vector<bool> A(n);
	vector<unsigned long> p(n);
	
	for(int i = 0; i < n; ++i)
		A[i] = 1;
	
	for(unsigned long i = 2; i*i <= n; ++i) {
		if(A[i]) {
			for(unsigned long j = i*2; j <= n; j += i) {
				A[j] = 0;
			}
		}
	}
	for(int i = 0; i < A.size(); ++i)
		if(A[i])
			p.push_back(i);
	return p;
}

vector<unsigned long> msp(vector<unsigned long> mvect,
						  vector<unsigned long> nvect) { 
	vector<unsigned long> msp;
	//unsigned long num;

	vector<unsigned long>::iterator itm = mvect.begin();
	vector<unsigned long>::iterator itn = nvect.begin();

	while(itm != mvect.end() && itn != nvect.end()) {
		if(*itm < *itn)
			itm++;
		else if( *itn < *itm)
			itn++;
		else {
			itm++;
			itn++;
			if(*itn != 0) 
				msp.push_back(*itn);
		}
	}
	cout << "msp size: " << msp.size() << endl;
	return msp;
}

vector<unsigned long> createVect(unsigned long n) {
	vector<unsigned long> vect;
	unsigned long num = 0;
	/* generate random number between 1 and n/2: */
	for(int i = 1; i < ((n/2) + 1); ++i) {		
	   num = rand()%i + 1;
	   vect.push_back(num);
	}

	sort(vect.begin(), vect.end());
	
	return vect;
}
