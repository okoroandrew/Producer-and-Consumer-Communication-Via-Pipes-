#ifndef Consumer_H
#define Consumer_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>

// function to read the input from the standard input
// and display the even integers
void mainConsumer(char * binaryData, char * outputFilePath);

#endif