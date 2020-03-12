#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   cout << "Testing operator []" << endl;
   cout << v[0] << endl;
   cout << stdv[0] << endl;

   cout << "Testing .at()" << endl;
   cout << v.at(0) << endl;
   cout << stdv.at(0) << endl;

   cout << "Testing copy constructor: " << endl;
   std::vector<int> new_stdv = stdv;
   vector<int> new_v = v;
   cout << new_v[0] << endl;
   cout << new_stdv[0] << endl;


   vector<int> asgn_v;
   asgn_v = v;
   cout << "Testing assignment operator overload" << endl;
   cout << asgn_v[0] << endl; 



   return 0;
}
