#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "=== FCFS Scheduling ===\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> pid(n), at(n), bt(n), ct(n), tat(n), wt(n);

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for P" << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for P" << pid[i] << ": ";
        cin >> bt[i];
    }

    int currentTime = 0;
    float totalWT = 0, totalTXT = 0;

    for(int i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];
        }
        ct[i] = currentTime + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        currentTime = ct[i];
        totalWT += wt[i];
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    // === GANTT CHART PRINTING ===
    cout << "\n=== Gantt Chart ===\n+";
    for(int i = 0; i < n; i++) cout << "-------+";
    cout << "\n|";
    for(int i = 0; i < n; i++) cout << "  P" << pid[i] << "   |";
    cout << "\n+";
    for(int i = 0; i < n; i++) cout << "-------+";
    cout << "\n0";
    for(int i = 0; i < n; i++) cout << "\t" << ct[i];
    cout << "\n";

    cout << "\nAverage Waiting Time = " << totalWT / n << endl;
    return 0;
}
