#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#include <cstddef>
#include <cctype>

void Question1();
void Question2();
void Question3();
int Question1B();
bool* Question2B();
void Question3B(char* ptr);
int* Question4B(const string& s);

int main() {
    //Question1();
    //Question2();
    //Question3();
    //cout << Question1B() << endl;
    //cout << Question2B() << endl;


/*  char str[] = "Hello, World!";
    Question3B(str);
    cout << str << endl; // Output the reversed string
*/

    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int* counts = Question4B(input);
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            char letter = 'a' + i;
            cout << letter << ": " << counts[i] << endl;
        }
    }

    delete[] counts;



    return 0;
}

void Question1(){
    int x = 7;
    //returns 1 (true)
    cout << (x < 10 && x >= -1) << endl;
    //returns 0 (false)
    cout << (!x && x >= 3) << endl;
    //returns 0 (false)
    cout << (x++ == 8 || x == 7) << endl;

}

void Question2(){
    //returns 'f'
    char s[] = "University of Wisconsin-Eau Claire";
    cout << s[12] << endl;

    //returns "It's been a very sunny day"
    string example("It's been a very busy day");
    cout << (example.replace(17, 4, "sunny")) << endl;

    //returns "Angry Birds"
    string animal("Birds");
    cout << (animal.insert(0, "Angry ")) << endl;

    //returns "Madness"
    string game("March Madness");
    cout << (game.substr(6, 7)) << endl;
}



void Question3(){
    //vectors are apparently used nowadays, but here are normal pointers
    int size;

    cout << "enter integer amount of how many doubles you want in the array!" << endl;
    cin >> size;

    //for our specific assignment, but I like the input more:
    //size = 10;

    double** d_array = new double*[size];
    for(int i = 0; i < size; i++){
        d_array[i] = new double;

        cout << "enter new double: " << endl;
        cin >> *(d_array[i]);
        
        //for our specific assignment, but I like the input more:
        // *(d_array[i]) = 1.0;
    }


    for(int i = 0; i < size; i++){
        cout << "value at d_array[" << i << "] = " << *(d_array[i]) << " (at memory address: " << d_array[i] << ")" << endl;
    }
    cout << endl;



    //free memory
    for (int i = 0; i < size; i++) {
        delete d_array[i];
    }
    delete[] d_array;
    
}


// ----------------------- SECTION B -------------------------------------//
int Question1B(){
    int array[] = {1, 2, 3, -1, 4, 5};
    int count = 0;
    if(std::size(array) != 0){
        for(int i = 0; i < int(std::size(array)); i++){
            if(array[i] < 0){
                //do nothing lol
            } else{
                count += array[i];
            }        
        }
    }
    
    return count;
}


bool* Question2B() {
    bool* array = new bool[1000];

    for (int i = 0; i < 1000; i++) {
        array[i] = true;

        for (int j = 2; j * j <= i; j++) { 
            if (i % j == 0) {
                array[i] = false;
                break;
            }
        }

        if (array[i] && i >= 2) {
            cout << i << " is prime" << endl;
        }
    }
    return array;
}


void Question3B(char* ptr) {
    int len = strlen(ptr);//gets length of C-string
    int start = 0;
    int end = len - 1;

    // swap characters from both ends
    while (start < end) {
        char temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;

        start++;
        end--;
    }
}


int* Question4B(const string& s) {
    int* freq = new int[26];

    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            freq[c - 'a']++;
        }
    }

    return freq;
}