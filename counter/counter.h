/*
 *  swc is a basic newline, word and character counter
 *  Copyright (C) 2015  Gustaf Järgren
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef COUNTER_H
#define COUNTER_H
#include <stdlib.h>
#include "swc_data.h"

#define COUNT_OK		 			0
#define COUNT_FILE_NOT_FOUND 		2
#define COUNT_FILE_UNABLE_TO_OPEN 	3


int count(swc_data *data);
void read(FILE *fp);

#endif