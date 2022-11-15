#include "neocore.h"
#include "externs.h"

static GFX_Picture background;

static void init();
static void display();
static BOOL update();

BOOL scene_main_menu_run() {
  init();
  display();
  return update();
}

static void init() {
  init_gpu();
  init_gp(&background, &menu_background_asset, &menu_background_asset_Palettes);
}

static void display() {
  display_gp(&background, 0, 0);
}

static BOOL update() {
  while (true) {
    wait_vbl();
    init_log();
    set_pos_log(20, 20);
    (get_frame_counter() % 100 >= 0 && get_frame_counter() %100 < 40 ) ? log_info("PRESS START"): log_info("");
    close_vbl();
  }
}
