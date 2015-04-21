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
#include <queue>
#include <stack>
#include <string>
#include "hw3.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

typedef Number (*Unary)(const Number);
typedef Number (*Binary)(const Number, const Number);

////////////////////////////////////////////////////////////////////////////////
// The queue and stack of Token                                               //
////////////////////////////////////////////////////////////////////////////////
class Token;
typedef std::queue<Token> TokenQueue;
typedef std::stack<Token> TokenStack;

////////////////////////////////////////////////////////////////////////////////
// The class of a token                                                       //
////////////////////////////////////////////////////////////////////////////////
class Token
{
 private:
  // The name of this token.
  // "#" means this token is a number.
  std::string name_;

  // The number of this token.
  // '0' for non-numeric tokens.
  Number number_;

  // The precedence of this token.
  // '0x00' means this token is a number.
  // '0xFF' means this token is a left parenthesis.
  // '0xFE' means this token is a right parenthesis.
  Type precedence_;

  // The associativity of this token.
  // 'true'  means the token is left-to-right.
  // 'false' means the token is right-to-left.
  bool associativity_;

  // The unary operator
  Unary unary_;

  // The binary operator
  Binary binary_;

 public:
  Token( const char*, Type, bool, Unary, Binary );
  Token( Number );

  Type precedence();

  void operator()( TokenStack& ) const;
  bool operator<( const Token& ) const;
  friend std::ostream& operator<<( std::ostream&, const Token& );
};

////////////////////////////////////////////////////////////////////////////////
// Non-numeric tokens                                                         //
////////////////////////////////////////////////////////////////////////////////
const Token kTokenLeftParenthesis =
    Token("(" , 0xFF, true, NULL, NULL);
const Token kTokenRightParenthesis =
    Token(")" , 0xFE, true, NULL, NULL);
// Level three
const Token kTokenUnaryPlus =
    Token("+" , 0x03, false, [](Number x)->Number{return (+x);}, NULL);
const Token kTokenUnaryMinus =
    Token("-" , 0x03, false, [](Number x)->Number{return (-x);}, NULL);
const Token kTokenLogicalNOT =
    Token("!" , 0x03, false, [](Number x)->Number{return (!x);}, NULL);
const Token kTokenBitwiseNOT =
    Token("~" , 0x03, false, [](Number x)->Number{return (~x);}, NULL);
// Level five
const Token kTokenMultiplication =
    Token("*" , 0x05, true, NULL,
          [](Number x, Number y)->Number{return (x * y);});
const Token kTokenDivision =
    Token("/" , 0x05, true, NULL,
          [](Number x, Number y)->Number{return (x / y);});
const Token kTokenModulo =
    Token("%" , 0x05, true, NULL,
          [](Number x, Number y)->Number{return (x % y);});
// Level six
const Token kTokenAddition =
    Token("+" , 0x06, true, NULL,
          [](Number x, Number y)->Number{return (x + y);});
const Token kTokenSubtraction =
    Token("-" , 0x06, true, NULL,
          [](Number x, Number y)->Number{return (x - y);});
const Token kTokenBitwiseLeftShift =
    Token("<<", 0x06, true, NULL,
          [](Number x, Number y)->Number{return (x << y);});
const Token kTokenBitwiseRightShift =
    Token(">>", 0x06, true, NULL,
          [](Number x, Number y)->Number{return (x >> y);});
// Level ten
const Token kTokenBitwiseAND =
    Token("&" , 0x0A, true, NULL,
          [](Number x, Number y)->Number{return (x & y);});
// Level eleven
const Token kTokenBitwiseXOR =
    Token("^" , 0x0B, true, NULL,
          [](Number x, Number y)->Number{return (x ^ y);});
// Level twelve
const Token kTokenBitwiseOR =
    Token("|" , 0x0C, true, NULL,
          [](Number x, Number y)->Number{return (x | y);});
// Level thirteen
const Token kTokenLogicalAND =
    Token("&&", 0x0D, true, NULL,
          [](Number x, Number y)->Number{return (x && y);});
// Level fourteen
const Token kTokenLogicalOR =
    Token("||", 0x0E, true, NULL,
          [](Number x, Number y)->Number{return (x || y);});

}

#endif
