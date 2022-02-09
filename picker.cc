#include "read.h"
#include "decision.h"
#include <map>
#include <algorithm>
#include <unistd.h>
using namespace std;

void error(string s = "BAD INPUT!\n") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

int main() {
	system("figlet DECISION 2022 | lolcat");
	usleep(1'000'000);
	cout << "Time to make a decision..." << endl;
	// PHASE 1: Input College Data
	enum MENU_OPTIONS { ADD = 1, MODIFY, SEARCH, DELETE, QUIT };
	map<College, int> colleges;
	map<Decision, int> decisions;
	while (true) {
		cout << "Please select an option: \n";
		int choice = read("1. Add College to Database\n"
						  "2. Modify College in Database\n"
						  "3. Search College in Database\n"
						  "4. Delete College in Database\n"
						  "5. Quit\n");
		if (choice < ADD || choice > QUIT) error("Invalid Input!\n");
		if (choice == ADD) {}
		else if (choice == MODIFY) {}
		else if (choice == SEARCH) {}
		else if (choice == DELETE) {}
		else if (choice == QUIT) break;
	}
	// PHASE 2: User weighs their options
	
	// Phase 3: Add in Extra variables (Cost of Living, among other stuff)
	
	// Phase 4: Do calculations based on user inputs
	
	// Phase 5: Output the colleges
	
}
