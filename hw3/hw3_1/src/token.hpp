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
#include <stack>
#include "hw3.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

typedef int (*Unary)(const int);
typedef int (*Binary)(const int, const int);

////////////////////////////////////////////////////////////////////////////////
// The stack of Token                                                         //
////////////////////////////////////////////////////////////////////////////////
class Token;
typedef std::stack<Token> StackToken;

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
  bool associativity_;

  // The unary operator
  Unary unary_;

  // The binary operator
  Binary binary_;

 public:
  Token( const char*, int8_t, bool, Unary, Binary );
  Token( int32_t );

  std::string name();
  bool associativity();

  int operator()( StackToken& ) const;
  bool operator<( const Token& ) const;
  friend std::ostream& operator<<( std::ostream&, const Token& );
};

////////////////////////////////////////////////////////////////////////////////
// Non-numeric tokens                                                         //
////////////////////////////////////////////////////////////////////////////////
const Token kLeftParenthesis =
    Token("(" , 0,  true, NULL, NULL);
const Token kRightParenthesis =
    Token(")" , 0,  true, NULL, NULL);
// Level three
const Token kUnaryPlus =
    Token("+" , 3, false, [](int x)->int{return (+x);}, NULL);
const Token kUnaryMinus =
    Token("-" , 3, false, [](int x)->int{return (-x);}, NULL);
const Token kLogicalNOT =
    Token("!" , 3, false, [](int x)->int{return (!x);}, NULL);
const Token kBitwiseNOT =
    Token("~" , 3, false, [](int x)->int{return (~x);}, NULL);
// Level five
const Token kMultiplication =
    Token("*" , 5,  true, NULL, [](int x, int y)->int{return (x * y);});
const Token kDivision =
    Token("/" , 5,  true, NULL, [](int x, int y)->int{return (x / y);});
const Token kModulo =
    Token("%" , 5,  true, NULL, [](int x, int y)->int{return (x % y);});
// Level six
const Token kAddition =
    Token("+" , 6,  true, NULL, [](int x, int y)->int{return (x + y);});
const Token kSubtraction =
    Token("-" , 6,  true, NULL, [](int x, int y)->int{return (x - y);});
const Token kBitwiseLeftShift =
    Token("<<", 6,  true, NULL, [](int x, int y)->int{return (x << y);});
const Token kBitwiseRightShift =
    Token(">>", 6,  true, NULL, [](int x, int y)->int{return (x >> y);});
// Level ten
const Token kBitwiseAND =
    Token("&" , 10, true, NULL, [](int x, int y)->int{return (x & y);});
// Level eleven
const Token kBitwiseXOR =
    Token("^" , 11, true, NULL, [](int x, int y)->int{return (x ^ y);});
// Level twelve
const Token kBitwiseOR =
    Token("|" , 12, true, NULL, [](int x, int y)->int{return (x | y);});
// Level thirteen
const Token kLogicalAND =
    Token("&&", 13, true, NULL, [](int x, int y)->int{return (x && y);});
// Level fourteen
const Token kLogicalOR =
    Token("||", 14, true, NULL, [](int x, int y)->int{return (x || y);});

}

#endif
