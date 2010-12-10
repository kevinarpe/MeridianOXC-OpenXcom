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
#ifndef OPENXCOM_BATTLEUNIT_H
#define OPENXCOM_BATTLEUNIT_H

#include <vector>
#include "../Battlescape/Position.h"

namespace OpenXcom
{

class RuleUnitSprite;
class Tile;
class BattleItem;

enum UnitStatus {STATUS_STANDING, STATUS_SITTING, STATUS_WALKING, STATUS_TURNING, STATUS_FALLING, STATUS_DEAD};

/**
 * Represents a moving unit in the battlescape, player controlled or AI controlled
 * it holds info about it's position, items carrying, stats, etc
 */
class BattleUnit
{
private:
	RuleUnitSprite *_renderRules;
	int _id;
	Position _pos;
	Position _lastPos;
	int _direction, _toDirection;
	Position _destination;
	UnitStatus _status;
	int _walkPhase;
	std::vector<Tile *> _visibleTiles;
	std::vector<BattleItem *> _inventory;
public:
	/// Creates a BattleUnit.
	BattleUnit(RuleUnitSprite *renderRules);
	/// Cleans up the BattleUnit.
	virtual ~BattleUnit();
	/// Gets the BattleUnit's ID.
	int getId() const;
	/// Sets the BattleUnit's ID.
	void setId(int id);
	/// Gets the unit's rendering ruleset.
	RuleUnitSprite *const getRenderRules() const;
	/// Sets the unit's position X, Y, Z
	void setPosition(const Position& pos);
	/// Gets the unit's position.
	const Position& getPosition() const;
	/// Gets the unit's position.
	const Position& getLastPosition() const;
	/// Sets the unit's direction 0-7.
	void setDirection(int direction);
	/// Gets the unit's direction.
	int getDirection() const;
	/// Gets the unit's status.
	UnitStatus getStatus();
	/// Start the walkingPhase
	void startWalking(int direction, const Position &destination);
	/// Increase the walkingPhase
	void keepWalking();
	/// Gets the walking phase
	int getWalkingPhase();
	/// Gets the unit's destination when walking
	const Position &getDestination() const;
	/// Look at a certain point.
	void lookAt(const Position &point);
	/// Look at a certain direction.
	void lookAt(int direction);
	/// Turn to the destination direction.
	void turn();

};

}

#endif
