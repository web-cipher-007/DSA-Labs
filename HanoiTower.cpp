#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk "<<n<<" from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "The sequence of moves is: " << endl;
    towerOfHanoi(n, 'A', 'C', 'B'); // A: source, C: destination, B: auxiliary
    return 0;
}
