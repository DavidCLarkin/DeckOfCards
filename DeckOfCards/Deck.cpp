#include "Deck.h";
#include <iostream>;
#include <iterator>;
#include <algorithm>;

using namespace std;

//Constructor for the deck, adds 52 cards
Deck::Deck()
{
	for (unsigned int i = 0; i < Spades+1; i++)
	{
		for (unsigned int j = 1; j < King+1; j++) //Ace starts at 1
		{
			m_decklist.push_back(new Card(static_cast<Suit>(i) , static_cast<Value>(j))); //cast to enum values
		}
	}
}

//Print the deck, double asterisk because it's a pointer pointing to a pointer, also show the deck size
const void Deck::showDeck()
{
	for (vector<Card*>::const_iterator iter = m_decklist.begin(); iter != m_decklist.end(); ++iter)
	{
		cout << **iter << "\n";
	}
	cout << "Size of Deck: " <<  m_decklist.size() << endl;
}

//Drawing a card from the deck, simply choose a card from the top of the deck and pop it off
void Deck::drawCard()
{
	Card* cd = m_decklist.back();
	m_decklist.pop_back();
	cout << *cd << endl;
}

//Shuffle the deck using STLs random_shuffle method
const void Deck::shuffle()
{
	cout << "Shuffling deck..." << endl;
	if (m_decklist.size() <= 0) //if deck empty, return
		return;

	random_shuffle(m_decklist.begin(), m_decklist.end());
}

//Default destructor with cout for clarity
Deck::~Deck()
{
	cout << "Deck Destructor called" << endl;
}
