// Daily Task Scheduler: You want to create a simple task scheduler for daily activities. Use a stack to manage tasks, where users can add  tasks and view the most recent task added. Implement functionality to mark tasks as completed and remove them from the stack.

#include <iostream>
#include <string>
using namespace std;

class Task {
    public:
        string task_name;
        bool status = false;

        Task() {
            task_name = "";
        }
        Task (string task_name_) {
            task_name = task_name_;
        }
};

class TaskSchedular {
    public:
        Task tasks_list [100];
        int top = -1;

        void addTask (string task_name) {
            if (!Full()) {
                top++;
                tasks_list[top] =  Task(task_name);
            }
            else {
                fullMessage();
            }
        }
        void removeTask () {
            if (Null()) {
                nullMessage();
            }
            else {
                string temp = tasks_list[top].task_name;
                top -= 1;
                cout << temp << " task is deleted..." << endl;
            }
        }
        void recentTask () {
            if (Null()) {
                nullMessage();
            }
            else {
                cout << "\t" << tasks_list[top].task_name << "\t" << tasks_list[top].status << endl;
            }
        }
        void markCompleted (string task_name) {
            if (Null()) {
                nullMessage();
            }
            else {
                tasks_list[top].status = true;
                cout << tasks_list[top].task_name << " task is completed..." << endl;
            }
        }
        void removeTask (string task_name) {
            if (Null()) {
                nullMessage();
            }
            else {
                int indexTask = searchTask(task_name);
                for (int i = indexTask; i < top; i++) {
                    tasks_list[i] = tasks_list[i+1];
                }
                cout << task_name << " task is deleted succeffully." << endl;
            }

        }
        int searchTask (string task_name) {
            for (int i = 0; i < top; i++) {
                if (task_name == tasks_list[top].task_name) {
                    return i;
                }
            }
            return -1;
        }
        bool Null () {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
        bool Full () {
            if (top == 99) {
                return true;
            }
            else {
                return false;
            }
        }
        void fullMessage () {
            cout << "our schedular is full of task..." << endl;
        }
        void nullMessage () {
            cout << "our schedular is currentl empty..." << endl;
        }
};

int main() {
    TaskSchedular obj;
    obj.addTask("DS");
    obj.addTask("CSA");
    obj.removeTask("CSA");
    obj.addTask("Discrete Mathematics");
    obj.removeTask();
    obj.markCompleted("DS");
    obj.recentTask();
    return 0;
}