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

#include "parser.h"
#include "counter.h"

int main(int argc, char **argv) {

	int status = 0;
	swc_data data;

	status = parse(argc - 1, ++argv, &data);
	if (status != 0)
	{
		if (status == PARSE_HELP_ARG)
		{
			printf("Usage: swc [OPTION]... [FILE]\n");
			printf("The number of lines, words and characters is counted and outputed in that order\ndepending on the optionsprovided. If no options provided all three are returned.\n");
			printf("The word counting is very basic and to complex text can't propperly be counted.\n\n");
			printf("With no FILE, or when FILE is -, standard input is read.\nTo finish inputing do a EOF with [Ctrl + D]\n\n");
			printf("The options below can be used to manipulate the output. Standard is all enabled.\n");
			printf(" -m, --chars\tprint the character count\n -l, --lines\tprint the newline counts\n -w, --words\tprint the word count\n -h, --help\tdisplay this help\n");
		}
		return status;
	}

	status = count(&data);
	if (status != 0)
	{
		if (status == COUNT_FILE_NOT_FOUND) {
			printf("File not found\n");
		} else if (status == COUNT_FILE_UNABLE_TO_OPEN) {
			printf("Could not open file\n");
		}
		return status;
	}

	if (data.printLines == 1)
	{	
		
		printf("%ld", data.lineCount);
	}

	if (data.printWords == 1)
	{
		if (data.printLines == 1)
		{
			printf(" ");
		}
		printf("%ld", data.wordCount);
	}

	if (data.printChar == 1)
	{
		if (data.printLines == 1 || data.printWords == 1)
		{
			printf(" ");
		}
		printf("%ld", data.charCount);
	}

	if (data.filePath != NULL)
	{
		printf(" %s", data.filePath);
	}
	printf("\n");

	return status;
}