////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 3-1                              //
// token_queue.cpp                                                            //
// The class TokenQueue                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "token_queue.hpp"
#include "token.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw3                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw3 {

////////////////////////////////////////////////////////////////////////////////
// Insert a token queue object into stream                                    //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the token queue object to be inserted into the stream                 //
//                                                                            //
// Return Value:                                                              //
// the ostream object, with tokens separated with spaces                      //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, TokenQueue& queue ) {
  if ( !queue.empty() ) {
    queue.push(NULL);
    auto pt = queue.front();
    queue.pop();
    os << *pt;
    queue.push(pt);
    pt = queue.front();
    queue.pop();
    while ( pt ) {
      os << ' ' << *pt;
      queue.push(pt);
      pt = queue.front();
      queue.pop();
    }
  }
  return os;
}

}
