#ifndef SWC_DATA_H
#define SWC_DATA_H
#include <stdio.h>

typedef struct swc_data_ {
	int printChar;
	int printLines;
	int printWords;

	char *filePath;

	long charCount;
	long lineCount;
	long wordCount;
} swc_data;


#endif