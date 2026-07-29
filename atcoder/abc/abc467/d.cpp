#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto px = input<lint>() * 2;
  auto py = input<lint>() * 2;
  auto qx = input<lint>() * 2;
  auto qy = input<lint>() * 2;
  auto rx = input<lint>() * 2;
  auto ry = input<lint>() * 2;
  auto sx = input<lint>() * 2;
  auto sy = input<lint>() * 2;

  lint vx = qx - px, vy = qy - py;
  lint wx = sx - rx, wy = sy - ry;
  if (vx * wy - vy * wx != 0) {
    yes();
    return;
  }

  lint ax = (px + qx) / 2, ay = (py + qy) / 2;
  lint bx = (rx + sx) / 2, by = (ry + sy) / 2;
  lint ux = bx - ax, uy = by - ay;
  yesno(vx * ux + vy * uy == 0);
}
