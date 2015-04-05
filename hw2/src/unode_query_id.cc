////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_query_id.cc                                                          //
// The class UNodeQueryID                                                     //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_query_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodeQueryID                                            //
////////////////////////////////////////////////////////////////////////////////
UNodeQueryID::UNodeQueryID() {
  clicked = false;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodeQueryID::insert( Line& line ) {
  child.emplace(line.position, UNodePosition{}).first->second.insert(line);
  clicked = clicked || (line.click > 0);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given Position                                          //
//                                                                            //
// Parameters:                                                                //
// position: the Position                                                     //
//                                                                            //
// Return:                                                                    //
// the node of the Position                                                   //
////////////////////////////////////////////////////////////////////////////////
UNodePosition& UNodeQueryID::operator[]( Position position ) {
  return child[position];
}

}
