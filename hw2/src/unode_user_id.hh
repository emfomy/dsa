////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_user_id.hh                                                           //
// The header file of UNodeUserID                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_USER_ID_HH_

#define HW2_UNODE_USER_ID_HH_

#include <unordered_map>
#include "hw2.hh"
#include "line.hh"
#include "unode_ad_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a UserID node in U-tree                                       //
////////////////////////////////////////////////////////////////////////////////
class UNodeUserID {
 public:
  // The the map of AdID nodes
  UMapAdID child;

  UNodeUserID();
  void insert( const Line& );
  UNodeAdID& operator[]( const AdID );
};

////////////////////////////////////////////////////////////////////////////////
// The hash map of UserID to UNodeUserID                                      //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<UserID, UNodeUserID> UMapUserID;

}

#endif
