#include <iostream>
#include <string>
#include "myrandom.h"

using namespace std;

class Bar {
 private:
	 string name;
	 int value;
	 string category;

 public:
//  default constructor
    Bar() {
		name = "";
		value = 0;
		category = "";
    }

//  Parameterized constructor for Bar object
    Bar(string name, int value, string category) {
		this -> name = name;
		this -> value = value;
		this -> category = category;
    }

//  Destructor
    virtual ~Bar() {

    }

// returns the name associated with the Bar object
	string getName() {

        return name;
	}

// returns the value associated with the Bar object
	int getValue() {

        return value;
	}

// returns the category associated with the Bar object
	string getCategory() {

        return category;
	}

//  Bar objects can now be compared by their values with the overloaded < operator
	bool operator<(const Bar &other) const {
        return this -> value < other.value;
	}

//  Bar objects can now be compared by their values with the overloaded <= operator
	bool operator<=(const Bar &other) const {
        return this -> value <= other.value;
	}

//  Bar objects can now be compared by their values with the overloaded > operator
	bool operator>(const Bar &other) const {
        return this -> value > other.value;
	}

//  Bar objects can now be compared by their values with the overloaded >= operator
	bool operator>=(const Bar &other) const {
        return this -> value >= other.value;
	}
};
