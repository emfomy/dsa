////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// hw3_1.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "hw3_1.hpp"
#include "token.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace hw3;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  StackToken st;
  Token t1(17), t2(3);
  const Token *pt;

  st.push(t1); pt = &kUnaryPlus;
  cout << (*pt) << t1 << "\t= " << (*pt)(st) << endl;
  st.push(t2); pt = &kUnaryMinus;
  cout << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); pt = &kLogicalNOT;
  cout << (*pt) << t1 << "\t= " << (*pt)(st) << endl;
  st.push(t2); pt = &kBitwiseNOT;
  cout << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  cout << endl;

  st.push(t1); st.push(t2); pt = &kMultiplication;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kDivision;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kModulo;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  cout << endl;

  st.push(t1); st.push(t2); pt = &kAddition;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kSubtraction;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kBitwiseLeftShift;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kBitwiseRightShift;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  cout << endl;

  st.push(t1); st.push(t2); pt = &kBitwiseAND;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kBitwiseXOR;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kBitwiseOR;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kLogicalAND;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;
  st.push(t1); st.push(t2); pt = &kLogicalOR;
  cout << t1 << (*pt) << t2 << "\t= " << (*pt)(st) << endl;




  return 0;
}
