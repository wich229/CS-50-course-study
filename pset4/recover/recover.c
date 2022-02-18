#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check command-line arguments
    // as => $ ./recover card.raw
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    
    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    FILE *output_img = NULL;

    // Read 512 bytes into a buffer
    BYTE buffer [512];
    
    // counting images.
    int counter = 0;
    
    // allocated 8 multiply by size of char in order to save ###.jpg’\0′ in the filename.
    // char *filename = malloc(8 * sizeof(char));
    char filename [8];
    
    //Read first four bytes
    while (fread(&buffer, sizeof(BYTE), 512, input))
    {
    
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            
            sprintf(filename, "%03i.jpg", counter);
            output_img = fopen(filename, "w");
            counter ++;
        }
        if (output_img != NULL)
        {
            fwrite(&buffer, sizeof(BYTE), 512, output_img);
        }
        
    }
    
    fclose(input);
    fclose(output_img);
    return 0;
    
}