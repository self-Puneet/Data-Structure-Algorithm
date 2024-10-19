// Student Grades Storage: A teacher wants to keep track of grades for a class of 30 students. Implement a system using arrays to input student names and their grades. The program should allow the teacher to calculate and display the average grade and identify the highest and lowest grades in the class.

#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
    public:
        double grade;
        string name;
        StudentRecord (double grade_, string name_) {
            this.grade, this.name = grade_, name_;
        }
};

class GradesStorage {
    
    public:
        StudentRecord students[30];
        int front = -1, rear = -1;

        void newEntry (string name_, double grade_) {
            if (front == -1) {
                front++;
                rear++;
                students[rear] = new StudentRecord(name_, grade_);
            }
            else if (rear < 29){
                rear++;
                students[rear] = new StudentRecord(name_, grade_);
            }
            else {
                limitExceed ();
            } 
        }

        void average () {
            double average_ = 0;
            for (int i = 0; i < 30; i++) {
                average_ += this.students[i].grade;
            }
            average_ = sum/30;
            cout << "average of class = " << grade << endl;
        }

        void limitExceed () {
            cout << "limit for students entry has reached its highest limit." << endl;
        }

        void highestGrade() {
            int highest_index = 0;
            for (int i = 0; i < 30; i++) {
                if (this.students[highest_index] < this.students[i]) {
                    highest_index = i;
                }
            }
            cout << "\t" << this.students[highest_index].name << "\t" << this.students[highest_index].grade << endl; 
        }

        void lowestGrade () {
            int lowest_index = 0;
            for (int i = 0; i < 30; i++) {
                if (this.students[lowest_index] < this.students[i]) {
                    lowest_index = i;
                }
            }
            cout << "\t" << this.students[lowest_index].name << "\t" << this.students[lowest_index].grade << endl; 
        }
};