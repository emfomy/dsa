////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// token_queue.hpp                                                            //
// The header file of TokenQueue                                              //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_2_TOKEN_QUEUE_HPP_

#define HW3_2_TOKEN_QUEUE_HPP_

#include <iostream>
#include "hw3.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The queue of Token                                                         //
////////////////////////////////////////////////////////////////////////////////
typedef std::queue<Token*> TokenQueue;
std::ostream& operator<<( std::ostream&, TokenQueue& );
void InsertToken( TokenQueue&, const char* );

}

#endif
