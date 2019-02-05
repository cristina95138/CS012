#include <iostream>
#include <algorithm>

using namespace std;

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    vector <char> suitName;
    
    suitName.push_back('s');
    suitName.push_back('h');
    suitName.push_back('d');
    suitName.push_back('c');
    
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 13; j > 0; --j) {
            theDeck.push_back(Card(suitName.at(i), j));
        }
    }
}

Card Deck::dealCard() {
    Card topCard = theDeck.at(theDeck.size() - 1);
    
    dealtCards.push_back(topCard);
    theDeck.pop_back();
    
    return topCard;
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}