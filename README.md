# aerobiosys_Intern
PULSE OXIMETRY
The processing of PPG(Photoplethysmogram) a pulsating wave signals from [AFE4490](https://www.ti.com/lit/gpn/afe4490) Integrated Analog Front-End, IR sensors and performing a FFT(Fast Fourier Transform) analysis to calculate the SpO2 value. The code appears to be calculating the SpO2 value based on the red and infrared signal magnitudes.

Setup Section
Initializes serial communication for debugging.
Waits until a serial connection is established before proceeding.
Loop Section
Constructs the input data arrays vRealir and vRealred with the acquired signal data (presumably from datair[] and datared[] arrays).
Calls the FFT.Compute() function to perform the FFT on the input data for both IR and red signals.
Calls FFT.ComplexToMagnitude() to calculate the magnitudes of the FFT results.
Searches for the maximum magnitude value (the peak) in the calculated magnitudes for both IR and red signals.
Calculates the red-to-IR ratio (r) using the maximum magnitudes of the red and IR signals.
Computes the SpO2 value using a polynomial equation involving the calculated r value.
