#include "TextureManager.h"

unordered_map<string, sf::Texture> Texture::TextureMap;

void Texture::loadTexture(string textureName) {
    string path = "images/" + textureName + ".png";
    TextureMap[textureName].loadFromFile(path);
}

sf::Texture &Texture::getTexture(string textureName) {
    if(TextureMap.find(textureName) == TextureMap.end())
        loadTexture(textureName);

    return TextureMap[textureName];
}

void Texture::Clear() {
    TextureMap.clear();
}