// DZ6.cpp
//

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const size_t M = 4;
const size_t N = 4;


//Exercise 6.1
size_t getSize()
{
    size_t n;
    cout << "Enter array size: ";
    cin >> n;
    return n;
}

int* createArray(size_t size)
{
    int* ptArr = nullptr;

    if (size > 0)
    {
        ptArr = new (std::nothrow) int[size];

        if (ptArr != nullptr)
        {
            for (size_t i = 0; i < size; i++)
            {
                ptArr[i] = 0;
            }
        }
    }

    return ptArr;
}

void fillArray2powN(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = pow(2, i);
    }
}

void printArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Exercise 6.2
int** create4x4Matrix()
{
    int** ptArr;

    ptArr = new (std::nothrow) int* [M];
    for (size_t i = 0; i < M; i++)
    {
        ptArr[i] = new (std::nothrow) int[N];
    }

    return ptArr;
}

void fill4x4Matrix(int** arr)
{
    for (size_t i = 0; i < M; i++)
        for (size_t j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 10;
        }
}

void print4x4Matrix(int** arr)
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Exercise 6.3
string create1stFile()
{
    string fname;
    cout << "Enter 1st filename: ";
    cin >> fname;
    fname += ".txt";

    ofstream fout(fname);
    for (int i = 0; i < rand() % 5 + 5; i++)
        fout << "Some text " << i << endl;
    fout.close();

    return fname;
}

string create2ndFile()
{
    string fname;
    cout << "Enter 2nd filename: ";
    cin >> fname;
    fname += ".txt";

    ofstream fout(fname);
    for (int i = 0; i < rand() % 5 + 5; i++)
        fout << "Another text " << i << endl;
    fout.close();

    return fname;
}

//Exercise 6.4
string mergeFiles(string firstFile, string secondFile)
{

    string fname;
    cout << "Enter merged filename: ";
    cin >> fname;
    fname += ".txt";
    ofstream fout(fname);

    ifstream fin1(firstFile);
    if (fin1.is_open())
    {
        const size_t SIZE = 256;
        char buf[SIZE];
        while (!fin1.eof())
        {
            fin1.getline(buf, SIZE);
            fout << buf << endl;
        }
        fin1.close();
    }

    ifstream fin2(secondFile);
    if (fin2.is_open())
    {
        const size_t SIZE = 256;
        char buf[SIZE];
        while (!fin2.eof())
        {
            fin2.getline(buf, SIZE);
            fout << buf << endl;
        }
        fin2.close();
    }

    fout.close();

    return fname;

}

int main()
{
    //Exercise 6.1
    cout << "Exercise 6.1:" << endl;
    size_t size = getSize();
    int* ptArr = createArray(size);
    fillArray2powN(ptArr, size);
    printArray(ptArr, size);
    delete[] ptArr;
    ptArr = nullptr;
    cout << endl;

    //Exercise 6.2
    cout << "Exercise 6.2:" << endl;
    srand(time(0));
    int** ptMtrx = create4x4Matrix();
    fill4x4Matrix(ptMtrx);
    print4x4Matrix(ptMtrx);
    for (size_t i = 0; i < M; i++)
        delete[] ptMtrx[i];
    delete[] ptMtrx;
    ptMtrx = nullptr;
    cout << endl;

    //Exercise 6.3
    cout << endl << "Exercise 6.3:" << endl;
    string firstFile = create1stFile();
    string secondFile = create2ndFile();
    cout << firstFile + " and " + secondFile + " created.";
    cout << endl;

    //Exercise 6.4
    cout << endl << "Exercise 6.4:" << endl;
    string mergedFile = mergeFiles(firstFile,secondFile);
    cout << firstFile + " and " + secondFile + " merged to " + mergedFile;
    cout << endl;
}
