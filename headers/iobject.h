#ifndef IOBJECT_H
#define IOBJECT_H

#include <SDL.h>

#include <cmath>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 600
#define RECT_WIDTH 90
#define RECT_HEIGHT 90

class IObject {
 private:
  int m;
  float speed;
  SDL_Rect rect;
  int r;
  int g;
  int b;
  int a;

 public:
  float pos;
  IObject(float position, int masse, float speed, int r, int g, int b, int a);
  void update_position(int dt);
  void print_rect(SDL_Renderer *renderer);
};

#endif /* IOBJECT_H */
