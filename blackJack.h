#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <array>
#include <thread>

using namespace std;

enum cardValue
{
	VALUE_2,
	VALUE_3,
	VALUE_4,
	VALUE_5,
	VALUE_6,
	VALUE_7,
	VALUE_8,
	VALUE_9,
	VALUE_10,
	VALUE_JACKET,
	VALUE_QUENN,
	VALUE_KING,
	VALUE_ACE,
	MAX_VALUE
};

enum cardSuit
{
	CLUB,
	DIAMOND,
	HEART,
	SPADE,
	MAX_SUITS
};

typedef struct	Card_s
{
	cardValue 	value;
	cardSuit 	suit;
}				Card_t;

void	printCard(Card_t &card);
void	swapCard(Card_t &card1, Card_t &card2);
void	printDeck(const std::array<Card_t, 52> &deck);
void	initializeDeck(std::array<Card_t, 52> &deck);
void	shuffleDeck(std::array<Card_t, 52> &deck);
int		getCardValue(const Card_t &card);
bool	whoWin(const int sumUser, const int sumDealer);
bool	userLose(const int &sumUser);
bool	dealerLose(const int &sumDealer);
