////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token.hpp                                                                  //
// The header file of Token                                                   //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_1_TOKEN_HPP_

#define HW3_1_TOKEN_HPP_

#include <iostream>
#include <cstdint>
#include "hw3.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The class of a token                                                       //
////////////////////////////////////////////////////////////////////////////////
class Token
{
 private:
  // The name of this token.
  // Empty means this token is a number.
  std::string name_;

  // The number of this token.
  // '0' for non-numeric tokens.
  int32_t number_;

  // The precedence of this token.
  // '-1' means this token is a number.
  int8_t precedence_;

  // The associativity of this token.
  // 'true'  means the token is left-to-right.
  // 'false' means the token is right-to-left.
  bool  associativity_;

 public:
  Token( const char*, int8_t, bool );
  Token( int32_t );
  bool operator<( const Token& ) const;
  friend std::ostream& operator<<( std::ostream&, const Token& );
};

////////////////////////////////////////////////////////////////////////////////
// Non-numeric tokens                                                         //
////////////////////////////////////////////////////////////////////////////////
const Token kLeftParenthesis   = Token("(" , 0,  true); // left parenthesis
const Token kRightParenthesis  = Token(")" , 0,  true); // right parenthesis
// Level three
const Token kUnaryPlus         = Token("+" , 3, false); // unary plus
const Token kUnaryMinus        = Token("-" , 3, false); // unary minus
const Token kLogicalNOT        = Token("!" , 3, false); // logical NOT
const Token kBitwiseNOT        = Token("~" , 3, false); // bitwise NOT
  // Level five
const Token kMultiplication    = Token("*" , 5,  true); // multiplication
const Token kDivision          = Token("/" , 5,  true); // division
const Token kModulo            = Token("%%", 5,  true); // modulo
  // Level six
const Token kAddition          = Token("+" , 6,  true); // addition
const Token kSubtraction       = Token("-" , 6,  true); // subtraction
const Token kBitwiseLeftShift  = Token("<<", 6,  true); // bitwise left shift
const Token kBitwiseRightShift = Token(">>", 6,  true); // bitwise right shift
  // Level ten
const Token kBitwiseAND        = Token("&" , 10, true); // bitwise AND
  // Level eleven
const Token kBitwiseXOR        = Token("^" , 11, true); // bitwise XOR
  // Level twelve
const Token kBitwiseOR         = Token("|" , 12, true); // bitwise OR
  // Level thirteen
const Token kLogicalAND        = Token("&&", 13, true); // logical AND
  // Level fourteen
const Token kLogicalOR         = Token("||", 14, true); // logical OR

}

#endif
