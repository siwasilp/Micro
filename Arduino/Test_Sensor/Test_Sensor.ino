/*

  read analog data from A1-A5 and send to PC via Serial port

*/



int sensor_1 , sensor_2 , sensor_3 , sensor_4 , sensor_5 ; //optical sensor values

String tmp ;

int ADC_stabilize = 5 ;



void setup ( ) {

  // initialize the serial communication:

  Serial . begin ( 115200 ) ;

}



void loop ( ) {

  //take a snapshot

  sensor_1 = digitalRead ( A1 ) ;

  delay ( ADC_stabilize ) ; //stabilize

  sensor_1 = digitalRead ( A1 ) ;

  delay ( ADC_stabilize ) ;



  sensor_2 = digitalRead ( A2 ) ;

  delay ( ADC_stabilize ) ;

  sensor_2 = digitalRead ( A2 ) ;

  delay ( ADC_stabilize ) ;



  sensor_3 = digitalRead ( A3 ) ;

  delay ( ADC_stabilize ) ;

  sensor_3 = digitalRead ( A3 ) ;

  delay ( ADC_stabilize ) ;



  sensor_4 = digitalRead ( A4 ) ;

  delay ( ADC_stabilize ) ;

  sensor_4 = digitalRead ( A4 ) ;

  delay ( ADC_stabilize ) ;



  sensor_5 = digitalRead ( A5 ) ;

  delay ( ADC_stabilize ) ;

  sensor_5 = digitalRead ( A5 ) ;

  delay ( ADC_stabilize ) ;



  tmp = " S1=" + String ( sensor_1 ) + " S2=" + String ( sensor_2 ) + " S3=" + String ( sensor_3 ) + " S4=" + String ( sensor_4 ) + " S5=" + String ( sensor_5 ) ;



  // send the value of analog inputs:

  Serial . println ( tmp ) ;



  // wait a bit for next reading

  delay ( 1000 ) ; //1000=1 sec


}
