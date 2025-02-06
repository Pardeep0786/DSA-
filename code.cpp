#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

//Sum of two numbers
int s;
void Sum(int a, int b){
    s = a + b;
    cout<<"The sum of a and b is : " <<s;
}

//Calculate the minimum number
void Min(int x, int y){
    if(x > y){
        cout<<"x is greater";
    }else{
        cout<<"y is greater";
    }
}

//Sum of number from 1 to n
int SumN(int n){
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum = sum + i;
    }
    cout<<sum;
}

//find the factorial of the n number
int fact(int j){
    int f = 1;
    for(int i = 1; i<=j; i++){
        f = f * i;
    }
    return f;
}

//Increase the value of number's by 10
int p;
void fun(int a , int b){
    a = a + 10;
    b = a + 10;
    p = a + b;
    cout<<p;
}

//Sum of digits in a number
void digitSum(int num){
    int sumdigit = 0;
    while(num > 0){
        int lastdigit = num%10;
        num/=10;
        sumdigit+=lastdigit;
    }
    cout<<"The sum of digit of the number is : " <<sumdigit;
}

//find binomial
void binomial(int n, int r){
    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_nmr = fact(n-r);

    cout<< fact_n / (fact_r * fact_nmr);
}

//To check the given number is Even or odd
void CheckNumber(int num){
    if(num%2==0){
        cout<<"Even number";
    }else{
        cout<<"odd number";
    }
}

//Print the digits of the number
void PrimeNumber(int n){
    for(int i = 0; i<n; i++){
        if(i%2!=0){
            cout<<i << " ";
        }
    }
    
}

//Find the binary value of the decimal number
int FindBinary(int decno){
    int result = 0;
    int power = 1;
    while(decno > 0){
        int rem = decno%2;
        decno /= 2;
        
        result += (rem * power);
        power+=10;
    }
    cout<<result;
    }
    int BinaryToDecimal(int binno){
        int res = 0, power = 1;
        while(binno > 0){
            int rem = binno%10;
            res += rem * power;

            binno/=10;
            power*=10;
        }
        cout<<res;
    }

// To Check the given input is AlphaNumeric or not   
int IsAlphaNumeric(char ch){
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }else {
        return false;
    }
} 

//To cehck the given string is Palindrome or not
int Palindrome(string s, int n){
    int st = 0, end = n - 1;
        while(st < end){
        if(s[st++] == s[end--]){
            return true;
        }
        else{
            return false;
        }
    }
}

//Remove the occurence in the string
string RemoveOccurence(string s, string part){
    while(s.length() >= 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}
bool isFreqSame(int freq1[], int freq2[]){
    for(int i = 0; i < 26; i++){
        if(freq1[i] == freq2[i]){
            return true;
        }
    }
    return false;
}
bool Inclusion(string s1, string s2){
    int freq[26] = {0};

    for(int i = 0; i < s1.length(); i++){
        freq[s1[i] - 'a']++;
    }

    int WindSize = s1.length();

    for(int i = 0; i < s2.length(); i++){
        int Windidx = 0, idx = i;
        int Windfreq[26] = {0};

        while(Windidx < WindSize && idx < s2.length()){
            Windfreq[s2[idx] - 'a']++;
            Windidx++; idx++;
        }
        if(isFreqSame(freq, Windfreq)){
            return true;
        }
    }
    return false;
}

// To reverse the given string
string ReverseString(string s, int n){
    string ans = "";

    reverse(s.begin(), s.end());

    for(int i = 0; i < n; i++){
        string word = "";
        while(i < n && s[i] != ' '){
            word+= s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if(word.length() > 0){
             ans += " " + word;
        }

    }
    return ans.substr(1);
}

//Compress the string
int Compressstring(vector<char> chars, int n){
    int idx = 0;
    for(int i = 0; i < n; i++){
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch){
            count++; i++;
        }
        if(chars[i] == ch){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            string str = to_string(count);
            for(char digit : str){
                chars[idx++] = digit;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
    
} 

// To check the given number is prime or non prime
string IsPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return "Non Prime Number";
        }
    }
    return "Prime number";
}
int IsPrimeForRange(int n){
    vector <bool> isPrime(n+1, true);
    
    int count = 0;

    for(int i = 2; i < n; i++){
        if(isPrime[i]){
            count++;
        
        for(int j = i * 2; j < n; j = j + i){
            isPrime[j] = false;
        }
    }
    }
    return count;
}

// calculate the Armstrong number( a number that is equal to the sum of its digits )
bool Armstrong(int n){
    int CopyN = n;
    int sumOfCubes = 0;

    while(n != 0){
        int digit = n % 10;
        sumOfCubes += (digit * digit * digit);

        n = n / 10;
    }
    return CopyN == sumOfCubes;
}

// Find the Greatest Common Divisor
int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    if(a == 0) return b;
    return a;
}

// To reverse the number
int revNo(int n){
    int revno = 0;
    while(n != 0){
        int digit = n % 10;
        revno = revno * 10 + digit;

        n = n / 10;
    }
    return revno;
}


