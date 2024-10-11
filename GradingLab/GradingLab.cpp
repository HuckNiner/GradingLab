#include <iostream>
#include <vector>

using namespace std;

void enterGrade(vector<int>& grades);
void removeGrade(vector<int>& grades);
void showGrades(const vector<int>& grades);
void showFinalGrade(const vector<int>& grades);
void showFinalGradeDropLowest(const vector<int>& grades);

int main() {
    vector<int> grades;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter grade\n";
        cout << "2. Remove grade\n";
        cout << "3. Show grades\n";
        cout << "4. Show final grade\n";
        cout << "5. Show final grade, drop lowest\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enterGrade(grades);
            break;
        case 2:
            removeGrade(grades);
            break;
        case 3:
            showGrades(grades);
            break;
        case 4:
            showFinalGrade(grades);
            break;
        case 5:
            showFinalGradeDropLowest(grades);
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void enterGrade(vector<int>& grades) {
    int grade;
    cout << "Enter grade (0-100): ";
    cin >> grade;
    if (grade >= 0 && grade <= 100) {
        grades.push_back(grade);
        cout << "Grade entered successfully.\n";
    }
    else {
        cout << "Invalid grade. Please enter a number between 0 and 100.\n";
    }
}

void removeGrade(vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades to remove.\n";
        return;
    }

    int grade;
    cout << "Enter grade to remove: ";
    cin >> grade;

    for (auto it = grades.begin(); it != grades.end(); ++it) {
        if (*it == grade) {
            grades.erase(it);
            cout << "Grade removed successfully.\n";
            return;
        }
    }
    cout << "Grade not found.\n";
}

void showGrades(const vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades to display.\n";
        return;
    }

    cout << "Grades: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
}

void showFinalGrade(const vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades to calculate final grade.\n";
        return;
    }

    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    double average = static_cast<double>(sum) / grades.size();
    cout << "Final grade: " << average << endl;
}

void showFinalGradeDropLowest(const vector<int>& grades) {
    if (grades.size() <= 1) {
        cout << "Not enough grades to drop the lowest and calculate final grade.\n";
        return;
    }

    int sum = 0;
    int lowest = grades[0];

    for (int grade : grades) {
        sum += grade;
        if (grade < lowest) {
            lowest = grade;
        }
    }

    sum -= lowest;
    double average = static_cast<double>(sum) / (grades.size() - 1);
    cout << "Final grade (lowest dropped): " << average << endl;
}
