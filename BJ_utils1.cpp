#include "blackJack.h"

void printCard(Card_t &card)
{
	switch (card.value)
	{
		case VALUE_2: cout << "2"; break;
		case VALUE_3: cout << "3"; break;
		case VALUE_4: cout << "4"; break;
		case VALUE_5: cout << "5"; break;
		case VALUE_6: cout << "6"; break;
		case VALUE_7: cout << "7"; break;
		case VALUE_8: cout << "8"; break;
		case VALUE_9: cout << "9"; break;
		case VALUE_10: cout << "10"; break;
		case VALUE_JACKET: cout << "J"; break;
		case VALUE_QUENN: cout << "Q"; break;
		case VALUE_KING: cout << "K"; break;
		case VALUE_ACE: cout << "A"; break;
		default:
			cout << "I don't know this type of card" << endl;
			break;
	}
	switch (card.suit)
	{
		case CLUB: cout << "C" << endl; break;
		case DIAMOND: cout << "D" << endl; break;
		case HEART: cout << "H" << endl; break;
		case SPADE: cout << "S" << endl; break;
		default:
			cout << "I don't know this suit of card" << endl;
	}
}

void printDeck(const std::array<Card_t, 52> &deck)
{
	int count = 0;
	for (auto card: deck)
	{
		cout << ' ';
		printCard(card);
		count++;
	}
	cout << '\n';
	cout << "Total cards in deck is " << count << endl;
}

void swapCard(Card_t &card1, Card_t &card2)
{
	Card_t tmp = card1;
	card1 = card2;
	card2 = tmp;
}

void initializeDeck(std::array<Card_t, 52> &deck)
{
	int card = 0;
	for (int suit = 0; suit < MAX_SUITS; ++suit)
	{
		for (int value = 0; value < MAX_VALUE; ++value)
		{
			deck[card].value = static_cast<cardValue>(value);
			deck[card].suit = static_cast<cardSuit>(suit);
			card++;
		}
	}
}
