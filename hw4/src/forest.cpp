////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 4                                //
// forest.cpp                                                                 //
// The class Forest                                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "forest.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace hw4                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw4 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Forest                                                  //
// Initialize by a sample set                                                 //
//                                                                            //
// Parameters:                                                                //
// set:       the sample set                                                  //
// num_trees: the number of trees                                             //
////////////////////////////////////////////////////////////////////////////////
Forest::Forest( const SampleSet& set, const int num_trees ) {
  for ( auto i = 0; i < num_trees; ++i ) {
    auto ptr = new Tree(set, i);
    this->trees_.emplace_back(ptr);
  }
  this->num_trees_ = num_trees;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Forest                                                   //
////////////////////////////////////////////////////////////////////////////////
Forest::~Forest() {
  for ( auto it = this->trees_.begin(); it != this->trees_.end(); ++it ) {
    delete (*it);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Insert this forest into standant stream                                    //
//                                                                            //
// Parameters:                                                                //
// indent: the number of indents                                              //
////////////////////////////////////////////////////////////////////////////////
void Forest::Print( const int indent ) {
  cout << setw(indent*2) << setfill(' ') << ""
       << "int vote = 0;" << endl << endl;
  for ( auto i = 0; i < num_trees_; i++ ) {
    cout << setw(indent*2) << setfill(' ') << ""
         << "// Tree"+to_string(i)+" predict" << endl;
    cout << setw(indent*2) << setfill(' ') << ""
         << "vote += tree"+to_string(i)+"_predict(attr);" << endl << endl;
  }
  cout << setw(indent*2) << setfill(' ') << ""
       << "// Voting" << endl;
  cout << setw(indent*2) << setfill(' ') << ""
       << "if ( vote > 0 ) {" << endl;
  cout << setw(indent*2+2) << setfill(' ') << ""
       << "return +1;" << endl;
  cout << setw(indent*2) << setfill(' ') << ""
       << "} else if ( vote < 0 ) {" << endl;
  cout << setw(indent*2+2) << setfill(' ') << ""
       << "return -1;" << endl;
  cout << setw(indent*2) << setfill(' ') << ""
       << "} else {" << endl;
  cout << setw(indent*2+2) << setfill(' ') << ""
       << "return (rand()%2*2-1);" << endl;
  cout << setw(indent*2) << setfill(' ') << ""
       << "}" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Insert the trees of this forest into standant stream                       //
//                                                                            //
// Parameters:                                                                //
// indent: the number of indents                                              //
////////////////////////////////////////////////////////////////////////////////
void Forest::PrintTrees() {
  for ( auto i = 0; i < num_trees_; i++ ) {
    // Display function comments
    cout << setw(80) << setfill('/')
         << "" << endl;
    cout << setw(78) << left << setfill(' ')
         << "// Tree"+to_string(i)+" predict" << "//" << endl;
    cout << setw(78) << setfill(' ')
         << "// " << "//\n";
    cout << setw(78) << left << setfill(' ')
         << "// Parameters:" << "//" << endl;
    cout << setw(78) << left << setfill(' ')
         << "// The features of a sample" << "//" << endl;
    cout << setw(78) << setfill(' ')
         << "// " << "//\n";
    cout << setw(78) << left << setfill(' ')
         << "// Return Value:" << "//" << endl;
    cout << setw(78) << left << setfill(' ')
         << "// The predicted response of this sample" << "//" << endl;
    cout << setw(80) << setfill('/')
         << "" << endl;
    // Display function
    cout << "int tree"+to_string(i)+"_predict( double *attr ) {" << endl;
    this->trees_[i]->Print(1);
    cout << "}" << endl << endl;
  }
}

}
