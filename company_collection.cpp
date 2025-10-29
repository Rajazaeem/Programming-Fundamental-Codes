#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// Function to calculate average rating of each product
void calculateAverage(int ratings[10][5], float average_ratings[5])
{
    for (int j = 0; j < 5; ++j)
    { // iterate over each product
        int total_rating = 0;
        for (int i = 0; i < 10; ++i)
        { // iterate over each customer
            total_rating += ratings[i][j];
        }
        average_ratings[j] = total_rating / 10.0; // calculate the everage
    }
}

// Function to find the product with the highest average rating
int findHighestAverage(float average_ratings[5])
{
    float highest_avg = average_ratings[5];
    int highest_product_index = 0;
    for (int i = 1; i < 5; ++i)
    {
        if (average_ratings[i] > highest_avg)
        {
            highest_avg = average_ratings[i];
            highest_product_index = i;
        }
    }
    return highest_product_index;
}

// Function to write output in file
void writeToFile(float average_ratings[5], int highest_product_index, float highest_avg)
{
    ofstream outputFile("ratings_output.txt");
    if (!outputFile)
    {
        cout << "Error: Could not open file for writing." << endl;
        exit(1); // Exit the program if the file can't be opend
    }

    outputFile << "Average rating for each product:" << endl;
    cout << "Average rating for each product:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        outputFile << "product " << i + 1 << ": " << average_ratings[i] << endl;
        cout << "product " << i + 1 << ": " << average_ratings[i] << endl;
    }
    outputFile << "\nproduct " << (highest_product_index = 1)
               << "has the highest average rating of " << highest_avg << endl;
    cout << "\nproduct " << (highest_product_index = 1)
         << " has the highest average rating of " << highest_avg << endl;
    outputFile.close();
}

int main()
{
    // step b: Store the individual ratings in a 2D array (10 coustomer, 5 products)
    int ratings[10][5] = {
        {4, 5, 3, 4, 2}, // rating from customer 1
        {3, 2, 4, 3, 5}, // rating from customer 2
        {5, 4, 5, 4, 4}, // rating from customer 3
        {2, 3, 4, 5, 4}, // reting from customer 4
        {4, 4, 4, 5, 3}, // rating from cudtomer 5
        {3, 5, 4, 3, 2}, // rating from customer 6
        {5, 5, 5, 5, 5}, // rating from customer 7
        {4, 3, 4, 2, 4}, // rating from customer 8
        {3, 4, 5, 4, 3}, // rating from customer 9
        {4, 3, 4, 5, 4}, // rating from customer 10
    };

    // step a: Initialize a 1D array for the average rating of each product
    float average_ratings[5] = {0};

    // calculate average ratings
    calculateAverage(ratings, average_ratings);

    // Find the product with the highest average rating
    int highest_product_index = findHighestAverage(average_ratings);
    float highest_avg = average_ratings[highest_product_index];

    // write output to the file
    writeToFile(average_ratings, highest_product_index, highest_avg);
    cout << "output successfully written to (ratings_output.txt)" << endl;

    return 0;
}
