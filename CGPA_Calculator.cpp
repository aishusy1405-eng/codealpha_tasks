#include <iostream>
using namespace std;

int main() {
    int n;
    float grade, credit;
    float totalCredits = 0, totalPoints = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nCourse " << i << endl;

        cout << "Enter grade: ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credit;

        totalPoints += grade * credit;
        totalCredits += credit;
    }

    float cgpa = totalPoints / totalCredits;

    cout << "\nTotal Credits = " << totalCredits;
    cout << "\nTotal Grade Points = " << totalPoints;
    cout << "\nFinal CGPA = " << cgpa << endl;

    return 0;
}