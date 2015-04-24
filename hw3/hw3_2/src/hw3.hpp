////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-2                              //
// hw3.hpp                                                                    //
// The header file of namespace hw3                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_2_HW3_HPP_

#define HW3_2_HW3_HPP_

#include <cstdint>
#include <deque>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Base types                                                                 //
////////////////////////////////////////////////////////////////////////////////
typedef double Number;
typedef uint8_t Type;

////////////////////////////////////////////////////////////////////////////////
// Token types                                                                //
////////////////////////////////////////////////////////////////////////////////
class Token;
typedef std::deque<Token*> TokenDeque;

}

#endif
