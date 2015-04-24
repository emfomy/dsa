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
#include "hw3.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

typedef Number (*Unary)(const Number);
typedef Number (*Binary)(const Number, const Number);

////////////////////////////////////////////////////////////////////////////////
// The class of a token                                                       //
////////////////////////////////////////////////////////////////////////////////
class Token
{
 private:
  // The name of this token.
  // "#" means this token is a number.
  const char* name_;

  // The number of this token.
  // '0' for non-numerical tokens.
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
  Token( const char*, const Type );
  Token( const char*, const Type, const bool, const Unary );
  Token( const char*, const Type, const bool, const Binary );
  Token( Number );

  Type precedence();

  void InsertNumber( const Number );

  void operator()( TokenDeque& );
  bool operator<( const Token& ) const;
  friend std::ostream& operator<<( std::ostream&, const Token& );
};

////////////////////////////////////////////////////////////////////////////////
// Non-numerical tokens                                                       //
////////////////////////////////////////////////////////////////////////////////
// Punctuation
static Token* pTokenLeftParenthesis =
    new Token("(" , 0xFF);
static Token* pTokenRightParenthesis =
    new Token(")" , 0xFE);
// Level three
static Token* pTokenUnaryPlus =
    new Token("+" , 0x03, false,
              [](Number x)->Number{return (+x);});
static Token* pTokenUnaryMinus =
    new Token("-" , 0x03, false,
              [](Number x)->Number{return (-x);});
static Token* pTokenLogicalNOT =
    new Token("!" , 0x03, false,
              [](Number x)->Number{return (!x);});
static Token* pTokenBitwiseNOT =
    new Token("~" , 0x03, false,
              [](Number x)->Number{return (~x);});
// Level five
static Token* pTokenMultiplication =
    new Token("*" , 0x05, true,
              [](Number x, Number y)->Number{return (x * y);});
static Token* pTokenDivision =
    new Token("/" , 0x05, true,
              [](Number x, Number y)->Number{return (x / y);});
static Token* pTokenModulo =
    new Token("%" , 0x05, true,
              [](Number x, Number y)->Number{return (x % y);});
// Level six
static Token* pTokenAddition =
    new Token("+" , 0x06, true,
              [](Number x, Number y)->Number{return (x + y);});
static Token* pTokenSubtraction =
    new Token("-" , 0x06, true,
              [](Number x, Number y)->Number{return (x - y);});
static Token* pTokenBitwiseLeftShift =
    new Token("<<", 0x06, true,
              [](Number x, Number y)->Number{return (x << y);});
static Token* pTokenBitwiseRightShift =
    new Token(">>", 0x06, true,
              [](Number x, Number y)->Number{return (x >> y);});
// Level ten
static Token* pTokenBitwiseAND =
    new Token("&" , 0x0A, true,
              [](Number x, Number y)->Number{return (x & y);});
// Level eleven
static Token* pTokenBitwiseXOR =
    new Token("^" , 0x0B, true,
              [](Number x, Number y)->Number{return (x ^ y);});
// Level twelve
static Token* pTokenBitwiseOR =
    new Token("|" , 0x0C, true,
              [](Number x, Number y)->Number{return (x | y);});
// Level thirteen
static Token* pTokenLogicalAND =
    new Token("&&", 0x0D, true,
              [](Number x, Number y)->Number{return (x && y);});
// Level fourteen
static Token* pTokenLogicalOR =
    new Token("||", 0x0E, true,
              [](Number x, Number y)->Number{return (x || y);});

}

#endif
