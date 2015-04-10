////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_ad_id.hh                                                             //
// The header file of UNodeAdID                                               //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_AD_ID_HH_

#define HW2_UNODE_AD_ID_HH_

#include <map>
#include "hw2.hh"
#include "line.hh"
#include "unode_query_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a AdID node in U-tree                                         //
////////////////////////////////////////////////////////////////////////////////
class UNodeAdID {
 public:
  // The the map of UQueryID nodes
  UMapQueryID child;

  UNodeAdID();
  void insert( const Line& );
  UNodeQueryID& operator[]( const QueryID );
};

////////////////////////////////////////////////////////////////////////////////
// The tree map of AdID to UNodeAdID                                          //
////////////////////////////////////////////////////////////////////////////////
typedef std::map<AdID, UNodeAdID> UMapAdID;

}

#endif
