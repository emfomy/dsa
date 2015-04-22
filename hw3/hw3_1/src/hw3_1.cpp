////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "hw3_1.hpp"
#include "token.hpp"
#include "token_stack.hpp"
#include "token_queue.hpp"
#include "shunting_yard.hpp"
#include "evaluate_postfix.hpp"
#include <iostream>
#include <string>
using namespace hw3;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  TokenQueue infix_queue, postfix_queue;
  TokenStack stack;

  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(new Token(3));
  infix_queue.push(pTokenAddition);
  infix_queue.push(new Token(2));
  infix_queue.push(pTokenRightParenthesis);
  infix_queue.push(pTokenMultiplication);
  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(new Token(5));
  infix_queue.push(pTokenBitwiseAND);
  infix_queue.push(new Token(7));
  infix_queue.push(pTokenRightParenthesis);
  infix_queue.push(pTokenSubtraction);
  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(new Token(7));
  infix_queue.push(pTokenMultiplication);
  infix_queue.push(new Token(7));
  infix_queue.push(pTokenRightParenthesis);
  cout << "Infix Exp: " << infix_queue << endl;
  ShuntingYard(infix_queue, stack, postfix_queue);
  cout << "Postfix Exp: " << postfix_queue << endl;
  EvaluatePostfix(postfix_queue, stack);
  cout << "RESULT: " << stack << endl;
  delete stack.top();
  stack.pop();

  infix_queue.push(new Token(47));
  infix_queue.push(pTokenDivision);
  infix_queue.push(new Token(6));
  infix_queue.push(pTokenAddition);
  infix_queue.push(new Token(123));
  infix_queue.push(pTokenMultiplication);
  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(pTokenLogicalNOT);
  infix_queue.push(new Token(90));
  infix_queue.push(pTokenRightParenthesis);
  infix_queue.push(pTokenLogicalAND);
  infix_queue.push(new Token(2));
  infix_queue.push(pTokenRightParenthesis);
  infix_queue.push(pTokenAddition);
  infix_queue.push(pTokenLogicalNOT);
  infix_queue.push(pTokenLeftParenthesis);
  infix_queue.push(pTokenLogicalNOT);
  infix_queue.push(new Token(90));
  infix_queue.push(pTokenRightParenthesis);
  cout << "Infix Exp: " << infix_queue << endl;
  ShuntingYard(infix_queue, stack, postfix_queue);
  cout << "Postfix Exp: " << postfix_queue << endl;
  EvaluatePostfix(postfix_queue, stack);
  cout << "RESULT: " << stack << endl;
  delete stack.top();
  stack.pop();

  infix_queue.push(new Token(7));
  infix_queue.push(pTokenAddition);
  infix_queue.push(new Token(7));
  cout << "Infix Exp: " << infix_queue << endl;
  ShuntingYard(infix_queue, stack, postfix_queue);
  cout << "Postfix Exp: " << postfix_queue << endl;
  EvaluatePostfix(postfix_queue, stack);
  cout << "RESULT: " << stack << endl;
  delete stack.top();
  stack.pop();

  return 0;
}
