#include "arduinoFFT.h"
int datair[64]={578.2,
579.1,
577.8,
579.1,
579.6,
580.1,
578.7,
578.9,
580.4,
581,
581.6,
579.5,
578.9,
575.2,
572.4,
572.4,
569.9,
568.2,
566.8,
564.5,
561.6,
561.1,
559,
557.3,
556,
555,
554.4,
554.5,
554,
554.6,
555.1,
555.9,
557,
558,
558.6,
560.7,
561.8,
563,
564.9,
565.4,
564.8,
566.3,
567.6,
569.1,
571.3,
571.5,
572,
571.6,
571.1,
569.9,
569.7,
568.7,
570.4,
569.4,
568.3,
567.9,
568.3,
569.5,
568.6,
569.2,
569.6,
570.3,
571.8,
571.8,};

int datared[64]={428.4,
427.3,
427.8,
428,
429.5,
428.2,
428.3,
429.1,
429.3,
430.5,
430.5,
430.8,
428.5,
426.6,
423.4,
425,
422.6,
420.2,
420.1,
419.7,
417,
416,
414.9,
413.1,
413,
411.4,
412.7,
412.6,
411.9,
413.2,
412.9,
413.9,
414.1,
415.1,
415.3,
416.6,
417.9,
418.5,
420,
418.6,
419.5,
421.1,
421.9,
422.9,
424.2,
424.6,
425,
422.5,
423.6,
423.7,
423.1,
423,
423.5,
423,
422.2,
422.5,
422,
421.2,
421.7,
422.9,
422.9,
423.8,
424.3,
424.5,};

arduinoFFT FFT = arduinoFFT(); // Create FFT object
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 1;
const double samplingFrequency = 100;
double vRealred[samples];
double vImagred[samples];
double vRealir[samples];
double vImagir[samples];
double mari,ir,red,r,spo2;

void setup()
{
   Serial.begin(115200);
   while(!Serial);
   Serial.println("Ready");
}

void loop()
{
   /* Build raw data */

   // Number of signal cycles that the sampling will read
   double cycles = (((samples-1) * signalFrequency) / samplingFrequency);
   for (uint16_t i = 0; i < samples; i++)
   {
   /* Build data with positive and negative values*/
   vRealir[i] = datair[i];
   // vRealir[i] = uint8_t((amplitude * (sin((i * (twoPi * cycles)) / samples) + 1.0)) / 2.0);
   /* Build data displaced on the Y aris to include only positive values*/
   /* Imaginary part must be zeroed in case of looping to avoid wrong calculations and overflows */
   vImagir[i] = 0.0;
   }

/* Print the results of the simulated sampling according to time */
   //Serial.println("Data:");
   //PrintVector(vRealir, samples, SCL_TIME);

   /* Weigh data */
   FFT.Compute(vRealir, vImagir, samples, FFT_FORWARD); //Compute FFT
   //Serial.println("Computed Real values:");
   //PrintVector(vRealir, samples, SCL_INDEr);
   //Serial.println("Computed Imaginary values:");
   //PrintVector(vImagir, samples, SCL_INDEr);
   FFT.ComplexToMagnitude(vRealir, vImagir, samples/2); // Compute magnitudes
   //Serial.println("Computed magnitudes:");
   //PrintVector(vRealir, (samples >> 1), SCL_FREQUENCY);
   double mari = vRealir[1];
   for(int i=1;i<33;i++){
      if(mari<vRealir[i]){
        mari=vRealir[i];
        };
    };
   double ir=mari/vRealir[0];
   for (uint16_t i = 0; i < samples; i++)
   {
   /* Build data with positive and negative values*/
   vRealred[i] = datared[i];
   // vRealir[i] = uint8_t((amplitude * (sin((i * (twoPi * cycles)) / samples) + 1.0)) / 2.0);
   /* Build data displaced on the Y aris to include only positive values*/
   /* Imaginary part must be zeroed in case of looping to avoid wrong calculations and overflows */
   vImagred[i] = 0.0;
   }

/* Print the results of the simulated sampling according to time */
   //Serial.println("Data:");
//   PrintVector(vRealred, samples, SCL_TIME);

   /* Weigh data */
   FFT.Compute(vRealred, vImagred, samples, FFT_FORWARD); //Compute FFT
  // Serial.println("Computed Real values:");
//   PrintVector(vRealred, samples, SCL_INDEr);
  // Serial.println("Computed Imaginary values:");
//   PrintVector(vImagred, samples, SCL_INDEr);
   FFT.ComplexToMagnitude(vRealred, vImagred, samples/2); // Compute magnitudes
   //Serial.println("Computed magnitudes:");
   //PrintVector(vRealred, (samples >> 1), SCL_FREQUENCY);
   double marired = vRealred[1];
   for(int i=1;i<33;i++){
      if(mari<vRealred[i]){
        mari=vRealred[i];
        };
    };
   double red=marired/vRealred[0];
   //Serial.println(red);
   double r = red/ir;
   Serial.println("R value : ");
   Serial.println(r);
   double spo2= (-0.6612*(r*r*r*r))+(10.0537*(r*r*r))+(-35.8702*(r*r))+(12.8909*(r))+100.343;
   Serial.println("SpO2 value :");
   Serial.println(spo2);
   while(1);         
   // delay(2000);   
}
