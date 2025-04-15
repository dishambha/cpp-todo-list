#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to represent each task
struct Task {
    string description;
    bool completed;

    // Constructor to initialize task
    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task
void addTask(vector<Task>& todoList) {
    cout << "Enter the task description: ";
    cin.sync(); // Alternative to clear the input buffer
    string description;
    getline(cin, description);
    todoList.emplace_back(description);
    cout << "Task added successfully.\n";
}

// Function to view all tasks
void viewTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "Your to-do list is empty.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << "[" << (todoList[i].completed ? "X" : " ") << "] "
             << (i + 1) << ". " << todoList[i].description << "\n";
    }
    cout << "------------------\n";
}

// Function to mark a task as completed
void markAsCompleted(vector<Task>& todoList) {
    viewTasks(todoList);
    if (todoList.empty()) return;

    cout << "Enter the number of the task to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (cin.fail() || taskNumber < 1 || taskNumber > todoList.size()) {
        cout << "Invalid task number. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    todoList[taskNumber - 1].completed = true;
    cout << "Task " << taskNumber << " marked as completed.\n";
}

// Function to remove a task
void removeTask(vector<Task>& todoList) {
    viewTasks(todoList);
    if (todoList.empty()) return;

    cout << "Enter the number of the task to remove: ";
    int taskNumber;
    cin >> taskNumber;

    if (cin.fail() || taskNumber < 1 || taskNumber > todoList.size()) {
        cout << "Invalid task number. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    todoList.erase(todoList.begin() + taskNumber - 1);
    cout << "Task " << taskNumber << " removed successfully.\n";
}

// Main menu
int main() {
    vector<Task> todoList;
    int choice;

    do {
        cout << "\n====== To-Do List Menu ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: addTask(todoList); break;
            case 2: viewTasks(todoList); break;
            case 3: markAsCompleted(todoList); break;
            case 4: removeTask(todoList); break;
            case 5: cout << "Exiting application. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
