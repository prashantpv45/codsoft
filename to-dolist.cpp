#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }

    void mark_as_completed() {
        completed = true;
    }

    string get_status() const {
        return completed ? "Completed" : "Pending";
    }
};

void show_menu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

void add_task(vector<Task>& tasks) {
    string task_description;
    cout << "Enter the task description: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, task_description);
    tasks.push_back(Task(task_description));
    cout << "Task added successfully!" << endl;
}

void view_tasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:" << endl;
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - " << tasks[i].get_status() << endl;
        }
    }
}

void mark_task_as_completed(vector<Task>& tasks) {
    view_tasks(tasks);
    int task_num;
    cout << "Enter the task number to mark as completed: ";
    cin >> task_num;
    if (task_num > 0 && task_num <= static_cast<int>(tasks.size())) {
        tasks[task_num - 1].mark_as_completed();
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void remove_task(vector<Task>& tasks) {
    view_tasks(tasks);
    int task_num;
    cout << "Enter the task number to remove: ";
    cin >> task_num;
    if (task_num > 0 && task_num <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + task_num - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        show_menu();
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                view_tasks(tasks);
                break;
            case 3:
                mark_task_as_completed(tasks);
                break;
            case 4:
                remove_task(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
