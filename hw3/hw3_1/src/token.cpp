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
// name:          the name                                                    //
// precedence:    the precedence                                              //
// associativity: the associativity                                           //
// unary:         the unary function                                          //
// binary:        the binary function                                         //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, uint8_t precedence, bool associativity,
              Unary unary, Binary binary ) {
  this->name_          = name;
  this->number_        = 0;
  this->precedence_    = precedence;
  this->associativity_ = associativity;
  this->unary_         = unary;
  this->binary_        = binary;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a number token                                                  //
//                                                                            //
// Parameters:                                                                //
// number: the number                                                         //
////////////////////////////////////////////////////////////////////////////////
Token::Token( int32_t number ) {
  this->name_          = "#";
  this->number_        = number;
  this->precedence_    = 0x00;
  this->associativity_ = true;
  this->unary_         = NULL;
  this->binary_        = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// Get the precedence of this token                                           //
//                                                                            //
// Return Value:                                                              //
// the precedence of this token                                               //
////////////////////////////////////////////////////////////////////////////////
uint8_t Token::precedence() {
  return this->precedence_;
}

////////////////////////////////////////////////////////////////////////////////
// Run the unary/binary function of this token                                //
//                                                                            //
// Parameters:                                                                //
// stack: the stack of tokens                                                 //
//                                                                            //
// Return Value:                                                              //
// the return value of the unary/binary function                              //
////////////////////////////////////////////////////////////////////////////////
int Token::operator()( TokenStack& stack ) const {
  if ( this->unary_ != NULL ) {
    auto x = stack.top(); stack.pop();
    return this->unary_(x.number_);
  } else {
    auto y = stack.top(); stack.pop();
    auto x = stack.top(); stack.pop();
    return this->binary_(x.number_, y.number_);
  }
}

////////////////////////////////////////////////////////////////////////////////
// The less than operator                                                     //
// Uses precedence to compare                                                 //
//                                                                            //
// Parameters:                                                                //
// rhs: another token object                                                  //
//                                                                            //
// Return Value:                                                              //
// whether this object is more precedent or not                               //
////////////////////////////////////////////////////////////////////////////////
bool Token::operator<( const Token& rhs ) const {
  if ( this->associativity_ ) {
    return (this->precedence_ < rhs.precedence_);
  } else {
    return (this->precedence_ <= rhs.precedence_);
  }
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
  if ( obj.precedence_ == 0 ) {
    return (os << obj.number_);
  } else {
    return (os << obj.name_);
  }
}

}
