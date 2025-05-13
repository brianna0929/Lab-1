#include <iostream>
#include <iomanip>  // for setprecision

// Step 5: Function to calculate the average grade
double calculateAverage(int* grades, int count) {
    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += grades[i];
    }
    return static_cast<double>(total) / count;
}

// Step 6: Function to return letter grade
char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

int main() {
    int numStudents;

    // Step 1: Ask how many students
    std::cout << "Enter number of students: ";
    std::cin >> numStudents;

    // Step 2: Dynamically allocate array
    int* grades = new int[numStudents];

    // Step 3 & 4: Input grades and validate
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter grade for student " << (i + 1) << ": ";
        std::cin >> grades[i];

        while (grades[i] < 0 || grades[i] > 100) {
            std::cout << "Invalid input. Grade must be between 0 and 100. Try again: ";
            std::cin >> grades[i];
        }
    }

    std::cout << std::endl;

    // Step 7: Output each student's grade
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student " << (i + 1) << ": " << grades[i] << std::endl;
    }

    // Step 8: Output average and letter grade
    double avg = calculateAverage(grades, numStudents);
    char gradeLetter = getLetterGrade(avg);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nClass Average: " << avg << std::endl;
    std::cout << "Class Grade: " << gradeLetter << std::endl;

    // Step 9: Clean up memory
    delete[] grades;

    return 0;
}
