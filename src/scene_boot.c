#include "neocore.h"
#include "scene_boot.h"
#include "externs.h"

static GFX_Picture logo;

static void init();
static void display();
static BOOL update();

BOOL scene_boot_run() {
  init();
  display();
  return update();
}

static void init() {
  init_gpu();
  init_gp(&logo, &logo_asset, &logo_asset_Palettes);
}

static void display() {
  display_gp(&logo, 70, 100);
}

static BOOL update() {
  while(true) {
    wait_vbl();
    close_vbl();
    wait_vbl_max(500); // TODO
    return false;
  }
}