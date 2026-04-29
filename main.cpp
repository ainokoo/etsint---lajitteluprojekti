#include "list.h"
#include "utility.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/* void print(int &x) {
    cout << x << endl;
} */

       
int entry_count(List<int>& list) {
    
    int group_of_data_size;
        cout << "How many data entries do you want? " << endl;
        cin >> group_of_data_size;

        for (int i = 0; i < group_of_data_size; i++) {
            list.insert(i, 2 * i + 1);
        }

        int wanted_number;
        cout << "Which number you want to search from the data entries? " << endl;
        cin >> wanted_number;

        return wanted_number;
    }

int main() {

List<int> list;
int choice;

cout << " 1. Linear searching " << endl;
cout << " 2. Binary searching " << endl;
cout << " 3. n^2 type sorting " << endl;
cout << " 4. n * log(n) type of sorting " << endl;
cout << " 5. Sorting algorithms performance inspection " << endl;
cout << " 6. Quit " << endl;

cout << " Your choice: _ " << endl;
cin >> choice;



switch (choice) {
    case 1: {

        int wanted_number = entry_count(list);

        bool found = false;

        for (int i = 0; i < list.size(); i++) {
            int x;
            list.retrieve(i, x);

            if (x == wanted_number) {
                cout << " Number found, it was entry number " << i << endl;
                found = true;
                break;
            } 
        }

        if (!found) {
          cout << "Wanted number does not exist" << endl;
    }

    } break;

    case 2: {

    int wanted_number = entry_count(list);

    bool found = false;

    int bottom = 0;
    int top = list.size() - 1;
    
    while (bottom <= top) {
    int mid = (bottom + top) / 2;

    int x;
    list.retrieve(mid, x);
    
    if (x == wanted_number) {
        cout << " Number found, it was entry number " << mid << endl;
        found = true;
        break;
    }

    if (x > wanted_number) {
        top = mid - 1;
    } else {
        bottom = mid + 1;
    }
    }

    if (!found) {
        cout << "Wanted number does not exist" << endl;
    }

    } break;

    case 3: {
    
    int data_size;
    cout << "How many data entries do you want? " << endl;
    cin >> data_size;

    vector<int> data(data_size);

    for (int i = 0; i < data_size; i++) {
        data[i] = rand() % (10 * data_size);
    }

    int data_entry_amount;
    cout << "How many data entries do you want to see from the beginning before sorting? " << endl;
    cin >> data_entry_amount;

    cout << "Data entries from the beginning (before sorting) are: " << endl;
    for (int i = 0; i < data_entry_amount; i++) {
    cout  << data[i] << endl;
        }

    cout << "Starting the sorting..." << endl;
    int first_unsorted = data[0];
    int position;
    int current;

    for (first_unsorted = 1; first_unsorted < data_size; first_unsorted++) {
        if (data[first_unsorted] < data[first_unsorted -1]) {
            position = first_unsorted;
            current = data[first_unsorted];
            do {
                data[position] = data[position - 1];
                position--;
            } while (position > 0 && data[position - 1 ] > current);
            data[position] = current;
        }
    }

    cout << "How many data entries do you want to see from the beginning after sorting? " << endl;
    cin >> data_entry_amount;

    cout << "Data entries from the beginning (after sorting) are: " << endl;
    for (int i = 0; i < data_entry_amount; i++) {
    cout << data[i] << endl;
        }
    } break;

    case 4: {

    } break;

    case 5: {

    } break;

    case 6: {
        cout << "Quitting program. " << endl;
        return 0;
    };
}

// listan pitäis olla 1 3 7 9 11 13 15 17 19 21....


    return 0;
}

