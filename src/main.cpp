#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const char* title = "Double Beat";

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << "error:" << SDL_GetError() << std::endl;
}
int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS) == -1) {
        logSDLError(std::cout, "SDL_init");
        return 1;
    } 
    SDL_Window *win = 0;
    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(win==0) {
        logSDLError(std::cout, "CreateWindow");
        return 1;
    }
    SDL_Event event;
    bool done = false;
    
    while(!done) {
        SDL_PumpEvents();
        while(SDL_PollEvent(&event)) {
            switch(event.type)
            {
                case SDL_QUIT:
                    done = true;
                    break;
            }
        }
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

