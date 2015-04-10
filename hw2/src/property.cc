////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// property.cc                                                                //
// The class Property                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "property.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Property                                                //
// Initialize by a line object                                                //
//                                                                            //
// Parameters:                                                                //
// line: the line object                                                      //
////////////////////////////////////////////////////////////////////////////////
Property::Property( const Line& line ) {
  display_url    = line.display_url;
  advertiser_id  = line.advertiser_id;
  keyword_id     = line.keyword_id;
  title_id       = line.title_id;
  description_id = line.description_id;
}

////////////////////////////////////////////////////////////////////////////////
// The smaller than operator                                                  //
//                                                                            //
// Parameters:                                                                //
// rhs: another property object                                               //
//                                                                            //
// Return Value:                                                              //
// the whether this object is smaller or not                                  //
////////////////////////////////////////////////////////////////////////////////
bool Property::operator<( const Property& rhs ) const {
  if ( display_url != rhs.display_url ) {
    return (display_url < rhs.display_url);
  }
  if ( advertiser_id != rhs.advertiser_id ) {
    return (advertiser_id < rhs.advertiser_id);
  }
  if ( keyword_id != rhs.keyword_id ) {
    return (keyword_id < rhs.keyword_id);
  }
  if ( title_id != rhs.title_id ) {
    return (title_id < rhs.title_id);
  }
  if ( description_id != rhs.description_id ) {
    return (description_id < rhs.description_id);
  }
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// Insert into stream                                                         //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the property object to be inserted into the stream                    //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const Property& obj ) {
  os << obj.display_url << ' ' << obj.advertiser_id  << ' '
     << obj.keyword_id  << ' ' << obj.title_id       << ' '
     << obj.description_id;
  return os;
}

}
