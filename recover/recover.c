#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

bool is_jpeg_start(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *jpeg_file = NULL;
    int jpeg_count = 0;
    char jpeg_name[8];

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (is_jpeg_start(buffer))
        {
            if (jpeg_file != NULL)
            {
                fclose(jpeg_file);
            }

            sprintf(jpeg_name, "%03i.jpg", jpeg_count);
            jpeg_file = fopen(jpeg_name, "w");
            jpeg_count++;
        }

        if (jpeg_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg_file);
        }
    }

    if (jpeg_file != NULL)
    {
        fclose(jpeg_file);
    }

    fclose(raw_file);
    return 0;
}

bool is_jpeg_start(BYTE buffer[])
{
    return buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}