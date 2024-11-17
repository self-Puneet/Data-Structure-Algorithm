// To-Do List: Create a to-do list application where users can add tasks, view all tasks, and mark tasks as completed. Use a queue to manage tasks, ensuring that the oldest task can be removed once completed. Include a function to display the list of current tasks and their statuses

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

class ToDoList {
    public:
        Task tasks_list [100];
        int front = -1;
        int rear = -1;

        void addTask (string task_name) {
            if (!Full()) {
                rear++;
                tasks_list[rear] =  Task(task_name);
                cout << tasks_list[front].task_name << " is added in To - Do List" << endl;
            }
            else if (front > 0) {
                rear = 0;
                tasks_list[rear] = task_name;
                cout << tasks_list[front].task_name << " is added in To - Do List" << endl;
            }
            else {
                if (tasks_list[front].status = true) {
                    cout << tasks_list[front].task_name << " is completed and thus removed..." << endl;
                    tasks_list[front] = Task(task_name);
                    cout << tasks_list[front].task_name << " is added in To - Do List" << endl;
                }
                else {
                    fullMessage();
                }
            }
        }
        void displayTask () {
            if (rear < front) {
                int count = 1;
                for (int i = front; i < tasks_list.length(); i++) {
                    cout << "\t" << count  << "\t" << tasks_list[i] << endl; 
                    count ++;
                }
                for (int i = 0; i <= rear; i++) {
                    cout << "\t" << count  << "\t" << tasks_list[i] << endl;
                    count ++;
                }
            }
            else {
                int count  = 1;
                for (int i = front; i <= rear; i ++) {
                    cout << "\t" << count  << "\t" << tasks_list[i] << endl;
                    count ++;
                }
            }
        }
        
        void markCompleted (string task_name) {
            if (Null()) {
                nullMessage();
            }
            else {
                int indexTask = searchTask (task_name);
                tasks_list[indexTask].status = true;
                cout << tasks_list[indexTask].task_name << " task is completed..." << endl;
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
            if (rear == -1) {
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
    ToDoList obj;
    obj.addTask("DS");
    obj.addTask("CSA");
    obj.displayTask();
    obj.markCompleted("DS");
    return 0;
}