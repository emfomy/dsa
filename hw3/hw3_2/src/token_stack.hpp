////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// token_stack.hpp                                                            //
// The header file of TokenStack                                              //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_2_TOKEN_STACK_HPP_

#define HW3_2_TOKEN_STACK_HPP_

#include <iostream>
#include "hw3.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The stack of Token                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream&, const TokenStack& );

}

#endif
