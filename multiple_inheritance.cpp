#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    string roll_number;
}; // <- Fixed missing semicolon

class branch {
public:
    string branch;
};

class coursesInfo {
public:
    vector<pair<string, string>> courses; // {course_code, status}
    map<string, string> grades;
};

class academicInfo : public student, public branch, public coursesInfo {
public:
    academicInfo(string name, string roll_number) {
        this->name = name;
        this->roll_number = roll_number;
    }

    void addCourse(string course_code, string status) {
        courses.push_back({course_code, status});
    }

    void grading(string course_code, string grade) {
        bool course_found = false;

        // Must loop by reference to modify status
        for (auto &it : courses) {
            if (it.first == course_code) {
                it.second = "completed";
                course_found = true;
                break;
            }
        }

        if (!course_found) {
            cout << "Enrollment is missing. Kindly contact the examination department or course instructor for further clarification.\n";
            return;
        }

        grades[course_code] = grade;
    }

    void displayCourseInfo(string course_code) {
        if (grades.find(course_code) == grades.end()) {
            cout << "Course not found or grade not yet submitted.\n";
            return;
        }

        for (auto &it : courses) {
            if (it.first == course_code) {
                if (it.second != "completed") {
                    cout << "Course in progress\n";
                    return;
                } else {
                    cout << "Grade: " << grades[course_code] << "\n";
                    return;
                }
            }
        }

        cout << "Course not found in enrolled list.\n";
    }
};

int main() {
    academicInfo s1("Ayush", "22084033");
    s1.addCourse("EE101", "incomplete");
    s1.grading("EE101", "A");
    s1.displayCourseInfo("EE101");

    return 0;
}
