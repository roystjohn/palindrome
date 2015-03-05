//
//  main.cpp
//  palindrome
//
//  Created by Roy St. John on 3/4/15.
//  Copyright (c) 2015 Roy St. John. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void init_string(string &);

int main(int argc, const char * argv[]) {
    
    string s = "namemanessssena";
    //string s = "abraabracadabra";
    //string s = "racecar";
    unsigned long palindrome_length = 0;
    unsigned long max_palindrom_length = 0;
    int x_index = 0;
    
    cout << s << endl;
    
    init_string(s);
    int x;
    int y = 1;
    int count = 0;
    //for(x = 2; x < s.length()  && s.length() - x > max_palindrom_length; x++) {
    //for(x = 2; x < s.length(); x = x + (y+1)/2) {
    for(x = 2; x < s.length()  && s.length() - x > max_palindrom_length; x = x + (y+1)/2) {
        y = 1;
        palindrome_length = 1;
        
        while((s[x-y] == s[x+y]) && s[x-y] != '^') {
            palindrome_length++;
            y++;
        }
        if(s[x-y+1] == '#' && s[x+y-1] == '#') {
            palindrome_length--;
        }
        
        if(palindrome_length > max_palindrom_length) {
            max_palindrom_length = palindrome_length;
            x_index = x;
        }
        count++;
    }
    
    cout << s << endl;
    cout << max_palindrom_length << endl;
    cout << x_index << endl;
    cout << "final x: " << x << endl;
    cout << "count: " << count << endl;
    
    
    return 0;
}

void init_string(string &s) {
    unsigned long n = s.length();
    string new_string = "^";
    
    for(int i = 0; i < n; i++) {
        new_string = new_string + s[i];
        if(i < n-1) {
            new_string.append("#");
        }
    }
    new_string.append("^");
    s = new_string;
}
