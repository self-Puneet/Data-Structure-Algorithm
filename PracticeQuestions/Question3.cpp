// Student Grades Storage: A teacher wants to keep track of grades for a class of 30 students. Implement a system using arrays to input student names and their grades. The program should allow the teacher to calculate and display the average grade and identify the highest and lowest grades in the class.

#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
    public:
        double grade;
        string name;

        StudentRecord () {
            grade = 0.0;
            name = "";
        }
        StudentRecord (double grade_, string name_) {
            grade = grade_;
            name = name_;
        }
};

class GradesStorage {
    
    public:
        StudentRecord students[30];
        int front = -1, rear = -1;
        GradesStorage (string names[], double grades[]) {
            for (int i = 0; i < 20; i++) {
                rear++;
                students[rear] = Book(names[i], grades[i]);
            }
        }
        void newEntry (string name_, double grade_) {
            if (front == -1) {
                front++;
                rear++;
                students[rear] = StudentRecord(name_, grade_);
            }
            else if (rear < 29){
                rear++;
                students[rear] = StudentRecord(name_, grade_);
            }
            else {
                limitExceed ();
            } 
        }
        void average () {
            if (rear == -1) {
                cout << "students record is empty" << endl;                
            }
            else {
                double average_ = 0;
                for (int i = 0; i < rear; i++) {
                    average_ += students[i].grade;
                }
                average_ = sum/30;
                cout << "average of class = " << grade << endl;
            }
        }
        void limitExceed () {
            cout << "limit for students entry has reached its highest limit." << endl;
        }
        void highestGrade() {
            if (rear == -1) {
                cout << "students record is empty" << endl;                
            }
            else {
                int highest_index = 0;
                for (int i = 0; i < 30; i++) {
                    if (students[highest_index] < students[i]) {
                        highest_index = i;
                    }
                }
                cout << "\t" << students[highest_index].name << "\t" << students[highest_index].grade << endl; 
            }
        }
        void lowestGrade () {
            if (rear == -1) {
                cout << "students record is empty" << endl;                
            }
            else {
                int lowest_index = 0;
                for (int i = 0; i < 30; i++) {
                    if (students[lowest_index] < students[i]) {
                        lowest_index = i;
                    }
                }
                cout << "\t" << students[lowest_index].name << "\t" << students[lowest_index].grade << endl;
            } 
        }
};

int main() {
    string names[] = {
        "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", 
        "Helen", "Ivan", "Judy", "Karl", "Laura", "Mike", "Nina", 
        "Oscar", "Paul", "Quinn", "Rachel", "Steve", "Tina", 
        "Uma", "Victor", "Wendy", "Xander", "Yara", "Zane", 
        "Anna", "Brian", "Clara", "Derek"
    };
    double grades[30] = {
        85.5, 90.0, 76.3, 88.9, 92.4, 
        67.8, 81.0, 74.5, 95.2, 69.9, 
        84.0, 78.6, 91.7, 73.4, 89.1, 
        60.2, 83.3, 79.8, 88.0, 94.5, 
        77.7, 82.9, 68.3, 93.6, 71.5, 
        66.0, 85.1, 90.5, 87.2, 75.9
    };
    GradesStorage obj(names, grades);
    obj.newEntry("puneet", 23);
    obj.highestGrade();
    obj.lowestGrade();
    obj.average();
    return 0;
}