#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int openFile(int argc, char *argv[])
{
    int fileDescriptor;
    fileDescriptor = 0;
    fileDescriptor = open(argv[1],O_RDONLY);
    return fileDescriptor;
}

size_t sizeOfFile(const char * filePath)
{
    struct stat fileStat;
    stat(filePath, &fileStat);
    if(fileStat.st_size == 0)
    {
        return 0;
    }
    return fileStat.st_size;
}

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

int printLine(char * buffer, size_t bufferSize, int line)
{
    size_t i = 0;
    while(i < bufferSize)
    {
        write(STDOUT_FILENO, buffer, 1);
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("\n Usage: head <filename>\n");
        return 1;
    }
    else
    {
        size_t size = sizeOfFile(argv[1]);
        int fileDescriptor = openFile(argc, argv);
        char * buffer;
        buffer = (char *) malloc(size);
        int readStatus = readFile(fileDescriptor, buffer, size);
        printf("\n");
        printLine(buffer, size, 1);
        printf("\n");
        free(buffer);
        return 0;
    }
}

