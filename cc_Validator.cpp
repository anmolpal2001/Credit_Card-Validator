// Source Code : 

#include<iostream>
#include<string>
using namespace std;

bool isValidNumber(string& s)
{
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i]) )
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string ccNumber;
    
    // This program uses the Luhn Algorigthm to validate a CC number.
    
    cout<<"******* Credit Card Validator *******"<<endl;
    cout<<" If you want to quit type `exit` "<<endl;
    
    while(true)
    {
        cout<<"Enter credit card number : ";
        cin>>ccNumber;
        
        if(ccNumber == "exit")
          {
               break;
          }
        
        else if(!isValidNumber(ccNumber))
        {
          cout<<"Please enter numbers only"<<endl;
          continue;
        }
        
        int len = ccNumber.length();
        int evenSum = 0;
        
        for(int i=len-2;i>=0;i=i-2)
        {
            int num = ((ccNumber[i] - 48 ) * 2);
            if(num > 9){
                num = num/10 + num%10;
            }
            evenSum += num;
        }
        
        int oddSum = 0;
        for(int i=len-1;i>=0;i=i-2)
        {
            oddSum += (ccNumber[i]-48);
        }
        
        int totalSum = evenSum + oddSum;
        
        cout<<(totalSum %10==0 ? "Valid" : "Invalid")<<endl;
        
        continue;
    }
    return 0;
}
