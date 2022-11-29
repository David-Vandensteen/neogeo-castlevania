#include "neocore.h"
#include "scene_manager.h"
#include "scene_boot.h"
#include "scene_main_menu.h"
#include "scene_level_01.h"

static BYTE current_scene;

void scene_manager(BYTE scene) {
  current_scene = scene;
  switch (scene) {
    case SCENE_BOOT:
      if (!scene_boot()) scene_manager(SCENE_MAIN_MENU);
    break;
    case SCENE_MAIN_MENU:
      clear_vram();
      if (!scene_main_menu()) scene_manager(SCENE_LEVEL_01);
    break;
    case SCENE_LEVEL_01:
      clear_vram();
      scene_level_01();
    break;

    default:
      break;
  }
}
