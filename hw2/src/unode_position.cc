////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_position.cc                                                          //
// The class UNodePosition                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_position.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodePosition                                           //
////////////////////////////////////////////////////////////////////////////////
UNodePosition::UNodePosition() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodePosition::insert( Line& line ) {
  child.emplace(line.depth, UNodeDepth{}).first->second.insert(line);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given AdID                                              //
//                                                                            //
// Parameters:                                                                //
// depth: the AdID                                                            //
//                                                                            //
// Return:                                                                    //
// the node of the AdID                                                       //
////////////////////////////////////////////////////////////////////////////////
UNodeDepth& UNodePosition::operator[]( Depth depth ) {
  return child[depth];
}

}
