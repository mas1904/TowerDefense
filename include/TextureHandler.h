#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
class TextureHandler
{
    public:
        /** Default constructor */
        TextureHandler();

        void loadTexture( std::string name, std::string path );

        const sf::Texture &getTexture( std::string name );

    protected:

    private:
        sf::Texture foo_texture;
        std::map<std::string, sf::Texture > textures;

};

#endif // TEXTUREHANDLER_H
