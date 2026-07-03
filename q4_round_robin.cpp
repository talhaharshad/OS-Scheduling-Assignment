#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, quantum;
    cout << "=== Round Robin Scheduling ===\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), rem_bt(n), wt(n), tat(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
        rem_bt[i] = bt[i]; // Remaining burst time copy
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0;
    bool done;

    do {
        done = true;
        for(int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false; // Process abhi bacha hai
                
                if (rem_bt[i] > quantum) {
                    currentTime += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    currentTime += rem_bt[i];
                    wt[i] = currentTime - bt[i];
                    rem_bt[i] = 0; // Finish
                }
            }
        }
    } while (!done);

    float totalWT = 0, totalTAT = 0;
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << totalWT / n << endl;
    cout << "Average Turnaround Time = " << totalTAT / n << endl;

    return 0;
}
