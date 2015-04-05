////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_user_id.hh                                                           //
// The header file of ANodeUserID                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_ANODE_USER_ID_HH_

#define HW2_ANODE_USER_ID_HH_

#include <unordered_map>
#include "hw2.hh"
#include "line.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a UserID node in A-tree                                       //
////////////////////////////////////////////////////////////////////////////////
class ANodeUserID {
 public:
  // The the total click number
  Click click;

  // The the total impression number
  Impression impression;

  ANodeUserID();
  void insert( Line& );
  double ctr();
};

////////////////////////////////////////////////////////////////////////////////
// The hash map of UserID to ANodeUserID                                      //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<UserID, ANodeUserID> AMapUserID;

}

#endif
