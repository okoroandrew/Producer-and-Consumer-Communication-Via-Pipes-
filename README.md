# Producer-and-Consumer-Communication-Via-Pipes-
The aim of this project is to develop inter-process communication using both fork() and pipe() process system calls.

##### keywords
Pipe, fork, producer, consumer

### Project Description
The producer takes the input from the user file which are ASCII characters, converts
each character into binary, encodes each character (8 bits binary) with a parity bit,
and writes the output to a pipe. Each frame contains 2 syn characters, a control
character that contains the length of the data to be transmitted, and the data
transmitted.

The consumer on the other end reads the binary bits from the pipe, gets each frame
transmitted using the syn bits, removes the frame, and obtains the data bits. The data
bits are checked for parity to ensure that there was no error during transmission, the
parity bit is dropped, and the bits are converted back to ASCII converting all
characters to upper case. The ASCII is then saved in another file or printed on the
screen. In the absence of error, the original user data and the data from the consumer
would be the same except that the consumer output is in upper case.

### Implementation Details
The program has one main method that call the mainConsumer and mainProducer
methods. First a pipe is created, then the fork system call. The fork duplicates the
parent process, so we have two processes running.

The mainProducer is called in the child process and its return value is written to
the pipe in frames. On the other hand, the mainConsumer is called in the parent
process. It reads frames from the pipe and process them. 

The wait system call is used in the parent process to allow the child process to execute before the parent
process begins.The mainProducer method is a method that returns an array of characters (a string)
stored in the reference variable writeThis. writeThis is a reference to an array of
binary bits generated the the mainProducer. 

The mainProducer function calls other functions that contains subroutines for:
I. Reading user input files.
II. Converting the input for text to binary with each character represented in 8
bits binary.
III. Adding a parity bit to each character bit
IV. Framing every 64 characters (518 bits) by adding a 16 bits (for
synchronization) and 8 bits (for control)
V. Writing the frames to a binary output file.

The mainConsumer on the other hand is a void method. It receives binary input
from the pipe and calls other subroutines to process the bits. The subroutines that
perform functions like:
I. De-framing the bits by dropping the SYN and control bits.
II. Checking for parity in the data bits and removing the parity bits if no error
occurred during the transmission process.
III. Converting the data bits to ASCII characters
IV. Converting the characters to upper case and writing to an output file.
