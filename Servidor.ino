// Código usado para mandar a requisição http://SEU-IP/LED_ON e acender TODOS os LEDs por 1 minuto

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA_DA_REDE";

const int buttonPin = 5;
bool buttonState = HIGH;
bool lastButtonState = HIGH;

WiFiClient wifiClient;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http1, http2, http3, http4;

      http1.begin(wifiClient, "http://SEU-IP1/LED_ON");
      http2.begin(wifiClient, "http://SEU-IP2/LED_ON");
      http3.begin(wifiClient, "http://SEU-IP3/LED_ON");
      http4.begin(wifiClient, "http://SEU-IP4/LED_ON");

      http1.GET();
      http2.GET();
      http3.GET();
      http4.GET();

      http1.end();
      http2.end();
      http3.end();
      http4.end();

      Serial.println("Comandos enviados para os quatro IPs.");
    } else {
      Serial.println("Erro: não conectado ao Wi-Fi");
    }

    delay(500);
  }

  lastButtonState = buttonState;
}
