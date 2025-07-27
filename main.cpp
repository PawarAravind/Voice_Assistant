
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include "command_handler.h"
using namespace std;

void greetUser() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;

    if(hour < 12)
        system("espeak -s 130 \"Good Morning Avi.How can I help You. \"");
    else if(hour < 18)
        system("espeak -s 130 \"Good Afternoon Avi.How can I help You. \"");
    else
        system("espeak -s 130 \"Good Evening Avi.How can I help You. \"");
}

string getVoiceCommand() {
    system("python voice_input.py > input.txt");
    string command;
    ifstream fin("input.txt");
    getline(fin, command);
    fin.close();
    return command;
}

int main() {
    greetUser();
    while(true) {
        cout<<"Commands:\nopen google\nsearch google for <topic>\nopen chatgpt\nask chatgpt about <topic>\nopen notepad\nnote\ntime please\nopen YouTube\nsearch YouTube for <topic>\nStart WhatsApp\nOpen whatsapp and message <person> like <message>\nexit"<<endl;
        system("espeak -s 100 \"Listening..\"");
        cout<<".....Listening.....\n";
        string command = getVoiceCommand();
        cout << "You said: " << command << endl;
        processCommand(command);
        if(command == "exit")
            break;
    }
    return 0;
}
