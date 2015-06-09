////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 6                                //
// hw6_3.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "node.hpp"

using namespace std;
using namespace hw6;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char const *argv[] ) {
  int n, m, p, t, i, j;
  long long int s;
  Node* user;

  ios::sync_with_stdio(false);

  cin >> n >> m;

  auto game = new Node*[n];
  for ( auto k = 0; k < n; ++k ) {
    cin >> p;
    game[k] = new Node(k+1, p);
  }

  for ( auto k = 0; k < m; ++k ) {
    cin >> t;
    if ( t == 1 ) { // Incident 1
      cin >> i >> j;
      game[i-1]->Merge(game[j-1]);
    } else { // Incident 2
      cin >> i >> s;
      user = game[i-1]->Find();
      cout << user->id() << ' ' << user->Afford(s) << endl;
    }
  }
}
