#include "read.h"
#include "decision.h"
#include <limits>
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
void uppercaseify(string &s) {
	for (char &c : s) c = toupper(c);
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
					cout << "Please enter the name of the college (Enter \"QUIT\" to break.)." << endl;
					string collegeName;
					getline(cin, collegeName);
					uppercaseify(collegeName);
					if (collegeName == "QUIT") break;
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
					int collegeRating = 0;
					while (true) {
						cout << "Please enter the average overall rating of the college.\n"
							<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1" << endl;
						cin >> collegeRating;
						if (!cin || collegeRating <= 0 || collegeRating > 5) {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						break;
					}
					tempCollege.set_totalRating(collegeRating);
					bool additionalRatings = false;
					while (true) {
						cout << "Would you like to input other ratings for the college (Academics, Party, Athletics)?\n"
							<< "Please type \"YES\" or \"NO\"." << endl;
						string response;
						cin >> response;
						uppercaseify(response);
						if (response == "YES") { 
							additionalRatings = true;
							break;
						}
						else if (response == "NO") { 
							additionalRatings = false;
							break;
						}
						else {
							if (failCounter == MAX_FAILS)
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
					}
					string rating;
					if (additionalRatings == true) {
						bool academic = false;
						while (true) {
							cout << "Do you want to add the academic rating of your college?\n"
								<< "Please type \"YES\" or \"NO\".\n";
							cin >> rating;
							uppercaseify(rating);

							if (rating == "YES") { 
								academic = true;
								break;
							}
							else if (rating == "NO") { 
								academic = false;
								break;
							}
							else {
								if (failCounter == MAX_FAILS)
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
									failCounter++;
									chance("Error: Entered invalid input. Please enter a valid input.\n");
									continue;
								}
							}
						}
						int acaRating = 0;
						if (academic == true) {
							while (true) {
								cout << "Please enter the academic rating of the college.\n"
									<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
								cin >> acaRating;
								if (!cin || acaRating <= 0 && acaRating > 5) {
									if (failCounter == MAX_FAILS) 
										fail("You've exceeded max attempts for correct input.\nQuitting now...");
									else {
										failCounter++;
										chance("Error: Entered invalid input. Please enter a valid input.\n");
										continue;
									}
								}
								break;
							}
						}
						tempCollege.set_academicRating(acaRating);
						bool athletic = false;
						while (true) {
							cout << "Do you want to add the athletic rating of your college?\n"
								<< "Please type \"YES\" or \"NO\".\n";
							cin >> rating;
							uppercaseify(rating);

							if (rating == "YES") { 
								athletic = true;;
								break;
							}
							else if (rating == "NO") { 
								athletic = false;
								break;
							}
							else {
								if (failCounter == MAX_FAILS)
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
									failCounter++;
									chance("Error: Entered invalid input. Please enter a valid input.\n");
									continue;
								}
							}
						}
						int athlRating = 0;
						if (athletic == true) {
							while (true) {
								cout << "Please enter the athletic rating of the college.\n"
									<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
								cin >> athlRating;
								if (!cin || athlRating <= 0 && athlRating > 5) {
									if (failCounter == MAX_FAILS)
										fail("You've exceeded max attempts for correct input.\nQuitting now...");
									else {
										failCounter++;
										chance("Error: Entered invalid input. Please enter a valid input.\n");
										continue;
									}
								}
								break;
							}
						}
						tempCollege.set_athleticRating(athlRating);
						bool party = false;
						while (true) {
							cout << "Do you want to add the party rating of your college?\n"
								<< "Please type \"Yes\" or \"NO\".\n";
							cin >> rating;
							uppercaseify(rating);

							if (rating == "YES") { 
								party = true;;
								break;
							}
							else if (rating == "NO") { 
								party = false;
								break;
							}
							else {
								if (failCounter == MAX_FAILS)
									fail("You've exceeded max attempts for correct input.\nQuitting now...");
								else {
									failCounter++;
									chance("Error: Entered invalid input. Please enter a valid input.\n");
									continue;
								}
							}
						}
						int partyRating = 0;
						if (party == true) {
							while (true) {
								cout << "Please enter the athletic rating of the college.\n"
									<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
								cin >> partyRating;
								if (!cin || partyRating <= 0 && partyRating > 5) {
									if (failCounter == MAX_FAILS)	
										fail("You've exceeded max attempts for correct input.\nQuitting now...");
									else {
										failCounter++;
										chance("Error: Entered invalid input. Please enter a valid input.\n");
										continue;
									}
								}
								break;
							}
						tempCollege.set_partyRating(partyRating);
						}
						// TODO: Continue getting info on college and making it part of tempCollege
					}
				}
				catch (exception &e) {
					cout << "CAUGHT " << e.what() << "\nPlease try again.\n";
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
