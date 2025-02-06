#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Wokwi-GUEST";    
const char* password = "";           

const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic = "home/commands";

#define LED1_PIN 23  
#define LED2_PIN 22
#define LED3_PIN 21  
#define LED4_PIN 19  
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);

  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Message: ");
  Serial.println(message);
  if (message == "LED1=ON") {
    digitalWrite(LED1_PIN, HIGH);
    Serial.println("LED1 turned ON");
  } else if (message == "LED1=OFF") {
    digitalWrite(LED1_PIN, LOW);
    Serial.println("LED1 turned OFF");
  } else if (message == "LED2=ON") {
    digitalWrite(LED2_PIN, HIGH);
    Serial.println("LED2 turned ON");
  } else if (message == "LED2=OFF") {
    digitalWrite(LED2_PIN, LOW);
    Serial.println("LED2 turned OFF");
  } else if (message == "LED3=ON") {
    digitalWrite(LED3_PIN, HIGH);
    Serial.println("LED3 turned ON");
  } else if (message == "LED3=OFF") {
    digitalWrite(LED3_PIN, LOW);
    Serial.println("LED3 turned OFF");
  } else if (message == "LED4=ON") {
    digitalWrite(LED4_PIN, HIGH);
    Serial.println("LED4 turned ON");
  } else if (message == "LED4=OFF") {
    digitalWrite(LED4_PIN, LOW);
    Serial.println("LED4 turned OFF");
  } else if (message == "FAN=ON") {
    digitalWrite(LED4_PIN, HIGH);   
    Serial.println("Fan turned ON");
  } else if (message == "FAN=OFF") {
    digitalWrite(LED4_PIN, LOW);    
    Serial.println("Fan turned OFF");
  } else {
    Serial.println("Unknown command");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    
    String clientId = "ESP32Client-";
    clientId += String(WiFi.macAddress());

    if (client.connect(clientId.c_str())) {  
      Serial.println("Connected to MQTT broker");
      client.subscribe(mqtt_topic);
      Serial.print("Subscribed to topic: ");
      Serial.println(mqtt_topic);
    } else {
      Serial.print("Failed to connect. Retry in 5 seconds. Error code: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
