////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// hw2_4.cc                                                                   //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "hw2_4.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace hw2;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] ) {
  UNodeRoot uroot;
  ANodeRoot aroot;
  Line line;
  string str;

  // Read data from file
  ifstream fin(argv[1]); 
  while ( fin.good() ) {
    fin >> line;
    uroot.insert(line);
    aroot.insert(line);
  }
  fin.close();

  // Read commands
  while ( true ) {
    cin >> str;
    if ( str == "quit" ) {
      break;
    } else if ( str == "get" ) {
      get(uroot);
    } else if ( str == "clicked" ) {
      clicked(uroot);
    } else if ( str == "impressed" ) {
      impressed(aroot);
    } else if ( str == "profit" ) {
      profit(aroot);
    }
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Get function                                                               //
// Display target Click-Impression pair                                       //
//                                                                            //
// Parameters:                                                                //
// uroot: the root node of U-tree                                             //
////////////////////////////////////////////////////////////////////////////////
void get( UNodeRoot& uroot ) {
  UserID u; AdID a; QueryID q; Position p; Depth d;
  cin >> u >> a >> q >> p >> d;
  cout << "********************" << endl;
  cout << uroot[u][a][q][p][d] << endl;
  cout << "********************" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Clicked function                                                           //
// Display the AdID-QueryID pairs target UserID cliecked                      //
//                                                                            //
// Parameters:                                                                //
// uroot: the root node of U-tree                                             //
////////////////////////////////////////////////////////////////////////////////
void clicked( UNodeRoot& uroot ) {
  UserID u;
  cin >> u;
  cout << "********************" << endl;
  for ( auto& paira : uroot[u].child ) {
    for ( auto& pairq : paira.second.child ) {
      if ( pairq.second.clicked ) {
        cout << paira.first << ' ' << pairq.first << endl;
      }
    }
  }
  cout << "********************" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Impressed function                                                         //
// Display the properties target UserIDs impressed                            //
//                                                                            //
// Parameters:                                                                //
// aroot: the root node of A-tree                                             //
////////////////////////////////////////////////////////////////////////////////
void impressed( ANodeRoot& aroot ) {
  UserID u1, u2;
  cin >> u1 >> u2;
  cout << "********************" << endl;
  for ( auto& paira : aroot.child ) {
    if ( paira.second.impressed.count(u1)
         && paira.second.impressed.count(u2) ) {
      cout << paira.first << endl;
      for ( auto& pairp : paira.second.child ) {
        if ( pairp.second.impressed.count(u1)
             || pairp.second.impressed.count(u2) ) {
          cout << '\t' << pairp.first << endl;
        }
      }
    }
  }
  cout << "********************" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Profit function                                                            //
// Display the UserIDs on target AdID with click-through-rate greater than or // 
// equal to the given value                                                   //
//                                                                            //
// Parameters:                                                                //
// aroot: the root node of A-tree                                             //
////////////////////////////////////////////////////////////////////////////////
void profit( ANodeRoot& aroot ) {
  AdID a; double theta;
  cin >> a >> theta;
  cout << "********************" << endl;
  for ( auto& pairu : aroot[a].child_user_id ) {
    if ( pairu.second.ctr() >= theta ) {
      cout << pairu.first << endl;
    }
  }
  cout << "********************" << endl;
}
