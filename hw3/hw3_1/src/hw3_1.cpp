////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "hw3_1.hpp"
#include "token.hpp"
#include "shunting_yard.hpp"
#include "evaluate_postfix.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace hw3;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  TokenQueue infix_queue, postfix_queue;
  TokenStack stack;

  infix_queue.push(pTokenBitwiseNOT); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenBitwiseNOT); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenBitwiseNOT); cout << *infix_queue.back() << ' ';
  infix_queue.push(new Token(3)); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenAddition); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenUnaryMinus); cout << *infix_queue.back() << ' ';
  infix_queue.push(new Token(4)); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenMultiplication); cout << *infix_queue.back() << ' ';
  infix_queue.push(new Token(2)); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenDivision); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenLeftParenthesis); cout << *infix_queue.back() << ' ';
  infix_queue.push(new Token(1)); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenSubtraction); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenUnaryPlus); cout << *infix_queue.back() << ' ';
  infix_queue.push(new Token(5)); cout << *infix_queue.back() << ' ';
  infix_queue.push(pTokenRightParenthesis); cout << *infix_queue.back() << endl;

  ShuntingYard(infix_queue, stack, postfix_queue);
  EvaluatePostfix(postfix_queue, stack);
  cout << *stack.top() << endl;

  return 0;
}
