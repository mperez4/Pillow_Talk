// MAX9814 example code. It records 5 seconds every 2 seconds then prints it on the command line.

#define SAMPLE_RATE 16000     // Sample rate of 16 kHz
#define RECORDING_DURATION 4  // Record for 3 seconds
#define BUFFER_SIZE SAMPLE_RATE * RECORDING_DURATION  // Total number of samples to store
#define DELAY_MICROSECONDS 1000000 / SAMPLE_RATE

// Buffer to hold audio samples
int16_t sampleBuffer[BUFFER_SIZE];
int MIC_PIN = A4; // GPIO34 (ADC1 channel 6) for reading from the MAX9814

void setup() {
  // Start the Serial Monitor
  Serial.begin(500000);

  // Configure the ADC1
  analogReadResolution(12);   // Set the ADC resolution (ESP32 supports up to 12 bits)
  analogSetAttenuation(ADC_11db);  // Set attenuation for the ADC (11dB for 0-3.3V range)

  Serial.println("MAX9814 Microphone Initialized.");
}

void loop() {
  // Clear the sample buffer
  memset(sampleBuffer, 0, sizeof(sampleBuffer));

  // Record 5 seconds of audio
  Serial.println("Recording audio for 5 seconds...");
  unsigned long startTime = millis();
  for (int i = 0; i < BUFFER_SIZE; i++) {
    sampleBuffer[i] = analogRead(MIC_PIN);  // Read the analog input
    delayMicroseconds(DELAY_MICROSECONDS);  // Delay to match the sample rate
  }

  // Print all the recorded samples
  Serial.println("Printing all audio samples:");
  for (int i = 0; i < BUFFER_SIZE; i++) {
    Serial.print(sampleBuffer[i]);
    Serial.print(',');
  }
  Serial.println('\n');

  // Wait for 2 seconds before recording again
  Serial.println("Waiting for 2 seconds...");
  delay(2000);
}