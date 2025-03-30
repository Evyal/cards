#include <SFML/Graphics.hpp>
#include <vector>

#include "card.hpp"
#include "graphics.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Card Display");

  // Initialize the CardGraphics
  CardGraphics imageLoader;

  // Create a deck of sample cards
  std::vector<Card> deck = {
      Card(Rank::Ace, Suit::Spades), Card(Rank::Queen, Suit::Hearts),
      Card(Rank::Ten, Suit::Diamonds),
      Card(Rank::Joker, Suit::Hearts)  // Joker card
  };

  // Create the renderer
  CardRenderer renderer(imageLoader);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear(sf::Color::Green);  // Green background like a poker table

    // Render the cards
    renderer.render(window, deck);

    window.display();
  }

  return 0;
}