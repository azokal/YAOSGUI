////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <SFML/Window.hpp>
#include "../inc/Scene.hh"
#include "../inc/Button.hh"
#include "../inc/DesignButton.hh"

class Cube
{
private:
  int dir;

public:
  Cube()
  {
    dir = 0;
  }
  virtual ~Cube(){}
  void setDir(int d)
  {
    this->dir = d;
  }
  void draw(sf::Clock &Clock)
  {	

	// Apply move direction
	if (dir == 0)
	  glRotatef(Clock.GetElapsedTime() * 90, 1.f, 0.f, 0.f);
	else if (dir == 1)
	  glRotatef(Clock.GetElapsedTime() * -90, 1.f, 0.f, 0.f);
	else if (dir == 2)
	  glRotatef(Clock.GetElapsedTime() * 90, 0.f, 1.f, 0.f);
	else if (dir == 3)
	  glRotatef(Clock.GetElapsedTime() * -90, 0.f, 1.f, 0.f);

        // Draw a cube
        glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f( 50.f,  50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-50.f, -50.f, 50.f);
	glVertex3f(-50.f,  50.f, 50.f);
	glVertex3f( 50.f,  50.f, 50.f);
	glVertex3f( 50.f, -50.f, 50.f);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f(-50.f,  50.f, -50.f);
	glVertex3f(-50.f,  50.f,  50.f);
	glVertex3f(-50.f, -50.f,  50.f);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(50.f, -50.f, -50.f);
	glVertex3f(50.f,  50.f, -50.f);
	glVertex3f(50.f,  50.f,  50.f);
	glVertex3f(50.f, -50.f,  50.f);
	
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-50.f, -50.f,  50.f);
	glVertex3f(-50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f, -50.f);
	glVertex3f( 50.f, -50.f,  50.f);
	
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-50.f, 50.f,  50.f);
	glVertex3f(-50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f, -50.f);
	glVertex3f( 50.f, 50.f,  50.f);
	
        glEnd();
  }
};

class CubeButton : public Cube, public ygui::Button
{
protected:
  Cube *c;

public:
  CubeButton(ygui::DesignButton &d, Cube *cube)
    : ygui::Button(d)
  {
    c = cube;
  }
  virtual ~CubeButton(){}
};

class CubeButtonUp : public CubeButton
{
public:
  CubeButtonUp(ygui::DesignButton &d, Cube *cube)
    : CubeButton(d, cube)
  {

  }

  void onEvent(sf::RenderWindow &app)
  {
    c->setDir(1);
  }
};

class CubeButtonDown : public CubeButton
{
public:
  CubeButtonDown(ygui::DesignButton &d, Cube *cube)
    : CubeButton(d, cube)
  {

  }

  void onEvent(sf::RenderWindow &app)
  {
    c->setDir(0);
  }
};

class CubeButtonLeft : public CubeButton
{
public:
  CubeButtonLeft(ygui::DesignButton &d, Cube *cube)
    : CubeButton(d, cube)
  {

  }

  void onEvent(sf::RenderWindow &app)
  {
    c->setDir(3);
  }
};

class CubeButtonRight : public CubeButton
{
public:
  CubeButtonRight(ygui::DesignButton &d, Cube *cube)
    : CubeButton(d, cube)
  {

  }

  void onEvent(sf::RenderWindow &app)
  {
    c->setDir(2);
  }
};

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

    // Create a clock for measuring time elapsed
    sf::Clock Clock;

    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 800.0f/600.0f, 1.f, 500.f);

    // set FPS limit to 60
    App.SetFramerateLimit(60);

    // Preserve OpenGl States
    App.PreserveOpenGLStates(true);

    Cube c;

    ygui::DesignButton d(200.0, 50.0);
    ygui::DesignButton d1(200.0, 50.0);
    ygui::DesignButton d2(50.0, 200.0);
    ygui::DesignButton d3(50.0, 200.0);

    CubeButtonUp	test(d, &c);
    CubeButtonDown	test1(d1, &c);
    CubeButtonLeft	test2(d2, &c);
    CubeButtonRight	test3(d3, &c);

    ygui::Scene	scene;

    test.setX(300.0);
    test.setY(50.0);
    test1.setX(300.0);
    test1.setY(500.0);
    test2.setX(50.0);
    test2.setY(200.0);
    test3.setX(700.0);
    test3.setY(200.0);
    scene.addObject("1", &test);
    scene.addObject("2", &test1);
    scene.addObject("3", &test2);
    scene.addObject("4", &test3);

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

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            // Resize event : adjust viewport
            if (Event.Type == sf::Event::Resized)
                glViewport(0, 0, Event.Size.Width, Event.Size.Height);
        }

        // Set the active window before using OpenGL commands
        // It's useless here because active window is always the same,
        // but don't forget it if you use multiple windows or controls
        App.Clear();
	App.SetActive();
       
        // Clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           
        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
	c.draw(Clock);

	scene.draw(App);

        // Finally, display rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
