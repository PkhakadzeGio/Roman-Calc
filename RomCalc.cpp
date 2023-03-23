#include<iostream>
#include <string>
using namespace std;
 
int RomToNum(char *rom)
{
    int num, finalRomNum = 0;
    for (int i = 0; rom[i]; i++)
    {
        switch (rom[i]) 
        {
            case 'I': 
                num = 1;
                if (rom[i + 1])
                {
                    if (rom[i + 1] == 'X')
                    {
                        num = 9;
                        i++;
                    }
                    else if (rom[i + 1] == 'V')
                    {
                        num = 4;
                        i++;
                    }
                }
                break;
 
            case 'V':
                num = 5;
                break;
 
            case 'X':if (rom[i + 1])
                {
                    if (rom[i + 1] == 'C')
                    {
                        num = 90;
                        i++;
                    }
                    else if (rom[i + 1] == 'L')
                    {
                        num = 40;
                        i++;
                    }
                }
                num = 10;
                
                break;
 
            case 'L':
                num = 50;
                break;
 
            case 'C':
                num = 100;
                break;
        }
        finalRomNum = finalRomNum + num;
    }
    return finalRomNum;
}
 
 string NumToRom(int num)
{
    string roman = "";
    
    while (num >= 100)
    {
        roman += "C";
        num -= 100;
    }
    while (num >= 90)
    {
        roman += "XC";
        num -= 90;
    }
    while (num >= 50)
    {
        roman += "L";
        num -= 50;
    }
    while (num >= 40)
    {
        roman += "XL";
        num -= 40;
    }
    while (num >= 10)
    {
        roman += "X";
        num -= 10;
    }
    while (num >= 9)
    {
        roman += "IX";
        num -= 9;
    }
    while (num >= 5)
    {
        roman += "V";
        num -= 5;
    }
    while (num >= 4)
    {
        roman += "IV";
        num -= 4;
    }
    while (num >= 1)
    {
        roman += "I";
        num -= 1;
    }
    return roman;
}

 
 
int main()
{
    char romNum1[9], romNum2[9];
    string input;
    int num1, num2, result;
    char op;

    cout << "Enter a number: ";
    cin >> romNum1;

    while (true) {
        cout << "Enter an operator (+, -, *, /) or 'exit': ";
        cin >> input;

        if (input == "exit") {
            break;
        }

        op = input[0];

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Invalid operator" << endl;
            break;
        }

        cout << "Enter another number: ";
        cin >>  romNum2;

            num1 = RomToNum(romNum1);
            num2 = RomToNum(romNum2);

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }

        
    }
    
    cout << "result: " << NumToRom(result) << endl;
}


