#include <iostream>
#include <cstdlib>

#include "incidence.h"

using namespace std;

bool a1(const Incidence &inc) {
	// There exists at least one line
	// There exists at least one point
	for (int i = 0; i < inc.size(); i++) {
		for (int j = 0; j < inc.size(); j++) {
			if (inc.at(i,j) == 1) 
				return true;
		}
	}
	return false;
}

bool a2(const Incidence &inc, unsigned int n) {
	// For every line there are exacty n points
	// For every point there are exactly n lines
	for (int i = 0; i < inc.size(); i++) {
		unsigned int num_points = 0;
		for (int j = 0; j < inc.size(); j++) {
			num_points += inc.at(i,j);
		}
		if (num_points != n)
			return false;
	}
	return true;
}

bool a3(const Incidence &inc) {
	// Not all points are co-linear
	// Not all lines are incident at one point (translation is weird but duality holds I can prove it)
	unsigned int num_nonempty_lines = 0;
	for (int i = 0; i < inc.size(); i++) {
		for (int j = 0; j < inc.size(); j++) {
			if (inc.at(i,j)) {
				num_nonempty_lines++;
				break;
			}
		}
		if (num_nonempty_lines > 1)
			return true;
	}
	return false;
}

bool a4(const Incidence &inc) {
	// Two points determine exactly one line
	for (int p1 = 0; p1 < inc.size(); p1++) {
		for (int p2 = 0; p2 < inc.size(); p2++) {
			if (p2 == p1)
				continue; // Trivial case
			unsigned int num_lines_determined = 0;
			for (int line = 0; line < inc.size(); line++) {
				if (inc.at(line,p1) && inc.at(line,p2))
					num_lines_determined++;
			}
			if (num_lines_determined != 1)
				return false;
		}
	}
	return true;
}

bool a5(const Incidence &inc) {
	// Every pair of lines has one point of intersection
	for (int l1 = 0; l1 < inc.size(); l1++) {
		for (int l2 = 0; l2 < inc.size(); l2++) {
			if (l1 == l2)
				continue;
			unsigned int num_intersections = 0;
			for (int point = 0; point < inc.size(); point++) {
				if (inc.at(l1,point) && inc.at(l2,point))
					num_intersections++;
			}
			if (num_intersections != 1)
				return false;
		}
	}
	return true;
}

int main() {
	vector<Incidence> geometries;
	vector<vector<bool> > empty(1, vector<bool> (1, 0));
	vector<vector<bool> > first_geometry(1, vector<bool> (1, 1));
	Incidence in(first_geometry);
	geometries.push_back(Incidence(empty));
	geometries.push_back(in);
	for (int i = 0; i < geometries.size(); i++) {
		geometries[i].print();
		cout << "A1 : " << a1(geometries[i]) << endl;
		for (int n = 0; n < 10; n++) {
			if (a2(geometries[i], n))
				cout << "A2 : " << a2(geometries[i], n) << " [" << n << "]" << endl;
		}
		cout << "A3 : " << a3(geometries[i]) << endl;
		cout << "A4 : " << a4(geometries[i]) << endl;
		cout << "A5 : " << a5(geometries[i]) << endl;
	}
	return 0;
}
