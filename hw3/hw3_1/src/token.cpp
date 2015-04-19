////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token.cpp                                                                  //
// The class Token                                                            //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a symbol token                                                  //
//                                                                            //
// Parameters:                                                                //
// name: the name                                                             //
// name: the precedence                                                       //
// name: the associativity                                                    //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, int8_t precedence, bool associativity ) {
  this->name_          = name;
  this->number_        = 0;
  this->associativity_ = associativity;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a number token                                                  //
//                                                                            //
// Parameters:                                                                //
// number: the number                                                         //
////////////////////////////////////////////////////////////////////////////////
Token::Token( int32_t number ) {
  this->name_          = "";
  this->number_        = number;
  this->precedence_    = -1;
  this->associativity_ = true;
}

////////////////////////////////////////////////////////////////////////////////
// The smaller than operator                                                  //
//                                                                            //
// Parameters:                                                                //
// rhs: another token object                                                  //
//                                                                            //
// Return Value:                                                              //
// the whether this object is smaller or not                                  //
////////////////////////////////////////////////////////////////////////////////
bool Token::operator<( const Token& rhs ) const {
  return (level_ < rhs.level_);
}

////////////////////////////////////////////////////////////////////////////////
// Insert into stream                                                         //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the token object to be inserted into the stream                       //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const Token& obj ) {
  if ( obj.precedence_ >= 0 ) return (os << obj.name_);
  else                        return (os << obj.number_);
}

}
