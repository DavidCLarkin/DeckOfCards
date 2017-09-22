// DeckOfCards.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Card.h"
#include <random>
#include <ctime> 
#include "Deck.h";

using namespace std;

int menu();

int main()
{
	srand(time(0)+1); //seed random numbers

	Deck deck;
	Deck* const pDeck = &deck; //pointer to deck


	int input = menu(); // display menu and get input

	while (input != 0) //while input not 0 - (0 = exit)
	{
		switch (input)
		{
		case 1:
			pDeck->showDeck();	//print deck
			break;
		case 2:
			pDeck->shuffle();	//shuffle the deck		
			break;
		case 3:
			int amount;
			cout << "How many cards do you want to draw?" << endl;
			cin >> amount;
			for(int i = 0; i < amount; i++)
				pDeck->drawCard();	//draw cards(print certain amount)
			break;
		case 4:
			(&deck)->~Deck(); // delete the deck
			new (&deck) Deck(); //remake the deck
		default:
			cout << "Choose a valid number" << endl;
			break;
		}
		input = menu();		//loop 
	}
	return 0;
}

int menu()
{
	bool goodInput = false;
	int input = 0;
	do
	{
		try
		{
			cout << endl;
			cout << "|--------------------------------------------------------------------|" << endl;
			cout << "|  Welcome to the Deck Player					     |" << endl;
			cout << "|  Here, you can choose what option you want to do, seen below.      |"<< endl;
			cout <<"|  Simply input a number to choose your option.			     |" << endl;
			cout << "|--------------------------------------------------------------------|" << endl;
			cout << "|   1) Show the Deck						     |"<< endl;
			cout << "|   2) Shuffle the Deck			     			     |" << endl;
			cout << "|   3) Draw A Specified amount of cards				     |" << endl;
			cout << "|   4) Get a new deck				     |" << endl;
			cout << "|   0) Exit						             |" << endl;
			cout << "|--------------------------------------------------------------------|" << endl;
			cout << "Choose your option ==>" << endl;
			cin >> input;
			goodInput = true;
		}
		catch(exception e)
		{
			cout << "Enter a valid number from the choices above" << endl;
		}
	} while (!goodInput);

	return input;
}


