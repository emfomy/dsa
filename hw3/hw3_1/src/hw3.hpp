////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3.hpp                                                                    //
// The header file of namespace hw3                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_1_HW3_HPP_

#define HW3_1_HW3_HPP_

#include <cstdint>
#include <queue>
#include <stack>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Base types                                                                 //
////////////////////////////////////////////////////////////////////////////////
typedef int32_t Number;
typedef uint8_t Type;
class Token;
typedef std::queue<Token*> TokenQueue;
typedef std::stack<Token*> TokenStack;

}

#endif
