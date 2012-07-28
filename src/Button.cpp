//
// Button.cpp for  in /home/consta_m/Projet/YAOSGUI/inc
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Tue Jun 12 10:46:20 2012 maxime constantinian
// Last update Fri Jul 27 16:20:57 2012 maxime constantinian
//

#include "Button.hh"

ygui::Button::Button(IDesign &d)
  : _design(d), _width(d.getSprite()->GetImage()->GetWidth()),
    _height(d.getSprite()->GetImage()->GetHeight()), _posXBut(0), _posYBut(0),
    _posXText(0), _posYText(0), _msg("")
{
}

ygui::Button::Button(IDesign &d, float width, float height, float posX, float posY)
  : _design(d), _width(width), _height(height), _posXBut(posX), _posYBut(posY),
    _posXText(0), _posYText(0), _msg("")
{
}

ygui::Button::Button(IDesign &d, float width, float height, float posX, float posY,
		      std::string msg, float posXText, float posYText)
  : _design(d), _width(width), _height(height), _posXBut(posX), _posYBut(posY),
    _posXText(posXText), _posYText(posYText), _msg(msg)
{
}

ygui::Button::~Button()
{
}

void		ygui::Button::setWidth(float width)
{
  _width = width;
}

void		ygui::Button::setHeight(float height)
{
  _height = height;
}

void		ygui::Button::setX(float x)
{
  _design.getSprite()->SetX(x);
  _msg.SetX(x + _posXText);
}

void		ygui::Button::setY(float y)
{
  _design.getSprite()->SetY(y);
  _msg.SetY(y + _posYText);
}

float		ygui::Button::getWidth()
{
  return  _width;
}

float		ygui::Button::getHeight()
{
  return _height;
}

float		ygui::Button::getX()
{
  return _design.getSprite()->GetPosition().x;
}

float		ygui::Button::getY()
{
  return _design.getSprite()->GetPosition().y;
}

void		ygui::Button::setTextSize(int size)
{
  _msg.SetSize(size);
}

void		ygui::Button::setTextColor(int r, int b, int g)
{
  _msg.SetColor(sf::Color(r, b, g));
}

void		ygui::Button::setTextColor(sf::Color c)
{
  _msg.SetColor(c);
}

void		ygui::Button::setTextRotation(float r)
{
  _msg.SetRotation(r);
}

void		ygui::Button::setTextFont(std::string path, int size)
{
  sf::Font font;

  if (!font.LoadFromFile(path, size))
    {
      std::cout << "Cannot load " << path << std::endl;
    }
  else
    {
      _msg.SetFont(font);
      _msg.SetSize(size);
    }
}

void		ygui::Button::setText(std::string msg)
{
  _msg.SetText(msg);
  _msg.SetX(_design.getSprite()->GetPosition().x + _posXText);
  _msg.SetY(_design.getSprite()->GetPosition().y + _posYText);
}

void		ygui::Button::setText(std::string msg, float x, float y)
{
  _msg.SetText(msg);
  _posXText = x;
  _posYText = y;
  _msg.SetX(_design.getSprite()->GetPosition().x + _posXText);
  _msg.SetY(_design.getSprite()->GetPosition().y + _posYText);
}

void		ygui::Button::setTextX(float x)
{
  _posXText = x;
  _msg.SetX(_design.getSprite()->GetPosition().x + _posXText);
}

void		ygui::Button::setTextY(float y)
{
  _posYText = y;
  _msg.SetY(_design.getSprite()->GetPosition().y + _posYText);
}

void	ygui::Button::onEvent(sf::RenderWindow &app)
{
  (void)app;
  std::cout << "CLICK on button pos x: " << _design.getSprite()->GetPosition().x << " y: " << _design.getSprite()->GetPosition().y << std::endl;
}

void	ygui::Button::draw(sf::RenderWindow &app)
{
  app.Draw(*(_design.getSprite()));
  app.Draw(_msg);
}
