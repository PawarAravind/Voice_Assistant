import webbrowser
import pyautogui
import sys
import time

if len(sys.argv) < 2:
    print("No search query provided")
    sys.exit()

query = sys.argv[1]
url = f"https://www.youtube.com/results?search_query={query}"
webbrowser.open(url)

# Give time for the page to load
time.sleep(3)

# Move to first video and click (tune coordinates if needed)
# These are default coordinates for 1920x1080 resolution
    #print("Move mouse to the first video thumbnail in next 5 seconds...") #To know coordinates if moveTo don't work
    #time.sleep(5)
    #print("Mouse position:", pyautogui.position())
    #sys.exit()
pyautogui.moveTo(670, 780)  # 400,400-for first video
pyautogui.click()
