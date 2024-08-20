import customtkinter as ctk
import requests
import threading

def acender_led(url):
    requests.get(url)

def acender_led_thread(url):
    threading.Thread(target=acender_led, args=(url,)).start()

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

app = ctk.CTk()
app.title("Acender LED")
app.geometry("240x240")
app.resizable(False, False)

button_size = 100

btn_led1 = ctk.CTkButton(app, text="LED 1", command=lambda: acender_led_thread('http://SEU-IP1/LED_ON'), width=button_size, height=button_size)
btn_led1.grid(row=0, column=0, padx=10, pady=10)

btn_led2 = ctk.CTkButton(app, text="LED 2", command=lambda: acender_led_thread('http://SEU-IP2/LED_ON'), width=button_size, height=button_size)
btn_led2.grid(row=0, column=1, padx=10, pady=10)

btn_led3 = ctk.CTkButton(app, text="LED 3", command=lambda: acender_led_thread('http://SEU-IP3/LED_ON'), width=button_size, height=button_size)
btn_led3.grid(row=1, column=0, padx=10, pady=10)

btn_led4 = ctk.CTkButton(app, text="LED 4", command=lambda: acender_led_thread('http://SEU-IP4/LED_ON'), width=button_size, height=button_size)
btn_led4.grid(row=1, column=1, padx=10, pady=10)

app.mainloop()
