////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token_deque.cpp                                                            //
// The class TokenDeque                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token_deque.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Insert a token deque object into stream                                    //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the token deque object to be inserted into the stream                 //
//                                                                            //
// Return Value:                                                              //
// the ostream object, with tokens separated with spaces and a leading space  //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const TokenDeque& deque ) {
  for ( auto it = deque.cbegin(); it != deque.cend(); ++it ) {
    os << ' ' << **it;
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
void InsertToken( TokenDeque& queue, const char* str ) {
  // The current token
  // 'true' means non-numerical tokens
  // 'false' means numerical tokens and RightParenthesis
  bool stat = true;

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
          queue.push_back(new Token(atol(pc)));
          stat = false;
        }
        break;
      }
      case '(': {
        queue.push_back(pTokenLeftParenthesis);
        stat = true;
        break;
      }
      case ')': {
        queue.push_back(pTokenRightParenthesis);
        stat = false;
        break;
      }
      case '!': {
        queue.push_back(pTokenLogicalNOT);
        stat = true;
        break;
      }
      case '~': {
        queue.push_back(pTokenBitwiseNOT);
        stat = true;
        break;
      }
      case '+': {
        if ( stat ) {
          queue.push_back(pTokenUnaryPlus);
        } else {
          queue.push_back(pTokenAddition);
        }
        stat = true;
        break;
      }
      case '-': {
        if ( stat ) {
          queue.push_back(pTokenUnaryMinus);
        } else {
          queue.push_back(pTokenSubtraction);
        }
        stat = true;
        break;
      }
      case '*': {
        queue.push_back(pTokenMultiplication);
        stat = true;
        break;
      }
      case '/': {
        queue.push_back(pTokenDivision);
        stat = true;
        break;
      }
      case '%': {
        queue.push_back(pTokenModulo);
        stat = true;
        break;
      }
      case '<': {
        queue.push_back(pTokenBitwiseLeftShift);
        pc++;
        stat = true;
        break;
      }
      case '>': {
        queue.push_back(pTokenBitwiseLeftShift);
        pc++;
        stat = true;
        break;
      }
      case '&': {
        if ( *(pc+1) == '&' ) {
          queue.push_back(pTokenLogicalAND);
          pc++;
        } else {
          queue.push_back(pTokenBitwiseAND);
        }
        stat = true;
        break;
      }
      case '|': {
        if ( *(pc+1) == '|' ) {
          queue.push_back(pTokenLogicalOR);
          pc++;
        } else {
          queue.push_back(pTokenBitwiseOR);
        }
        stat = true;
        break;
      }
      case '^': {
        queue.push_back(pTokenBitwiseXOR);
        stat = true;
        break;
      }
      case '\0': {
        return;
      }
    }
  }
}

}
