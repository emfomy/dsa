////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// shunting_yard.cpp                                                          //
// The shunting-yard algorithm                                                //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "shunting_yard.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// The shunting-yard algorithm                                                //
// Convert infix expressions to postfix expressions                           //
//                                                                            //
// Input Parameters:                                                          //
// infix_queue:    the queue with infix expressions, will be cleared          //
// operator_stack: an empty stack used as workspace                           //
//                                                                            //
// Output Parameters:                                                         //
// postfix_queue:  an empty queue, overwritten by postfix expressions         //
////////////////////////////////////////////////////////////////////////////////
void ShuntingYard( TokenDeque& infix_queue,
                   TokenDeque& operator_stack,
                   TokenDeque& postfix_queue ) {

  // Pop tokens from input queue
  while ( !infix_queue.empty() ) {
    auto& token1 = *infix_queue.front();
    infix_queue.pop_front();
    switch (token1.precedence()) {
      case 0x00: { // Numerical tokens
        postfix_queue.push_back(&token1);
        break;
      }
      case 0xFF: { // Left parenthesis tokens
        operator_stack.push_back(&token1);
        break;
      }
      case 0xFE: { // Right parenthesis tokens
        while ( !(operator_stack.empty()) ) {
          auto& token2 = *operator_stack.back();
          operator_stack.pop_back();
          if ( token2.precedence() == 0xFF ) {
            break;
          }
          postfix_queue.push_back(&token2);
        }
        break;
      }
      default: { // Operator tokens
        while ( !(operator_stack.empty()) ) {
          auto& token2 = *operator_stack.back();
          if ( token1 < token2 ) {
            break;
          }
          operator_stack.pop_back();
          postfix_queue.push_back(&token2);
        }
        operator_stack.push_back(&token1);
      }
    }
  }

  // Pop tokens from operator stack
  while ( !(operator_stack.empty()) ) {
    auto& token2 = *operator_stack.back();
    operator_stack.pop_back();
    postfix_queue.push_back(&token2);
  }
}

}
