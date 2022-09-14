#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"
#include "barchart.h"

using namespace std;

class BarChartAnimate {
 private:
    BarChart* barcharts;  // pointer to a C-style array
	map<string, string> colorMap;
	int size;
    int capacity;
	int cycle;
	string title;
	string xlabel;
	string source;
 public:
    // parameterized constructor
    BarChartAnimate(string title, string xlabel, string source) {
		capacity = 4;
		cycle = 0;
		size = 0;
		barcharts = new BarChart[capacity];
		this -> title = title;
		this -> xlabel = xlabel;
		this -> source = source;
    }
	// Destroctor called automatically to free memory associated with BarChartAnimate
    virtual ~BarChartAnimate() {
		delete[] barcharts;
    }

	/* Reads input from a filestream and after creating a frame and associating
		color with each bar adds all the information into BarChartAnimate */
    void addFrame(ifstream &file) {
		string name = ""; string value = ""; string category = "";
		string frame = ""; string records = "";
		string country = ""; string blank = "";

		if(size == capacity) {
			BarChart* temp = new BarChart[capacity * 2];
			for(int i = 0; i < capacity; i++)
				temp[i] = barcharts[i];
			delete[] barcharts;
			capacity = capacity * 2;
			barcharts = temp;
		}

		getline(file, blank);
		getline(file, records);

		if(records == "")
			return;

		BarChart bc(stoi(records)); // BarChart bc = BarChart(stoi(records));
		// Barchart* is pointing at the whole object NOT only bars

		for(int i = 0; i < stoi(records); i++) {
			getline(file, frame, ',');

			getline(file, name, ',');
			getline(file, country, ',');
			getline(file, value, ',');
			getline(file, category);

			if(colorMap.count(category) != 1) {
				colorMap[category] = COLORS[cycle%7];
				cycle++;
			}

			bc.addBar(name, stoi(value), category); // adds bar into array inside barchart
			// calls addBar and if true stores a bar inside a barchart bc
		}
		bc.setFrame(frame);
		barcharts[size] = bc;
		size++;
    }

/* Animates the frames inside of BarChartAnimate clearing the previous frame
	before showing the next with a 50000 microsecond delay */
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;

		if (endIter < 0 || endIter > size)
			endIter = size;

		for(int i = 0; i < endIter; i++) {
			usleep(3 * microsecond); // pause
			output << CLEARCONSOLE; // clear
			output << "\x1B[1;37m" << title << "\n" << source << endl;
			barcharts[i].graph(output, colorMap, top);
			output << "\x1B[1;37m" << xlabel << "\n" << "Frame: " << barcharts[i].getFrame() << endl;
		}
	}

    //  returns the size of the BarChartAnimate object.
    int getSize() {

      return this -> size;
    }

// This gives public access to barcharts stored in the BarChartAnimate
    BarChart& operator[](int i){
		if(i < 0 || i >= this -> size)
        	throw out_of_range("BarChartAnimate: i out of bounds");

        return barcharts[i];
    }
};
