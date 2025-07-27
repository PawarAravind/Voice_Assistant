VOICE ASSISTANT USING C++

Overview:

This project implements a simple yet powerful voice assistant in C++ that mimics basic features of Alexa or Siri on your PC. The assistant interacts using voice commands and responds via speech synthesis. It uses Python for speech recognition and integrates with system commands for browsing, note-taking, and web-based interactions.

Features:

- Voice-based activation and interaction
- Open websites (Google, ChatGPT, Youtube)
- Search Google via voice
- Ask ChatGPT via browser
- Plays YouTube videos
- Opens WhatsApp and can text peoples.
- Open Notepad
- Take and save voice notes
- Speak current time
- Greet the user based on time
- Exit via voice command
- Fully console-based operation

Commands Supported:

1. open google
2. search google for <query>
3. open chatgpt, ask chatgpt about <topic>
4. open notepad
5. note
6. what’s the time
7. open youtube, search youTube for <topic>
8. start WhatsApp and open WhatsApp and message <person> like <msg>
9. exit

How It Works:

> Voice Capture:
- `voice_input.py` uses Google's speech recognition API to convert voice into text
- 'play_youtube.py' uses webbrowser and pyautogui to open and play a video on youtube
- 'send_whatsapp_message.py' used for texting a person and the message

> C++ Logic:
- `main.cpp` calls Python scripts and reads voice command
- Greets based on time
- Delegates commands to `command_handler.cpp`

> Command Handler:
- Executes relevant commands using `system()` calls
- Uses `espeak` for speech output

Requirements:

- Windows OS (or WSL/Linux)
- C++ Compiler (MinGW/G++)
- Python 3.x
- Python Libraries:
  - `speechrecognition`
  - `pyaudio`
  - `requests` (optional)
- Tools:
  - `espeak` (for text-to-speech)
  - `VLC` (for music playback)

How to Compile:

g++ main.cpp command_handler.cpp -o assistant
./assistant

Usage Example:

Say:
- "search google for India independence"
- "ask chatgpt about AI ethics"
- "note"
- "exit"
