/**
 * SlashGaming Diablo II Free Resolution
 * Copyright (C) 2019-2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Free Resolution.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "patches.hpp"

#include <algorithm>

namespace sgd2fr::patches {
namespace {

static DrawPatches& GetDrawPatches() {
  static DrawPatches draw_patches;
  return draw_patches;
}

} // namespace

Patches::Patches() = default;

void Patches::Apply() {
  this->draw_patches_.Apply();
}

void Patches::Remove() {
  this->draw_patches_.Remove();
}

std::vector<mapi::GamePatch> MakeGamePatches() {
  std::vector<mapi::GamePatch> game_patches;

  std::vector required_patches = MakeRequiredPatches();
  game_patches.insert(
      game_patches.end(),
      std::make_move_iterator(required_patches.begin()),
      std::make_move_iterator(required_patches.end())
  );

  std::vector inventory_patches = MakeInventoryPatches();
  game_patches.insert(
      game_patches.end(),
      std::make_move_iterator(inventory_patches.begin()),
      std::make_move_iterator(inventory_patches.end())
  );

  std::vector interface_bar_patches = MakeInterfaceBarPatches();
  game_patches.insert(
      game_patches.end(),
      std::make_move_iterator(interface_bar_patches.begin()),
      std::make_move_iterator(interface_bar_patches.end())
  );

  return game_patches;
}

} // namespace sgd2fr::patches
