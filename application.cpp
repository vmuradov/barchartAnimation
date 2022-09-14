/* Included a menu for the user of this application to be able to select which
	file they wish to itterate through, cities, movies, brands, etc. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"

using namespace std;

void selectionMenu(int& userInput) {
	cout << "1. baby-names\n2. brands\n3. cities-usa\n4. cities\n5. countries\n"
		<< "6. endgame\n7. football\n8. game-of-thrones\n9. infinity-war\n10. movies\n11. patents\n12. trademarks\n0. To end program.\n\n";
	cout << "Choose test number (1-12, or 0 to end): ";
	cin >> userInput;
}
string menu() {
	int userInput = -1;
	while (userInput != 0) {
		selectionMenu(userInput);
		if (userInput == 1) {
			return "baby-names.txt";
		} else if (userInput == 2) {
			return "brands.txt";
		} else if (userInput == 3) {
			return "cities-usa.txt";
		} else if (userInput == 4) {
			return "cities.txt";
		} else if (userInput == 5) {
			return "countries.txt";
		} else if (userInput == 6) {
			return "endgame.txt";
		} else if (userInput == 7) {
			return "football.txt";
		} else if (userInput == 8) {
			return "game-of-thrones.txt";
		} else if (userInput == 9) {
			return "infinity-war.txt";
		} else if (userInput == 10) {
			return "movies.txt";
		} else if (userInput == 11) {
			return "patents.txt";
		} else if (userInput == 12) {
			return "trademarks.txt";
		} else {
			cout << "Goodbye!\n";
			return "";
		}
	}
	return "";
}

int main() {

	string filename = menu();
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);

	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}

		bca.animate(cout, 12, -1);

    return 0;
}
