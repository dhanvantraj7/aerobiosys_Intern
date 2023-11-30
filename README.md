# PULSE OXIMETRY
A pulse oximeter measures your blood oxygen levels and pulse. A low level of oxygen saturation may occur if you have certain health conditions. Pulse oximetry is a noninvasive test that measures the oxygen saturation level of your blood. It can rapidly detect even small changes in oxygen levels. These levels show how efficiently blood is carrying oxygen to the extremities furthest from your heart, including your arms and legs. The pulse oximeter is a small, clip-like device. It attaches to a body part, most commonly to a finger.

The device contains a photo detector and two light emitting diodes with different wavelengths (Red - 660nm and IR - 940nm). The light emitted by the didoes are absorbed by tissues and the amount of absorption is determined by the photodetector. Using these information the microprocessor determines the concentration of oxyhemoglobin(absorbs more IR) and deoxyhemoglobin(absorbs more red), then calculates the percentage of oxyhemoglobin and displays Spo2 and heart rate.

![Screenshot 2023-11-30 215435](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/c27d33aa-ab23-4073-ba11-87e046d3708a)

## Photo-plethysmography(PPG)
It is a low cost and non-invasive method that makes measurements at the surface of the skin. The technique provides valuable information related to our cardiovascular system. Recent advances in technology has revived interest in this technique, which is widely used in clinical physiological measurement and monitoring.

The voltage signal from PPG is proportional to the quantity of blood flowing through the blood vessels. Even small changes in blood volume can be detected using this method, though it cannot be used to quantify the amount of blood.

PPG Waveform shows the blood flow changes as a waveform with the help of a bar or a graph. The waveform has an alternating current (AC) component and a direct current (DC) component.

The AC component corresponds to variations in blood volume in syncronization with the heart beat. The DC component arises from the optical signals reflected or transmitted by the tissues and is determined by the tissue structure as well as venous and arterial blood volumes.

The DC component shows minor changes with respiration. The basic frequency of the AC component varies with the heart rate and is superimposed on the DC baseline.

![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/6b27697a-2e1d-421d-9c56-fddfa9da599e)
![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/0899f51f-b6ef-4ec0-9c1b-d068a56252ab)

## ProtoCentral AF4490 based PPG/SpO2/HR shield for Arduino

![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/569dfbdf-766a-4481-bb21-e838bbbb7ea2)

The PPG or pulsating wave signals from [AFE4490](https://www.ti.com/lit/gpn/afe4490) Integrated Analog Front-End for Pulse Oximeters along with the PPG finger clip is used for calculating SpO2 and Heart Rate respectively.

## SpO2
Oxygen saturation (SpO2) is a measurement of how much oxygen your blood is carrying as a percentage of the maximum it could carry. For a healthy individual, the normal SpO2 should be between 96% to 99%. The ratio of ratios used to estimate SpO2

![image](https://github.com/dhanvantraj7/aerobiosys_Intern/assets/143879823/1bf243bc-302e-4522-92fd-9ea7a1c8c4e6)
The SpO2 is calculated by (-0.6612 x (R)^4) + (10.0537 x (R)^3) + (-35.8702 x (R)^2) + (12.8909 x (R)) + 100.343

The code is given by: spo2.ino

## heart rate 
Heart rate is the number of times your heart beats per minute. A normal resting heart rate should be between 60 to 100 beats per minute, but it can vary from minute to minute. The heart rate per minute is calculated by (sampling rate/(distance between consecutive peaks)) x 60

The code is given by: heart_rate.ino

## General algorithm of FFT

### Setup Section

- George Washington
* John Adams
+ Thomas Jefferson

-Initializes serial communication for debugging.
+Waits until a serial connection is established before proceeding.

### Loop Section
-Constructs the input data arrays vRealir and vRealred with the acquired signal data (presumably from datair[] and datared[] arrays).
*Calls the FFT.Compute() function to perform the FFT on the input data for both IR and red signals.
*Calls FFT.ComplexToMagnitude() to calculate the magnitudes of the FFT results.
*Searches for the maximum magnitude value (the peak) in the calculated magnitudes for both IR and red signals.
*Calculates the red-to-IR ratio (r) using the maximum magnitudes of the red and IR signals.
+Computes the SpO2 value using a polynomial equation involving the calculated r value.
