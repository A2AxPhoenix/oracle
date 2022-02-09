#ifndef DECISION_H
#define DECISION_H

#include "college.h"

class Decision {
	private:
		double distanceFromFam;
		College college;
		double costOfLiving;
		bool jobMarket;
		bool haveFriendsNearby;
		int points; // Key to sort on
		bool studentLoans;
		bool hasOpportunities; // Internships, TC work, etc.
	public:
		Decision();
		Decision(College newCollege, double newCostOfLiving, double distanceFromFam);

		double get_distanceFromFam() const;
		College get_college() const;
		double get_costOfLiving() const;
		bool get_jobMarket() const;
		bool get_hasFriendsNearby() const;
		int get_points() const;
		bool get_hasStudentLoans() const;
		bool get_hasOpportunities() const;

		void set_distanceFromFam(double newDistanceFromFam);
		void set_college(College newCollege);
		void set_costOfLiving(double newCostOfLiving);
		void set_jobMarket(bool newHasJobMarket);
		void set_hasFriendsNearby(bool newHasFriendsNearby);
		void set_points(int newPoints);
		void set_hasStudentLoans(bool newHasStudentLoans);
		void set_hasOpportunities(bool newHasOpportunities);

		bool operator<(const Decision &d);
		bool operator==(const Decision &d);

		friend std::ostream& operator<<(std::ostream& outs, const Decision &d);
		friend std::istream& operator>>(std::istream& ins, Decision &d);
};

	bool sort_by_distanceFromFam(const Decision &d1, const Decision &d2);
	bool sort_by_college(const Decision &d1, const Decision &d2);
	bool sort_by_costOfLiving(const Decision &d1, const Decision &d2);
	bool sort_by_points(const Decision &d1, const Decision &d2);
	void print_stats(const Decision &d);

#endif
