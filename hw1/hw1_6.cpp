////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 1                                //
// hw1_6.cpp                                                                  //
// GCD algorithms                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <cstdio>

#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b

// Global variables
int iter0, iter1, iter2, iter3, iter4;

// Functions
int gcd_by_reverse_search( const int, const int );
int gcd_by_filter( const int, const int );
int gcd_by_filter_faster( const int, const int );
int gcd_by_filter_faster_internel( const int, const int, const int );
int gcd_by_binary( const int, const int );
int gcd_by_euclid( const int, const int );


////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main()
{
  int a, b, d;
  while ( true ) {
    // Load data
    scanf("%d", &a);
    if ( a == 0 ) {
      break;
    }
    scanf("%d", &b);

    // GCD-By-Reverse-Search
    iter0 = 0;
    d = gcd_by_reverse_search(a, b);
    printf(
        "Case (%d, %d): GCD-By-Reverse-Search = %d, taking %d iterations\n",
        a, b, d, iter0);

    // GCD-By-Filter
    iter1 = 0;
    d = gcd_by_filter(a, b);
    printf(
        "Case (%d, %d): GCD-By-Filter = %d, taking %d iterations\n",
        a, b, d, iter1);

    // GCD-By-Filter-Faster
    iter2 = 0;
    d = gcd_by_filter_faster(a, b);
    printf(
        "Case (%d, %d): GCD-By-Filter-Faster = %d, taking %d iterations\n",
        a, b, d, iter2);

    // GCD-By-Binary
    iter3 = 0;
    d = gcd_by_binary(a, b);
    printf(
        "Case (%d, %d): GCD-By-Binary = %d, taking %d iterations\n",
        a, b, d, iter3);

    // GCD-By-Euclid
    iter4 = 0;
    d = gcd_by_euclid(a, b);
    printf(
        "Case (%d, %d): GCD-By-Euclid = %d, taking %d iterations\n",
        a, b, d, iter4);
  }
  return 0;
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by searching reversely                                            //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_reverse_search( const int a, const int b ) {
  for ( int i = min(a, b); i >= 1; i-- ) {
    iter0++;
    if ( !(a % i || b % i) ) {
      return i;
    }
  }
  return 0;
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by filter                                                         //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_filter( const int a, const int b ) {
  int n = min(a, b);
  for ( int i = 2; i <= n; i++ ) {
    iter1++;
    if ( !(a % i || b % i) ) {
      return i * gcd_by_filter(a/i, b/i);
    }
  }
  return 1;
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by filter faster                                                  //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_filter_faster( const int a, const int b ) {
  return gcd_by_filter_faster_internel(a, b, 2);
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by filter faster - internel                                       //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
// s: a parameter                                                             //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_filter_faster_internel( const int a, const int b, const int s ) {
  int n = min(a, b);
  for ( int i = s; i <= n; i++ ) {
    iter2++;
    if ( !(a % i || b % i) ) {
      return i * gcd_by_filter_faster_internel(a/i, b/i, i);
    }
  }
  return 1;
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by binary                                                         //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_binary( const int a, const int b ) {
  int n = min(a, b);
  int m = max(a, b);
  int ans = 1;
  int tmp;
  while ( n && m ) {
    iter3++;
    if ( !( n % 2 || m % 2 ) ) {
      n /= 2;
      m /= 2;
      ans *= 2;
    } else if ( !(n % 2) && (m % 2) ) {
      n /= 2;
    } else if ( (n % 2) && !(m % 2) ) {
      m /= 2;
    }
    if ( n > m ) {
      tmp = n;
      n = m;
      m = tmp;
    }
    m -= n;
  }
  return n * ans;
}


////////////////////////////////////////////////////////////////////////////////
// Find GCD by Euclid's algorithm                                             //
//                                                                            //
// Parameters:                                                                //
// a: the first number                                                        //
// b: the second number                                                       //
//                                                                            //
// Return Value:                                                              //
// the GCD of a and b                                                         //
////////////////////////////////////////////////////////////////////////////////
int gcd_by_euclid( const int a, const int b ) {
  int n = min(a, b);
  int m = max(a, b);
  int tmp;
  while ( m % n ) {
    iter4++;
    tmp = n;
    n = m % n;
    m = tmp;
  }
  return n;
}
