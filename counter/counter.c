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

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include "counter.h"

long ccount;
long lcount;
long wcount;

int count(swc_data *data) {

	FILE *fp;
	ccount = lcount = 0;

	if (data->filePath == NULL) {
		fp = stdin;
	} else {
		fp = fopen(data->filePath, "r");

		if (fp == NULL) {
			if (errno == 2) {
				return COUNT_FILE_NOT_FOUND;
			} else {
				return COUNT_FILE_UNABLE_TO_OPEN;
			}
		}
	}

	read(fp);
	fclose(fp);

	data->charCount = ccount;
	data->lineCount = lcount;
	data->wordCount = wcount;
	return COUNT_OK;
}

void read(FILE *fp) {
	int c;
	char lastChar = ' ';
	while((c = getc(fp)) != EOF) {

		if ((lastChar == ' ' || lastChar == '\n') && isalpha(c)) {
			wcount++;
		}
		ccount++;

		if (c == '\n') {
			lcount++;
		}
		lastChar = c;
	}
}