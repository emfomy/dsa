////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_user_id.cc                                                           //
// The class UNodeUserID                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_user_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodeUserID                                             //
////////////////////////////////////////////////////////////////////////////////
UNodeUserID::UNodeUserID() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodeUserID::insert( const Line& line ) {
  child.emplace(line.ad_id, UNodeAdID{}).first->second.insert(line);
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
UNodeAdID& UNodeUserID::operator[]( const AdID ad_id ) {
  return child[ad_id];
}

}
