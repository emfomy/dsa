////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_depth.cc                                                             //
// The class UNodeDepth                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_depth.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodeDepth                                              //
////////////////////////////////////////////////////////////////////////////////
UNodeDepth::UNodeDepth() {
  click = 0;
  impression = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodeDepth::insert( Line& line ) {
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
std::ostream& operator<<( std::ostream& os, const UNodeDepth& obj ) {
  os << obj.click << ' ' << obj.impression;
  return os;
}

}
