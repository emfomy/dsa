////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// evaluate_postfix.cpp                                                       //
// The postfix algorithm                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "evaluate_postfix.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The postfix algorithm                                                      //
// Evaluating postfix expressions                                             //
//                                                                            //
// Input Parameters:                                                          //
// postfix_queue: the queue with postfix expressions, will be cleared         //
//                                                                            //
// Output Parameters:                                                         //
// number_stack:  overwritten by evaluating result                            //
////////////////////////////////////////////////////////////////////////////////
void EvaluatePostfix( TokenQueue& postfix_queue, TokenStack& number_stack ) {
  while ( !postfix_queue.empty() ) {
    auto& token1 = postfix_queue.front();
    token1(number_stack);
    postfix_queue.pop();
  }
}

}
