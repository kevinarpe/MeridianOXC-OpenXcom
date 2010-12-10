/*
 * Copyright 2010 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_RULESET_H
#define OPENXCOM_RULESET_H

#include <map>
#include <vector>
#include <string>
#include "../Savegame/SavedGame.h"
#include "../Savegame/SavedBattleGame.h"

namespace OpenXcom
{

class SoldierNamePool;
class RuleBaseFacility;
class RuleCraft;
class RuleCraftWeapon;
class RuleItem;
class RuleUfo;
class RuleTerrain;
class MapDataFile;
class ResourcePack;
class RuleUnitSprite;

/**
 * Set of rules and stats for a game.
 * A ruleset holds all the constant info that never changes
 * throughout a game, like stats of all the in-game items,
 * countries, research tree, soldier names, starting base, etc.
 */
class Ruleset
{
protected:
	std::vector<SoldierNamePool*> _names;
	std::map<std::string, RuleBaseFacility*> _facilities;
	std::map<std::string, RuleCraft*> _crafts;
	std::map<std::string, RuleCraftWeapon*> _craftWeapons;
	std::map<std::string, RuleItem*> _items;
	std::map<std::string, RuleUfo*> _ufos;
	std::map<std::string, RuleTerrain*> _terrains;
	std::map<std::string, MapDataFile*> _mapDataFiles;
	std::map<std::string, RuleUnitSprite*> _unitSprites;
public:
	/// Creates a blank ruleset.
	Ruleset();
	/// Cleans up the ruleset.
	virtual ~Ruleset();
	/// Generates the starting saved game.
	virtual SavedGame *newSave(GameDifficulty diff);
	/// Generates a battlescape saved game.
	virtual SavedBattleGame *newBattleSave(ResourcePack *res, SavedGame *save, int texture, Craft *craft, Ufo* ufo);
	/// Handles the end battle stuff.
	virtual void endBattle(SavedGame *save);
	/// Gets the pool list for soldier names.
	std::vector<SoldierNamePool*> *const getPools();
	/// Gets the ruleset for a facility type.
	RuleBaseFacility *const getBaseFacility(std::string id);
	/// Gets the ruleset for a craft type.
	RuleCraft *const getCraft(std::string id);
	/// Gets the ruleset for a craft weapon type.
	RuleCraftWeapon *const getCraftWeapon(std::string id);
	/// Gets the ruleset for an item type.
	RuleItem *const getItem(std::string id);
	/// Gets the ruleset for a UFO type.
	RuleUfo *const getUfo(std::string id);
	/// Gets terrains for battlescape games
	RuleTerrain *getTerrain(std::string name);
	/// Gets mapdatafile for battlescape games
	MapDataFile *getMapDataFile(std::string name);
	/// Gets unitsprite rules
	RuleUnitSprite *getUnitSprites(std::string name);
};

}

#endif
