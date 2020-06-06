#include <stdio.h>
#include <cs50.h>

void pyramid(int Height);

int main (void) {

    int Height = 0;
    
    // Get a number between 1 to 8
    do {
        Height = get_int("Height: ");
    } 
    while (Height < 1 || Height > 8);
    
    // The function that print the pryamid
    pyramid(Height);
    
}

void pyramid(int Height) {
    
    // Print # from top to bottom
    for (int i = 1; i <= Height; i++) {
        
        // Print height - i spaces on the left
        for (int k = 0; k < Height - i ; k++){
            printf(" ");
        }
        
        // Print i blocks on the right
        for (int k = 0; k < i; k++){
            printf("#");
        }
        
        // Print the gaps in the middle
        printf("  ");
        
        // Print i blocks on the right
        for (int k = 0; k < i; k++){
            printf("#");
        }
        printf("\n");
        
    }
    
}