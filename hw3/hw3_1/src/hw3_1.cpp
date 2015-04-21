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

  infix_queue.emplace(3); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenAddition); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenUnaryMinus); cout << infix_queue.back() << ' ';
  infix_queue.emplace(4); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenMultiplication); cout << infix_queue.back() << ' ';
  infix_queue.emplace(2); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenDivision); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenLeftParenthesis); cout << infix_queue.back() << ' ';
  infix_queue.emplace(1); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenSubtraction); cout << infix_queue.back() << ' ';
  infix_queue.emplace(5); cout << infix_queue.back() << ' ';
  infix_queue.push(kTokenRightParenthesis); cout << infix_queue.back() << endl;

  ShuntingYard(infix_queue, postfix_queue);

  auto token = EvaluatePostfix(postfix_queue);
  cout << token << endl;

  return 0;
}
