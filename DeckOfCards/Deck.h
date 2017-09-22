#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h";
#include <vector>;
#include <ostream>;

using namespace std;

class Deck
{
public:
	Deck();
	~Deck();
	const void showDeck();
	const void shuffle();
	void drawCard();
private:
	vector<Card*> m_decklist;
};
#endif // !DECK_H
