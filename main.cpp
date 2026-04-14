#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int marks;
};

vector<Student> students;

// ================= Utility =================
char calculateGrade(int mark) {
    if (mark >= 90) return 'A';
    else if (mark >= 75) return 'B';
    else if (mark >= 60) return 'C';
    else if (mark >= 40) return 'D';
    else return 'F';
}

// ================= File Handling =================
void saveToFile() {
    ofstream file("students.txt");

    for (auto &s : students) {
        file << s.name << "," << s.marks << endl;
    }

    file.close();
    cout << "Data saved to file.\n";
}

void loadFromFile() {
    ifstream file("students.txt");

    if (!file) return;

    students.clear();
    string line;

    while (getline(file, line)) {
        int comma = line.find(',');
        Student s;
        s.name = line.substr(0, comma);
        s.marks = stoi(line.substr(comma + 1));
        students.push_back(s);
    }

    file.close();
}

// ================= Core Features =================
void addStudent() {
    Student s;

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter marks: ";
    cin >> s.marks;

    if (s.marks < 0 || s.marks > 100) {
        cout << "Invalid marks!\n";
        return;
    }

    students.push_back(s);
    cout << "Added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No records.\n";
        return;
    }

    cout << "\n--- Students ---\n";
    for (auto &s : students) {
        cout << s.name << " | " << s.marks
             << " | Grade: " << calculateGrade(s.marks) << endl;
    }
}

void searchStudent() {
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);

    for (auto &s : students) {
        if (s.name == name) {
            cout << "Found: " << s.marks
                 << " Grade: " << calculateGrade(s.marks) << endl;
            return;
        }
    }

    cout << "Not found.\n";
}

void updateStudent() {
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);

    for (auto &s : students) {
        if (s.name == name) {
            cout << "Enter new marks: ";
            cin >> s.marks;
            cout << "Updated.\n";
            return;
        }
    }

    cout << "Not found.\n";
}

void deleteStudent() {
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            cout << "Deleted.\n";
            return;
        }
    }

    cout << "Not found.\n";
}

// ================= Sorting =================
void sortByMarks() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.marks > b.marks; // descending
    });

    cout << "Sorted by marks (highest first).\n";
}

// ================= Statistics =================
void showStatistics() {
    if (students.empty()) {
        cout << "No data.\n";
        return;
    }

    int sum = 0;
    int highest = students[0].marks;
    int lowest = students[0].marks;

    for (auto &s : students) {
        sum += s.marks;
        if (s.marks > highest) highest = s.marks;
        if (s.marks < lowest) lowest = s.marks;
    }

    double avg = (double)sum / students.size();

    cout << "\n--- Statistics ---\n";
    cout << "Average: " << avg << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
}

// ================= Export =================
void exportResults() {
    ofstream file("report.txt");

    for (auto &s : students) {
        file << s.name << " | "
             << s.marks << " | Grade: "
             << calculateGrade(s.marks) << endl;
    }

    file.close();
    cout << "Report exported to report.txt\n";
}

// ================= Menu =================
void menu() {
    cout << "\n===== Student System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search\n";
    cout << "4. Update\n";
    cout << "5. Delete\n";
    cout << "6. Sort by Marks\n";
    cout << "7. Statistics\n";
    cout << "8. Save to File\n";
    cout << "9. Export Report\n";
    cout << "10. Exit\n";
    cout << "Choice: ";
}

// ================= Main =================
int main() {
    loadFromFile(); // load existing data

    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortByMarks(); break;
            case 7: showStatistics(); break;
            case 8: saveToFile(); break;
            case 9: exportResults(); break;
            case 10: cout << "Exiting...\n"; break;
            default: cout << "Invalid.\n";
        }

    } while (choice != 10);

    return 0;
}
