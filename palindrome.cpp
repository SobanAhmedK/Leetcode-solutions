#include<iostream>
#include<string>
using namespace std;
bool palindrome(string a , int length)
{  bool flag=false;
   for(int i=0,j=length-1 ;i<length&&j>=0; i++,j--)
   {
     if(i!=j)
     {
     if(a[i]==a[j])
     {
         flag = true;
     }
     else if(a[i]!=a[j])
     {
        flag=false;
     }
   }}                                                                       
   return flag;
   
}
int main()
{string a;
cin>>a;
int length=a.length();

bool result = palindrome(a , length);
cout<<"The string is palindrome?"<<" "<<"it's "<<result<<"!"<<endl;

    return 0;
}