#include "DataLinkLayerConsumer.h"
#include "ApplicationLayerConsumer.h"

void mainConsumer(char * binaryData, char * outputFilePath) {
    /** Iterate through the binary data string, extract each frame using the syn bit, deframe by dropping
     * the syn bits and control bits, break the data bits into 8, check for parity and replace the MSB with
     * '0' after which it would be ready for conversion to text*/
    char* frameString; char * ToTextConvert;
    int start = 0, end = 535, countBitsLeft = (int)strlen(binaryData);
    char *ToTextConverter = (char *) malloc(sizeof(char) * strlen(binaryData)); //This space is much

    for (int i = 0; i <= strlen(binaryData) / 536; i++){
        if (countBitsLeft >= 536) frameString = sliceStringC(binaryData, start, end);
        else frameString = sliceStringC(binaryData, start, start + countBitsLeft - 1);
        ToTextConvert = getDataString(deFraming(frameString));
        strcat(ToTextConverter, ToTextConvert);
        start += 536; end += 536; countBitsLeft -= 536;
    }
    BinaryToText(ToTextConverter, outputFilePath);
    free(ToTextConverter);
}




     /** Iterate through the binary data string, extract each frame using the syn bit, deframe by dropping
     * the syn bits and control bits, break the data bits into 8, check for parity and replace the MSB with
     * '0' after which it would be ready for conversion to text*/
/*char* frameString; char * ToTextConvert;
int start = 0, end = SIZE_OF_FRAME - 1, countBitsLeft = (int)strlen(binaryData);
char *ToTextConverter = (char *) malloc(sizeof(char) * strlen(binaryData)); //This space is much

for (int i = 0; i <= strlen(binaryData) / SIZE_OF_FRAME; i++){
if (countBitsLeft >= SIZE_OF_FRAME) frameString = sliceStringC(binaryData, start, end);
else frameString = sliceStringC(binaryData, start, start + countBitsLeft - 1);

//check for error with CRC
int flag = 0;
char * remainder = crcErrorDetection(frameString);
for (int r = 0; r < strlen(remainder); r++){
if (remainder[i] == '1'){
flag = 1;
break;
}
}
if (flag != 0) printf("Error in frame %d\n", i + 1);
else {
printf("No error in frame %d\n", i + 1);
ToTextConvert = getDataString(deFraming(sliceString(frameString, 0, 535)));
strcat(ToTextConverter, ToTextConvert);
start += SIZE_OF_FRAME; end += SIZE_OF_FRAME; countBitsLeft -= SIZE_OF_FRAME;
}
}



BinaryToText(ToTextConverter, outputFilePath); */