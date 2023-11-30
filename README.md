#PULSE OXIMETRY
A pulse oximeter measures your blood oxygen levels and pulse. A low level of oxygen saturation may occur if you have certain health conditions. Pulse oximetry is a noninvasive test that measures the oxygen saturation level of your blood. It can rapidly detect even small changes in oxygen levels. These levels show how efficiently blood is carrying oxygen to the extremities furthest from your heart, including your arms and legs. The pulse oximeter is a small, clip-like device. It attaches to a body part, most commonly to a finger.

#Photo-plethysmography
Photo-plethysmography(PPG) is a non-invasive testing method and is an essential tool in every physiological vascular testing examination. The PPG sensors transmit infra-red waveforms to the skin and detect the signals that are reflected back to the sensor from the skin. The skin partially absorbs the transmitted signals, and the reflected signals are a function of this light absorption, which in turn is a function of the local blood perfusion. Therefore, the PPG waveforms reflect local and relatively shallow skin variations in blood flow.

#ProtoCentral AF4490 based PPG/SpO2/HR shield for Arduino

![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/569dfbdf-766a-4481-bb21-e838bbbb7ea2)

The PPG or pulsating wave signals from [AFE4490](https://www.ti.com/lit/gpn/afe4490) Integrated Analog Front-End for Pulse Oximeters along with the PPG finger clip is used for calculating SPO2 and Heart Rate respectively.

SPO2:(SATURATION OF PERIPHERAL OXYGEN) 	the ratio of oxy-hemoglobin to the total concentration of hemoglobin present in the blood ![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/4d934328-069a-463e-9a9c-bb008e8c1b94)


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
