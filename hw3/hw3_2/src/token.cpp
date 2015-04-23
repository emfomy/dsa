////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// token.cpp                                                                  //
// The class Token                                                            //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token.hpp"
#include "token_stack.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a punctuation token                                             //
//                                                                            //
// Parameters:                                                                //
// name:          the name                                                    //
// precedence:    the precedence                                              //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, const Type precedence ) {
  this->name_          = name;
  this->number_        = 0;
  this->precedence_    = precedence;
  this->associativity_ = true;
  this->unary_         = NULL;
  this->binary_        = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a unary token                                                   //
//                                                                            //
// Parameters:                                                                //
// name:          the name                                                    //
// precedence:    the precedence                                              //
// associativity: the associativity                                           //
// unary:         the unary function                                          //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, const Type precedence,
              const bool associativity, const Unary unary ) {
  this->name_          = name;
  this->number_        = 0;
  this->precedence_    = precedence;
  this->associativity_ = associativity;
  this->unary_         = unary;
  this->binary_        = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a binary token                                                  //
//                                                                            //
// Parameters:                                                                //
// name:          the name                                                    //
// precedence:    the precedence                                              //
// associativity: the associativity                                           //
// binary:        the binary function                                         //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, const Type precedence,
              const bool associativity, const Binary binary ) {
  this->name_          = name;
  this->number_        = 0;
  this->precedence_    = precedence;
  this->associativity_ = associativity;
  this->unary_         = NULL;
  this->binary_        = binary;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of Token                                                   //
// Initialize a numerical token                                               //
//                                                                            //
// Parameters:                                                                //
// number: the number                                                         //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const Number number ) {
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
Type Token::precedence() {
  return this->precedence_;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a number at the end of this number Token                            //
// multiply the this number by ten and added by the new number                //
////////////////////////////////////////////////////////////////////////////////
void Token::InsertNumber( const Number number ) {
  this->number_ = this->number_*10 + number;
}

////////////////////////////////////////////////////////////////////////////////
// Run the unary/binary function of this token                                //
//                                                                            //
// Input Parameters:                                                          //
// stack: the stack of tokens                                                 //
//                                                                            //
// Output Parameters:                                                         //
// stack: the stack after running the unary/binary function                   //
////////////////////////////////////////////////////////////////////////////////
void Token::operator()( TokenStack& stack ) {
  if ( this->unary_ != NULL ) {
    auto px = stack.top();
    px->number_ = this->unary_(px->number_);
  } else if ( this->binary_ != NULL ) {
    auto py = stack.top(); stack.pop();
    auto px = stack.top();
    px->number_ = this->binary_(px->number_, py->number_);
    delete py;
  } else {
    stack.push(this);
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
// Insert a token object into stream                                          //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// token: the token object to be inserted into the stream                     //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const Token& token ) {
  if ( token.precedence_ == 0 ) {
    return (os << token.number_);
  } else {
    return (os << token.name_);
  }
}

}
