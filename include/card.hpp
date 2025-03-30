#ifndef CARD_HPP
#define CARD_HPP

enum class Suit { Hearts, Diamonds, Clubs, Spades };

enum class Rank {
  Two = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace,
  Joker
};

class Card {
 private:
  Rank rank_{};
  Suit suit_{};

 public:
  // Constructor
  Card(Rank rank, Suit suit) : rank_(rank), suit_(suit) {}

  // Constructor for Jokers
  Card() : rank_(Rank::Joker), suit_(Suit::Hearts) {}

  Rank getRank() const { return rank_; }
  Suit getSuit() const { return suit_; }
  bool isJoker() const { return rank_ == Rank::Joker; }
};

#endif