//
// main.cpp for  in /home/consta_m/Projet/YAOSGUI/lib
// 
// Made by maxime constantinian
// Login   <consta_m@epitech.net>
// 
// Started on  Wed Jul 25 02:58:51 2012 maxime constantinian
// Last update Thu Jul 26 01:08:00 2012 maxime constantinian
//

#include "../inc/Scene.hh"
#include "../inc/Button.hh"
#include "../inc/DesignButton.hh"

int main()
{
  // Create the main rendering window
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");

  // Create button design
  ygui::DesignButton d(200.0, 50.0);
  ygui::DesignButton d1(200.0, 50.0);

  // Create Button with previous design
  ygui::Button	test(d);
  ygui::Button	test1(d1);

  // Create Scene
  ygui::Scene	scene;

  // Modify position Button
  test.setX(50.0);
  test.setY(50.0);
  test1.setX(50.0);
  test1.setY(200.0);

  // Add button to scene
  scene.addObject("1", &test);
  scene.addObject("2", &test1);

  // Start game loop
  while (App.IsOpened())
    {
      // Process events
      sf::Event Event;
      while (App.GetEvent(Event))
        {
	  // Close window : exit
	  if (Event.Type == sf::Event::Closed)
	    App.Close();
        }

      // Clear the screen (fill it with black color)
      App.Clear();

      // Draw scene
      scene.draw(App);
      
      // Display window contents on screen
      App.Display();
    }

  return EXIT_SUCCESS;
}
