using namespace std;

#include <iostream>

void BinaryOperations(int n) 
{
    const int bitsNumber = 32;
    int bits[bitsNumber];
    cout << "Binary of the given number= ";
    cout << "0b ";
    int numberOfBlocks = 4;

    for (int i = bitsNumber - 1; i >= 0; i--)
    {
        int numberToConvert = n >> i;
        if (numberToConvert & 1) cout << "1";
        else cout << "0";
        --numberOfBlocks;
        if (numberOfBlocks == 0) {
            cout << " ";
            numberOfBlocks = 4;
        }
    }
    cout << endl;
}

void DivisionAndModulo(int n) 
{
    int a[10], i;
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    cout << "Binary of the given number= ";
    cout << " 0b";
    for (i = i - 1; i >= 0; i--)
    {
        cout << a[i];
    }
}

int main()
{
    int Selection;
    cout << "Welcome to the number to binary converter program. ";
    cout << "Please enter '1' for Division and Modula formula, '2' for binary operations. ";
    cin >> Selection;

    if (Selection == 1)
    {
        int n;
        cout << "Enter the number you want to convert: ";
        cin >> n;
        
        DivisionAndModulo(n);
    }
    else if (Selection == 2)
    {
        int n;
        cout << "Enter the number you want to convert: ";
        cin >> n;
        BinaryOperations(n);
    }
    else
    {
        cout << "You entered invalid number for method type.";       
    }
    
}
