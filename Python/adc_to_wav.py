"""
    Convert raw ADC data (from analog microphone [MAX9814]) to a WAV file.
"""

import wave
import struct

def adc_to_wav(adc_data, output_file, sample_rate, num_channels=1, bits_per_sample=16):

    # First, scale the 12-bit ADC data (0 to 4095) to 16-bit signed PCM (-32768 to 32767)
    pcm_data = [int((sample - 2048) * 16) for sample in adc_data]  # Scale 12-bit to 16-bit

    # Set up the WAV file parameters
    byte_rate = sample_rate * num_channels * (bits_per_sample // 8)
    
    # Create the WAV file
    with wave.open(output_file, 'wb') as wav_file:
        # Set parameters: number of channels, sample width, and sample rate
        wav_file.setnchannels(num_channels)  # Mono
        wav_file.setsampwidth(bits_per_sample // 8)  # 16-bit PCM is 2 bytes
        wav_file.setframerate(sample_rate)  # Set the sample rate

        # Pack the PCM data into a binary format that the WAV file can accept
        wav_data = struct.pack('<' + ('h' * len(pcm_data)), *pcm_data)

        # Write the packed data to the WAV file
        wav_file.writeframes(wav_data)

    print(f"WAV file '{output_file}' created successfully.")

# Example use
sample_rate = 9000 #sample rate should match the microcontrollers sample rate.

adc_data = [
    #PASTE MICROPHONE DATA HERE
]
# Convert the raw ADC data to a WAV file
output_file = "output.wav"
adc_to_wav(adc_data, output_file, sample_rate=sample_rate)