#pragma once
#include<time.h>
#include"Hand.h"
#include"GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck(){}

	void populate();
	void shuffle();
	void deal(Hand& hand);
	void additionalCards(GenericPlayer& gp);
};

void Deck::populate()
{
	typedef Card::Suit Suit;
	typedef Card::Face Face;

	for (int i = 2; i <= 10; ++i)
	for (int j = 1; j <= 4; ++j)
		add(&Card(i, Suit(j)));
	for (int i = 1; i <= 4; ++i)
	for (int j = 1; j <= 4; ++j)
		add(&Card(Face(i), Suit(j)));
}

void Deck::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < 52; ++i)
	{
		int x = rand() % 51;
		Card temp = card[i];
		card[i] = card[x];
		card[x] = temp;
	}
}

void Deck::deal(Hand& hand)
{
	hand.add(&card.back());
	card.pop_back();
}

void Deck::additionalCards(GenericPlayer& gp)
{
	gp.add(&card.back());
	card.pop_back();
}


