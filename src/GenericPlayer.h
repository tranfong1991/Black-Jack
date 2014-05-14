#pragma once
#include "Hand.h"
#include <iomanip>
#include <string>

class GenericPlayer : public Hand
{
protected:
	string name;
	GenericPlayer(string n) : name(n){}

	virtual bool isHitting() const = 0;
public:
	bool isBusted() const { return (getTotal() > 21 && getTotalAce() > 21) ? true : false; }
	void bust() const { cout << name << " busted.\n"; }

	friend ostream& operator<< (ostream& os, const GenericPlayer& gp);
};

ostream& operator<< (ostream& os, const GenericPlayer& gp)
{
	os << gp.name << ": " << (Hand)gp;
	return os;
}
