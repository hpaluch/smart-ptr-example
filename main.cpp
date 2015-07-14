/*
 * main.cpp - example, how to use shared_ptr with vector
 */
#include <iostream>
#include <boost/smart_ptr.hpp>

#include <vector>

using namespace std;

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

static void shared_ptr_example(void){
  MY_DEBUG("Entering");

  MyObj loc1("loc1");
  loc1.hello();

 // scoped array mi funguje jen na primitivni typy, ale tohle je snad ok...
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


int main(int argc, char **argv){

    shared_ptr_example();
    return 0;
}
