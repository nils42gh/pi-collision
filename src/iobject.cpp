#include "iobject.h"

IObject::IObject(float position, int mass, float ispeed, int _r, int _g, int _b,
                 int _a)
    : pos(position), m(mass), speed(ispeed), r(_r), g(_g), b(_b), a(_a) {}

void IObject::update_position(int dt) { this->pos = 20.0F; }

void IObject::print_rect(SDL_Renderer *renderer) {
  SDL_Rect rect2 = {(int)round(pos), SCREEN_HEIGHT - RECT_HEIGHT, RECT_WIDTH,
                    RECT_HEIGHT};
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderFillRect(renderer, &rect2);
}
