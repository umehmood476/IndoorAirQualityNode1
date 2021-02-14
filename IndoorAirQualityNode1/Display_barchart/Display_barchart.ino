//     Aeras Version 1.0.1
//     Air Quality Monitoring with onboard display
//     Date: 07/12/2020
//     Author: Abdul Muqeet

//========== Libraries ==========

#include <TFT_HX8357.h>
#include "Free_Fonts.h"




//========== Initializers ========

TFT_HX8357 tft = TFT_HX8357();



//================================
//             SETUP
//================================

const int buttonPin = 12; 
int buttonState = 0; 


const int rpin = 7;

const int ypin = 6;
const int gpin = 5;




int ind1, ind2,ind3,ind4,ind5,ind6,ind7,ind8;
String str1,str2,str3,str4,str5,str6,str7,str8;





void setup() {

 pinMode(buttonPin, INPUT);
 pinMode(rpin, OUTPUT);
 pinMode(ypin, OUTPUT);
 pinMode(gpin, OUTPUT);
 digitalWrite(4, LOW);

 digitalWrite(rpin, LOW);
 digitalWrite(ypin, LOW);
 digitalWrite(gpin, LOW);

 
 digitalWrite(11, HIGH);
  
  tft.begin();
  tft.setRotation(1);

//=========== LCD Background Objects ===========
  tft.fillScreen(TFT_WHITE);
 // tft.fillRoundRect(5,4,150,250,20,TFT_YELLOW);

  tft.setTextColor(TFT_PURPLE);
  tft.setCursor(55,39);
  tft.setTextSize(1);
  tft.setFreeFont(FF35);
  tft.print(" INDOOR AIR QUALITY ");

 



tft.fillRect(0,80,480,240,TFT_WHITE);





 Serial1.begin(9600);
  Serial.begin(9600);
}

//=======================================
//             LOOP
//=======================================

void loop() {





  

  String str1="",str2="",str13="",str4="",str5="",str6="",str7="",str8="";
Serial1.write("s");
   if(Serial1.available()>0){


//tft.fillRect(0,90,480,65,TFT_WHITE);
  //tft.fillRect(0,225,480,65,TFT_WHITE);
  
   String readvalue="";
   int checksum =0;

      readvalue=  Serial1.readStringUntil('*');
     
     
      Serial.println(readvalue);
       checksum = readvalue.length();
      Serial.println(checksum);
if( 30 < checksum <= 33 ){

  
      ind1=readvalue.indexOf('&');
      str1=readvalue.substring(0,ind1);
      Serial.println(str1);
      
      ind2=readvalue.indexOf('&',ind1+1);
      str2=readvalue.substring(ind1+1,ind2);
      Serial.println(str2);

      ind3=readvalue.indexOf('&',ind2+1);
      str3=readvalue.substring(ind2+1,ind3);
      Serial.println(str3);

      ind4=readvalue.indexOf('&',ind3+1);
      str4=readvalue.substring(ind3+1,ind4);
      Serial.println(str4);

      ind5=readvalue.indexOf('&',ind4+1);
      str5=readvalue.substring(ind4+1,ind5);
      Serial.println(str5);

      ind6=readvalue.indexOf('&',ind5+1);
      str6=readvalue.substring(ind5+1,ind6);
      Serial.println(str6);

      ind7=readvalue.indexOf('&',ind6+1);
      str7=readvalue.substring(ind6+1,ind7);
      Serial.println(str7);

      ind8=readvalue.indexOf('&',ind7+1);
      str8=readvalue.substring(ind7+1,ind8);
      Serial.println(str8);

     






//int var = str2.compareTo(str6);
//Serial.print("comparison value is:");
//Serial.println(var);


      float temp = str1.toFloat();

float pm25 = str2.toFloat();

float nh3 = str3.toFloat();

float co = str4.toFloat();

float hum = str5.toFloat();

float co2 = str6.toFloat();

float no2 = str7.toFloat();

float ch4 = str8.toFloat();

if(pm25>=55 || ch4>= 150 ||  co>=12.4 )
{
  digitalWrite(rpin, HIGH);
  digitalWrite(gpin, LOW);
  digitalWrite(ypin, LOW);
  
  }
else if(55>pm25>=35 || 150>ch4>=100  ||  12.4>co>=9.4)
{
  digitalWrite(rpin, LOW);
  digitalWrite(gpin, LOW);
  digitalWrite(ypin, HIGH);
  
  }
else
{
  digitalWrite(rpin, LOW);
  digitalWrite(gpin, HIGH);
  digitalWrite(ypin, LOW);
  
  }

  


Serial.println("correct values updated");

buttonState = digitalRead(buttonPin);

if (buttonState == 0){
tft.fillRect(0,40,480,280,TFT_WHITE);

  tft.setTextColor(TFT_PURPLE);
  tft.setCursor(48, 80);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("TEMP");

 // tft.setTextColor(TFT_PURPLE);
  tft.setCursor(186, 80);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("PM2.5");

  tft.setCursor(334, 80);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CO");

//  tft.setCursor(398, 80);
//  tft.setTextSize(0.5);
//  tft.setFreeFont(FF34);
//  tft.print("CO");




  


  tft.setCursor(68, 170);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("'C");

  tft.setCursor(186, 170);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("ug/m3");

  tft.setCursor(334, 170);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("ppm");

//  tft.setCursor(395, 170);
//  tft.setTextSize(0.5);
//  tft.setFreeFont(FF34);
//  tft.print("ppm");




tft.setCursor(48, 215);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("HUMD");

 // tft.setTextColor(TFT_PURPLE);
  tft.setCursor(196, 215);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CO2");

  tft.setCursor(334, 215);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CH4");

//  tft.setCursor(393, 215);
//  tft.setTextSize(0.5);
//  tft.setFreeFont(FF34);
//  tft.print("CH4");




  


  tft.setCursor(68, 305);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("%");

  tft.setCursor(196, 305);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("ppm");

  tft.setCursor(334, 305);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("ppm");

//  tft.setCursor(389, 305);
//  tft.setTextSize(0.5);
//  tft.setFreeFont(FF34);
//  tft.print("ppm");











  
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(50,110);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str1);


   tft.setTextColor(TFT_BLACK);
  tft.setCursor(185,110);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str2);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(310,110);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str4);

//   tft.setTextColor(TFT_BLACK);
//  tft.setCursor(375,110);
//  tft.setTextSize(1);
//  tft.setTextFont(6);
//  tft.print(str4);




   tft.setTextColor(TFT_BLACK);
  tft.setCursor(50,245);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str5);


   tft.setTextColor(TFT_BLACK);
  tft.setCursor(185,245);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str6);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(310,245);
  tft.setTextSize(1);
  tft.setTextFont(6);
  tft.print(str8);

//   tft.setTextColor(TFT_BLACK);
//  tft.setCursor(375,245);
//  tft.setTextSize(1);
//  tft.setTextFont(6);
//  tft.println(str8);



//Color Coding

////---- for temperature ----
 if(temp > 0 && temp  <=30 ){

   tft.fillRect(50,90,70,7,TFT_GREEN);
 }else if(temp  > 30 && temp  <= 40){

   tft.fillRect(50,90,70,7,TFT_YELLOW);
 }else if(temp  > 40 && temp  <= 50){
tft.fillRect(30,90,70,7,TFT_ORANGE);

 }else if(temp  > 50 && temp  <= 60){

tft.fillRect(50,90,70,7,TFT_RED);
   
  }else if(temp  > 60 && temp  <= 70){
tft.fillRect(50,90,70,7,TFT_PURPLE);

  }else if(temp  > 70 && temp  <= 500){
tft.fillRect(50,90,70,7,TFT_MAROON);
 }

////---- for pm25 ----
 if(pm25 > 0 && pm25  <=12 ){

   tft.fillRect(180,90,70,7,TFT_GREEN);
 }else if(pm25  > 12 && pm25  <= 35.4){

   tft.fillRect(180,90,70,7,TFT_YELLOW);
 }else if(pm25  > 35.4 && pm25  <= 55.4){
tft.fillRect(180,90,70,7,TFT_ORANGE);

 }else if(pm25  > 55.4 && pm25  <= 150.4){

tft.fillRect(180,90,70,7,TFT_RED);
   
  }else if(pm25  > 150.4 && pm25  <= 250.4){
tft.fillRect(180,90,70,7,TFT_PURPLE);

  }else if(pm25  > 250.4 && pm25  <= 400){
tft.fillRect(180,90,70,7,TFT_MAROON);
 }

//////---- for nh3 ----
// if(nh3 >= 0 && nh3  <=200 ){
//
//   tft.fillRect(255,90,70,7,TFT_GREEN);
// }else if(nh3  > 200 && nh3  <= 400){
//
//   tft.fillRect(255,90,70,7,TFT_YELLOW);
// }else if(nh3  > 400 && nh3  <= 800){
//tft.fillRect(255,90,70,7,TFT_ORANGE);
//
// }else if(nh3 > 800 && nh3  <= 1200){
//
//tft.fillRect(255,90,70,7,TFT_RED);
//   
//  }else if(nh3  > 1200 && nh3  <= 1800){
//tft.fillRect(255,90,70,7,TFT_PURPLE);
//
//  }else if(nh3  > 1800 && nh3  <= 2500){
//tft.fillRect(255,90,70,7,TFT_MAROON);
// }

////---- for co ----
 if(co > 0 && co  <=4.4 ){

   tft.fillRect(315,90,70,7,TFT_GREEN);
 }else if(co  > 4.4 && co  <= 9.4){

   tft.fillRect(315,90,70,7,TFT_YELLOW);
 }else if(co  > 9.4 && co  <= 12.4){
tft.fillRect(315,90,70,7,TFT_ORANGE);

 }else if(co  > 12.4 && co  <= 15.4){

tft.fillRect(315,90,70,7,TFT_RED);
   
  }else if(co  > 15.4 && co  <= 30.4){
tft.fillRect(315,90,70,7,TFT_PURPLE);

  }else if(co  > 30.4 && co  <= 5000){
tft.fillRect(315,90,70,7,TFT_MAROON);
 }

////---- for hum ----
 if(hum > 0 && hum  <=30 ){

   tft.fillRect(50,225,70,7,TFT_GREEN);
 }else if(hum  > 30 && hum  <= 40){

   tft.fillRect(50,225,70,7,TFT_YELLOW);
 }else if(hum  > 40 && hum  <= 50){
tft.fillRect(50,225,70,7,TFT_ORANGE);

 }else if(hum  > 50 && hum  <= 60){

tft.fillRect(50,90,70,7,TFT_RED);
   
  }else if(hum  > 60 && hum  <= 70){
tft.fillRect(50,225,70,7,TFT_PURPLE);

  }else if(hum  > 70 && hum  <= 500){
tft.fillRect(50,225,70,7,TFT_MAROON);
 }

////---- for co2 ----
 if(co2 > 0 && co2  <=1000 ){

   tft.fillRect(180,225,70,7,TFT_GREEN);
 }else if(co2  > 1000 && co2  <= 2000){

   tft.fillRect(180,225,70,7,TFT_YELLOW);
 }else if(co2  > 2000 && co2  <= 5000){
tft.fillRect(180,225,70,7,TFT_ORANGE);

 }else if(co2  > 5000 && co2  <= 10000){

tft.fillRect(180,225,70,7,TFT_RED);
   
  }else if(co2  > 10000 && co2  <= 20000){
tft.fillRect(180,225,70,7,TFT_PURPLE);

  }else if(co2  > 20000 && co2  <= 50000000){
tft.fillRect(180,225,70,7,TFT_MAROON);
 }

////---- for no2 ----
// if(no2 > 0 && no2 <=0.053 ){
//
//   tft.fillRect(315,225,70,7,TFT_GREEN);
// }else if(no2  > 0.053 && no2  <= 0.1){
//
//   tft.fillRect(315,225,70,7,TFT_YELLOW);
// }else if(no2  > 0.1 && no2  <= 0.36){
//tft.fillRect(315,225,70,7,TFT_ORANGE);
//
// }else if(no2 > 0.36 && no2  <= 0.65){
//
//tft.fillRect(315,225,70,7,TFT_RED);
//   
//  }else if(no2  > 0.65 && no2  <= 1.24){
//tft.fillRect(315,225,70,7,TFT_PURPLE);
//
//  }else if(no2  > 1.24 && no2  <= 500){
//tft.fillRect(315,225,70,7,TFT_MAROON);
// }

////---- for ch4 ----
 if(ch4 > 0 && ch4  <=50 ){

   tft.fillRect(315,225,70,7,TFT_GREEN);
}else if(ch4  > 50 && ch4  <= 100){

   tft.fillRect(315,225,70,7,TFT_YELLOW);
 }else if(ch4  > 100 && ch4  <= 150){
tft.fillRect(315,225,70,7,TFT_ORANGE);

 }else if(ch4 > 150 && ch4  <= 200){

tft.fillRect(315,225,70,7,TFT_RED);
 
 }else if(ch4 > 200 && ch4  <= 300){
tft.fillRect(315,225,70,7,TFT_PURPLE);

 }else if(ch4  > 300 && ch4  <= 5000){
tft.fillRect(315,225,70,7,TFT_MAROON);
 }

 delay(60000);
}

else if (buttonState == 1){
  
tft.fillRect(0,40,480,280,TFT_WHITE);


  tft.setTextColor(TFT_PURPLE);
  tft.setCursor(25, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("TEM");
  
tft.setCursor(95, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("HUM");

  tft.setCursor(170, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("DUS");

  tft.setCursor(245, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CO2");

  tft.setCursor(324, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CH4");

  
  tft.setCursor(410, 65);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print("CO");

  tft.setCursor(35, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("'C");

  tft.setCursor(110, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("%");

  tft.setCursor(170, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("ug/m3");

  tft.setCursor(245, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("ppm");

  tft.setCursor(320, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("ppm");

  tft.setCursor(410, 318);
  tft.setTextSize(0.3);
  tft.setFreeFont(FF34);
  tft.print("ppm");




  tft.setTextColor(TFT_BLACK);
  tft.setCursor(30,295);
 tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str1);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(110,295);
tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str5);
  
   tft.setTextColor(TFT_BLACK);
  tft.setCursor(175,295);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str2);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(245,295);
tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str6);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(320,295);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str8);

   tft.setTextColor(TFT_BLACK);
  tft.setCursor(410,295);
  tft.setTextSize(0.5);
  tft.setFreeFont(FF34);
  tft.print(str4);

  
//Color Coding

////---- for temperature ----
 if(temp > 0 && temp  <=30 ){
 int var = ((temp-0)/30)*55;
   tft.fillRect(28,270,50,-var,TFT_GREEN);
 }
 else if(temp  > 30 && temp  <= 40){
int var = ((temp-30)/10)*45;
   tft.fillRect(28,270,50,-(55+var),TFT_YELLOW);
 }
 else if(temp  > 40 && temp  <= 50){
  int var = ((temp-40)/10)*35;
tft.fillRect(28,270,50,-(100+var),TFT_ORANGE);

 }
 else if(temp  > 50 && temp  <= 60){
  int var = ((temp-50)/10)*30;

tft.fillRect(28,270,50,-(135+var),TFT_RED);
   
  }
  else if(temp  > 60 && temp  <= 70){
    int var = ((temp-60)/10)*25;
tft.fillRect(28,270,50,-(165+var),TFT_PURPLE);

  }
  else if(temp  > 70 && temp  <= 500){
    int var = ((temp-70)/430)*25;
tft.fillRect(28,270,50,-(190+var),TFT_MAROON);
 }


////---- for hum ----
 if(hum > 0 && hum  <=30 ){
int var = ((hum-0)/30)*55;
   tft.fillRect(103,270,50,-var,TFT_GREEN);
 }
 else if(hum  > 30 && hum  <= 40){
int var = ((hum-30)/10)*45;
   tft.fillRect(103,270,50,-(55+var),TFT_YELLOW);
 }
 else if(hum  > 40 && hum  <= 50){
  int var = ((hum-40)/10)*35;
tft.fillRect(103,270,50,-(100+var),TFT_ORANGE);

 }
 else if(hum  > 50 && hum  <= 60){
int var = ((hum-50)/10)*30;
tft.fillRect(103,270,50,-(135+var),TFT_RED);
   
  }
  else if(hum  > 60 && hum  <= 70){
    int var = ((hum-60)/10)*25;
tft.fillRect(103,270,50,-(165+var),TFT_PURPLE);

  }
  else if(hum  > 70 && hum  <= 100){
    int var = ((hum-70)/30)*25;
tft.fillRect(103,270,50,-(190+var),TFT_MAROON);
 }

 

////---- for pm25 ----
 if(pm25 > 0 && pm25  <=12 ){
int var = ((pm25-0)/12)*55;
   tft.fillRect(178,270,50,-(var),TFT_GREEN);
 }
 else if(pm25  > 12 && pm25  <= 35.4){
  
 int var = ((pm25-12)/23.4)*45;

   tft.fillRect(178,270,50,-(55+var),TFT_YELLOW);
 }
 else if(pm25  > 35.4 && pm25  <= 55.4){
  
    
int var = ((pm25-35.4)/20)*35;
  
tft.fillRect(178,270,50,-(100+var),TFT_ORANGE);

 }
 else if(pm25  > 55.4 && pm25  <= 150.4){
int var = ((pm25-55.4)/95)*30;
tft.fillRect(178,270,50,-(135+var),TFT_RED);
   
  }
  else if(pm25  > 150.4 && pm25  <= 250.4){
    int var = ((pm25-150.4)/100)*25;
tft.fillRect(178,270,50,-(165+var),TFT_PURPLE);

  }
  else if(pm25  > 250.4 && pm25  <= 400){
    int var = ((pm25-250.4)/150)*25;
tft.fillRect(178,270,50,-(190+var),TFT_MAROON);
 }

////---- for co2 ----
 if(co2 > 0 && co2  <=1000 ){
int var = ((co2-0)/1000)*55;
   tft.fillRect(253,270,50,-(var),TFT_GREEN);
 }
 else if(co2  > 1000 && co2  <= 2000){
  int var = ((co2-1000)/1000)*45;

   tft.fillRect(253,270,50,-(55+var),TFT_YELLOW);
 }
 else if(co2  > 2000 && co2  <= 5000){
  int var = ((co2-2000)/3000)*35;
tft.fillRect(253,270,50,-(100+var),TFT_ORANGE);

 }
 else if(co2  > 5000 && co2  <= 10000){
int var = ((co2-5000)/5000)*30;
tft.fillRect(253,270,50,-(135+var),TFT_RED);
   
  }else if(co2  > 10000 && co2  <= 20000){
    int var = ((co2-10000)/10000)*25;
tft.fillRect(253,270,50,-(165+var),TFT_PURPLE);

  }
  else if(co2  > 20000 && co2  <= 50000){
    int var = ((co2-20000)/30000)*25;
tft.fillRect(253,270,50,-(190+var),TFT_MAROON);
 }




////---- for ch4 ----
 if(ch4 > 0 && ch4 <=50 ){
int var = ((ch4-0)/50)*55;
   tft.fillRect(328,270,50,-(var),TFT_GREEN);
 }
 else if(ch4  > 50 && ch4  <= 100){
int var = ((ch4-50)/50)*45;
   tft.fillRect(328,270,50,-(55+var),TFT_YELLOW);
 }
 else if(ch4  > 100 && ch4  <= 150){
  int var = ((ch4-100)/50)*35;
tft.fillRect(328,270,50,-(100+var),TFT_ORANGE);

 }
 else if(ch4 > 150 && ch4  <= 200){
int var = ((ch4-150)/50)*30;
tft.fillRect(328,270,50,-(135+var),TFT_RED);
   
  }else if(ch4  > 200 && ch4  <= 300){
    int var = ((ch4-200)/100)*25;
tft.fillRect(328,270,50,-(165+var),TFT_PURPLE);

  }
  else if(ch4  > 300 && ch4  <= 1000000000){
    int var = ((ch4-300)/9700)*9.76;
tft.fillRect(328,270,50,-(190+var),TFT_MAROON);
 }


////---- for co ----
 if(co > 0 && co  <=4.4 ){
int var = ((co-0)/4.4)*55;
   tft.fillRect(403,270,50,-(var),TFT_GREEN);
 }
 else if(co  > 4.4 && co  <= 9.4){
int var = ((co-4.4)/5)*45;
   tft.fillRect(403,270,50,-(55+var),TFT_YELLOW);
 }
 else if(co  > 9.4 && co  <= 12.4){
  int var = ((co-9.4)/4)*35;
tft.fillRect(403,270,50,-(100+var),TFT_ORANGE);

 }
 else if(co  > 12.4 && co  <= 15.4){
int var = ((co-12.4)/3)*30;
tft.fillRect(403,270,50,-(135+var),TFT_RED);
   
  }
  else if(co  > 15.4 && co  <= 30.4){
    int var = ((co-15.4)/15)*25;
tft.fillRect(403,270,50,-(165+var),TFT_PURPLE);

  }
  else if(co  > 30.4 && co  <= 100){
    int var = ((co-30.4)/69.6)*25;
tft.fillRect(403,270,50,-(190+var),TFT_MAROON);
 }
 delay(60000);
}






  
  
}

   }





  else {
  Serial.print("Data not received and size of structure is ");
  //Serial.print(sizeof(var));

  
  }

  
   
  delay(100);

}
