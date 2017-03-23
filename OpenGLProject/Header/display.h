#ifndef  DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL\SDL.h>

class Display {
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	void Update();
	bool getIsClosed();
	void Clear(float r, float g, float b, float a);
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {} //Erstmal return void

	SDL_Window* window;
	SDL_GLContext glContext;
	bool isClosed;
};
#endif // ! DISPLAY_H

