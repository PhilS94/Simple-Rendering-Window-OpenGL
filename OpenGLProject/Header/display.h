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
	int getWidth() { return width; };
	int getHeigth() { return heigth; };
	void Clear(float r, float g, float b, float a);
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {} //Erstmal return void

	int width;
	int heigth;
	SDL_Window* window;
	SDL_GLContext glContext;
	bool isClosed;
};
#endif // ! DISPLAY_H

