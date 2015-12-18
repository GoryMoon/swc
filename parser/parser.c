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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "swc_data.h"

int parse(int argc, char **args, swc_data *data) {
	
	int i;
	/* Default values */
	data->printChar 	= 0;
	data->printLines 	= 0;
	data->printWords 	= 0;

	if (argc == 0)
	{
		data->filePath = NULL;
	}

	for (i = 0; i < argc; ++i)
	{	
		if (strcmp("-h", args[i]) == 0 || strcmp("--help", args[i]) == 0) {
			return PARSE_HELP_ARG;
		}

		if (strcmp("-m", args[i]) == 0 || strcmp("--chars", args[i]) == 0) {
			data->printChar = 1;
		} else if (strcmp("-l", args[i]) == 0 || strcmp("--lines", args[i]) == 0) {
			data->printLines = 1;
		}  else if (strcmp("-w", args[i]) == 0 || strcmp("--words", args[i]) == 0) {
			data->printWords = 1;
		}
		if (i == argc - 1) {
			if (args[i][0] == '-') {
				data->filePath = NULL;
			} else {
				data->filePath = args[i];
			}
		}
	}

	if (data->printChar + data->printLines + data->printWords == 0)
	{
		data->printChar = data->printLines = data->printWords = 1;
	}

	return PARSE_OK;
}