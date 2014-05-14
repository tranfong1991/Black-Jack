#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Card
{
public:
	enum Suit{ Spades = 1, Hearts, Diamonds, Clubs };
	enum Face{ None = 0, Jack, Queen, King, Ace };
	enum Direction{ Down = 0, Up };

	Card(int v, Suit s = Spades, Direction d = Up)
		: value(v), suit(s), face(None), direction(d) {}
	Card(Face f = None, Suit s = Spades, Direction d= Up)
		: suit(s), face(f), direction(d) {
		(face != Ace) ? value = 10 : value = 1;
	}

	Face getFace() const { return face; }
	Suit getSuit() const { return suit; }
	int getValue() const { return (direction == Up) ? value : 0; }
	bool isFaceUp() const { return direction == Up; }
	void flip() { (direction == Down) ? direction = Up : direction = Down; }

	friend ostream& operator<<(ostream& os, const Card& c);
	friend ostream& operator<<(ostream& os, const Suit& s);
	friend ostream& operator<<(ostream& os, const Face& f);
private:
	int value;
	Suit suit;
	Face face;
	Direction direction;
};

ostream& operator<< (ostream& os, const Card::Face& f)
{
	switch (f)
	{
	case Card::Jack:
		os << "J";
		break;
	case Card::Queen:
		os << "Q";
		break;
	case Card::King:
		os << "K";
		break;
	case Card::Ace:
		os << "A";
		break;
	}
	return os;
}

ostream& operator<< (ostream& os, const Card::Suit& s)
{
	switch (s)
	{
	case Card::Spades:
		os << static_cast<char>(6);
		break;
	case Card::Clubs:
		os << static_cast<char>(5);
		break;
	case Card::Diamonds:
		os << static_cast<char>(4);
		break;
	case Card::Hearts:
		os << static_cast<char>(3);
		break;
	}
	return os;
}

ostream& operator<< (ostream& os, const Card& c)
{
	if (c.direction == Card::Up)
	{
		if (c.face == Card::None)
			os << c.value << c.suit;
		else os << c.face << c.suit;
	}
	else os << "XX";
	return os;
}