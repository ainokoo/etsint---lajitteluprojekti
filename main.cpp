#include "list.h"
#include "utility.h"
#include <iostream>

using namespace std;

/* void print(int &x) {
    cout << x << endl;
} */

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

        int group_of_data_size;
        cout << "How many data entries do you want? " << endl;
        cin >> group_of_data_size;

        for (int i = 0; i < group_of_data_size; i++) {
            list.insert(i, 2 * i + 1);
        }

        int wanted_number;
        cout << "Which number you want to search from the data entries? " << endl;
        cin >> wanted_number;

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

    case 6: {
        cout << "Quitting program. " << endl;
    };
}

/*List<int> test_list;

test_list.insert(0, 3);
test_list.insert(1, 5);
test_list.insert(2, 7);

test_list.traverse(print);

int x;
test_list.retrieve(2, x);

cout << "Haettu paikka 2: " << x << endl;

cout << "Listan koko: " << test_list.size() << endl;

List<int> copy_list = test_list;

cout << "Alkuperäisen istan tyhjäys..." <<endl;

test_list.clear();

cout << "Kokeillaan kopioidun listan tulostus: " << endl;
copy_list.traverse(print);
*/

    return 0;
}

