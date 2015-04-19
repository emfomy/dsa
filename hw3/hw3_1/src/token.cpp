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
// name:   the name                                                           //
// name:   the precedence                                                     //
// name:   the associativity                                                  //
// unary:  the unary function                                                 //
// binary: the binary function                                                //
////////////////////////////////////////////////////////////////////////////////
Token::Token( const char* name, int8_t precedence, bool associativity,
              Unary unary, Binary binary ) {
  this->name_          = name;
  this->number_        = 0;
  this->associativity_ = associativity;
  this->isunary_       = (unary != NULL);
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
  this->name_          = "";
  this->number_        = number;
  this->precedence_    = -1;
  this->associativity_ = true;
  this->isunary_       = true;
  this->unary_         = NULL;
  this->binary_        = NULL;
}

////////////////////////////////////////////////////////////////////////////////
// Get the name of this token                                                 //
//                                                                            //
// Return Value:                                                              //
// the name of this token                                                     //
////////////////////////////////////////////////////////////////////////////////
std::string Token::name() {
  return this->name_;
}

////////////////////////////////////////////////////////////////////////////////
// Get the associativity of this token                                        //
//                                                                            //
// Return Value:                                                              //
// the associativity of this token                                            //
////////////////////////////////////////////////////////////////////////////////
bool Token::associativity() {
  return this->associativity_;
}

////////////////////////////////////////////////////////////////////////////////
// Whether the token is unary or not                                          //
//                                                                            //
// Return Value:                                                              //
// 'true'  means the token is unary                                           //
 // 'false' means the token is binary                                         //
////////////////////////////////////////////////////////////////////////////////
bool Token::isunary() {
  return isunary_;
}

////////////////////////////////////////////////////////////////////////////////
// The unary function of this token                                           //
//                                                                            //
// Parameters:                                                                //
// x: a number token object                                                   //
//                                                                            //
// Return Value:                                                              //
// the return value of the unary function                                     //
////////////////////////////////////////////////////////////////////////////////
int Token::unary( const int x ) {
  return this->unary_(x);
}

////////////////////////////////////////////////////////////////////////////////
// The binary function of this token                                          //
//                                                                            //
// Parameters:                                                                //
// x: a number token object                                                   //
// y: a number token object                                                   //
//                                                                            //
// Return Value:                                                              //
// the return value of the binary function                                    //
////////////////////////////////////////////////////////////////////////////////
int Token::binary( const int x, const int y ) {
  return this->binary_(x, y);
}

////////////////////////////////////////////////////////////////////////////////
// The smaller than operator                                                  //
// Uses precedence to compare                                                 //
//                                                                            //
// Parameters:                                                                //
// rhs: another token object                                                  //
//                                                                            //
// Return Value:                                                              //
// the whether this object is smaller or not                                  //
////////////////////////////////////////////////////////////////////////////////
bool Token::operator<( const Token& rhs ) const {
  return (precedence_ < rhs.precedence_);
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
