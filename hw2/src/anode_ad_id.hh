////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_ad_id.hh                                                             //
// The header file of ANodeAdID                                               //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_ANODE_AD_ID_HH_

#define HW2_ANODE_AD_ID_HH_

#include <map>
#include "hw2.hh"
#include "line.hh"
#include "anode_property.hh"
#include "anode_user_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a AdID node in A-tree                                         //
////////////////////////////////////////////////////////////////////////////////
class ANodeAdID {
 public:
  // The the map of Property nodes
  AMapProperty child;

  // The the map of UserID nodes
  AMapUserID child_user_id;

  // The the set of UserIDs that impressed this node
  SetUserID impressed;

  ANodeAdID();
  void insert( Line& );
};

////////////////////////////////////////////////////////////////////////////////
// The tree map of AdID to ANodeAdID                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::map<AdID, ANodeAdID> AMapAdID;

}

#endif
