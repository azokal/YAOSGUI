//
// Button.hh for  in /home/consta_m/Projet/GameDevLabLyon/ygui/inc
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Tue May 15 12:04:50 2012 maxime constantinian
// Last update Thu Jul 26 01:04:34 2012 maxime constantinian
//

#ifndef BUTTON_HH
#define BUTTON_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IObject.hh"
#include "DesignButton.hh"

namespace ygui
{
  class Button : public IObject
  {
  private:
    IDesign		&_design;
    float		_width;
    float		_height;
    float		_posXBut;
    float		_posYBut;
    float		_posXText;
    float		_posYText;
    sf::String		_msg;

  public:
    Button(IDesign &d);
    Button(IDesign &d, float width, float height, float posX, float posY);
    Button(IDesign &d, float width, float height, float posX, float posY,
	   std::string msg, float posXText, float posYText);
    virtual ~Button();
    float		getX();
    float		getY();
    float		getWidth();
    float		getHeight();
    void		setWidth(float);
    void		setHeight(float);
    void		setX(float);
    void		setY(float);
    void		setText(std::string msg);
    void		setText(std::string msg, float x, float y);
    void		setTextX(float);
    void		setTextY(float);
    virtual void	onEvent(sf::RenderWindow &);
    virtual void	draw(sf::RenderWindow &);
  };
}
#endif /* BUTTON_HH */
