////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_ad_id.cc                                                             //
// The class ANodeAdID                                                        //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "anode_ad_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of ANodeAdID                                               //
////////////////////////////////////////////////////////////////////////////////
ANodeAdID::ANodeAdID() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void ANodeAdID::insert( Line& line ) {
  Property prop(line);
  if ( line.impression ) {
    child.emplace(prop, ANodeProperty{}).first->second.insert(line);
    impressed.emplace(line.user_id);
  }
  child_user_id.emplace(line.user_id, ANodeUserID{}).first->second.insert(line);
}

}
