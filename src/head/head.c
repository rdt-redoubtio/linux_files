#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fileDescriptor;
    fileDescriptor = 0;
    if(argc != 2)
    {
        printf("\n Usage: \n");
    }
    else
    {
        printf(argv[1]);
        fileDescriptor = open(argv[1],O_RDONLY);

        if(fileDescriptor == -1)
        {
            printf("\n Could not open file.\n");
        }
        else
        {
            printf("File Opened\n\n");
            char buffer[400];
            ssize_t bytes_read;
            int bytes_to_read;
            bytes_to_read = sizeof(buffer);
            bytes_read = read(fileDescriptor, buffer, bytes_to_read);
            printf(&buffer[0]);
        }
    }
}
