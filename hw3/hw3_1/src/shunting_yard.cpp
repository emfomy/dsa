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
// infix_queue: the queue with infix expressions, will be cleared             //
//                                                                            //
// Output Parameters:                                                         //
// postfix_queue: an empty queue, will be filled by postfix expressions       //
////////////////////////////////////////////////////////////////////////////////
void ShuntingYard( TokenQueue& infix_queue, TokenQueue& postfix_queue ) {
  TokenStack operator_stack;

  // Pop tokens from input queue
  while ( !infix_queue.empty() ) {
    auto& token1 = infix_queue.front();
    infix_queue.pop();
    switch (token1.precedence()) {
      case 0x00: { // Number tokens
        postfix_queue.push(token1);
        break;
      }
      case 0xFF: { // Left parenthesis token
        operator_stack.push(token1);
        break;
      }
      case 0xFE: { // Right parenthesis token
        while ( !(operator_stack.empty()) ) {
          auto& token2 = operator_stack.top();
          operator_stack.pop();
          if ( token2.precedence() == 0xFF ) {
            break;
          }
          postfix_queue.push(token2);
        }
        break;
      }
      default: { // Other tokens
        while ( !(operator_stack.empty()) ) {
          auto& token2 = operator_stack.top();
          if ( token1 < token2 ) {
            break;
          }
          operator_stack.pop();
          postfix_queue.push(token2);
        }
        operator_stack.push(token1);
      }
    }
  }

  // Pop tokens from operator stack
  while ( !(operator_stack.empty()) ) {
    auto& token2 = operator_stack.top();
    operator_stack.pop();
    postfix_queue.push(token2);
  }
}

}
