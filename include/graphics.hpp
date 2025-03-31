#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string>

#include "card.hpp"
#include "structs.hpp"

class Gui {
 private:
  std::map<std::pair<Rank, Suit>, sf::Texture> textures_;

  std::string getImagePath(Rank rank, Suit suit,
                           const std::string& resolution = "1x") const;

  sf::Texture loadImage(Rank rank, Suit suit,
                        const std::string& resolution) const;
  std::string rankToString(Rank rank) const;
  std::string suitToString(Suit suit) const;

 public:
  Gui();

  sf::Texture& getTexture(Rank rank, Suit suit);

  void displayCard(sf::RenderWindow& window, const Card& card,
                   const TguiPar& par);
};
