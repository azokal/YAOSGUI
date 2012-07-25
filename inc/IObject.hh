/* 
 * File:   IObject.hh
 * Author: consta_m
 *
 * Created on February 9, 2012, 11:07 PM
 */

#ifndef IOBJECT_HH
#define	IOBJECT_HH

#include <SFML/Graphics.hpp>

namespace ygui
{
  class IObject
  {
  public:
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual float getWidth() = 0;
    virtual float getHeight() = 0;
    virtual void draw(sf::RenderWindow &) = 0;
    virtual void onEvent(sf::RenderWindow &) = 0;
  };
}

#endif	/* IOBJECT_HH */

