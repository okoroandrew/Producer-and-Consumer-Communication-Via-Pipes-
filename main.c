#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "MainProducer.h"
#include "MainConsumer.h"
#include "consumer.h"
#include "producer.h"
#define MAX_FRAME_SIZE 536

int main() {
    // Read the user file and store it in the string array. Then convert to Binary
    char inputFilePath[100];
    char outputFilePath[100];
    printf("Please enter input file directory: ");
    scanf("%s", inputFilePath);
    printf("Enter binary output file directory: ");
    scanf("%s", outputFilePath);

    // Reads a binary file from the producer and store in string variable binaryData
    char textOutputFilePath[100];
    printf("Enter ASCII output file directory: ");
    scanf("%s", textOutputFilePath);

    //Pipe
    int fd[2];
    if (pipe(fd) < 0){
        printf("pipe failed");
        exit(1);
    }

    //Fork to create Parent and Child process
    int id = fork();
    if (id < 0){
        printf("Fork failed");
        return 1;
    }

    //Child process
    else if (id == 0){
        close(fd[0]);
        char *binaryBits = mainProducer(inputFilePath, outputFilePath);
        int sizeOfBits = (int)strlen(binaryBits);
        int start = 0, end = MAX_FRAME_SIZE - 1;
        for (int i = 0; i <= sizeOfBits/ MAX_FRAME_SIZE; i++) {
            write(fd[1], sliceString(binaryBits, start, end), MAX_FRAME_SIZE);
            start += MAX_FRAME_SIZE; end += MAX_FRAME_SIZE;
        }
    }

    //Parent Process: it waits for the child process to execute first
    else{
        close(fd[1]);
        char bitsFromPipe[9000];
        read(fd[0], bitsFromPipe, 9000);
        mainConsumer(bitsFromPipe, textOutputFilePath);
        wait(NULL);
        close(fd[0]);
    }
    return 0;
}
