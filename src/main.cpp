#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <Box2D/Box2D.h>
#include "physics/World.h"
#include "draw/glDraw.h"

int SCREEN_WIDTH = 1366;
int SCREEN_HEIGHT = 768;
const char* title = "Double Beat";

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << "error:" << SDL_GetError() << std::endl;
}

void setupOpenGL(int width, int height) {

    glShadeModel(GL_SMOOTH);

    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    // glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glClearColor(0, 0, 0, 0);

    glEnable(GL_TEXTURE_2D);
    // gluPerspective(60.0, ratio, 1.0, 1024.0);
}

void reloadProperties(World* world) {
    world->reInit();
}

void render(SDL_Window* win, World* world) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    int hp = 10;

    glLoadIdentity();
    glTranslatef(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);
    glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

    position heroPos = world->getHeroPosition();
    glDraw::drawSimpleTriangle(heroPos.x, heroPos.y, 1.0f, 0.0f, 1.0f, 1.6f);

    glDraw::drawHPbar(-(SCREEN_WIDTH / 2.f) + 50.0f, (SCREEN_HEIGHT / 2.f)- 50.0f, 1.0f, 0.0f, 0.0f, hp * 50.0f);

    glDraw::drawSprite(1.0f, 1.0f, (char*) "test.bmp");
    
    glDraw::drawText(1.0f, 1.0f, (char*) "Hello World");
    world->draw();
    
    SDL_GL_SwapWindow(win);
}

void update(World* world) {
    world->step();
}

bool input(World* world) {
    SDL_Event event;
    SDL_PumpEvents();
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_r:
                        PropertyUtil::initValues();
                        reloadProperties(world);
                        break;
                    case SDLK_s:
                        world->jump();
                        break;
                    case SDLK_a:
                        world->createAttackHitBox();
                        break;
                }
                break;
            case SDL_QUIT:
                return true;

        }
    }
    return false;
}

int setWorkspaceResolution() {
    RECT *rect = new RECT();

    if (SystemParametersInfo(SPI_GETWORKAREA, 0, rect, 0) != 0) {
        logSDLError(std::cout, "GetWorkArea");
        return 1;
    }

    SCREEN_WIDTH = rect->right;
    SCREEN_HEIGHT = rect->bottom;

    return 0;
}

void shutdown(World* world, SDL_Window* win, SDL_GLContext con) {
    world->shutdown();

    SDL_GL_DeleteContext(con);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int main(int argc, char** argv) {

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    PropertyUtil::initValues();
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) == -1) {
        logSDLError(std::cout, "SDL_init");
        return 1;
    }

    setWorkspaceResolution();

    SDL_Window *win = 0;
    SDL_GLContext con;

    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (win == 0) {
        logSDLError(std::cout, "CreateWindow");
        return 1;
    }


    con = SDL_GL_CreateContext(win);

    setupOpenGL(SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_GL_SetSwapInterval(1);


    bool done = false;
    World* world = new World();
    world->init();

    while (!done) {
        done = input(world);
        update(world);
        render(win, world);
    }
    
    shutdown(world, win, con);
    return 0;
}