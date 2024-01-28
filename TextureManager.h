#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#pragma once
using namespace std;
class Texture{
    static std::unordered_map<string, sf::Texture> TextureMap;
    static void loadTexture(string textureName);
public:
    static sf::Texture& getTexture(string textureName);
    static void Clear();
};
