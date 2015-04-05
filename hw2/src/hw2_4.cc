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
    }
    cout << "********************" << endl;
    if ( str == "get" ) {
      get(uroot);
    } else if ( str == "clicked" ) {
      clicked(uroot);
    } else if ( str == "impressed" ) {
      impressed(aroot);
    } else if ( str == "profit" ) {
      profit(aroot);
    }
    cout << "********************" << endl;
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
  cout << uroot[u][a][q][p][d] << endl;
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
  for ( auto& paira : uroot[u].child ) {
    for ( auto& pairq : paira.second.child ) {
      if ( pairq.second.clicked ) {
        cout << paira.first << ' ' << pairq.first << endl;
      }
    }
  }
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
  for ( auto& paira : aroot.child ) {
    bool btemp = true;
    for ( auto& pairp : paira.second.child ) {
      if( pairp.second.child.count(u1)
          && pairp.second.child.count(u2) ) {
        if ( btemp ) {
          btemp = false;
          cout << paira.first << endl;
        }
        cout << '\t' << pairp.first << endl;
      }
    }
  }
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
  for ( auto& pairu : aroot[a].child_user_id ) {
    if( pairu.second.ctr() >= theta ) {
      cout << pairu.first << endl;
    }
  }
}
