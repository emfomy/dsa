////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// hw2.hh                                                                     //
// The header file of namespace hw2                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_HW2_HH_

#define HW2_HW2_HH_

#include <cstdint>
#include <unordered_set>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// Base types                                                                 //
////////////////////////////////////////////////////////////////////////////////
typedef uint64_t UserID;        // Range: 0 ~ 23907634
typedef uint32_t AdID;          // Range: 1000031 ~ 22238277
typedef uint32_t QueryID;       // Range: 0 ~ 26243605
typedef uint16_t Position;      // Range: 1 ~ 3
typedef uint16_t Depth;         // Range: 1 ~ 3
typedef uint32_t Click;         // Range: 0 ~ 39900
typedef uint32_t Impression;    // Range: 1 ~ 764404
typedef uint64_t DisplayURL;    // Range: 482436910553333 ~ 18445899849997222722
typedef uint16_t AdvertiserID;  // Range: 78 ~ 39191
typedef uint32_t KeywordID;     // Range: 0 ~ 1249783
typedef uint32_t TitleID;       // Range: 0 ~ 4051439
typedef uint32_t DescriptionID; // Range: 0 ~ 3171828

typedef uint16_t PosDep;        // Position*4 + Depth

////////////////////////////////////////////////////////////////////////////////
// The hash set of UserID                                                     //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_set<UserID> SetUserID;

}

#endif
