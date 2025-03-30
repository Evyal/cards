#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "card.hpp"

class CardGraphics {
 public:
  // Constructor to load all card images
  CardGraphics();

  // Access the texture for a specific card
  sf::Texture& getTexture(Rank rank, Suit suit);

 private:
  std::map<std::pair<Rank, Suit>, sf::Texture> textures_;

  std::string getImagePath(Rank rank, Suit suit,
                           const std::string& resolution = "1x") const;

  sf::Texture loadImage(Rank rank, Suit suit,
                        const std::string& resolution) const;
  std::string rankToString(Rank rank) const;
  std::string suitToString(Suit suit) const;
};

class CardRenderer {
 private:
  CardGraphics& imageLoader_;  // Reference to the CardGraphics

 public:
  // Constructor
  CardRenderer(CardGraphics& imageLoader) : imageLoader_(imageLoader) {}

  // Render a list of cards
  void render(sf::RenderWindow& window, const std::vector<Card>& deck) {
    float x = 50;
    for (const auto& card : deck) {
      sf::Texture& texture =
          imageLoader_.getTexture(card.getRank(), card.getSuit());
      sf::Sprite sprite(texture);

      sprite.setPosition(x, 200);
      window.draw(sprite);

      x += 150;  // Space between cards
    }
  }
};
