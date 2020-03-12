#include <stdlib.h>
#include <iostream>

using std::cout;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
             s=0;
             v=NULL;
      }
	  // Big Three //
      ~vector(){
             delete [] v;
      }

	  vector operator= (const vector<T> &vec) {
		  	 T *temp_array = new T [vec.s];
			 for (int i = 0; i < vec.s; i++) {
			 		temp_array[i] = vec.v[i];
			 }
			 v = temp_array;
			 delete [] temp_array;
			 s = vec.s;
			 return *this;
	  }
	  
	  vector(const vector<T> &vec) {
		  	 T *temp_array = new T [vec.s];
			 for (int i = 0; i < vec.s; i++) {
			 		temp_array[i] = vec.v[i];
			 }
			 v = temp_array;
			 s = vec.s;
	  }

	  T operator[](int i) {
		  	 return *(v + i);
	  }
	  
	  T at(int i) {
		  	 if (i > s) {
				 cout<< "ERROR: out of range";
		  	 } else {
					return *(v + i);	
		  	 }
	  }

      int size() {
             return s;
      }

      void push_back(T ele) {
             T *temp;
             temp = new T[++s];
             for(int i=0; i<s-1; i++)
                temp[i]=v[i];
             delete [] v;
             v=temp;
             v[s-1]=ele;
      }
};
