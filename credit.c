#include <stdio.h>
#include <stdbool.h>

bool isAmericanExpress(long long cardNumber) {
    int length = 0;
    long long temp = cardNumber;
    
    // Calculate the length of the card number
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    
    // Check if the card number is of valid length for American Express
    if (length != 15) {
        return false;
    }
    
    // Check the starting digits for American Express
    int firstDigit = cardNumber / 10000000000000;
    int secondDigit = (cardNumber / 1000000000000) % 10;
    
    if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7)) {
        return true;
    }
    
    return false;
}

bool isMastercard(long long cardNumber) {
    int length = 0;
    long long temp = cardNumber;
    
    // Calculate the length of the card number
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    
    // Check if the card number is of valid length for Mastercard
    if (length != 16) {
        return false;
    }
    
    // Check the starting digits for Mastercard
    int firstDigit = cardNumber / 1000000000000000;
    int secondDigit = (cardNumber / 100000000000000) % 10;
    
    if (firstDigit == 5 && (secondDigit >= 1 && secondDigit <= 5)) {
        return true;
    }
    
    return false;
}

bool isVisa(long long cardNumber) {
    int length = 0;
    long long temp = cardNumber;
    
    // Calculate the length of the card number
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    
    // Check if the card number is of valid length for Visa
    if (length != 13 && length != 16) {
        return false;
    }
    
    // Check the starting digit for Visa
    int firstDigit = cardNumber / 1000000000000000;
    
    if (firstDigit == 4) {
        return true;
    }
    
    return false;
}

int main() {
    long long cardNumber;
    
    printf("Enter a credit card number: ");
    scanf("%lld", &cardNumber);
    
    if (isAmericanExpress(cardNumber)) {
        printf("American Express\n");
    } else if (isMastercard(cardNumber)) {
        printf("Mastercard\n");
    } else if (isVisa(cardNumber)) {
        printf("Visa\n");
    } else {
        printf("Unknown card type\n");
    }
    
    return 0;
}
