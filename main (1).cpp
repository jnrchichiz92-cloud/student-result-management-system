#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 100;
const double PASS_MARK = 50.0;

// Parallel arrays store each student's name and mark at the same index.
string studentNames[MAX_STUDENTS];
double studentMarks[MAX_STUDENTS];
int studentCount = 0;

int readInt(const string& prompt, int minimum, int maximum) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minimum && value <= maximum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Enter a number from " << minimum
             << " to " << maximum << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readMark() {
    double mark;
    while (true) {
        cout << "Enter mark (0-100): ";
        if (cin >> mark && mark >= 0.0 && mark <= 100.0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return mark;
        }
        cout << "Invalid mark. Enter a value between 0 and 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "The system is full. Maximum capacity is "
             << MAX_STUDENTS << " students.\n";
        return;
    }

    string name;
    do {
        cout << "Enter student's full name: ";
        getline(cin, name);
        if (name.empty()) cout << "Name cannot be empty.\n";
    } while (name.empty());

    double mark = readMark();

    // The same index links a student's name to their mark.
    studentNames[studentCount] = name;
    studentMarks[studentCount] = mark;
    ++studentCount;

    cout << "Student result added successfully.\n";
}

void displayResults() {
    if (studentCount == 0) {
        cout << "No student records have been entered yet.\n";
        return;
    }

    cout << "\n================ STUDENT RESULTS ================\n";
    cout << left << setw(6) << "No." << setw(30) << "Student Name"
         << setw(12) << "Mark" << "Status\n";
    cout << string(58, '-') << '\n';

    for (int i = 0; i < studentCount; ++i) {
        cout << left << setw(6) << i + 1
             << setw(30) << studentNames[i]
             << setw(12) << fixed << setprecision(2) << studentMarks[i]
             << (studentMarks[i] >= PASS_MARK ? "Pass" : "Fail") << '\n';
    }
}

void showSummary() {
    if (studentCount == 0) {
        cout << "Add student records before viewing the summary.\n";
        return;
    }

    double total = 0.0;
    double highest = studentMarks[0];
    double lowest = studentMarks[0];
    int highestIndex = 0;
    int lowestIndex = 0;
    int passes = 0;

    for (int i = 0; i < studentCount; ++i) {
        total += studentMarks[i];

        if (studentMarks[i] > highest) {
            highest = studentMarks[i];
            highestIndex = i;
        }
        if (studentMarks[i] < lowest) {
            lowest = studentMarks[i];
            lowestIndex = i;
        }
        if (studentMarks[i] >= PASS_MARK) {
            ++passes;
        }
    }

    cout << "\n================ CLASS SUMMARY =================\n";
    cout << "Number of students : " << studentCount << '\n';
    cout << "Total marks        : " << fixed << setprecision(2) << total << '\n';
    cout << "Class average      : " << total / studentCount << '\n';
    cout << "Highest mark       : " << highest << " (" << studentNames[highestIndex] << ")\n";
    cout << "Lowest mark        : " << lowest << " (" << studentNames[lowestIndex] << ")\n";
    cout << "Students passed    : " << passes << '\n';
    cout << "Students failed    : " << studentCount - passes << '\n';
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "No records to search.\n";
        return;
    }

    string target;
    cout << "Enter the student's full name to search: ";
    getline(cin, target);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (studentNames[i] == target) {
            cout << "\nRecord found\n";
            cout << "Name  : " << studentNames[i] << '\n';
            cout << "Mark  : " << fixed << setprecision(2) << studentMarks[i] << '\n';
            cout << "Status: " << (studentMarks[i] >= PASS_MARK ? "Pass" : "Fail") << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "No exact match found. Check the spelling and capitalization.\n";
    }
}

void showMenu() {
    cout << "\n===============================================\n";
    cout << "       STUDENT RESULT MANAGEMENT SYSTEM\n";
    cout << "===============================================\n";
    cout << "1. Add student result\n";
    cout << "2. Display all results\n";
    cout << "3. View class summary\n";
    cout << "4. Search for a student\n";
    cout << "5. Exit\n";
}

int main() {
    cout << "Welcome to the Student Result Management System.\n";
    cout << "Pass mark: " << PASS_MARK << " | Maximum students: "
         << MAX_STUDENTS << "\n";

    bool running = true;
    while (running) {
        showMenu();
        int choice = readInt("Choose an option (1-5): ", 1, 5);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                showSummary();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                running = false;
                cout << "Thank you for using the system. Goodbye!\n";
                break;
        }
    }

    return 0;
}
