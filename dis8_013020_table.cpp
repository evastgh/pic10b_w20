#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void print_table(ostream& os, const vector<int>& ids, const vector<double>& heights, const int w_id = 3, const int w_height = 8) {
	// first horizontal line
	os << string(w_id + w_height + 3, '-') << endl;
	// descriptors of the columns
	os << "|ID " << "|height  |" << endl;
	for (size_t i = 0; i < ids.size(); ++i) {
		// horizontal separator
		os << '|' << string(w_id, '-') << '|' << string(w_height, '-') << '|' << endl;
		// data
		os << '|' << setw(w_id) << setfill('*') << ids[i];
		os << '|' << setw(w_height) << setfill(' ') << heights[i] << '|' << endl;
	}
	// final horizontal line
	os << string(w_id + w_height + 3, '-') << endl;
}
int main()
{
	/*
	const vector<int> ids = { 1, 2, 3 };
	const vector<double> heights = { 101.111, 5.16, 20.88 };
	const int w_id = 3, w_height = 8;

	ofstream fs("table.txt");
	print_table(fs, ids, heights, w_id, w_height);
	fs.close();
	*/
	
	ifstream fs("table.txt");
	string line;
	getline(fs, line); // skip first hline
	getline(fs, line); // skip column descriptors
	getline(fs, line); // skip another hlind
	getline(fs, line);
	stringstream ss(line);
	ss.get(); // skip first vert bar
	int id;
	ss >> id;
	ss.get(); // skip another ver bar
	double height;
	ss >> height;

	cout << "Got id = " << id;
	cout << " and height = " << height;

	fs.close();
}
