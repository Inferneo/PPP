#include <iostream>
using namespace std;

int main(){
    string first_name;
    cout << "Enter your first name:\n";
    cin >> first_name;
    cout << "Hello, " << first_name;
    string recipient_name;
    cout << "\nEnter the name of the person you want to write to:\n";
    cin >> recipient_name;
    string friend_name;
    cout << "Enter the name of a mutual:\n";
    cin >> friend_name;
    int age = 0;
    cout << "Enter the age of the recipient:\n";
    cin >> age;
    if (age < 0 | age > 110){
        cout << "You're kidding!\n";
    }
    cout << "Dear " << recipient_name << ",\n"
         << "\tHow are you? I am well. I miss you more than cracked soil misses the rain. I hope we will"
         << " meet again soon, there are so many things I want to tell you. My heart aches with longing for "
         << "our conversations. All in due time. Till then, take care.\n"
         << "Have you seen " << friend_name << " lately?"
         << " I hear you just had a birthday and are now " << age << " years old.";
    if (age<12){
        cout << " Next year you will be " << age+1 << " years old.";
    }     
    if (age==17){
    cout << " Next year you will be able to vote.";
    }   
    if (age>70){
        cout << " Are you retired?\n";
    }
    cout << "\nYours Sincerely, \n"
         << "\n\n"
         << first_name << "\n";
    return 0;
}