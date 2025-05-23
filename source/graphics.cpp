#include "../include/graphics.hpp"

#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "constants.hpp"
#include "structs.hpp"

////////////////////////////////////////////////////////////////////////////////

Gui::Gui() {
  for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::Ace);
       ++r) {
    for (int s = static_cast<int>(Suit::Hearts);
         s <= static_cast<int>(Suit::Spades); ++s) {
      Rank rank = static_cast<Rank>(r);
      Suit suit = static_cast<Suit>(s);

      if (rank != Rank::Joker) {
        textures_[{rank, suit}] = loadImage(rank, suit, "1x");
      }
    }
  }
  // Load Joker images (if needed)
  textures_[{Rank::Joker, Suit::Hearts}] =
      loadImage(Rank::Joker, Suit::Hearts, "1x");
}

////////////////////////////////////////////////////////////////////////////////

sf::Texture& Gui::getTexture(Rank rank, Suit suit) {
  return textures_[{rank, suit}];
}

////////////////////////////////////////////////////////////////////////////////

std::string Gui::getImagePath(Rank rank, Suit suit,
                              const std::string& resolution) const {
  if (rank == Rank::Joker) {
    return "../images/face/joker@" + resolution + ".png";  // Joker path
  }

  if (rank == Rank::Ten) {
    return "../images/face/TC@" + resolution + ".png";
  }

  if (rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King ||
      rank == Rank::Ace) {
    // Handle face cards: J, Q, K, A
    std::string rankStr = rankToString(rank);
    std::string suitStr = suitToString(suit);
    return "../images/face/" + rankStr + suitStr + "@" + resolution + ".png";
  }

  // Handle normal numbered cards
  std::string rankStr = rankToString(rank);
  std::string suitStr = suitToString(suit);
  return "../images/face/" + rankStr + suitStr + "@" + resolution + ".png";
}
////////////////////////////////////////////////////////////////////////////////

sf::Texture Gui::loadImage(Rank rank, Suit suit,
                           const std::string& resolution) const {
  std::string imagePath = getImagePath(rank, suit, resolution);
  sf::Texture texture;
  if (!texture.loadFromFile(imagePath)) {
    std::cerr << "Error loading image: " << imagePath << std::endl;
  }
  return texture;
}

////////////////////////////////////////////////////////////////////////////////

std::string Gui::rankToString(Rank rank) const {
  switch (rank) {
    case Rank::Two:
      return "2";
    case Rank::Three:
      return "3";
    case Rank::Four:
      return "4";
    case Rank::Five:
      return "5";
    case Rank::Six:
      return "6";
    case Rank::Seven:
      return "7";
    case Rank::Eight:
      return "8";
    case Rank::Nine:
      return "9";
    case Rank::Ten:
      return "T";
    case Rank::Jack:
      return "J";
    case Rank::Queen:
      return "Q";
    case Rank::King:
      return "K";
    case Rank::Ace:
      return "A";
    case Rank::Joker:
      return "joker";
    default:
      return "Unknown";
  }
}

////////////////////////////////////////////////////////////////////////////////

std::string Gui::suitToString(Suit suit) const {
  switch (suit) {
    case Suit::Hearts:
      return "H";
    case Suit::Diamonds:
      return "D";
    case Suit::Clubs:
      return "C";
    case Suit::Spades:
      return "S";
    default:
      return "Unknown";
  }
}

////////////////////////////////////////////////////////////////////////////////

void Gui::displayCard(sf::RenderWindow& window, const Card& card,
                      const TguiPar& par) {
  sf::Sprite sprite;
  sf::Texture texture{getTexture(card.getRank(), card.getSuit())};
  sprite.setTexture(texture);
  sprite.setPosition(par.posX, par.posY);
  sprite.setScale(
      constants::cardWidth / static_cast<float>(texture.getSize().x),
      constants::cardHeight / static_cast<float>(texture.getSize().y));

  window.draw(sprite);
}