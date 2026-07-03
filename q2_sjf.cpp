#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, burstTime, waitingTime, turnaroundTime, completionTime;
};

bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "=== Non-Preemptive SJF Scheduling ===\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Burst Time for P" << p[i].id << ": ";
        cin >> p[i].burstTime;
    }

    sort(p.begin(), p.end(), compareBurstTime);

    int currentTime = 0;
    float totalWT = 0;

    for(int i = 0; i < n; i++) {
        p[i].waitingTime = currentTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        currentTime += p[i].burstTime;
        p[i].completionTime = currentTime;
        totalWT += p[i].waitingTime;
    }

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].burstTime << "\t" << p[i].waitingTime << "\t" << p[i].turnaroundTime << "\n";
    }

    // === GANTT CHART PRINTING ===
    cout << "\n=== Gantt Chart ===\n+";
    for(int i = 0; i < n; i++) cout << "-------+";
    cout << "\n|";
    for(int i = 0; i < n; i++) cout << "  P" << p[i].id << "   |";
    cout << "\n+";
    for(int i = 0; i < n; i++) cout << "-------+";
    cout << "\n0";
    for(int i = 0; i < n; i++) cout << "\t" << p[i].completionTime;
    cout << "\n";

    cout << "\nAverage Waiting Time = " << totalWT / n << endl;
    return 0;
}
