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
#include "RNG.h"
#include <cstdlib>
#include <ctime>

namespace OpenXcom
{

int RNG::_seed = 0;

/**
 * Seeds the random generator with a new number.
 * Defaults to the current time if none is set.
 * @param seed New seed.
 */
void RNG::init(int seed)
{
	if (seed == -1)
	{
		_seed = (int)time(NULL);
	}
	else
	{
		_seed = seed;
	}
	srand(_seed);
}

/**
 * Returns the last seed used by the generator.
 * @return Generator seed.
 */
int RNG::getSeed()
{
	return _seed;
}

/**
 * Generates a random integer number within a certain range.
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Generated number.
 */
int RNG::generate(int min, int max)
{
	_seed = rand();
	return (_seed % (max - min + 1) + min);
}

/**
 * Generates a random decimal number within a certain range.
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Generated number.
 */
double RNG::generate(double min, double max)
{
	_seed = rand();
	return (_seed * (max - min) / RAND_MAX + min);
}

}
