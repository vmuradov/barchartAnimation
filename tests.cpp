#include <iostream>
#include <fstream>
#include "barchart.h"
// #include "barchartanimate.h"

using namespace std;

// -------------------------------------- Bar Class Test Start
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarGetters() {
	string name = "Vlad";
	int value = 20;
	string category = "Human";
	Bar a(name, value, category); // parameterizes bar

	if(a.getName() == name && a.getValue() == value && a.getCategory() == category) {
		cout << "All Bar Getters Passed!" << endl;
		return true;
	} else if(a.getName() == name && a.getValue() == value && a.getCategory() != category) {
		cout << "Bar: getCategory Failed!" << endl;
		return false;
	} else if(a.getName() == name && a.getValue() != value && a.getCategory() == category) {
		cout << "Bar: getValue Failed!" << endl;
		return false;
	} else if(a.getName() != name && a.getValue() == value && a.getCategory() == category) {
		cout << "Bar: getName Failed!" << endl;
		return false;
	} else {
		cout << "Bar: multiple getters Failed!" << endl;
		return false;
	}

}

bool testBarLessThanOperator()  {
	Bar a("", 2 ,"");
	Bar b("", 4 ,"");
	if(b < a) {
		cout << "Bar: Operator < Passed!" << endl;
		return true;
	} else {
		cout << "Bar: Operator < Failed!" << endl;
		return false;
	}
}

bool testBarLessThanEqualToOperator() {
	Bar a("", 2 ,"");
	Bar b("", 4 ,"");
	if(b <= a) {
		cout << "Bar: Operator <= Passed!" << endl;
		return true;
	} else {
		cout << "Bar: Operator <= Failed!" << endl;
		return true;
	}
}

bool testBarMoreThanOperator() {
	Bar a("", 2 ,"");
	Bar b("", 4 ,"");
	if(b > a) {
		cout << "Bar: Operator > Passed!" << endl;
		return true;
	} else {
		cout << "Bar: Operator > Failed!" << endl;
		return true;
	}
}

bool testBarMoreThanEqualToOperator() {
	Bar a("", 2 ,"");
	Bar b("", 4 ,"");
	if(b >= a) {
		cout << "Bar: Operator >= Passed!" << endl;
		return true;
	} else {
		cout << "Bar: Operator >= Failed!" << endl;
		return true;
	}
}
// -------------------------------------- Bar Class Test End

bool testBarChartDefaulConstructor() {
	BarChart b;
    if (b.getSize() != 0) {
    	cout << "testBarChartDefaultConstructor: getSize failed" << endl;
    	return false;
    } else if (b.getFrame() != "") {
    	cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}
bool testBarChartParamaterizedConstructor() {
	BarChart b(5);
	if (b.getSize() != 5) {
		cout << "testBarChartDefaultConstructor: getSize failed" << endl;
		return false;
 	} else if (b.getFrame() != "") {
		cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
		return false;
 	}
	 cout << "testBarDefaultConstructor: all passed!" << endl;
	 return true;
}

bool testBarChartCopyConstructor() {}

bool testBarChartEquals() {
	BarChart a;
	BarChart b;

   a.setFrame("AAA");
   b = a;

   if(a.getFrame() == b.getFrame()) {
	   cout << "Overloaded Operator = Passed!" << endl;
	   return true;
   } else {
	   cout << "Overloaded Operator = Failed!" << endl;
	   return false;
   }
}

bool testBarChart() {
	map<string, string> colorMap;
    BarChart bc(10);
	
    bc.setFrame("1950");
    bc.addBar("Chicago", 1020, "US");
    bc.addBar("NYC", 1300, "NY");
    bc.addBar("Paris", 1200, "France");
    bc.dump(cout);

    string red("\033[1;31m");
    string blue("\033[1;34m");

    colorMap["US"] = red;
    colorMap["France"] = blue;

    bc.graph(cout, colorMap, 3);

    return 1;
}

int main() {

    return 0;
}
