#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(string n = "") : GenericPlayer(n){}

	bool isHitting() const;
	void win() const { cout << name << " (" << getTotalAce() << ") Won.\n"; }
	void lose() const { cout << name << " (" << getTotalAce() << ") Losed.\n"; }
	void push() const { cout << name << " (" << getTotalAce() << ") Pushed.\n"; }
};

bool Player::isHitting() const
{
	char choice;
	cout << name << ", do you want a hit? (Y/N)";
	cin >> choice;
	return choice == 'y' || choice == 'Y';
}