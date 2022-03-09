#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void blink_led(void *parameters);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    xTaskCreate(blink_led, "Blink", 128, nullptr, 2, nullptr);
}

void loop() {

}

_Noreturn void blink_led(void *parameters) {
    (void) parameters;

    while (true) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }
}
