#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//openFile()
// Given a file path (from command line arguements), open a file and return a file descriptor
int openFile(char *argv[])
{
    int fileDescriptor = 0;
    fileDescriptor = open(argv[1],O_RDONLY);
    return fileDescriptor;
}

// sizeOfFile()
// Given a file path, determine the size of the file in bytes
size_t sizeOfFile(const char * filePath)
{
    struct stat fileStat;
    stat(filePath, &fileStat);
    return fileStat.st_size;
}

// readFile()
// Given a file descriptor of an open file, a pre-allocated character array and the size of the file, read the contents of the file into the character array
int readFile(int fileDescriptor, char * buffer, size_t bytesToRead)
{
    ssize_t bytesRead;
    bytesRead = read(fileDescriptor, buffer, bytesToRead);
    if(bytesRead == bytesToRead)
    {
        return 0;
    }
    return 1;
}

// findNextEndOfLine()
// Given a character array, size of the array and an initial offset to search from, return the next offset which is a line return character \r
int findNextEndOfLine(char * buffer, size_t bufferSize, int initialOffset)
{
    int i = initialOffset;
    while (i<bufferSize)
    {
        if(buffer[i] == '\n') {
            return i;
        }       
        i = i + 1; 
    }
    return bufferSize;
}

//printBufferHead()
// Given a character array, the size of the array and a line number, output the contents of the file line by line until you hit the line number targeted.
int printBufferHead(char * buffer, size_t bufferSize, int lastLine)
{
    int currentLine = 1;
    int lastEol = 0;
    int nextEol = 0;
    while(currentLine <= lastLine)
    {
        write(STDOUT_FILENO, "\n", 1);
        nextEol = findNextEndOfLine(buffer, bufferSize, lastEol);
        write(STDOUT_FILENO, buffer+lastEol, nextEol-lastEol);
        lastEol = nextEol + 1;
        currentLine = currentLine + 1;
    }
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        write(STDOUT_FILENO,"\nUsage: head <filename>\n\n",25);
        return 1;
    }
    else
    {
        size_t size = sizeOfFile(argv[1]);
        int fileDescriptor = openFile(argv);

        char * buffer;
        buffer = (char *) malloc(size);

        readFile(fileDescriptor, buffer, size);

        printBufferHead(buffer, size, 10);

        free(buffer);
        close(fileDescriptor);
        return 0;
    }
}

