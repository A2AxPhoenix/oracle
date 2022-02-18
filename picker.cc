#include "college.h"
#include "read.h"
#include "decision.h"
#include <limits>
#include <deque>
#include <list>
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
	(void)!system("clear");
	error(s);
	usleep(500'000);
	reset_state();
}
void uppercaseify(string &s) {
	for (char &c : s) c = toupper(c);
}

int main() {
	(void)!system("figlet DECISION 2022 | lolcat");
	usleep(1'000'000);
	cout << "Time to make a decision..." << endl;
	const int MAX_FAILS = 5;
	int failCounter = 0;
	// PHASE 1: Input College Data
	enum MENU_OPTIONS { ADD = 1, MODIFY = 2, SEARCH, DELETE, QUIT };
	deque<College> colleges;
	list<Decision> decisions;
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
		if (choice == ADD) {
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
					cout << "Please enter the city the college is in." << endl;
					string collegeLocation;
					getline(cin, collegeLocation);
					uppercaseify(collegeLocation);
					tempCollege.set_location(collegeLocation);
					while (true) {
						cout << "Please enter the total distance (in miles) the college is from your hometown." << endl;
						double collegeDistance = 0.0;
						cin >> collegeDistance;
						if (!cin || collegeDistance < 0) {
							if (failCounter == MAX_FAILS) 
								fail("You've exceeded max attempts for correct input.\nQuitting now...");
							else {
								failCounter++;
								chance("Error: Entered invalid input. Please enter a valid input.\n");
								continue;
							}
						}
						tempCollege.set_distance(collegeDistance);
						break;
					}
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
								if (!cin || (acaRating <= 0 && acaRating > 5)) {
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
								if (!cin || (athlRating <= 0 && athlRating > 5)) {
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
								cout << "Please enter the party rating of the college.\n"
									<< "Note: A = 5, B = 4, C = 3, D = 2, F = 1\n";
								cin >> partyRating;
								if (!cin || (partyRating <= 0 && partyRating > 5)) {
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
						tempCollege.set_partyRating(partyRating);
					}
					bool campusHousing = false;
					reset_state();
					while (true) {
						cout << "Does the college offer on campus housing?\nEnter \"YES\" or \"NO\"." << endl;
						string housing;
						getline(cin, housing);
						uppercaseify(housing);
						if (housing == "YES") campusHousing = true;
						else if (housing == "NO") campusHousing = false;
						else {
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
					tempCollege.set_liveOnCampus(campusHousing);
					bool desiredMajor = false;
					while (true) {
						cout << "Does the college offer your desired major?\nEnter \"YES\" or \"NO\"." << endl;
						string major;
						getline(cin, major);
						uppercaseify(major);
						if (major == "YES") desiredMajor = true;
						else if (major == "NO") desiredMajor = false;
						else {
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
					tempCollege.set_hasMajor(desiredMajor);

					cout << "You are about to add a college, please make sure all information is correct before moving on." << endl;
					print_stats(tempCollege);
					bool completed = false;
					while (true) {
						cout << "\nIs all information correct (Enter \"YES\" or \"NO\".)?\n";
						string doubleCheck;
						getline(cin, doubleCheck);
						uppercaseify(doubleCheck);
						if (doubleCheck == "YES") completed = true;
						else if (doubleCheck == "NO") completed = false;
						else {
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
					if (completed == true) {
						colleges.push_back(tempCollege);
						cout << colleges.size() << endl;
					}
					else if (completed == false)
						// TODO: Reprompt with specific modifications rather than have them redo the entire prompt from beginning to end.
						continue;
					bool moreInputs = false;
					while (true) {
						cout << "Do you have more colleges to add (Enter \"YES\" or \"NO\".)?\n";
						string addingMore;
						getline(cin, addingMore);
						uppercaseify(addingMore);
						if (addingMore == "YES") moreInputs = true;
						else if (addingMore == "NO") moreInputs = false;
						else {
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
					if (moreInputs == true) continue;
					else break;
				}
				catch (exception &e) {
					cout << "CAUGHT " << e.what() << "\nPlease try again.\n";
				}
			}
		}// TODO: Everything below... Finish Phase 2 - Phase 5
		else if (choice == MODIFY) {
			// IN PROGRESS...
			if (colleges.size() == 0)
				cout << "No colleges are in database. Add colleges to the database first to modify.\n";
			else {
				for (size_t i = 0; i < colleges.size(); i++) {
					cout << i << ": " << colleges.at(i).get_name() << endl;
				}
			}
			while (true) {
				try {

				}
				catch (exception &e) {
					cout << "CAUGHT " << e.what() << endl;
				}
			}
		}
		else if (choice == SEARCH) {}
		else if (choice == DELETE) {}
		else if (choice == QUIT) break;
	}
	// PHASE 2: User weighs their options

	// Phase 3: Add in Extra variables (Cost of Living, among other stuff)

	// Phase 4: Do calculations based on user inputs

	// Phase 5: Output the colleges

}
