////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token_stack.cpp                                                            //
// The class TokenStack                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token_stack.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Insert a token stack object into stream                                    //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the token stack object to be inserted into the stream                 //
//                                                                            //
// Return Value:                                                              //
// the ostream object, with the top token of stack                            //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const TokenStack& stack ) {
  return stack.empty() ? os : (os << *stack.top()); 
}

}
