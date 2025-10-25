////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_root.hh                                                              //
// The header file of UNodeRoot                                               //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_ROOT_HH_

#define HW2_UNODE_ROOT_HH_

#include "hw2.hh"
#include "line.hh"
#include "unode_user_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a root node in U-tree                                         //
////////////////////////////////////////////////////////////////////////////////
class UNodeRoot {
 public:
  // The the map of UserID nodes
  UMapUserID child;

  UNodeRoot();
  void insert( const Line& );
  UNodeUserID& operator[]( const UserID );
};

}

#endif
