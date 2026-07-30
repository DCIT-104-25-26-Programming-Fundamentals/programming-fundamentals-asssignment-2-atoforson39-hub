#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    cin.ignore();
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[taskNum - 1];
    tasks.erase(tasks.begin() + (taskNum - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

void showMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<string> tasks;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}