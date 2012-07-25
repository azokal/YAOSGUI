/* 
 * File:   IDesign.hh
 * Author: consta_m
 *
 * Created on February 9, 2012, 11:15 PM
 */

#ifndef IDESIGN_HH
#define	IDESIGN_HH

#include <SFML/Graphics.hpp>

namespace ygui
{
  class IDesign
  {
  public:
    virtual ~IDesign(){}
    virtual sf::Sprite *getSprite() const = 0;
  };
}

#endif	/* IDESIGN_HH */

