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

#include "Action.h"

namespace OpenXcom
{

/**
 * Creates a new action.
 * @param xScale Screen's X scaling factor.
 * @param yScale Screen's Y scaling factor.
 * @param ev Pointer to SDL_event.
 */
Action::Action(SDL_Event *ev, double xScale, double yScale) : _ev(ev), _xScale(xScale), _yScale(yScale), _sender(0)
{
}

Action::~Action()
{
}

/**
 * Returns the X scaling factor used by the screen
 * when this action was fired (used to correct mouse input).
 * @return Screen's X scaling factor.
 */
double Action::getXScale() const
{
	return _xScale;
}

/**
 * Returns the Y scaling factor used by the screen
 * when this action was fired (used to correct mouse input).
 * @return Screen's Y scaling factor.
 */
double Action::getYScale() const
{
	return _yScale;
}

/**
 * Returns the interactive surface that triggered
 * this action (the sender).
 * @return Pointer to interactive surface.
 */
InteractiveSurface *const Action::getSender() const
{
	return _sender;
}

/**
 * Changes the interactive surface that triggered
 * this action (the sender).
 * @param sender Pointer to interactive surface.
 */
void Action::setSender(InteractiveSurface *sender)
{
	_sender = sender;
}

/**
 * Returns the details about this action.
 * @return Pointer to SDL_event.
 */
SDL_Event *const Action::getDetails() const
{
	return _ev;
}

}
