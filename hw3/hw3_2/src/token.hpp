////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// token.hpp                                                                  //
// The header file of Token                                                   //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_2_TOKEN_HPP_

#define HW3_2_TOKEN_HPP_

#include <cmath>
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
  // '0xFD' means this token is a function argument separator.
  // '0xFC' means this token is a function.
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
static Token* pTokenLeftParenthesis  = new Token("(" , 0xFF);
static Token* pTokenRightParenthesis = new Token(")" , 0xFE);
static Token* pTokenComma            = new Token("," , 0xFD);
// Level three
static Token* pTokenUnaryPlus =
    new Token("+" , 0x03, false,
              [](Number x)->Number{return (+x);});
static Token* pTokenUnaryMinus =
    new Token("-" , 0x03, false,
              [](Number x)->Number{return (-x);});
// Level five
static Token* pTokenMultiplication =
    new Token("*" , 0x05, true,
              [](Number x, Number y)->Number{return (x * y);});
static Token* pTokenDivision =
    new Token("/" , 0x05, true,
              [](Number x, Number y)->Number{return (x / y);});
// Level six
static Token* pTokenAddition =
    new Token("+" , 0x06, true,
              [](Number x, Number y)->Number{return (x + y);});
static Token* pTokenSubtraction =
    new Token("-" , 0x06, true,
              [](Number x, Number y)->Number{return (x - y);});
// Functions
static Token* pTokenSin  = new Token("sin" , 0xFC, false, sin);
static Token* pTokenCos  = new Token("cos" , 0xFC, false, cos);
static Token* pTokenExp  = new Token("exp" , 0xFC, false, exp);
static Token* pTokenLog  = new Token("log" , 0xFC, false, log);
static Token* pTokenPow  = new Token("pow" , 0xFC, false, pow);
static Token* pTokenSqrt = new Token("sqrt", 0xFC, false, sqrt);
static Token* pTokenFabs = new Token("fabs", 0xFC, false, fabs);

}

#endif
