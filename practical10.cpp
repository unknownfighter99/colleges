// Consider a scenario for Hospital to cater services to different kinds of patients as Serious  (top priority), b) non-serious (medium priority), c) General Checkup (Least priority). Implement the priority queue to cater services to the patients.
#include <bits/stdc++.h>

using namespace std;

struct Patient {
    string name;
    int priority;

    // Constructor
    Patient(const string& n, int p) : name(n), priority(p) {}

    // Overloading the less than operator for priority comparison
    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    priority_queue<Patient> queue;
    int ch;

    while (true) {
        cout << "Select the option \n1.add patient \n2.display the list" << endl;
        cin >> ch;
        if (ch == 1) {
            string patientName;
            int priority;
            cout << "ENter patient name: " << endl;
            cin >> patientName;
            cout << "ENter patient type / category (1-3): " << endl;
            cin >> priority;

            queue.push(Patient(patientName, priority));
        } else if (ch == 2) {
            // Serve patients in order of priority
            while (!queue.empty()) {
                Patient currentPatient = queue.top();
                queue.pop();
                cout << "Now serving: " << currentPatient.name << " (Priority: " << currentPatient.priority << ")\n";
            }
        } else if (ch == 3) {
            exit(0);
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}
