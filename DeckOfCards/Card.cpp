#include "Card.h"
#include <iostream>
#include "stdafx.h"

using namespace std;

//card constructor for a random card (not needed for this, but could be useful)
Card::Card()
{
	m_suit = generateSuit();
	m_value = generateValue();
}

//constant reference to the values of suit/value
Card::Card(const Suit &suit, const Value &value) : m_suit(suit), m_value(value)
{
}

//generate random value between 0 and King
const Value& Card::generateValue()
{
	Value valueRand = static_cast<Value>(rand() % King);
	return valueRand;
}

//generate random value between 0 and Spades
const Suit& Card::generateSuit()
{
	Suit suitRand = static_cast<Suit>(rand() % Spades);	
	return suitRand;
}

//getter for suits
const Suit& Card::getSuit()
{
	return m_suit;
}

//getter for values
const Value& Card::getValue()
{
	return m_value;
}

//Operator overload so I can print the values of the card object
ostream& operator <<(ostream &stream, Card &card)
{
	return stream << "Card(" << "Suit " << *(&card.m_suit) << ", " << "Value " << *(&card.m_value) << ")"; //dereferencing so it shows values, not addresses
}

//destructor for card
Card::~Card()
{
}

//copy constructor
Card::Card(const Card& card)
{
	m_value = card.m_value;
	m_suit = card.m_suit;
}