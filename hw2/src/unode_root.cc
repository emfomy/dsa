////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_root.cc                                                              //
// The class UNodeRoot                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "unode_root.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of UNodeRoot                                               //
////////////////////////////////////////////////////////////////////////////////
UNodeRoot::UNodeRoot() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void UNodeRoot::insert( Line& line ) {
  child.emplace(line.user_id, UNodeUserID{}).first->second.insert(line);
}

////////////////////////////////////////////////////////////////////////////////
// Access element                                                             //
// Access the node of given UserID                                            //
//                                                                            //
// Parameters:                                                                //
// user_id: the UserID                                                        //
//                                                                            //
// Return:                                                                    //
// the node of the UserID                                                     //
////////////////////////////////////////////////////////////////////////////////
UNodeUserID& UNodeRoot::operator[]( UserID user_id ) {
  return child[user_id];
}

}
