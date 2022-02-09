#include "decision.h"
#include <limits>
#include <stdexcept>
using namespace std;
using D = Decision;

D::Decision() {
	distanceFromFam = 100.00;
	costOfLiving = 25'000.00;
	jobMarket = true;
	haveFriendsNearby = false;
	points = 0;
	studentLoans = true;
	hasOpportunities = false;	
}
D::Decision(College newCollege, double newCostOfLiving, double newDistanceFromFam) {
	college = newCollege;
	costOfLiving = newCostOfLiving;
	distanceFromFam = newDistanceFromFam;
}

double D::get_distanceFromFam() const { return distanceFromFam; }
College D::get_college() const { return college; }
double D::get_costOfLiving() const { return costOfLiving; }
bool D::get_jobMarket() const { return jobMarket; }
bool D::get_hasFriendsNearby() const { return haveFriendsNearby; }
int D::get_points() const { return points; }
bool D::get_hasStudentLoans() const { return studentLoans; }
bool D::get_hasOpportunities() const { return hasOpportunities; }

void D::set_distanceFromFam(double newDistanceFromFam) {
	if (newDistanceFromFam < 0) throw logic_error("ERROR: Distance passed in is less than 0.\n"
												  "Distance passed in must be positive.\n");
	if (newDistanceFromFam > numeric_limits<double>::max()) {
		throw overflow_error("ERROR: Distance passed in generates an overflow error.\n"
							 "Lower distance values to prevent overflow.\n");
	}
	distanceFromFam = newDistanceFromFam;
}
void D::set_college(College newCollege) {
	college = newCollege;
}
void D::set_costOfLiving(double newCostOfLiving) {
	if (newCostOfLiving < 0) throw logic_error("ERROR: Cost of Living passed in is less than 0.\n"
											   "Cost of Living passed in must be positive.\n");
	if (newCostOfLiving > numeric_limits<double>::max()) {
		throw overflow_error("ERROR: Cost of Living passed in generates an overflow error.\n"
							 "Lower Cost of Living values to prevent overflow.\n");
	}
	costOfLiving = newCostOfLiving;
}
void D::set_jobMarket(bool newHasJobMarket) {
	jobMarket = newHasJobMarket;
}
void D::set_hasFriendsNearby(bool newHasFriendsNearby) {
	haveFriendsNearby = newHasFriendsNearby;
}
void D::set_points(int newPoints) {
	if (newPoints < 0) throw logic_error("ERROR: Points passed in is less than 0.\n"
										 "Points passed in must be positive.\n");
	if (newPoints > numeric_limits<int>::max()) {
		throw overflow_error("ERROR: Points passed in generates an overflow error.\n"
							 "Lower point values to prevent overflow.\n");
	}
}
void D::set_hasStudentLoans(bool newHasStudentLoans) {
	studentLoans = newHasStudentLoans;
}
void D::set_hasOpportunities(bool newHasOpportunities) {
	hasOpportunities = newHasOpportunities;
}

bool D::operator<(const Decision &d) {
	return points < d.points;
}
bool D::operator==(const Decision &d) {
	return points == d.points;
}

ostream& operator<<(ostream& outs, const Decision &d) {
	outs << "Decision: " << endl;
	outs << "\tCollege Name: " << d.college.get_name() << endl;
	outs << "\tCollege Cost: " << d.college.get_cost() << endl;
	outs << "\tCollege Location: " << d.college.get_location() << endl;
	outs << "\tCollege Rating: " << d.college.get_totalRating() << endl;
	outs << "\tCost of Living: " << d.costOfLiving << endl;
	outs << "\tDistance from Family: " << d.distanceFromFam << endl;
	return outs;
}
istream& operator>>(istream& ins, Decision &d) {
	ins >> d.costOfLiving >> d.distanceFromFam >> d.points;
	return ins;
}
bool sort_by_distanceFromFam(const Decision &d1, const Decision &d2) {
	return d1.get_distanceFromFam() < d2.get_distanceFromFam();
}
bool sort_by_college(const Decision &d1, const Decision &d2) {
	return d1.get_college() < d2.get_college();
}
bool sort_by_costOfLiving(const Decision &d1, const Decision &d2) {
	return d1.get_costOfLiving() < d2.get_costOfLiving();
}
bool sort_by_points(const Decision &d1, const Decision &d2) {
	return d1.get_points() < d2.get_points();
}
void print_stats(const Decision &d) {
	cout << "Decision: " << endl;
	cout << "\tCollege Name: " << d.get_college().get_name() << endl;
	cout << "\tCollege Cost: " << d.get_college().get_cost() << endl;
	cout << "\tCollege Location: " << d.get_college().get_location() << endl;
	cout << "\tCollege Rating: " << d.get_college().get_totalRating() << endl;
	cout << "\tCost of Living: " << d.get_costOfLiving() << endl;
	cout << "\tDistance from Family: " << d.get_distanceFromFam() << endl;
	
}
