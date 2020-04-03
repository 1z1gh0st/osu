#ifndef INCIDENCE_H
#define INCIDENCE_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Incidence {
	private:
		unsigned int size_;
		vector<vector<bool> > matrix_;
	public:
		Incidence(vector<vector<bool> > matrix) {
			matrix_ = matrix;
			size_ = matrix.size();
		}
		bool at(unsigned int i, unsigned int j) const {
			if (i >= size_ || j >= size_)
				throw "Out of range";
			else 
				return matrix_[i][j];
		}
		unsigned int size() const { return size_; }
		void print() const {
			for (int i = 0; i < size_; i++) {
				for (int j = 0; j < size_; j++) {
					cout << " " << matrix_[i][j];
				}
				cout << endl;
			}
		}
};

#endif
