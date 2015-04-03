////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 1                                //
// biginteger_for_binary.cpp                                                  //
// The header file of BigInteger for binary                                   //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

#ifndef BIGINTEGER_FOR_BINARY

#define BIGINTEGER_FOR_BINARY

const int kBase = 100;

////////////////////////////////////////////////////////////////////////////////
// The big integer class                                                      //
////////////////////////////////////////////////////////////////////////////////
class BigInteger{
private:
  list<int> digits;

  void carry();
  void shorten();

public:
  BigInteger();
  BigInteger( const int& );
  BigInteger( const string& );
  BigInteger( const BigInteger& );
  ~BigInteger();

  bool operator<( const BigInteger& ) const;
  const BigInteger operator-( const BigInteger& ) const;
  const BigInteger operator*( const BigInteger& ) const;
  BigInteger& operator*=( int );
  BigInteger& operator/=( int );
  BigInteger& operator=( const BigInteger& );
  bool iseven() const;
  bool iszero() const;

  friend ostream& operator<<( ostream&, const BigInteger& );
};

#endif
