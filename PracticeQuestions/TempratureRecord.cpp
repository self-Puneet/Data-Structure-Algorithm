// Temperature Record: You are collecting daily temperature readings for a week. Implement a program that uses an array to store 7 temperature readings. The program should allow the user to input these temperatures and then calculate and display the highest and lowest temperatures recorded.

#include <iostream>
#include <string>
using namespace std;

class TempratureRecord {
    public:
        double temp_array[7];
        int top = -1;
        void clearRecord() {
            for (int i = 0; i <= top; i++) {
                temp_array[i] = 0.0;
            }
            cout << "Records of last week are cleared ..." << endl;
        }
        void addRecord(double temp) {
            if (isFull()) {
                fullMessege();
            }
            else {
                top ++;
                temp_array[top] = temp;
                cout << temp << " temprature for day #" << top + 1 << " is added into database." << endl; 
            }
        }
        void highestRecord() {
            double highest = temp_array[0];
            for (int i = 0; i < 7; i++) {
                if (highest < temp_array[i]) {
                    highest = temp_array[i];
                }
            }
            cout << "highest temprature of last weak is = " << highest << endl;
        }
        void lowestRecord() {
            double lowest;
            for (int i = 0; i < 7; i++) {
                if (lowest > temp_array[i]) {
                    lowest = temp_array[i];
                }
            }
            cout << "highest temprature of last weak is = " << lowest << endl;
        }

    private:
        bool isFull() {
            if (top == 6) {
                return true;
            }
            return false;
        }
        void fullMessege() {
            cout << "records are filled with temprature record of previous week. try clearing that data..." << endl;
        }
};

int main() {
    TempratureRecord obj;
    obj.addRecord(2.3);
    obj.addRecord(4.5);
    obj.addRecord(3.5);
    obj.addRecord(1.9);
    obj.addRecord(-6.7);
    obj.highestRecord();
    obj.lowestRecord();
    obj.clearRecord();
    return 0;
}