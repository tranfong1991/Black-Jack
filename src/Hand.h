#pragma once
#include "Card.h"

class Hand
{
	int findAce() const;
protected:
	vector<Card> card;
public:
	Hand() : card(){}

	void add(Card* c) { card.push_back(*c); }
	void clear() { card.clear(); }
	int getTotal() const;
	int getTotalAce() const;

	friend ostream& operator<< (ostream& os, const Hand& hand);
};

int Hand::findAce() const
{
	for (int i = card.size() - 1; i >= 0; --i)
	if (card[i].getFace() == Card::Ace)
		return i;
	return -1;
}

int Hand::getTotal() const
{
	int total = 0;
	for (int i = 0; i < card.size(); i++)
		total += card[i].getValue();
	return total;
}

int Hand::getTotalAce() const
{
	if (findAce() != -1)
	{
		if ((getTotal() + 10)>21) return getTotal();
		else return getTotal() + 10;
	}
	else return getTotal();
}

ostream& operator<< (ostream& os, const Hand& hand)
{
	for (int i = 0; i < hand.card.size(); ++i)
		os << hand.card[i] << " ";
	if (hand.findAce() != -1 && hand.card[hand.findAce()].isFaceUp())
		os << "     (" << hand.getTotal() << "/" << hand.getTotalAce() << ")";
	else os << "     (" << hand.getTotal() << ")";
	return os;
}
