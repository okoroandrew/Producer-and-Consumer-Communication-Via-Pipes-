#ifndef Producer_H
#define Producer_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>

// function to write 0-19 values to the standard
// output
char * mainProducer(char * inputFilePath, char * binaryOutputFilePath);

#endif
