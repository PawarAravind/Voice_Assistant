
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include <algorithm>
using namespace std;

void processCommand(string command) {
    if(command.find("time please") != string::npos) {
        time_t now = time(0);
        char* dt = ctime(&now);
        string say = "espeak -s 130 \"The time is.. ";
        say += dt;
        say += "\"";
        system(say.c_str());
    }  //Just opens GOOGLE
    else if(command.find("open google") != string::npos) {
        system("espeak -s 130 \"Opening Google\"");
        system("start https://www.google.com");
    }  //Opens GOOGLE and search
    else if(command.find("search google for") != string::npos) {
        int pos = command.find("search google for");
        if (command.size() > pos + 18) {
            string query = command.substr(pos + 18);
            replace(query.begin(), query.end(), ' ', '+');
            string url = "start https://www.google.com/search?q=" + query;
            string say = "espeak -s 130 \"Searching Google for " + query + "\"";
            system(say.c_str());
            system(url.c_str());
        } else {
            cout << "Please specify what to search for.\n";
            system("espeak -s 130 \"Please specify what to search for\"");
        }
    }  //Opens ChatGpt and search
    else if(command.find("open chat gpt") != string::npos) {
        system("espeak -s 130 \"Opening Chatgpt\"");
        system("start https://chat.openai.com");
    }
    else if(command.find("ask chat gpt about") != string::npos) {
    int pos = command.find("ask chat gpt about");
    if (command.size() > pos + 18) {
        string query = command.substr(pos + 18);
        replace(query.begin(), query.end(), ' ', '+');
        string url = "start https://chat.openai.com/chat?q=" + query;
        string say = "espeak -s 130 \"Asking ChatGPT about " + query + "\"";
        system(say.c_str());
        system(url.c_str());
    } else {
        cout << "Please specify what to ask ChatGPT about.\n";
        system("espeak -s 130 \"Please specify what to ask ChatGPT about\"");
    }
    }  //Opens Notepad
    else if(command.find("open notepad") != string::npos) {
        system("espeak -s 130 \"Opening Notepad\" && start notepad");
    }
    else if(command.find("note") != string::npos) {
        system("espeak -s 130 \"What should I write?\"");
        system("python voice_input.py > note.txt");
        system("espeak -s 130 \"Note saved\"");
        system("start notepad note.txt");
    }  //Opens YouTube and plays video
    else if(command.find("open youtube") != string::npos) {
        system("espeak -s 130 \"Opening youtube\"");
        system("start https://www.youtube.com");
    }
    else if(command.find("search youtube for") != string::npos) {
        int pos = command.find("search youTube for");
        if (command.size() > pos + 18) {
            string query = command.substr(pos + 18);
            query.erase(0, query.find_first_not_of(" r"));
            replace(query.begin(), query.end(), ' ', '+');
            //string url = "start https://www.youtube.com/search?q=" + query;
            string say = "espeak -s 130 \"Searching YouTube for " + query + "\"";
            system(say.c_str());
            //system(url.c_str());
            
            string cmd = "python play_youtube.py \"" + query + "\"";
            system(cmd.c_str());
        } else {
            cout << "Please specify what to search for on YouTube\n";
            system("espeak -s 130 \"Please specify what to search for on YouTube\"");
        }
    }  //Opens whatsapp and messages a person
    else if(command.find("start whatsapp") != string::npos) {
        system("espeak -s 130 \"Opening WhatsApp\"");
        system("explorer.exe shell:AppsFolder\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App");
    }
    else if (command.find("open whatsapp and message") != string::npos && command.find("like") != string::npos) {
        int personStart = command.find("open whatsapp and message") + 25;
        int likePos = command.find("like");
        string person = command.substr(personStart, likePos - personStart - 1);
        string message = command.substr(likePos + 4);

        string say = "espeak -s 130 \"Messaging " + person + "\"";
        system(say.c_str());

        // Start WhatsApp desktop
        system("explorer.exe shell:AppsFolder\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App");

        // Python script to send message
        string cmd = "python send_whatsapp_message.py \"" + person + "\" \"" + message + "\"";
        system(cmd.c_str());
    }

    else if(command.find("exit") != string::npos) {
        system("espeak -s 130 \"Bye Avi\"");
    }
    else {
        system("espeak -s 130 \"Sorry, I did not understand the command..\"");
    }
}
