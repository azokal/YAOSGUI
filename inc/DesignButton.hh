/* 
 * File:   IDesign.hh
 * Author: consta_m
 *
 * Created on February 9, 2012, 11:15 PM
 */

#ifndef DESIGNBUTTON_HH
#define	DESIGNBUTTON_HH

#include <SFML/Graphics.hpp>
#include <string>
#include "IDesign.hh"

namespace ygui
{
  class DesignButton : public IDesign
  {
  private:
    sf::Image		*_img;
    sf::Sprite		*_sprite;

  public:
    DesignButton(float, float);
    DesignButton(std::string &);
    DesignButton(ygui::DesignButton const&);
    virtual ~DesignButton();

  public:
    const ygui::DesignButton	&operator=(ygui::DesignButton const&);

  public:
    virtual sf::Sprite		*getSprite() const;
    virtual sf::Image		*getImg() const;
    void			setFond(sf::Image *);
    void			setFond(std::string const&);
  };
}
#endif	/* DESIGNBUTTON_HH */
