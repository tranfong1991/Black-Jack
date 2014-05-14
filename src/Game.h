#pragma once
#include "House.h"
#include "Player.h"
#include "Deck.h"

int max(int a, int b)
{
	return (a > b) ? a : b;
}

class Game
{
	House house;
	vector<Player> player;
public:
	Game(int num = 0) : player(num), house(){}

	void play();
};

void Game::play()
{
	Deck deck;
	deck.populate();
	deck.shuffle();
	deck.deal(house);
	deck.deal(house);
	house.flipFirstCard();
	for (int i = 0; i < player.size(); ++i)
	{
		string name;
		cout << "Player " << i + 1 << "'s name: ";
		cin >> name;
		player[i] = Player(name);
		deck.deal(player[i]);
		deck.deal(player[i]);
	}
	cout << endl << house << endl;
	for (int i = 0; i < player.size(); ++i)
		cout << player[i] << endl;
	cout << endl;
	for (int i = 0; i < player.size(); ++i)
	{
		cout << player[i] << endl;
		cout << "==============================================\n";
		while (player[i].isHitting())
		{
			deck.additionalCards(player[i]);
			cout << player[i] << endl;
			if (player[i].isBusted())
			{
				player[i].bust();
				player.erase(player.begin() + i);
				i--;
				break;
			}
		}
		cout << endl << endl;
	}
	house.flipFirstCard();
	cout << house << endl;
	while (house.isHitting())
	{
		deck.additionalCards(house);
		cout << house << endl;
		if (house.isBusted())
		{
			house.bust();
			cout << endl;
			for (int i = 0; i < player.size(); ++i)
				player[i].win();
			return;
		}
	}
	cout << endl;
	for (int i = 0; i < player.size(); ++i)
	{
		int playerTotal = player[i].getTotal();
		int playerTotalAce = player[i].getTotalAce();
		int houseTotal = house.getTotal();
		int houseTotalAce = house.getTotalAce();

		if (max(playerTotal, playerTotalAce) > max(houseTotal, houseTotalAce)) player[i].win();
		else if (max(playerTotal, playerTotalAce) < max(houseTotal, houseTotalAce)) player[i].lose();
		else player[i].push();
	}
	deck.clear();
	house.clear();
	for (int i = 0; i < player.size(); ++i)
		player[i].clear();
}