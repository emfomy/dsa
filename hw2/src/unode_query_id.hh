////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_query_id.hh                                                          //
// The header file of UNodeQueryID                                            //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_QUERY_ID_HH_

#define HW2_UNODE_QUERY_ID_HH_

#include <map>
#include "hw2.hh"
#include "line.hh"
#include "unode_position.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a QueryID node in U-tree                                      //
////////////////////////////////////////////////////////////////////////////////
class UNodeQueryID {
 public:
  // The map of Position nodes
  UMapPosition child;

  // Whether this node is clicked or not
  bool clicked;

  UNodeQueryID();
  void insert( Line& );
  UNodePosition& operator[]( Position );
};

////////////////////////////////////////////////////////////////////////////////
// The tree map of QueryID to UNodeQueryID                                    //
////////////////////////////////////////////////////////////////////////////////
typedef std::map<QueryID, UNodeQueryID> UMapQueryID;

}

#endif
