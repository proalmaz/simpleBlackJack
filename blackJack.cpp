#include "blackJack.h"

static int userMove(std::array<Card_t, 52> &deck,
					int &i, string userName, int &sumUser)
{
	string userDecision;
	do
	{
		cout << userName << " your move!" << endl;
		cout << "Sum of your cards = " << sumUser << endl;
		do
		{
			cout << "It's time to make decision. You can 'hit' or 'stand'. "
					"What do you want?" << endl;
			cin >> userDecision;
		} while (userDecision != "stand" && userDecision != "hit");
		if (userDecision == "hit")
			sumUser += getCardValue(deck[i++]);
	} while (userDecision != "stand");
	return sumUser;
}

static int dealerMove(std::array<Card_t, 52> &deck, int i, int sumDealer)
{

	while (sumDealer < 17)
	{
		cout << "Dealer has " << sumDealer << " points and he take one more "
											  "card!"	<< endl;
		sumDealer += getCardValue(deck[i++]);
		sleep(1);
	}
	return sumDealer;
}

bool playBlackJack(std::array<Card_t, 52> &deck)
{
	int 	sumUser = 0, sumDealer = 0;
	int 	i = 0; // iterator for cards;
	string 	userName;

	cout << "Please enter your name: ";
	cin >> userName;
	while (true)
	{
		sumDealer += getCardValue(deck[i++]);
		sumUser = getCardValue(deck[i++]) + getCardValue(deck[i++]);
		sumUser = userMove(deck, i, userName, sumUser);
		if (sumUser > 21)
			return userLose(sumUser);
		sumDealer = dealerMove(deck, i, sumDealer);
		if (sumDealer > 21)
			return dealerLose(sumDealer);
		if (sumDealer == sumUser)
		{
			cout << "Your and dealer's points = " << sumUser << ". It's a "
			"draw. No one win!";
			return true;
		}
		cout << "Sum of your cards = " << sumUser << "\nSum of dealer's cards"
													 " = " << sumDealer << endl;
		return	whoWin(sumUser, sumDealer);
	}
}

static bool playAgain(std::array<Card_t, 52> &deck)
{
	char	decision;
	do
	{
		cout << " Do you wanna play again? y/n" << endl;
		cin >> decision;
	} while (decision != 'y' && decision != 'n');
	if (decision == 'y')
	{
		shuffleDeck(deck);
		playBlackJack(deck);
		return true;
	}
	else
	{
		cout << "Bye bye!" << endl;
		return false;
	}
}

int main()
{
	std::array<Card_t, 52> deck;

	initializeDeck(deck);
	shuffleDeck(deck);
	playBlackJack(deck);
	while (playAgain(deck))
	{}
	return (0);
}