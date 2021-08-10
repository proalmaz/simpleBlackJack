#include "blackJack.h"

void shuffleDeck(std::array<Card_t, 52> &deck)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int shuffleCount = 0; shuffleCount < 52; ++shuffleCount)
		swapCard(deck[rand() % 52], deck[rand() % 52]);
}

bool whoWin(const int sumUser, const int sumDealer)
{
	if (sumUser > sumDealer)
	{
		cout << "Congratulations, you win!" << endl;
		return true;
	}
	if (sumUser < sumDealer)
	{
		cout << "It's sad, but you lose." << endl;
		return false;
	}
	if (sumUser == sumDealer)
	{
		cout << "It's a draw! No one win" << endl;
		return true;
	}
}

bool userLose(const int &sumUser)
{
	cout << "Sum of your cards = " << sumUser << " and it's more than 21. You"
												 " lose." << endl;
	return false;
}

bool dealerLose(const int &sumDealer)
{
	cout << "Sum of dealer's cards = " << sumDealer << " and it's more than 21."
	" You win!" << endl;
	return true;
}

int getCardValue(const Card_t &card)
{
	switch (card.value)
	{
		case VALUE_2: 						return 2;
		case VALUE_3: 						return 3;
		case VALUE_4: 						return 4;
		case VALUE_5: 						return 5;
		case VALUE_6: 						return 6;
		case VALUE_7: 						return 7;
		case VALUE_8: 						return 8;
		case VALUE_9: 						return 9;
		case VALUE_10:						return 10;
		case VALUE_JACKET:					return 10;
		case VALUE_QUENN: 					return 10;
		case VALUE_KING: 					return 10;
		case VALUE_ACE: 					return 11;
	}
	return 0;
}