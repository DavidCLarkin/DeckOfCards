#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include "stdafx.h"

using namespace std;

enum Suit { Hearts, Diamonds, Clubs, Spades };
enum Value { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

class Card
{
public:
	Card();
	~Card();
	Card(const Card &card); //copy constructor
	Card(const Suit& suit, const Value& value); //const value to point to the value of suit and value
	const Suit& getSuit();
	const Value& getValue();
	const Value& generateValue();
	const Suit& generateSuit();

private:
	friend ostream& operator <<(ostream &stream, Card &card);
	Suit m_suit;
	Value m_value;
};


#endif // !card.h