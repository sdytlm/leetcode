/* Implement pow(x,n);
 *
 */

#include<iostream>
using namespace std;

class Solution {

public:
    double pow(double x, int n) {

		double result;
			if(n>0)
			  result = pow_recursive(x,n);        // n >0
			else
			  result = 1.0/pow_recursive(x,-n);   // n < 0
		return result;
		}

	double pow_recursive(double x, int n) {	
			if(n==0)
			  return 1.0;
			double result=1.0;
			result = pow_recursive(x,n/2);
			if(n%2==0)                           // n is even
			  return result*result;
			else                                 // n is odd
			  return result*result*x;
		}

};


