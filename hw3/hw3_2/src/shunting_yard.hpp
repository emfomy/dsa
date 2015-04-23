////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// shunting_yard.hpp                                                          //
// The header file of shunting-yard algorithm                                 //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_2_SHUNTING_YARD_HPP_

#define HW3_2_SHUNTING_YARD_HPP_

#include "hw3.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The shunting-yard algorithm                                                //
////////////////////////////////////////////////////////////////////////////////
void ShuntingYard( TokenQueue&, TokenStack&, TokenQueue& );

}

#endif
