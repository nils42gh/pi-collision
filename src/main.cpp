// Using SDL and standard IO
#include <SDL.h>
#include <iobject.h>
#include <stdio.h>

#include <ctime>
#include <iostream>

void main_loop(SDL_Renderer* gRenderer, IObject* redRect, IObject* blueRect) {
  static int prevTime = time(NULL);
  int currTime = time(NULL);
  // redRect->update_position(currTime - prevTime);
  // blueRect->update_position(currTime - prevTime);
  prevTime = currTime;
  redRect->print_rect(gRenderer);
  blueRect->print_rect(gRenderer);
  // render renderer
  SDL_RenderClear(gRenderer);
  SDL_RenderPresent(gRenderer);
}

int main(int argc, char* args[]) {
  SDL_Window* window = NULL;
  SDL_Renderer* gRenderer = NULL;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow("Pi collisions", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // init renderer with a grey background
  gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(gRenderer, 0x1F, 0x24, 0x2D, 0xFF);
  SDL_RenderFillRect(gRenderer, NULL);

  IObject* redRect =
      new IObject(SCREEN_WIDTH - RECT_WIDTH, 1, 0.0F, 0xF2, 0x0D, 0xB5, 0xFF);
  IObject* blueRect = new IObject(SCREEN_WIDTH / 2 - RECT_WIDTH / 2, 1, -100.0F,
                                  0x0A, 0xC7, 0xB7, 0xFF);

  // Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) quit = true;
      main_loop(gRenderer, redRect, blueRect);
    }
  }

  // Destroy window
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}