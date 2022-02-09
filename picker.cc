#include "read.h"
#include "decision.h"
#include <map>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <unistd.h>
using namespace std;

void reset_state() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void error(string s = "BAD INPUT!\n") {
	cout << s << endl;
}
void fail(string s = "") {
	error(s);
	usleep(1'000'000);
	exit(EXIT_FAILURE);
}
void chance(string s = "") {
	usleep(500'000);
	system("clear");
	error(s);
	usleep(500'000);
	reset_state();
}

int main() {
	system("figlet DECISION 2022 | lolcat");
	usleep(1'000'000);
	cout << "Time to make a decision..." << endl;
	const int MAX_FAILS = 5;
	int failCounter = 0;
	// PHASE 1: Input College Data
	enum MENU_OPTIONS { ADD = 1, MODIFY, SEARCH, DELETE, QUIT };
	map<College, int> colleges;
	map<Decision, int> decisions;
	while (true) {
		cout << "Please select an option: \n";
		cout << "1. Add College to Database\n"
			"2. Modify College in Database\n"
			"3. Search College in Database\n"
			"4. Delete College in Database\n"
			"5. Quit" << endl;
		int choice = 0;
		cin >> choice;
		if (!cin || choice < ADD || choice > QUIT) {
			if (failCounter == MAX_FAILS) 
				fail("You've exceeded max attempts to choose from menu.\nQuitting now...");
			else {
				failCounter++;
				chance("Error: Entered invalid input. Please enter a valid input.\n");
				continue;
			}
		}
		reset_state();
		if (choice == ADD) { // TODO: FINISH ADDING
			failCounter = 0;
			while (true) {
				College tempCollege;
				try {
					cout << "Please enter the name of the college (Enter \"Quit\" to break.)." << endl;
					string collegeName;
					getline(cin, collegeName);
					if (collegeName == "Quit" || collegeName == "quit" || collegeName == "QUIT") break;
					tempCollege.set_name(collegeName);
					while (true) {
						cout << "Please enter the cost of the college.\n";
						double collegeCost = 0.0;
						cin >> collegeCost;
						if (!cin || collegeCost < 0) {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						tempCollege.set_cost(collegeCost);
						break;
					}
					while (true) {
						cout << "Please enter the average overall rating of the college.\n"
							<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1" << endl;
						int collegeRating = 0;
						cin >> collegeRating;
						if (!cin || collegeRating < 0 || collegeRating > 5) {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						tempCollege.set_totalRating(collegeRating);
						break;
					}
					bool additionalRatings = false;
					string response;
					cout << "Would you like to input other ratings for the college (Academics, Party, Athletics)?\n"
						<< "Please type No or Yes.\n";
					cin >> response;
					if (response != "YES" || response != "Yes" || response != "yes" || response != "NO" || response != "no" || response != "No") {
						if (failCounter == MAX_FAILS)
							fail("You've exceeded max attempts for correct input.\nQuitting now...");
						else {
							failCounter++;
							chance("Error: Entered invalid input. Please enter a valid input.\n");
							continue;
						}
					}
					if (response == "YES" || response == "yes" || response == "Yes") additionalRatings = true;
					else additionalRatings = false;

					if (additionalRatings == true) {
						cout << "Do you want to add the academic rating of your college?\n"
							<< "Please type Yes or No.\n";
						string rating;
						cin >> rating;

						if (rating != "YES" || rating != "Yes" || rating != "yes" || rating != "NO" || rating != "no" || rating != "No") {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						bool academic = false;
						if (rating == "YES" || rating == "yes" || rating == "Yes") academic = true;
						else academic = false;

						if (academic == true) {
							cout << "Please enter the academic rating of the college.\n"
								<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
							int acaRating = 0;
							cin >> acaRating;
							if (!cin || acaRating < 0 && acaRating > 5) {
								if (failCounter == MAX_FAILS) 
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
								}
							}

						}
						cout << "Do you want to add the athletic rating of your college?\n"
							<< "Please type Yes or No.\n";
						cin >> rating;

						if (rating != "YES" || rating != "Yes" || rating != "yes" || rating != "NO" || rating != "no" || rating != "No") {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						bool athletic = false;
						if (rating == "YES" || rating == "yes" || rating == "Yes") academic = true;
						else athletic = false;

						if (athletic == true) {
							cout << "Please enter the athletic rating of the college.\n"
								<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
							int athlRating = 0;
							if (!cin || athlRating < 0 && athlRating > 5) {
								if (failCounter == MAX_FAILS)
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
									failCounter++;
									chance("Error: Entered invalid input. Please enter a valid input.\n");
									continue;
								}
							}
						}
						cout << "Do you want to add the party rating of your college?\n"
							<< "Please type Yes or No.\n";
						cin >> rating;

						if (rating != "YES" || rating != "Yes" || rating != "yes" || rating != "NO" || rating != "no" || rating != "No") {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						bool party = false;
						if (rating == "YES" || rating == "yes" || rating == "Yes") academic = true;
						else party = false;

						if (party == true) {
							cout << "Please enter the athletic rating of the college.\n"
								<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
							int partyRating = 0;
							cin >> partyRating;
							if (!cin || partyRating < 0 && partyRating > 5) {
								if (failCounter == MAX_FAILS)	
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
									failCounter++;
									chance("Error: Entered invalid input. Please enter a valid input.\n");
									continue;
								}
							}
						}
						// TODO: Continue getting info on college and making it part of tempCollege
					}
				}
				catch (exception &e) {
					cout << "Caught: " << e.what() << "\nPlease try again.\n";
				}
			}
		}// TODO: Everything below... Finish Phase 1 - Phase 5
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
