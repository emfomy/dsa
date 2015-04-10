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
void UNodeQueryID::insert( const Line& line ) {
  child.emplace(4*line.position + line.depth, UNodePosDep{}).first
      ->second.insert(line);
  clicked = clicked || (line.click > 0);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given Position and Depth                                //
//                                                                            //
// Parameters:                                                                //
// position: the Position                                                     //
// depth   : the Depth                                                        //
//                                                                            //
// Return:                                                                    //
// the node of the PosDep                                                     //
////////////////////////////////////////////////////////////////////////////////
UNodePosDep& UNodeQueryID::at( const Position position, const Depth depth ) {
  return child[4*position + depth];
}

}
