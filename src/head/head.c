#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("\n Usage: \n");
        return 1;
    }
    else
    {
        int fileDescriptor = openFile(argc, argv);
        char buffer[400];
        int readStatus = readFile(fileDescriptor, buffer);
        printf("\n");
        printf(buffer);
        printf("\n");
        return 0;
    }
    
}

int openFile(int argc, char *argv[])
{
    int fileDescriptor;
    fileDescriptor = 0;
    
    fileDescriptor = open(argv[1],O_RDONLY);

    if(fileDescriptor == -1)
    {
        return fileDescriptor;
    }
    else
    {
        return fileDescriptor;
    }
}

int readFile(int fileDescriptor, char *buffer[])
{
    ssize_t bytesRead;
    int bytesToRead = sizeof(buffer);
    bytesRead = read(fileDescriptor, buffer, bytesToRead);
    // TODO: Error handling
    return 0;
}