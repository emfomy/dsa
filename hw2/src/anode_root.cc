////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_root.cc                                                              //
// The class ANodeRoot                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "anode_root.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of ANodeRoot                                               //
////////////////////////////////////////////////////////////////////////////////
ANodeRoot::ANodeRoot() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void ANodeRoot::insert( const Line& line ) {
  child.emplace(line.ad_id, ANodeAdID{}).first->second.insert(line);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given AdID                                              //
//                                                                            //
// Parameters:                                                                //
// ad_id: the AdID                                                            //
//                                                                            //
// Return:                                                                    //
// the node of the AdID                                                       //
////////////////////////////////////////////////////////////////////////////////
ANodeAdID& ANodeRoot::operator[]( const AdID ad_id ) {
  return child[ad_id];
}

}
