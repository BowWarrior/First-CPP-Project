#include <string>
#include <iostream>
using namespace std;

void Question1();
void Question2();
void Question3();

int main() {
    //Question1();
    //Question2();
    Question3();


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