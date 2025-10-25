////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "token.hpp"
#include "token_deque.hpp"
#include "shunting_yard.hpp"
#include "evaluate_postfix.hpp"
using namespace hw3;
using namespace std;

#define MAX_LENGTH 1000000

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char** const argv ) {
  char str[MAX_LENGTH+1];
  TokenDeque infix_queue, postfix_queue;
  TokenDeque stack;

  ios::sync_with_stdio(false);

  while ( cin.getline(str, MAX_LENGTH) ) {
    InsertToken(infix_queue, str);
    ShuntingYard(infix_queue, stack, postfix_queue);
    cout << "Postfix Exp:" << postfix_queue << endl;
    EvaluatePostfix(postfix_queue, stack);
    cout << "RESULT:" << stack << endl;
    delete stack.back();
    stack.clear();
  }

  return 0;
}
