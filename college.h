#ifndef COLLEGE_HELP_H
#define COLLEGE_HELP_H

#include <iostream>

class College {
	private:
		std::string name;
		double cost;
		double distance;
		int totalRating; // Key to sort on
		int partyRating;
		int academicRating;
		int athleticRating;
		std::string location;
		bool liveOnCampus;
		bool hasMajor;
		bool hasBonusMiOrMa; // Has bonus Minor or Major
		bool bonusOpportunities; // Gives extra opportunities to graduates or current students
	public:
		College();
		College(std::string newName, double newCost, double newDistance, std::string newLocation);

		std::string get_name() const;
		double get_cost() const;
		double get_distance() const;
		int get_totalRating() const;
		int get_partyRating() const;
		int get_academicRating() const;
		int get_athleticRating() const;
		std::string get_location() const;
		bool get_liveOnCampus() const;
		bool get_hasMajor() const;
		bool get_hasBonusMiOrMa() const;
		bool get_hasBonusOpportunities() const;

		void set_name(std::string newName);
		void set_cost(double newCost);
		void set_distance(double newDistance);
		void set_totalRating(int newTotalRating);
		void set_partyRating(int newPartyRating);
		void set_academicRating(int newAcademicRating);
		void set_athleticRating(int newAthleticRating);
		void set_location(std::string newLocation);
		void set_liveOnCampus(bool newLiveOnCampus);
		void set_hasMajor(bool newHasMajor);
		void set_hasBonusMiOrMa(bool newBonusMiOrMa);
		void set_newBonusOpportunities(bool newBonusOpportunities);

		bool operator==(const College &c);
		bool operator<(const College &c);

		
		friend std::ostream& operator<<(std::ostream& outs, const College &c);
		friend std::istream& operator>>(std::istream& ins, College &c);
};

	bool sort_by_cost(const College &c1, const College &c2);
	bool sort_by_distance(const College &c1, const College &c2);
	bool sort_by_rating(const College &c1, const College &c2);
	bool sort_by_location(const College &c1, const College &c2);
	bool sort_by_name(const College &c1, const College &c2);
	void print_stats(const College &c);

#endif
