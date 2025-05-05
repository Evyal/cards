#include <SFML/Graphics.hpp>
#include <iostream>

#include "card.hpp"
#include "constants.hpp"
#include "graphics.hpp"
#include "structs.hpp"

int main() {
  sf::RenderWindow window(
      sf::VideoMode(constants::windowWidth, constants::windowHeight),
      "Card Display");
  window.setPosition({constants::windowPosX, constants::windowPosY});

  Gui Gui{};
  Card HK{Rank::King, Suit::Hearts};
  Card HQ{Rank::Queen, Suit::Hearts};
  Card D3{Rank::Three, Suit::Diamonds};
  TguiPar par1{};
  par1.posX += -50;
  TguiPar par2{};
  par2.posX += 300;
  TguiPar par3{};
  par3.posX += 650;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear(sf::Color{0, 153, 0});

    Gui.displayCard(window, HK, par1);
    Gui.displayCard(window, HQ, par2);
    Gui.displayCard(window, D3, par3);

    window.display();
  }

  std::cout << Gui.getTexture(Rank::King, Suit::Hearts).getSize().x
            << '\n'; // 320
  std::cout << Gui.getTexture(Rank::King, Suit::Hearts).getSize().y
            << '\n'; // 448

  return 0;
}