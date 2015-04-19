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
// input_queue: the queue with infix expressions, will be cleared             //
//                                                                            //
// Output Parameters:                                                         //
// output_queue: an empty queue, will be filled by postfix expressions        //
////////////////////////////////////////////////////////////////////////////////
void ShuntingYard( TokenQueue& input_queue, TokenQueue& output_queue ) {
  TokenStack operator_stack;

  // Pop tokens from input queue
  while ( !input_queue.empty() ) {
    auto& token1 = input_queue.front();
    input_queue.pop();
    switch (token1.precedence()) {
      case 0: { // Number tokens
        output_queue.push(token1);
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
          output_queue.push(token2);
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
          output_queue.push(token2);
        }
        operator_stack.push(token1);
      }
    }
  }

  // Pop tokens from operator stack
  while ( !(operator_stack.empty()) ) {
    auto& token2 = operator_stack.top();
    operator_stack.pop();
    output_queue.push(token2);
  }
}

}
