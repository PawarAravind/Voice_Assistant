
import speech_recognition as sr

r = sr.Recognizer()
with sr.Microphone() as source:
    audio = r.listen(source)

try:
    command = r.recognize_google(audio)
    print(command.lower())
except:
    print("Could not understand")
