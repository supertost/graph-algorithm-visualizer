#ifndef CURSORS_HPP
#define CURSORS_HPP

#include <SFML/Graphics.hpp>

struct Cursors
{
        sf::Cursor normalCursor;
        sf::Cursor handCursor;
        sf::Cursor moveCursor;

        Cursors()
        {
                normalCursor.loadFromSystem(sf::Cursor::Arrow);
                handCursor.loadFromSystem(sf::Cursor::Hand);
                moveCursor.loadFromSystem(sf::Cursor::SizeAll);
        }
};

#endif