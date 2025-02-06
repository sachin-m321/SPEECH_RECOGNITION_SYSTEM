# SPEECH_RECOGNITION_SYSTEM
COMPANY : CODETECH IT SOLUTIONS

NAME : SACHINN M

INTERN ID : CT08LTG

DOMAIN : EMBEDDED SYSTEMS

DURATION : 4 WEEKS

MENTORS : NEELA SANTOSH KUMAR

Description :

This program enables the ESP32 to control four LEDs and a fan remotely via MQTT over Wi-Fi, making it suitable for home automation. By subscribing to the MQTT topic home/commands, the ESP32 listens for specific commands like "LED1=ON" or "FAN=OFF" to control the state of the connected devices. The ESP32 connects to the Wi-Fi network and the MQTT broker (HiveMQ), and when a message is received, the corresponding device (LED or fan) is turned on or off. The program supports various commands for controlling each LED and the fan, providing real-time feedback via the serial monitor. To integrate voice recognition, an external voice module such as the Elechouse Voice Recognition Module V3 can be used, allowing the ESP32 to understand voice commands. With this integration, the user can control the devices by simply speaking commands like "LED1 ON" or "Fan OFF." The ESP32 listens for these voice commands through serial communication, then executes the corresponding actions, such as toggling LEDs or controlling the fan.Alternatively, cloud-based voice recognition services like Google Assistant or Amazon Alexa can be used to send MQTT messages, allowing voice control through these platforms. This integration would enhance the project's functionality, combining both MQTT and voice commands for easy device management.

OUTPUT:![Image](https://github.com/user-attachments/assets/2ce4f38b-2986-48e4-9786-4dfe4883d9f9)
