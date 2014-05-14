#pragma once
#include"Game.h"

int main()
{
	try
	{
		int num;
		cout << "Welcome To Black Jack\n\n";
		cout << "==================================================\n\n";
		cout << "How many players? (1-9)\n";
		do{
			cin >> num;
			if (num<1 || num>9) cout << "Please re-enter number of players. (1-9)\n";
			else break;
		} while (true);
		cout << endl;

		Game game(num);
		game.play();

		cout << endl;
		system("pause");

		return 0;
	}
	catch (...)
	{
		cerr << "Unknown Exception! \n";
	}
}