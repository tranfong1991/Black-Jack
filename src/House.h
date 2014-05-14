#pragma once
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House() : GenericPlayer("House"){}

	bool isHitting() const { return (getTotal() < 16 || getTotalAce() < 16) ? true : false; }
	void flipFirstCard() { card[0].flip(); }
};