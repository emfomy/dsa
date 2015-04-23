////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// token_queue.cpp                                                            //
// The class TokenQueue                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token_queue.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Insert a token queue object into stream                                    //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the token queue object to be inserted into the stream                 //
//                                                                            //
// Return Value:                                                              //
// the ostream object, with tokens separated with spaces                      //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, TokenQueue& queue ) {
  if ( !queue.empty() ) {
    queue.push(NULL);
    auto pt = queue.front();
    queue.pop();
    os << *pt;
    queue.push(pt);
    pt = queue.front();
    queue.pop();
    while ( pt ) {
      os << ' ' << *pt;
      queue.push(pt);
      pt = queue.front();
      queue.pop();
    }
  }
  return os;
}

////////////////////////////////////////////////////////////////////////////////
// Extract a token queue object from a char array                             //
//                                                                            //
// Parameters:                                                                //
// queue: the token queue object to be extracted into from stream             //
// str:   char array                                                          //
////////////////////////////////////////////////////////////////////////////////
void InsertToken( TokenQueue& queue, const char* str ) {
  bool stat = false; // The current token is numerical/left-parenthesis or not

  // Create tokens
  for ( auto pc = str; ; pc++ ) {
    switch ( *pc ) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': {
        if ( stat ) {
          queue.back()->InsertNumber(*pc-'0');
        } else {
          queue.push(new Token(*pc-'0'));
        }
        stat = true;
        break;
      }
      case '(': {
        queue.push(pTokenLeftParenthesis);
        stat = false;
        break;
      }
      case ')': {
        queue.push(pTokenRightParenthesis);
        stat = true;
        break;
      }
      case '!': {
        queue.push(pTokenLogicalNOT);
        stat = false;
        break;
      }
      case '~': {
        queue.push(pTokenBitwiseNOT);
        stat = false;
        break;
      }
      case '+': {
        if ( stat ) {
          queue.push(pTokenAddition);
        } else {
          queue.push(pTokenUnaryPlus);
        }
        stat = false;
        break;
      }
      case '-': {
        if ( stat ) {
          queue.push(pTokenSubtraction);
        } else {
          queue.push(pTokenUnaryMinus);
        }
        stat = false;
        break;
      }
      case '*': {
        queue.push(pTokenMultiplication);
        stat = false;
        break;
      }
      case '/': {
        queue.push(pTokenDivision);
        stat = false;
        break;
      }
      case '%': {
        queue.push(pTokenModulo);
        stat = false;
        break;
      }
      case '<': {
        queue.push(pTokenBitwiseLeftShift);
        pc++;
        stat = false;
        break;
      }
      case '>': {
        queue.push(pTokenBitwiseLeftShift);
        pc++;
        stat = false;
        break;
      }
      case '&': {
        if ( *(pc+1) == '&' ) {
          queue.push(pTokenLogicalAND);
          pc++;
        } else {
          queue.push(pTokenBitwiseAND);
        }
        stat = false;
        break;
      }
      case '|': {
        if ( *(pc+1) == '|' ) {
          queue.push(pTokenLogicalOR);
          pc++;
        } else {
          queue.push(pTokenBitwiseOR);
        }
        stat = false;
        break;
      }
      case '^': {
        queue.push(pTokenBitwiseXOR);
        stat = false;
        break;
      }
      case '\0': {
        return;
      }
    }
  }
}

}
