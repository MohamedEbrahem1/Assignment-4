#include <iostream>
#include "Deck.h"
using namespace std;

  // constructor
  Deck::Deck() { top = -1; }
  // destructor
  Deck::~Deck() {}
  // empty function, return true if deck is empty
  bool Deck::EmptyDeck() { return top == -1; }
  // add a card (c) to top of deck
  void Deck::AddCard(cardType &c) {
    top++;
    D[top] = c;
  }
  Deck::cardType Deck::RemoveCard() // Remove and return top card
  {
    cardType c = D[top];
    top--;
    return c;
  }
  // create a fresh deck function
  void Deck::Create_FreshDeck() {
    cardType c;
    string v = "23456789TJQKA";
    top = -1;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        c.suit = char(i + 3); // Card Suit: ASCII values of 3,4,5 or 6
        c.rank = v[j];        // Card rank
        AddCard(c);           // Add card to deck
      }
    }
  }


  // Shuffle Deck.
  // For i from 51 down to 1 generate a random integer k whose value is from 0
  // to i. Then swap cards (i) and (k).
  void Deck::Shuffle_Deck() {
    srand((unsigned)time(NULL)); // Initialize Random Number Generator
    for (int i = 51; i >= 1; i--) {
      int k = rand() % (i + 1); // Random integer from 0 to i
      swap(i, k);
    }
  }
  void Deck::Cut_Deck() // Cut Deck: Exchange upper half with lower half
  {
    for (int i = 0; i < 26; i++) {
      swap(i, i + 26);
    }
  }
  void Deck::Display_Deck() const // Display Deck
  {
    // check if the deck is empty or not
    if (top != -1) {
      for (int i = 0; i <= top; i++) {
        cout << "card: " << i << "-->"
             << " rank: " << D[i].rank << " suit: " << D[i].suit << endl;
      }
    }
  }
  // Swap cards (i) and (k)
  void Deck::swap(int i, int k) {
    cardType temp;
    temp = D[i];
    D[i] = D[k];
    D[k] = temp;
  }