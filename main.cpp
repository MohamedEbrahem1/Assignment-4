#include "Deck.h"
#include <iostream>
using namespace std;
int main() {
  int NP = 4;
  string v = "23456789TJQKA";
  Deck cdeck;
  Deck Hand[NP];
  Deck::cardType c;
  Deck::cardType card[NP];
  int score[NP];
  int N;
  int p;
  int wp;
  int win;
  cdeck.Create_FreshDeck();
  cdeck.Shuffle_Deck();
  cdeck.Cut_Deck();
  cdeck.Display_Deck();
  N = 0;
  while (!cdeck.EmptyDeck()) // While there are still cards left
  {
    p = N % NP; // select player (0,1,2,3,0,1,2,3, etc)
    c = cdeck.RemoveCard();
    Hand[p].AddCard(c);
    N++; // next player
  }
  for (int i = 0; i < NP; i++) {
    score[i] = 0;
  }
  for (int i = 0; i < NP; i++) {
    Hand[i].Display_Deck();
  }
  // Game starts here __________________________________________________
  while (!Hand[0].EmptyDeck()) // while first player still has a card
  {
    // Start a round. Each player puts a card face down on table
    for (p = 0; p < NP; p++)
      card[p] = Hand[p].RemoveCard();
    // Cards are turned and winner player is defined (wp)
    Deck::cardType winning = card[0];
    wp = 0;
    for (int i = 1; i < NP; i++) {
      if (card[i].rank > winning.rank) {
        winning = card[i];
        wp = i;
      } else if (card[i].rank == winning.rank) {
        if (card[i].suit > winning.suit) {
          winning = card[i];
          wp = i;
        }
      }
    }

    // display cards on table and winner card
    for (int i = 0; i < NP; i++) {
      cout << i << " : " << card[i].rank << " , " << card[i].suit << endl;
    }
    cout << "The winner in this round is card: " << wp << " : " << winning.rank
         << " , " << winning.suit << endl;
    // Accumulate score for winning player
    score[wp]++;
    // Stop to view results for this round, then continue to next round.
    cout << "The result is: " << endl;
    for (int i = 0; i < NP; i++) {
      cout << i << " : " << score[i] << endl;
    }
  }
  // Game ends here __________________________________________________
 // Display Final scores 
  cout << "The Final result is: " << endl;
  for (int i = 0; i < NP; i++) {
    cout << i << " : " << score[i] << endl;
  }
  return 0;
}
// End of application program 