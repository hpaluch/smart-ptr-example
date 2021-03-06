/*
 * main.cpp - example, how to use shared_ptr with vector
 */
#include <iostream>
#include <boost/smart_ptr.hpp>

#include <vector>

using namespace std;

/**
 * Class to debug Constructors/Destructors and simple hello method.
 */
class MyObj {
      const char *name;
      public:
      MyObj(const char *_name){
             name = _name;
             cout << name  << " MyObj()" << endl;
      }
      virtual void hello(void){
              cout << name << " hello()" << endl;
      }
      virtual ~MyObj(){
             cout << name << " ~MyObj()" << endl;
      }
};

#define MY_DEBUG(msg) cout << __FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << " " << (msg) <<  endl

/**
 * Example how to use vector of shared_ptr objects
 */
static void vector_shared_ptr_example(void){
  MY_DEBUG("Entering");

  MyObj loc1("loc1");
  loc1.hello();

 // I had no luck with scoped_array<MyObj>
 // However vector< shared_ptr<MyObj> > seems to be better anyway...
 vector< boost::shared_ptr<MyObj> > vec;
 vec.push_back( boost::shared_ptr<MyObj>( new MyObj("array[0]") ) );
 vec.push_back( boost::shared_ptr<MyObj>( new MyObj("array[1]") ) );
 for( vector< boost::shared_ptr<MyObj> >::iterator i = vec.begin();
      i != vec.end(); i++ ){
       // Note double dereference, like i->->hello() !!!
       (*i)->hello();
 } 

  MY_DEBUG("Exiting");
}

/**
 * Example how to use scoped_ptr
 */
static void scoped_ptr_example(void){
  MY_DEBUG("Entering");

  boost::scoped_ptr<MyObj> scoped(new MyObj("scoped"));
  scoped->hello();

  MY_DEBUG("Exiting");
}

int main(int argc, char **argv){

    vector_shared_ptr_example();
    cout << endl;
    scoped_ptr_example();
    return 0;
}
