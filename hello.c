// Hello World program
// Matthew Bourque
// COSC 519
// Homework 2

#include<stdio.h>
#include<windows.h>

main()
{
    printf("\nHello World\n");

    // Open a file
    FILE* test_file = fopen("test.dat", "r+");

    // Read the file
    int number;
    printf("\nReading file:\n");
    while ( fscanf(test_file, "%d", &number ) == 1 )  
             { 
               printf("%d\n", number); 
             } 

    // Write to the file
    printf("\nWriting to the file.\n");
    fprintf(test_file, "\nThis is another line");

    // Close the file
    printf("\nClosing the file.\n");
    fclose(test_file);
}