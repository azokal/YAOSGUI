//
// Scene.hh for  in /home/consta_m/Projet/YAOSGUI
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Mon Jul 16 21:51:20 2012 maxime constantinian
// Last update Thu Jul 26 01:05:44 2012 maxime constantinian
//

#ifndef SCENE_HH__
# define SCENE_HH__

#include "IObject.hh"

namespace ygui
{
  class Scene
  {
    std::map<std::string, IObject *> _listObject;
  
  public:
    Scene();
    ~Scene();
    void addObject(std::string, IObject *);
    void delObject(std::string);
    IObject *getObject(std::string);
    void update(sf::RenderWindow &);
    void draw(sf::RenderWindow &);
  };
}

#endif
