#include "TextureHandler.h"

TextureHandler::TextureHandler()
{
    foo_texture.loadFromFile("foo.bmp");
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void TextureHandler::loadTexture(std::string name, std::string path)
{
    sf::Texture txt;
    if (!txt.loadFromFile(path))
        std::cout << "ta";
    std::cout << txt.getSize().x  << std::endl;
    textures.insert( std::pair< std::string, sf::Texture >(name, txt) );

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
const sf::Texture& TextureHandler::getTexture(std::string name)
{
    auto it = textures.find( name );
    if( it == textures.end() )
        return foo_texture;
    return it->second;

}

