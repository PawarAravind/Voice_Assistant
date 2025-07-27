import pyautogui
import time
import sys

if len(sys.argv) < 3:
    print("Usage: python send_whatsapp_message.py <person> <message>")
    sys.exit()

person = sys.argv[1]
message = sys.argv[2]

# Wait for WhatsApp to load
time.sleep(5)

# Adjust the following coordinates based on your screen

# Click search bar
pyautogui.moveTo(150, 150)  # <-- You MUST update this if this coordinate don't work
pyautogui.click()
time.sleep(1)

# Type person name
pyautogui.write(person)
time.sleep(1)
pyautogui.press("enter")
time.sleep(1)

pyautogui.moveTo(150, 200)  # <-- You MUST update this if this coordinate don't work
pyautogui.click()
time.sleep(1)

# Type and send message
pyautogui.write(message)
pyautogui.press("enter")
