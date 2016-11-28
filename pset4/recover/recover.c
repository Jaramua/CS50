#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) //making sure that we are using our program properly;
{
    if (argc != 2)
    {
        fprintf (stderr, "Usage: ./recover\n"); 
        return 1;
    }
    
    FILE *raw_file = fopen(argv[1], "r"); // file, that need to be recovered (card);
    if (raw_file == NULL) //cheking if it is open; 
    {
        return 2;
    }
    
    char file_name[8]; //JPEG filename length: [1, 2, 3, 4, 5, 6, 7, \0]; 
    int counter = 0; //keeping track of the number of JPEG files; 
    unsigned char buffer[512]; //data from the card; 
    bool opened = false;//cheking if file is already opened;
    FILE* jpeg_file;//particular file 
    
    //the number of files that have been read successfully; 
    while (fread(buffer, 1, 512, raw_file) != 0)
    
    {       // cheking if file is JPEG           
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) 
        {
                
            if (opened){     //if file is already opened then we have to close it;
            fclose(jpeg_file);
            }
            
                                                            
            sprintf(file_name, "%03i.jpg", counter++ ); //time to open our file;  
            jpeg_file = fopen(file_name, "w");
            opened = true;
            fwrite(buffer, 1, 512, jpeg_file); //writing 512 bytes into our file;
        } 
        
        else //if bytes that we were ckeking at srting#30 didnt`t match a JPEG file, all in all we are going to write data in it;
        {
            if (opened)
            {
               fwrite(buffer, 1, 512, jpeg_file);
            }
        }
    }
    
    fclose(jpeg_file); //clising file
    fclose(raw_file); //closing card 
    return 0; //happy end.
}