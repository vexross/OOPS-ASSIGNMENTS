#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double marks;
};

char calculateGrade(double marks) {
    if (marks >= 90.0) return 'A';
    if (marks >= 75.0) return 'B';
    if (marks >= 60.0) return 'C';
    return 'F';
}

int main() {
    vector<Student> students = {
        {101, "Justin", 82.0},
        {102, "Emma", 94.5},
        {103, "Jennifer", 58.0},
        {104, "Sunny", 76.0},
        {105, "Victoria", 88.5}
    };

    transform(students.begin(), students.end(), students.begin(), [](Student s) {
        s.marks = min(100.0, s.marks + 2.5);
        return s;
    });

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    });

    cout << "Sorted Leaderboard (with Bonus Marks):\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << " | " << s.name << " : " << s.marks << "\n";
    }

    auto it = find_if(students.begin(), students.end(), [](const Student& s) {
        return s.marks < 65.0;
    });

    if (it != students.end()) {
        cout << "\nFirst student needing attention (<65): "
             << it->name << " (" << it->marks << ")\n";
    }

    unordered_map<int, double> idToMarks;
    map<char, vector<string>> gradeDistribution;

    for (const auto& s : students) {
        idToMarks[s.id] = s.marks;
        gradeDistribution[calculateGrade(s.marks)].push_back(s.name);
    }

    cout << "\nFast Lookup -> marks for ID 104: "
         << idToMarks[104] << "\n";

    cout << "Grade Distribution:\n";
    for (const auto& entry : gradeDistribution) {
        cout << "Grade " << entry.first << ": ";
        for (const auto& name : entry.second) {
            cout << name << " ";
        }
        cout << "\n";
    }

    return 0;
}
