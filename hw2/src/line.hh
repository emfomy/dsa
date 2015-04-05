////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// line.hh                                                                    //
// The main header the class Line                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_LINE_HH_

#define HW2_LINE_HH_

#include <iostream>
#include <forward_list>
#include "hw2.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a line of data                                                //
////////////////////////////////////////////////////////////////////////////////
class Line {
 public:
  Click click;
  Impression impression;
  DisplayURL display_url;
  AdID ad_id;
  AdvertiserID advertiser_id;
  Depth depth;
  Position position;
  QueryID query_id;
  KeywordID keyword_id;
  TitleID title_id;
  DescriptionID description_id;
  UserID user_id;

  Line();
  friend std::istream& operator>>( std::istream&, Line& );
  friend std::ostream& operator<<( std::ostream&, const Line& );
};

}

#endif
