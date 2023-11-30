float data[128]={7793,
7769,
7791,
7845,
7891,
7924,
7922,
7637,
7553,
7716,
7775,
7779,
7817,
7855,
7904,
7933,
7848,
7600,
7614,
7770,
7777,
7789,
7818,
7876,
7898,
7957,
7797,
7561,
7648,
7804,
7757,
7798,
7831,
7883,
7921,
7953,
7727,
7563,
7688,
7812,
7745,
7807,
7839,
7883,
7915,
7917,
7651,
7567,
7716,
7796,
7768,
7814,
7851,
7907,
7948,
7855,
7601,
7610,
7748,
7780,
7786,
7821,
7851,
7906,
7952,
7809,
7559,
7639,
7793,
7759,
7783,
7840,
7879,
7915,
7959,
7727,
7565,
7684,
7793,
7769,
7800,
7848,
7884,
7931,
7927,
7675,
7552,
7708,
7800,
7771,
7815,
7850,
7896,
7931,
7886,
7609,
7592,
7753,
7779,
7781,
7827,
7870,
7901,
7947,
7814,
7565,
7640,
7797,
7774,
7791,
7835,
7875,
7917,
7954,
7739,
7564,
7679,
7795,
7763,
7805,
7838,
7888,
7922,
7946,
7686,
7565,
7706,
7794,};
float d[128];
int y=0;
int index[20];
float peaks[20];
float x[10];
float sum=0;
float temp,temp1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println("avg values");
  for(int i=0;i<125;i++){
   data[i]=(data[i]+data[i+1]+data[i+2]+data[i+3])/4;
  // Serial.println(data[i]);
  }
 // Serial.println("derivative values");
   for(int i=0;i<124;i++){
    d[i]=data[i+1]-data[i];
    //Serial.println(d[i]);
   }
    //Serial.println("derivative avg");
    for(int i=0;i<125;i++){
    d[i]=(d[i]+d[i+1]+d[i+2]+d[i+3])/4;
    //Serial.println(d[i]);
    }
    for(int i=0;i<125;i++){
      if(d[i]>0){
        d[i]=0;
      }
    }
    for(int i=0;i<120;i++){
      d[i]=(d[i+1]-d[i])*2;
      //Serial.println(d[i]);
    }
    
   // Serial.println("peaks");
    for(int i=1;i<120;i++){
      if(d[i-1]>d[i]&&d[i+1]>d[i]&&d[i]<-15)
      {
        index[y]=i;
        peaks[y]=d[i];
        //Serial.print(index[y]);
       // Serial.print("\t");
       // Serial.println(peaks[y]);
        y=y+1;
      }}
      for(int i=0;i<y-1;i++){
       index[i]=index[1+i]-index[i];
       x[i]=(60000)/(30.3*index[i]);
      // Serial.println(x[i]);
       //Serial.println(y);
      }
    for(int i=0;i<y-1;i++){
      sum=sum+x[i];
        
    }
    sum=sum/(y-1);
   // Serial.println(sum);
      Serial.print("HR=");
      Serial.println(sum);
    
       
       
    
  while(1);
}
