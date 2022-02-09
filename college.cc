#include "college.h"
#include <limits>
#include <stdexcept>
using namespace std;
using C = College;

C::College() {
	name = "CSU Fresno";
	cost = 100;
	distance = 100;
	totalRating = 1;
	partyRating = 1;
	academicRating = 1;
	athleticRating = 1;
	location = "Fresno";
	liveOnCampus = false;
	hasMajor = true;
	hasBonusMiOrMa = false;
	bonusOpportunities = false;
}

C::College(string newName, double newCost, double newDistance, string newLocation) {
	set_name(newName);
	set_cost(newCost);
	set_distance(newDistance);
	set_location(newLocation);
}
string C::get_name() const { return name; }
double C::get_cost() const { return cost; }
double C::get_distance() const { return distance; }
int C::get_totalRating() const { return totalRating; }
int C::get_partyRating() const { return partyRating; }
int C::get_academicRating() const { return academicRating; }
int C::get_athleticRating() const { return athleticRating; }
string C::get_location() const { return location; }
bool C::get_liveOnCampus() const { return liveOnCampus; }
bool C::get_hasMajor() const { return hasMajor; }
bool C::get_hasBonusMiOrMa() const { return hasBonusMiOrMa; }
bool C::get_hasBonusOpportunities() const { return bonusOpportunities; }

void C::set_name(string newName) {
	for (const char &c : newName) {
		if (isdigit(c)) {
			throw logic_error("ERROR: Name passed in contains invalid characters.\n"
							  "Only alphabetical characters are allowed in name.\n");
		}
	}
	name = newName;
}
void C::set_cost(double newCost) {
	if (newCost < 0) throw logic_error("ERROR: Cost passed in is less than 0.\n"
									   "College costs should be positive.\n");
	if (newCost > numeric_limits<double>::max()) throw overflow_error("ERROR: Cost passed in is greater than accepted values.\n"
																	  "Cost values cannot exceed maximum values. Overflow Detected.\n");
	cost = newCost;
}
void C::set_distance(double newDistance) {
	if (newDistance < 0) throw logic_error("ERROR: Distance passed in is less than 0.\n"
										   "Distance should always be positive.\n");
	if (newDistance > numeric_limits<double>::max()) throw overflow_error("ERROR: Distance passed in is greater than accepted values.\n"
																		  "Distance values cannot exceed maximum values. Overflow Detected.\n");
	distance = newDistance;
}
void C::set_totalRating(int newTotalRating) {
	if (newTotalRating < 0) throw logic_error("ERROR: Rating passed in is less than 0.\n"
											  "Rating values should always be positive.\n");
	if (newTotalRating > numeric_limits<int>::max()) throw overflow_error("ERROR: Rating passed in is greater than accepted values.\n"
																		  "Rating values cannot exceed maximum values. Overflow Detected.\n");
	totalRating = newTotalRating;
}     
void C::set_partyRating(int newPartyRating) {
	if (newPartyRating < 0) throw logic_error("ERROR: Rating passed in is less than 0.\n"
											  "Rating values should always be positive.\n");
	if (newPartyRating > numeric_limits<int>::max()) throw overflow_error("ERROR: Rating passed in is greater than accepted values.\n"
																		  "Rating values cannot exceed maximum values. Overflow Detected.\n");
	partyRating = newPartyRating;
}
void C::set_academicRating(int newAcademicRating) {
	if (newAcademicRating < 0) throw logic_error("ERROR: Rating passed in is less than 0.\n"
											  "Rating values should always be positive.\n");
	if (newAcademicRating > numeric_limits<int>::max()) throw overflow_error("ERROR: Rating passed in is greater than accepted values.\n"
																		  "Rating values cannot exceed maximum values. Overflow Detected.\n");
	academicRating = newAcademicRating;
}
void C::set_athleticRating(int newAthleticRating) {
	if (newAthleticRating < 0) throw logic_error("ERROR: Rating passed in is less than 0.\n"
											  "Rating values should always be positive.\n");
	if (newAthleticRating > numeric_limits<int>::max()) throw overflow_error("ERROR: Rating passed in is greater than accepted values.\n"
																		  "Rating values cannot exceed maximum values. Overflow Detected.\n");
	athleticRating = newAthleticRating;
}
void C::set_location(string newLocation) {
	for (const char &c : newLocation) {
		if (isdigit(c)) {
			throw logic_error("ERROR: Location passed in contains invalid characters.\n"
							  "Only alphabetical characters are allowed.\n");
		}
	}
	location = newLocation;
}
void C::set_liveOnCampus(bool newLiveOnCampus) {
	liveOnCampus = newLiveOnCampus;
}
void C::set_hasMajor(bool newHasMajor) {
	hasMajor = newHasMajor;
}
void C::set_hasBonusMiOrMa(bool newBonusMiOrMa) {
	hasBonusMiOrMa = newBonusMiOrMa;
}
void C::set_newBonusOpportunities(bool newBonusOpportunities) {
	bonusOpportunities = newBonusOpportunities;
}

bool C::operator==(const College &c) {
	return cost == c.cost;
}
bool C::operator<(const College &c) {
	return cost < c.cost;
}


ostream& operator<<(ostream& outs, const College &c) {
	outs << "College Stats: " << endl;
	outs << "\tName: " << c.name << endl;
	outs << "\tCost: " << c.cost << endl;
	outs << "\tDistance: " << c.distance << endl;
	outs << "\tRating: " << c.totalRating << endl;
	return outs;
}
istream& operator>>(istream& ins, College &c) {
	ins >> c.name >> c.cost >> c.distance >> c.totalRating;
	return ins;
}

bool sort_by_cost(const College &c1, const College &c2) {
	return c1.get_cost() < c2.get_cost();
}
bool sort_by_distance(const College &c1, const College &c2) {
	return c1.get_distance() < c2.get_distance();
}
bool sort_by_rating(const College &c1, const College &c2) {
	return c1.get_totalRating() < c2.get_totalRating();
}
bool sort_by_location(const College &c1, const College &c2) {
	return c1.get_location() < c2.get_location();
}
bool sort_by_name(const College &c1, const College &c2) {
	return c1.get_name() < c2.get_name();
}
void print_stats(const College &c) {
	cout << "Stats of " << c.get_name() << ":\n";
	cout << "\tCost: " << c.get_cost() << endl;
	cout << "\tDistance: " << c.get_distance() << endl;
	cout << "\tRating: " << c.get_totalRating() << endl;
	cout << "\tLocation: " << c.get_location() << endl;
}

