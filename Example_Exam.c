/**
 *
 * IMPORTANT:
 *
 * - You need to achieve at least 7 points to have a positive result on the programming task.
 *   Complete as many subtasks as you can.
 *
 * - Upload your program to Moodle!
 *
 * - Your submitted program MUST compile successfully without error messages,
 *   otherwise, you will receive 0 points for the ENTIRE programming task!
 *   (Warnings do not necessarily lead to point deductions.)
 *
 * - If your submitted program code is strikingly similar to another student's during the plagiarism check,
 *   both of you will receive 0 points!
 *
 * - The use of GitHub Copilot or similar AI-supported code generators during the programming task is not allowed.
 *
 * - The use of any messaging programs during the programming task is not allowed.
 *
 */

/* Program description:
 *   This program should
 *    + record Ikea items,
 *    + add items to the shopping cart,
 *    + calculate the sum of the items in the shopping cart, and
 *    + print a receipt (list of items with sum) to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <string.h>


#define LENGTH 4
/* Here: Definition of the Struct for an item [1 Point]
 * The following values should be stored:
 * - Name of the item (string)
 * - Price of the individual item (floating-point number)
 */
// Here: Declaration of the new type "Artikel" with typedef [1 Point]

typedef struct
{
    char name[50];
    double preis;
} Artikel;
/**
 * Implementation [5 Points]:
 * First read in the number of an item to be added to the shopping cart. [1 Point]
 * If no item with the entered number exists (i.e., less than 0 or greater or equal to the number of items),
 * an error message should be displayed and the function should be terminated. [3 Points]
 * If an item with the entered number exists, the number of items with the entered number in the "warenkorb" array should be incremented by 1. [1 Point]
 *
 * @param artikel Array with the items that can be added
 * @param warenkorb Array with the number of added items
 * @param anzahl Number of items that can be added (= length of the "artikel" array)
 */
void artikel_hinzufuegen(Artikel artikel[], int warenkorb[], int anzahl);

/**
 * Implementation [4 Points]:
 * First, create a variable "summe" with the value 0. [1 Point]
 * Use a loop to multiply the price of each item in the "artikel" array by the number of added items and add this to the sum. [2 Points]
 * Finally, return the sum. [1 Point]
 *
 * @param artikel Array with the items that can be added
 * @param warenkorb Array with the number of added items
 * @param anzahl Number of items that can be added (= length of the "artikel" array)
 */
double summe_berechnen(Artikel artikel[], int warenkorb[], int anzahl);

/**
 * Implementation [6 Points]:
 * For each item in the "artikel" array that has been added to the shopping cart at least once (check the number in the "warenkorb" array),
 * a line should be written to the console with
 *  + the name of the item,
 *  + the number of added items, and
 *  + the price of the item multiplied by the number of added items. Use printf(). [4 Points]
 * As the last line, a line with the sum of all prices of all items should be written to the console [1 Point]. Use the function summe_berechnen() [1 Point].
 *
 * @param artikel Array with the items that can be added
 * @param warenkorb Array with the number of added items
 * @param anzahl Number of items that can be added (= length of the "artikel" array)
 */
void quittung_ausgeben(Artikel artikel[], int warenkorb[], int anzahl);



double summe_berechnen(Artikel artikel[], int warenkorb[], int anzahl)
{
    // Here: Implementation    
    double summe = 0;
    for (int i = 0; i < anzahl; i++)
    {
        summe += artikel[i].preis * warenkorb[i];
    }
    return summe;
}
void artikel_hinzufuegen(Artikel artikel[], int warenkorb[], int anzahl)
{
    int item;
    // Here: Implementation
    printf("Which item do you wanna buy? ");
    scanf("%d", &item);
    if (item < 0 || item >= anzahl)
    {
        printf("Invalid item\n");
        return;
    }
    printf("warenkorb before ++: %d\n", warenkorb[item]);
    warenkorb[item]=warenkorb[item]+1;
    printf("Warenk: %d\n", warenkorb[item]);

}
void quittung_ausgeben(Artikel artikel[], int warenkorb[], int anzahl)
{
    // Here: Implementation
    double summe = summe_berechnen(artikel, warenkorb, anzahl);
    for (int i = 0; i < anzahl; i++)
    {
        if (warenkorb[i] > 0)
        {
            printf("Name: %s, Number: %d, Price: %.2f\n", artikel[i].name, warenkorb[i], artikel[i].preis * warenkorb[i]);
        }
    }
    printf("Summe: %.2f\n", summe);
}

/**
 * Main function of the program [11 Points].
 */


int main(void)
{
    // Here: Declaration of the "artikel" array of type Artikel (= Your Struct) [1 Point]
    // Instead of putting 4 directly in for the length, use a "#define" [1 Point]

    Artikel artikel[LENGTH];
    strcpy(artikel[0].name, "BILLY");
    artikel[0].preis = 24.99;
    strcpy(artikel[1].name, "KALLAX");
    artikel[1].preis = 39.99;
    strcpy(artikel[2].name, "LACK");
    artikel[2].preis = 5.99;
    strcpy(artikel[3].name, "MALM");
    artikel[3].preis = 129.00;

    // Here: Enter 3 more items here [1 Point]
    // KALLAX, 39.99€
    // LACK, 5.99€
    // MALM, 129.00€
printf("Enter an item with 'a'\n");
    // Here: Declaration of the "warenkorb" array of type int. It has the same length as the artikel array [1 Point]
int warenkorb[LENGTH];
float summe;
char choice;

/*do
    {
        printf("Available Items:\n");
        for (size_t i = 0; i < 4; i++)
        {
            printf("Name %s,Price: %.2f\n", artikel[i].name, artikel[i].preis);
            //printf("Name:%s, Price:%.2f\n", artikel[i].name, artikel[i].preis);
        }
        printf("////////////////////\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            artikel_hinzufuegen(artikel, warenkorb, LENGTH); // ist gleich artikel[0]?
            break;
        case 's':
            summe = summe_berechnen(artikel, warenkorb, LENGTH);
            printf("summe: %.2lf\n", summe);
            break;
        case 'q':
            quittung_ausgeben(artikel, warenkorb, LENGTH);
            break;
        case 'x':
            return 0;
        default:
            printf("error.");
            break;
        }
    } while (true);*/
do {
    printf("Aviable items: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("Name %s,Price: %.2f\n", artikel[i].name, artikel[i].preis);
    }
    printf("Enter your choice: ");

    scanf("%c", &choice);
    switch (choice)
    {
    case 'a':
        artikel_hinzufuegen(artikel, warenkorb, LENGTH);
        break;
    case 's':
        summe = summe_berechnen(artikel, warenkorb, LENGTH);
        printf("Summe: %2lf", summe);
        break;
    case 'q':
        quittung_ausgeben(artikel, warenkorb, LENGTH);
        break; 
    case 'x':
        return 0;
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
while (true);


    /*
     * Here: In a loop with switch/case, ask which of the 4 options should be executed.
     * In the loop, display the list of available items at the beginning each time [1 Point].
     *
     * 1. Add an item with 'a'
     * 2. Calculate the sum of the items in the shopping cart with 's'
     * 3. Print the receipt 'q'
     * 4. End the program 'x'
     *
     * If you select option 1 'a', you should call the function artikel_hinzufuegen() [1 Point].
     * If you select option 2 's', you should call the function summe_berechnen() [1 Point].
     *    In this case, the sum should be returned as the return value of the function and printed out in main() with printf [1 Point].
     * If you select option 3 'q', you should call the function quittung_ausgeben() [1 Point].
     *    In this case, the function should have no return value and print the receipt on the console [1 Point].
     * If you select option 4 'x', you should end the program. [1 Point]
     */
}