// Include headers
#include <stdio.h>
#include <string.h>

// Length of the generator polynomial
char gen_poly[10]; // Declare generator polynomial globally
int N; // Declare N globally

// Data to be transmitted and received
char data[28];
// CRC value
char check_value[28];

// Variables
int data_length, i, j;

// Function that performs XOR operation
void XOR() {
    // If both bits are the same, the output is 0
    // If the bits are different, the output is 1
    for (j = 1; j < N; j++) {
        check_value[j] = ((check_value[j] == gen_poly[j]) ? '0' : '1');
    }
}

// Function to perform CRC
void crc() {
    // Initializing check_value
    for (i = 0; i < N; i++)
        check_value[i] = data[i];

    int index = 0; // Added index variable for data processing
    do {
        // Check if the first bit is 1 and call XOR function
        if (check_value[0] == '1')
            XOR();

        // Move the bits by 1 position for the next computation
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];

        // Appending a bit from data
        check_value[j] = data[index++];
    } while (index <= data_length + N - 1);
}

// Function to check for errors on the receiver side
void receiver() {
    // Get the received data
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\n-----------------------------\n");
    printf("Data received: %s", data);

    // Cyclic Redundancy Check
    crc();

    // Check if the remainder is zero to find the error
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++);

    if (i < N - 1)
        printf("\nError detected\n\n");
    else
        printf("\nNo error detected\n\n");
}

// Main function
int main() {
    // Get the data to be transmitted
    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);

    printf("\nEnter the Generating polynomial: ");
    // Get the generator polynomial
    scanf("%s", gen_poly);
    
    // Set the length of the generator polynomial
    N = strlen(gen_poly);

    // Find the length of data
    data_length = strlen(data);

    // Appending n-1 zeros to the data
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    data[i] = '\0'; // Null-terminate the string

    printf("\n----------------------------------------");
    // Print the data with padded zeros
    printf("\nData padded with n-1 zeros: %s", data);
    printf("\n----------------------------------------");

    // Cyclic Redundancy Check
    crc();

    // Print the computed check value
    printf("\nCRC or Check value is: %s", check_value);

    // Append data with check_value (CRC)
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];
    data[i] = '\0'; // Null-terminate the string

    printf("\n----------------------------------------");
    // Printing the final data to be sent
    printf("\nFinal data to be sent: %s", data);
    printf("\n----------------------------------------\n");

    // Calling the receiver function to check errors
    receiver();

    return 0;
}
