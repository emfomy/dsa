////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_ad_id.cc                                                             //
// The class UNodeAdID                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_ad_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodeAdID                                               //
////////////////////////////////////////////////////////////////////////////////
UNodeAdID::UNodeAdID() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodeAdID::insert( Line& line ) {
  child.emplace(line.query_id, UNodeQueryID{}).first->second.insert(line);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given QueryID                                           //
//                                                                            //
// Parameters:                                                                //
// query_id: the QueryID                                                      //
//                                                                            //
// Return:                                                                    //
// the node of the QueryID                                                    //
////////////////////////////////////////////////////////////////////////////////
UNodeQueryID& UNodeAdID::operator[]( QueryID query_id ) {
  return child[query_id];
}

}
