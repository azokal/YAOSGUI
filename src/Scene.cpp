//
// Scene.cpp for  in /home/consta_m/Projet/YAOSGUI
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Wed Jul 25 01:58:08 2012 maxime constantinian
// Last update Thu Jul 26 01:09:44 2012 maxime constantinian
//

#include <iostream>
#include "Scene.hh"

ygui::Scene::Scene()
{

}

ygui::Scene::~Scene()
{

}

void ygui::Scene::addObject(std::string index, IObject *object)
{
  this->_listObject[index] = object;
}

void ygui::Scene::delObject(std::string index)
{
  this->_listObject.erase(index);
}

ygui::IObject *ygui::Scene::getObject(std::string index)
{
  return this->_listObject[index];
}

void ygui::Scene::update(sf::RenderWindow &app)
{
  std::map<std::string, IObject *>::iterator it;
  const sf::Input& i = app.GetInput();
  static int flag = 0;
  bool tmp;

  tmp = i.IsMouseButtonDown(sf::Mouse::Left);
  if (tmp == true)
    {
      flag = 1;
    }
  else
    {
      if (flag == 1)
	for (it = this->_listObject.begin(); it != this->_listObject.end(); it++)
	  {
	    if (((*it).second->getX() <= i.GetMouseX()
		 && (*it).second->getX() + (*it).second->getWidth() >= i.GetMouseX())
		&& ((*it).second->getY() <= i.GetMouseY()
		    && (*it).second->getY() + (*it).second->getHeight() >= i.GetMouseY()))
	      {
		(*it).second->onEvent(app);
	      }
	  }
      flag = 0;
    }
}

void ygui::Scene::draw(sf::RenderWindow &app)
{
  std::map<std::string, IObject *>::iterator it;

  this->update(app);
  for (it = this->_listObject.begin(); it != this->_listObject.end(); it++)
    (*it).second->draw(app);
}
