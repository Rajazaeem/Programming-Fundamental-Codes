#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Function to calculate the total score of each student and find the highest score
void calculateTotalScores(int scores[30][5], int totalScore[30], int &highestScoreStudent, int &highestScore)
{
    for (int i = 0; i < 30; ++i)
    {
        totalScore[i] = 0;
        for (int j = 0; j < 5; ++j)
        {
            totalScore[i] += scores[i][j];
        }
        // Check of current student total score is the highest
        if (totalScore[i] > highestScore)
        {
            highestScore = totalScore[i];
            highestScoreStudent = i;
        }
    }
}

// Function to calculate the average score of each subject
void calculateSubjectAvearge(int scores[30][5], double subjectAverages[5])
{
    for (int j = 0; j < 5; j++)
    {
        subjectAverages[j] = 0;
        for (int i = 0; i < 30; ++i)
        {
            subjectAverages[j] += scores[i][j];
        }
        subjectAverages[j] /= 30.0; // calculate the average for each sebject
    }
}

// Function to print the results to both consoles and file
void printResults(int totalScores[30], int highestScoreStudent, int highestScore, double subjectAverages[5], ofstream &outputFile)
{
    cout << "Total scores of students:" << endl;
    outputFile << "Total scores of students:" << endl;
    for (int i = 0; i < 30; ++i)
    {
        cout << "student " << i + 1 << ": " << totalScores[i] << endl;
        outputFile << "student " << i + 1 << ": " << totalScores[i] << endl;
    }

    cout << "\nhighest Total Score: " << highestScore << "by Student " << highestScoreStudent + 1 << endl;
    outputFile << "\nhighest Total Score: " << highestScore << "by Student " << highestScoreStudent + 1 << endl;

    cout << "\nAverage scores for each subject:" << endl;
    outputFile << "\nAverage scores for each subject:" << endl;
    for (int j = 0; j < 5; ++j)
    {
        cout << "Subject " << j + 1 << ": " << subjectAverages[j] << endl;
        outputFile << "Subject " << j + 1 << ": " << subjectAverages[j] << endl;
    }
}

int main()
{
    // Initializing the scores for 30 students and 5 subjects
    int scores[30][5];
    int totalScores[30] = {0};
    int highestScoreStudent = -1;
    int highestScore = -1;
    double subjectAverages[5] = {0.0};

    // File handling
    ofstream outputFile("student_scores_analysis.txt");
    if (!outputFile)
    {
        cout << "Error: Could not open file forwriting." << endl;
        return 1;
    }
    // Taking input the scores of 30 studentsin 5 subjects
    cout << "Enter the scores of 30 students in 5 subjects (0-100):" << endl;
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            while (true)
            {
                cout << "Enter score of student" << i + 1 << ", subject " << j + 1 << ":";
                cin >> scores[i][j];

                // Error handling for invalid score input
                if (cin.fail() || scores[i][j] < 0 || scores[i][j] > 100)
                {
                    cin.clear();                                         // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Inavalid score! Please enter a score between 0 to 100." << endl;
                }
                else
                {
                    break; // Break if the output is valid
                }
            }
        }
    }

    // Calculate total scores for each student and find the highest score
    calculateTotalScores(scores, totalScores, highestScoreStudent, highestScore);

    // Calculate the average score for each subject
    calculateSubjectAvearge(scores, subjectAverages);

    // Print the result to the console and write them to the file
    printResults(totalScores, highestScoreStudent, highestScore, subjectAverages, outputFile);

    // Close the file
    outputFile.close();

    cout << "Result have bee written to (student_scores_analysis.txt)" << endl;

    return 0;
}