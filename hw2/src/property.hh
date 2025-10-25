////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// property.hh                                                                //
// The header file of Property                                                //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_PROPERTY_HH_

#define HW2_PROPERTY_HH_

#include "hw2.hh"
#include "line.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of properties                                                    //
////////////////////////////////////////////////////////////////////////////////
class Property {
public:
  DisplayURL display_url;
  AdvertiserID advertiser_id;
  KeywordID keyword_id;
  TitleID title_id;
  DescriptionID description_id;

  Property( const Line& );
  bool operator<( const Property& ) const;
  friend std::ostream& operator<<( std::ostream&, const Property& );
};

}

#endif
