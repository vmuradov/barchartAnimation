#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "myrandom.h"
#include "bar.h"

using namespace std;

const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Codio (light/dark mode)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

class BarChart {
 private:
    Bar* bars;  //  pointer to a C-style array
    int capacity;
    int size; //  need to keep track
	string frame;

 public:
// default constructor
    BarChart() {
		bars = NULL;
		capacity = 0;
		size = 0;
		frame = "";
    }

// parameterized constructor, n determines memory allocated
    BarChart(int n) {
		bars = new Bar[n];
		capacity = n;
		size = 0;
		frame = "";
    }

// Creates a BarChart that contains a copy of everything that is passed in
    BarChart(const BarChart& other) {
		this -> bars = new Bar[other.capacity];
		this -> capacity = other.capacity;
		this -> size = other.size;
		this -> frame = other.frame;

		for(int i = 0; i < other.size; i++) //  copy over value inside of bars
			this -> bars[i] = other.bars[i];
    }

// Called when you assign one BarChart into another, i.e. this = other;
    BarChart& operator=(const BarChart& other) {
		this -> bars = new Bar[other.capacity];
		this -> capacity = other.capacity;
		this -> size = other.size;
		this -> frame = other.frame;

		for(int i = 0; i < other.size; i++) //  copy over value inside of bars
			this -> bars[i] = other.bars[i];

		return *this;
    }

// frees memory and resets all private member variables to default values.
    void clear() {
		delete[] bars;
		bars = NULL;
		capacity = 0;
		size = 0;
		frame = "";
    }

// Called automatically to free memory associated by the BarChart.
    virtual ~BarChart() {
		clear();
    }

    // setFrame
    void setFrame(string frame) {
		this -> frame = frame;
    }

    // Returns the frame of the BarChart oboject.
    string getFrame() {
        return this -> frame;
    }

	// Return # of bars in BarChart object
    int getSize() {
   	 return this -> size;
    }

// Adds a Bar into the BarChart if there is enough space allocated for it
    bool addBar(string name, int value, string category) {
		if(capacity <= size)
			return false;

		Bar b(name, value, category); // creates bar

		this -> bars[this -> size] = b; // puts bar into array inside barchart
		this -> size += 1;

		return true;
    }

// This gives public access to Bars stored in the Barchart
    Bar& operator[](int i) {
		if(i < 0 || i >= this -> size)
        	throw out_of_range("BarChart: i out of bounds");

        return bars[i];
    }

/* Sorts the bars in decending order, and then writes barcharts frame#,
			name, value, and catagory into the output file */
    void dump(ostream &output) {
		sort(bars, bars+size, greater<Bar>());

		output << "frame: " << getFrame() << endl;

		for(int i = 0; i < this -> size; i++) {
			output << bars[i].getName() << " " << bars[i].getValue()
					<< " " << bars[i].getCategory() << endl;
		}
    }

// Displays a colored frame with the bars in decending order
    void graph(ostream &output, map<string, string> &colorMap, int top) {
		int count = 0;

		sort(bars, bars+size, greater<Bar>());

		// if user wants us to print is more than the actual size of the BarChart
		if(top > size)
			top = size;

		for(int i = 0; i < top; i++) { // print amount of bars requested by top
			string boxes = "";
			string myColor = "";

			if(colorMap.count(bars[i].getCategory() ) == 1) {
				myColor = colorMap[bars[i].getCategory()];
			} else {
				myColor = BLACK;
			}

			count = ((double)bars[i].getValue() / bars[0].getValue()) * 60;

			for(int j = 0; j < count; j++)
				boxes += BOX;

			output << myColor << boxes << " " << bars[i].getName() << " "
						<< bars[i].getValue() << endl;
		}
	}

};
