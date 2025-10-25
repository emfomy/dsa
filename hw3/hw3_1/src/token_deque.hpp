////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token_deque.hpp                                                            //
// The header file of TokenDeque                                              //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_1_TOKEN_DEQUE_HPP_

#define HW3_1_TOKEN_DEQUE_HPP_

#include <iostream>
#include "hw3.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The deque of Token                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream&, const TokenDeque& );
void InsertToken( TokenDeque&, const char* );

}

#endif
