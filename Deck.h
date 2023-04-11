#include <iostream>
using namespace std;
class Deck {
public:
  class cardType {
  public:
    char suit;
    char rank;
  };
  // constructor
  Deck();
  // destructor
  ~Deck();
  // empty function, return true if deck is empty
  bool EmptyDeck();
  // add a card (c) to top of deck
  void AddCard(cardType &c);
  // Remove and return top card
  cardType RemoveCard();
  // create a fresh deck function
  void Create_FreshDeck();
  // Shuffle Deck.
  void Shuffle_Deck();
  // Cut Deck: Exchange upper half with lower half
  void Cut_Deck();
  // Display Deck
  void Display_Deck() const;

private:
  int top;
  cardType D[52];
  // Swap cards (i) and (k)
  void swap(int i, int k);
};