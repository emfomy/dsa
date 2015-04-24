////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// evaluate_postfix.cpp                                                       //
// The postfix algorithm                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "evaluate_postfix.hpp"

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
void EvaluatePostfix( TokenDeque& postfix_queue, TokenDeque& number_stack ) {
  while ( !postfix_queue.empty() ) {
    auto& token = *postfix_queue.front();
    token(number_stack);
    postfix_queue.pop_front();
  }
}

}
