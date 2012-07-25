//
// DesignButton.cpp for  in /home/consta_m/Projet/GameDevLabLyon/ygui/inc
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Tue Mar  6 19:56:51 2012 maxime constantinian
// Last update Thu Jul 26 01:06:05 2012 maxime constantinian
//

#include "DesignButton.hh"

ygui::DesignButton::DesignButton(float x, float y)
  : _img(new sf::Image), _sprite(new sf::Sprite)
{
  this->_img->Create(x, y, sf::Color(0, 255, 0));
  this->_sprite->SetImage(*(this->_img));
}

ygui::DesignButton::DesignButton(std::string &str)
    : _img(new sf::Image), _sprite(new sf::Sprite)
{
  this->_img->LoadFromFile(str);
  this->_sprite->SetImage(*(this->_img));
}

ygui::DesignButton::DesignButton(ygui::DesignButton const &design)
    : _img(new sf::Image), _sprite(new sf::Sprite)
{
  this->_img = design._img;
  this->_sprite->SetImage(*(this->_img));
}

ygui::DesignButton::~DesignButton()
{
  delete this->_img;
  delete this->_sprite;
}

const ygui::DesignButton &ygui::DesignButton::operator=(ygui::DesignButton const &design)
{
  this->_img = design._img;
  this->_sprite->SetImage(*(this->_img));
  return (*this);
}

sf::Sprite *ygui::DesignButton::getSprite() const
{
  return this->_sprite;
}

sf::Image *ygui::DesignButton::getImg() const
{
  return this->_img;
}

void	ygui::DesignButton::setFond(sf::Image *img)
{
  this->_img = img;
  this->_sprite->SetImage(*(this->_img));
}

void	ygui::DesignButton::setFond(std::string const &path)
{
  this->_img->LoadFromFile(path);
  this->_sprite->SetImage(*(this->_img));
}
