#include "neocore.h"
#include "game_manager.h"
#include "scene_boot.h"
#include "scene_main_menu.h"

static BYTE current_scene;

void game_manager_run(BYTE scene) {
  current_scene = scene;
  switch (scene) {
  case SCENE_BOOT:
    if (!scene_boot_run()) {
      clear_vram();
    }
    break;
  case SCENE_MAIN_MENU:
    scene_main_menu_run();
    break;
  default:
    break;
  }
}
