////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_root.hh                                                              //
// The header file of ANodeRoot                                               //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_ANODE_ROOT_HH_

#define HW2_ANODE_ROOT_HH_

#include "hw2.hh"
#include "line.hh"
#include "anode_ad_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a root node in A-tree                                         //
////////////////////////////////////////////////////////////////////////////////
class ANodeRoot {
 public:
  // The the map of AdID nodes
  AMapAdID child;

  ANodeRoot();
  void insert( const Line& );
  ANodeAdID& operator[]( const AdID );
};

}

#endif
