/*
 * Copyright (C) 2009 Christopho, Zelda Solarus - http://www.zelda-solarus.com
 * 
 * Zelda: Mystery of Solarus DX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Zelda: Mystery of Solarus DX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ZSDX_GAMEOVER_SEQUENCE_H
#define ZSDX_GAMEOVER_SEQUENCE_H

#include "Common.h"
#include "Controls.h"

/**
 * The game over sequence displayed when the hero dies.
 */
class GameoverSequence {

 private:

  // data
  Game *game;       /**< the game */
  MusicId music_id; /**< the music played before game over */

  // graphics
  SDL_Surface *gameover_menu_img; /**< image of the game over menu */
  Sprite *hero_dead_sprite;       /**< sprite of the hero dying or dead (different from the real hero which is
				   * suspended as all map entities) */
  int hero_dead_x;                /**< x position of the hero dead sprite on the screen */
  int hero_dead_y;                /**< y position of the hero dead sprite on the screen */

  Sprite *fade_sprite;            /**< sprite of the fade in / fade out effect */
  Uint32 red_screen_color;        /**< exact color of the red screen */

  Sprite *fairy_sprite;           /**< sprite of the fairy (as rescuing fairy or cursor for the menu) */
  int fairy_x;                    /**< x position of the fairy on the screen */
  int fairy_y;                    /**< y position of the fairy on the screen */
  TargetMovement *fairy_movement; /**< movement of the fairy */

  int cursor_position;            /**< position of the cursor in the gameover menu (0 to 3) */

  // state
  enum State {
    WAITING_START,  /**< the game over sequence will start soon */
    CLOSING_GAME,   /**< fade out on the game screen */
    RED_SCREEN,     /**< red screen during a small delay */
    OPENING_MENU,   /**< fade in on the game over menu */
    SAVED_BY_FAIRY, /**< the player is being saved by a fairy */
    WAITING_END,    /**< the game will be resumed soon */
    RESUME_GAME,    /**< the game can be resumed */
    MENU,           /**< the player can choose an option in the game over menu */
   };

  State state;            /**< current state of the gameover sequence */
  Uint32 next_state_date; /**< date when moving from a state to another one */

 public:

  // creation and destruction
  GameoverSequence(Game *game, int hero_direction);
  ~GameoverSequence(void);

  // state
  bool is_finished(void);

  // update and display
  void update(void);
  void display(SDL_Surface *destination_surface);
  void key_pressed(Controls::GameKey key);
};

#endif
