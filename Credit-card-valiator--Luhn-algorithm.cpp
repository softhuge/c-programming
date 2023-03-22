// ############################################################### //
// ##                                                           ## //
// ##  Program:     Luhn's Algorithm For Credit Card Validation ## //
// ##  Developer:   Rajesh Dinodia                              ## //
// ##  Dev Profile: https://github.com/hritikdinodia            ## //
// ##  Organiation: Softhuge                                    ## //
// ##  Repo Url:    https://github.com/softhuge/c-programming   ## //
// ##                                                           ## //
// ############################################################### //

#include <iostream>
using namespace std;
int count(long long workingcc);
int lastdigit(long long workingcc);
int seclast(long long workingcc);
void chk_type(long long cc);

int main()
{

    long long ccnumber;
    cout << "Credit Card Validator" << endl;
    cout << "Enter the CC number" << endl;
    cin >> ccnumber;
    int len = count(ccnumber);
    if (len >= 13 && len <= 16)
    {
        int evensum = lastdigit(ccnumber);
        int oddsum = seclast(ccnumber);

        int ccsum = evensum + oddsum;

        if (ccsum % 10 == 0)
        {
            cout << "The card is valid." << endl;
            chk_type(ccnumber);
        }
        else
        {
            cout << "The card is invalid." << endl;
        }
    }
    else
    {
        cout << "CHECK YOUR CC NUMBER !!!!" << endl;
    }
}

int count(long long workingcc)
{

    int count = 0;
    while (workingcc != 0)
    {
        workingcc = workingcc / 10;
        count++;
    }
    return count;
}

int lastdigit(long long workingcc)
{
    int sum = 0;
    while (workingcc != 0)
    {
        sum = sum + workingcc % 10;
        workingcc = workingcc / 100;
    }
    return sum;
}

int seclast(long long workingcc)
{
    int n;
    int temp_sum;
    int sum = 0;
    workingcc = workingcc / 10;
    while (workingcc != 0)
    {
        n = (workingcc % 10) * 2;
        if (n > 9)
        {
            temp_sum = (n % 10) + (n / 10);
            sum = sum + temp_sum;
        }
        else
        {
            sum = sum + n;
        }
        workingcc = workingcc / 100;
    }
    return sum;
}

void chk_type(long long cc)
{

    while (cc > 100)
    {
        cc = cc / 10;
    }

    if ((cc >= 40 && cc <= 69) || (cc == 37))
    {
        if (cc >= 40 && cc <= 49)
        {
            cout << "Visa card." << endl;
        }
        else if (cc >= 50 && cc <= 59)
        {
            cout << "Master card." << endl;
        }
        else if (cc == 37)
        {
            cout << "American express card." << endl;
        }
        else
        {
            cout << "Discover card." << endl;
        }
    }
    else
    {
        cout << "error card type" << endl;
    }
}