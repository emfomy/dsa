////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_pos_dep.cc                                                           //
// The class UNodePosDep                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_pos_dep.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodePosDep                                              //
////////////////////////////////////////////////////////////////////////////////
UNodePosDep::UNodePosDep() {
  click = 0;
  impression = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodePosDep::insert( const Line& line ) {
  click += line.click;
  impression += line.impression;
}

////////////////////////////////////////////////////////////////////////////////
// Insert into stream                                                         //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the node object to be inserted into the stream                        //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const UNodePosDep& obj ) {
  os << obj.click << ' ' << obj.impression;
  return os;
}

}
