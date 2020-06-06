#include <stdio.h>
#include <cs50.h>

void luhn (long number);

int main (void) {

    long number = get_long("Number: ");

    // The function that calculate luhn algorithum
    luhn(number);
}


void luhn (long number) {
    int result;
    int count = 0;
    int digits = 0;
    int underlinedigits = 0;
    int calc;
    int cardtype;
    bool amex;
    bool mastercard;
    bool visa;
    bool luhn;

    while (number != 0) {

        // start analysing the digits from the left
        // if count is even, don't multiply that digit by 2
        // if count is odd, multiply that digit by 2
        if (count%2 == 0){
            digits = number%10 + digits;
        //    printf("%d, ", digits);
        } else {
            calc =  (number%10)*2;
        //    printf("c%d, ", calc);
            if (calc < 10) {
                underlinedigits = calc + underlinedigits;
            } else {
                underlinedigits = calc/10 + calc%10 + underlinedigits;
            }
        //    printf("-%d, ", underlinedigits);
        }
        
        if (number == 34 || number == 37) {
            amex = true;
        } 
        else if (number == 51 || number == 52 || number == 53 || number == 54 || number == 55) {
            mastercard = true;
        } 
        else if (number == 4) {
            visa = true;
        }
        
        // remove the digit that is already analysed
        number = number/10;
        count++;

    }

    printf("%d\n", count);
    result = digits + underlinedigits;
    result = result%10;
    printf("%d\n", result);
    
    
    // checks all requirements
    if (result == 0) {
        
        if (count == 13 && visa == true) {
            printf("VISA\n");
        } else if (count == 15 && amex == true) {
            printf("AMEX\n");
        } else if (count == 16 && visa == true){
            printf("VISA\n");
        } else if (count == 16 && mastercard == true) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
        
        } else {
            printf("INVALID\n");
        }

}

