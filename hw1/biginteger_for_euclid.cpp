////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 1                                //
// biginteger_for_euclid.cpp                                                  //
// The class BigInteger for binary                                            //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <cstring>

#ifndef BIGINTEGER_FOR_BINARY
#include "biginteger_for_euclid.h"
#endif


////////////////////////////////////////////////////////////////////////////////
// The constructor of BigInteger                                              //
//                                                                            //
// Initialize the value to zero                                               //
////////////////////////////////////////////////////////////////////////////////
BigInteger::BigInteger() {
}


////////////////////////////////////////////////////////////////////////////////
// The constructor of BigInteger                                              //
//                                                                            //
// Initialize the value to the given integer                                  //
//                                                                            //
// Parameters:                                                                //
// inum: an integer number                                                    //
////////////////////////////////////////////////////////////////////////////////
BigInteger::BigInteger( const int& inum ) {
  int itmp = inum;
  while ( itmp ) {
    this->digits.push_back(itmp % kBase);
    itmp /= kBase;
  }
}


////////////////////////////////////////////////////////////////////////////////
// The constructor of BigInteger                                              //
//                                                                            //
// Initialize the value to the given string                                   //
//                                                                            //
// Parameters:                                                                //
// str: a string number                                                       //
////////////////////////////////////////////////////////////////////////////////
BigInteger::BigInteger( const string& str ) {
  bool btmp = true;
  for ( auto rit = str.crbegin(); rit != str.crend(); ++rit, btmp = !btmp ) {
    if ( btmp ) {
      this->digits.push_back(*rit-'0');
    } else {
      this->digits.back() += (*rit-'0') * 10;
    }
  }

  // Shorten
  this->shorten();
}


////////////////////////////////////////////////////////////////////////////////
// The constructor of BigInteger                                              //
//                                                                            //
// Initialize the value to the given BigInteger                               //
//                                                                            //
// Parameters:                                                                //
// binum: a BigInteger                                                        //
////////////////////////////////////////////////////////////////////////////////
BigInteger::BigInteger( const BigInteger& binum ) {
  this->digits = binum.digits;
}


////////////////////////////////////////////////////////////////////////////////
// The destructor of BigInteger                                               //
////////////////////////////////////////////////////////////////////////////////
BigInteger::~BigInteger() {
}


////////////////////////////////////////////////////////////////////////////////
// The less than operator of BigInteger                                       //
//                                                                            //
// Parameters:                                                                //
// that: another BigInteger                                                   //
//                                                                            //
// Return Value:                                                              //
// whether this value is smaller or not                                       //
////////////////////////////////////////////////////////////////////////////////
bool BigInteger::operator<( const BigInteger& that ) const {
  // Compare
  if ( this->digits.size() != that.digits.size() ) { // Different size
    return (this->digits.size() < that.digits.size());
  } else { // Same size
    for ( auto rit0 = this->digits.crbegin(), rit1 = that.digits.crbegin();
        rit0 != this->digits.crend(); ++rit0, ++rit1 ) {
      if ( *rit0 != *rit1 ) {
        return (*rit0 < *rit1);
      }
    }
  }
  return false; // Same value;
}


////////////////////////////////////////////////////////////////////////////////
// The subtraction operator of BigInteger                                     //
//                                                                            //
// Parameters:                                                                //
// that: the minuend BigInteger                                               //
//                                                                            //
// Return Value:                                                              //
// the difference BigInteger                                                  //
////////////////////////////////////////////////////////////////////////////////
const BigInteger BigInteger::operator-( const BigInteger& that ) const {
  BigInteger ans;
  auto it0 = this->digits.cbegin(), it1 = that.digits.cbegin();

  // Subtract
  if ( this->digits.size() < that.digits.size() ) { // This shorter
    for ( ; it0 != this->digits.end(); ++it0, ++it1 ) {
      ans.digits.push_back(*it0 - *it1);
    }
    for ( ; it1 != that.digits.end(); ++it1 ) {
      ans.digits.push_back(-*it1);
    }
  } else { // That shorter
    for ( ; it1 != that.digits.end(); ++it0, ++it1 ) {
      ans.digits.push_back(*it0 - *it1);
    }
    for ( ; it0 != this->digits.end(); ++it0 ) {
      ans.digits.push_back(*it0);
    }
  }

  // Carry
  ans.carry();

  return ans;
}


////////////////////////////////////////////////////////////////////////////////
// The modulus operator of BigInteger                                         //
//                                                                            //
// Parameters:                                                                //
// that: the divisor BigInteger                                               //
//                                                                            //
// Return Value:                                                              //
// the remainder BigInteger                                                   //
////////////////////////////////////////////////////////////////////////////////
const BigInteger BigInteger::operator%( const BigInteger& that ) const {
  BigInteger ans(*this), bitmp(that);

  // Divide
  while ( ans.digits.size() > bitmp.digits.size() ) {
    bitmp.digits.push_front(0);
  }
  while ( bitmp.digits.size() >= that.digits.size() ) {
    while ( !(ans < bitmp) ) {
      ans = ans - bitmp;
    }
    bitmp.digits.pop_front();
  }

  return ans;
}


////////////////////////////////////////////////////////////////////////////////
// The move assignment operator of BigInteger                                 //
//                                                                            //
// Parameters:                                                                //
// inum: another integer                                                      //
//                                                                            //
// Return Value:                                                              //
// this BigInteger                                                            //
////////////////////////////////////////////////////////////////////////////////
BigInteger& BigInteger::operator=( const BigInteger& that ) {
  this->digits = that.digits;

  return *this;
}


////////////////////////////////////////////////////////////////////////////////
// Zero test                                                                  //
//                                                                            //
// Return Value:                                                              //
// whether the value is zero or not                                           //
////////////////////////////////////////////////////////////////////////////////
bool BigInteger::iszero() const {
  return this->digits.empty();
}


////////////////////////////////////////////////////////////////////////////////
// Insert formatted output                                                    //
//                                                                            //
// Parameters:                                                                //
// out:   the ostream object                                                  //
// binum: the BinInteger to be formatted and inserted into the stream         //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& out, const BigInteger& binum) {
  if ( binum.iszero() ) {
    return (out << 0);
  }
  for ( auto rit = binum.digits.crbegin(); rit != binum.digits.crend(); ++rit ) {
    if ( *rit < 10 && rit != binum.digits.crbegin() ) {
      out << '0' << *rit;
    } else {
      out << *rit;
    }
  }
  return out;
}


////////////////////////////////////////////////////////////////////////////////
// Carry the digits and remove the leading zeros                              //
////////////////////////////////////////////////////////////////////////////////
void BigInteger::carry() {
  int itmp = 0;

  for ( auto it = this->digits.begin(); it != this->digits.end(); ++it ) {
    *it += itmp;
    itmp = *it / kBase;
    *it %= kBase;
    while ( *it < 0 ) {
      --itmp;
      *it += kBase;
    }
  }
  if ( itmp < 0 ) {
    printf("This number is negative!\n");
    return;
  }
  while ( itmp ) {
    this->digits.push_back(itmp % kBase);
    itmp /= kBase;
  }
  this->shorten();
}


////////////////////////////////////////////////////////////////////////////////
// Remove the leading zeros                                                   //
////////////////////////////////////////////////////////////////////////////////
void BigInteger::shorten() {
  while ( !(this->digits.empty() || this->digits.back()) ) {
    this->digits.pop_back();
  }
}
