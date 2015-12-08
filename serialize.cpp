// Done by Samirah Siddiq
// This code is to do serialization and deserialization of three objects- array of type int, double and string.

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// For quickly demo purpose, all data members are made public
class IntArray{
public:
    IntArray(int* d, int sz){
        size = sz;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = d[i];
    }

    void print(){
        for (int i = 0; i < size; i++)
            cout << data[i] << endl;
    }

    int* data;
    int size;
};

class DoubleArray{
public:
    DoubleArray(double* d, int sz){
        size = sz;
        data = new double[size];
        for (int i = 0; i < size; i++)
            data[i] = d[i];
    }

    void print(){
        for (int i = 0; i < size; i++)
            cout << data[i] << endl;
    }

    double* data;
    int size;
};

class StringArray{
public:
    StringArray(string* d, int sz){
        size = sz;
        data = new string[size];
        for (int i = 0; i < size; i++)
            data[i] = d[i];
    }

    void print(){
        for (int i = 0; i < size; i++)
            cout << data[i] << endl;
    }

    string* data;
    int size;
};

// serialize functions
void serialize(IntArray& arr, const char* filename);
void serialize(DoubleArray& arr, const char* filename);
void serialize(StringArray& arr, const char* filename);

// deserialize function
void* deserialize(const char* filename, string& type, int& size);

int main(){
    string type;
    int size;
    void* d;

    // test int array
    int arr[] = {10, 20, 30, 40};
    IntArray ia(arr, 4);
    serialize(ia, "ia.ser");

    // recreate object
    d = deserialize("ia.ser", type, size);
    if (type == "int"){
        IntArray obj((int*)d, size);
        obj.print();
    }
    cout << endl;

    // test double array
    double darr[] = {1.1, 2.2, 3.3, 4.4};
    DoubleArray da(darr, 4);
    serialize(da, "da.ser");

    // recreate object
    d = deserialize("da.ser", type, size);
    if (type == "double"){
        DoubleArray obj((double*)d, size);
        obj.print();
    }
    cout << endl;

    // test string array
    string sarr[] = {"one", "two", "three", "four"};
    StringArray sa(sarr, 4);
    serialize(sa, "sa.ser");

    // recreate object
    d = deserialize("sa.ser", type, size);
    if (type == "string"){
        StringArray obj((string*)d, size);
        obj.print();
    }

    return 0;
}

void serialize(IntArray& arr, const char* filename){
    ofstream fout(filename);

    fout << "int\n"; // write array type
    fout << arr.size << "\n"; // write array size

    // write array data
    for (int i = 0; i < arr.size; i++)
        fout << arr.data[i] << "\n";

    fout.close();
}

void serialize(DoubleArray& arr, const char* filename){
    ofstream fout(filename);

    fout << "double\n"; // write array type
    fout << arr.size << "\n"; // write array size

    // write array data
    for (int i = 0; i < arr.size; i++)
        fout << arr.data[i] << "\n";

    fout.close();
}

void serialize(StringArray& arr, const char* filename){
    ofstream fout(filename);

    fout << "string\n"; // write array type
    fout << arr.size << "\n"; // write array size

    // write array data
    for (int i = 0; i < arr.size; i++)
        fout << arr.data[i] << "\n";

    fout.close();
}


// deserialize function
// This function returns an array of void that needs to be casted to appropriate type
// based on the type and size returned
void* deserialize(const char* filename, string& type, int& size){
    void* arr;
    string line;
    int* ia;
    double* da;
    string* sa;

    ifstream fin(filename);
    if (!fin){
        cout << "File " << filename << " not found\n";
        exit(1);
    }

    fin >> type >> size;
    fin.ignore(1000, '\n');

    // read data
    if (type == "int")
        ia = new int[size];
    else if (type == "double")
        da = new double[size];
    else if (type == "string")
        sa = new string[size];
    for (int i = 0; i < size; i++){
        getline(fin, line);
        stringstream ss(line);
        if (type == "int")
            ss >> ia[i];
        else if (type == "double")
            ss >> da[i];
        else if (type == "string")
            sa[i] = line;
    }

    fin.close();
    if (type == "int")
        arr = ia;
    else if (type == "double")
        arr = da;
    else if (type == "string")
        arr = sa;
    return arr;
}

