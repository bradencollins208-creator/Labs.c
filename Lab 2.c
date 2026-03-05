//Braden Collins
//Lab 2 Assignment: foreign currency conversion table
//Lab Section: Online
//1-26-26

#include <stdio.h>
#include <math.h>

int main(){
	//initilizes fAmount and sets it to 0
	float fAmount=0;
	
	//initilizes and sets constant float values for all the exchange rates from USD
	const float constUSDtoGBP=0.7431;
	const float constUSDtoCAD=1.3831;
	const float constUSDtoEUR=0.8527;
	const float constUSDtoAUD=1.4847;
	const float constUSDtoMXN=17.5992;
	
	//initilizes and sets constant float values for all exchange rates from GBP
	const float constGBPtoUSD=1.3426;
	const float constGBPtoCAD=1.8573;
	const float constGBPtoEUR=1.1494;
	const float constGBPtoAUD=1.9869;
	const float constGBPtoMXN=23.4797;
	
	//initilizes and sets constant float values for all exchange rates from CAD
	const float constCADtoUSD=0.7224;
	const float constCADtoGBP=0.5383;
	const float constCADtoEUR=0.6190;
	const float constCADtoAUD=1.0697;
	const float constCADtoMXN=12.6391;
	
	//initilizes and sets constant float values for all exchange rates from EUR
	const float constEURtoUSD=1.1675;
	const float constEURtoGBP=0.8698;
	const float constEURtoCAD=1.6161;
	const float constEURtoAUD=1.7283;
	const float constEURtoMXN=20.4266;
	
	//initilizes and sets constant float values for all exchange rates from AUD
	const float constAUDtoUSD=0.6756;
	const float constAUDtoGBP=0.5034;
	const float constAUDtoCAD=0.9350;
	const float constAUDtoEUR=0.5785;
	const float constAUDtoMXN=11.8184;
	
	//initilizes and sets constant float values for all exchange rates from MXN
	const float constMXNtoUSD=0.0572;
	const float constMXNtoGBP=0.0426;
	const float constMXNtoCAD=0.0791;
	const float constMXNtoEUR=0.0490;
	const float constMXNtoAUD=0.0846;
	
	//asks the user for an amount to exchange and assigns the value to fAmount
	printf("Enter amount to exchange: ");
	scanf("%f",&fAmount);
	
	//checks if the fAmount is less than 0, if true, sets fAmount to a positive value (the absolute value of fAmount)
	if (fAmount<0){
		fAmount=abs(fAmount);
	}
	
	//creates the top row of the table
	printf("\n\t|\tUSD\t|\tGBP\t|\tCAD\t|\tEUR\t|\tAUD\t|\tMXN\t|");
	
	//creates the next row of the table
	printf("\n|USD\t|%10.2f\t",fAmount);
	printf("|%10.2f\t",fAmount*constGBPtoUSD);
	printf("|%10.2f\t",fAmount*constCADtoUSD);
	printf("|%10.2f\t",fAmount*constEURtoUSD);
	printf("|%10.2f\t",fAmount*constAUDtoUSD);
	printf("|%10.2f\t",fAmount*constMXNtoUSD);
	printf("|");
	
	//creates the next row of the table
	printf("\n|GBP\t|%10.2f\t",fAmount*constUSDtoGBP);
	printf("|%10.2f\t",fAmount);
	printf("|%10.2f\t",fAmount*constCADtoGBP);
	printf("|%10.2f\t",fAmount*constEURtoGBP);
	printf("|%10.2f\t",fAmount*constAUDtoGBP);
	printf("|%10.2f\t",fAmount*constMXNtoGBP);
	printf("|");
	
	//creates the next row of the table
	printf("\n|CAD\t|%10.2f\t",fAmount*constUSDtoCAD);
	printf("|%10.2f\t",fAmount*constGBPtoCAD);
	printf("|%10.2f\t",fAmount);
	printf("|%10.2f\t",fAmount*constEURtoCAD);
	printf("|%10.2f\t",fAmount*constAUDtoCAD);
	printf("|%10.2f\t",fAmount*constMXNtoCAD);
	printf("|");
	
	//creates the next row of the table
	printf("\n|EUR\t|%10.2f\t",fAmount*constUSDtoEUR);
	printf("|%10.2f\t",fAmount*constGBPtoEUR);
	printf("|%10.2f\t",fAmount*constCADtoEUR);
	printf("|%10.2f\t",fAmount);
	printf("|%10.2f\t",fAmount*constAUDtoEUR);
	printf("|%10.2f\t",fAmount*constMXNtoEUR);
	printf("|");
	
	//creates the next row of the table
	printf("\n|AUD\t|%10.2f\t",fAmount*constUSDtoAUD);
	printf("|%10.2f\t",fAmount*constGBPtoAUD);
	printf("|%10.2f\t",fAmount*constCADtoAUD);
	printf("|%10.2f\t",fAmount*constEURtoAUD);
	printf("|%10.2f\t",fAmount);
	printf("|%10.2f\t",fAmount*constMXNtoAUD);
	printf("|");
	
	//creates the next row of the table
	printf("\n|MXN\t|%10.2f\t",fAmount*constUSDtoMXN);
	printf("|%10.2f\t",fAmount*constGBPtoMXN);
	printf("|%10.2f\t",fAmount*constCADtoMXN);
	printf("|%10.2f\t",fAmount*constEURtoMXN);
	printf("|%10.2f\t",fAmount*constAUDtoMXN);
	printf("|%10.2f\t",fAmount);
	printf("|");
	
	return 0;
}