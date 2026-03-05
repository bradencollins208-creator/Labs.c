//Braden Collins
//Lab 3 Assignment: calculator
//Lab Section: Online
//2-3-26

#include <stdio.h>

int main(){
	int iChoice=0;//creates the variable used by the user to choose an option from the calculator menu
	
	//loops unless the user enter 7
	while(iChoice!=7){
		//creates the calculator menu
		printf("\nCalculator Menu:\n");
		printf("(1) Addition\n");
		printf("(2) Subtraction\n");
		printf("(3) Multiplication\n");
		printf("(4) Division\n");
		printf("(5) Modulus (integers only)\n");
		printf("(6) Test if prime (integers only)\n");
		printf("(7) Exit\n");
		
		//asks the user for an input to determine calculator option and assigns it to iChoice
		printf("Please choose an operation: ");
		scanf("%d",&iChoice);
		
		//runs the addition operation if the user chooses 1
		if(iChoice==1){
			//creates two float variables
			float fNum1;
			float fNum2;
			
			//assigns fNum1 and fNum2 to the numbers the user wants to add
			printf("Enter the first number: ");
			scanf("%f",&fNum1);
			printf("Enter the second number: ");
			scanf("%f",&fNum2);
			
			float fResult=fNum1+fNum2;//creates a variable for the sum of fNum1 and fNum2
			printf("%.2f + %.2f = %.2f\n",fNum1,fNum2,fResult);//prints the result
		}
		//runs the subtraction operation if the user chooses 2
		else if(iChoice==2){
			//creates two float variables
			float fNum1;
			float fNum2;
			
			//assigns fNum1 and fNum2 to the numbers the user wants to subtract
			printf("Enter the first number: ");
			scanf("%f",&fNum1);
			printf("Enter the second number: ");
			scanf("%f",&fNum2);
			
			float fResult=fNum1-fNum2;//creates a variable for the difference of fNum1 and fNum2
			printf("%.2f - %.2f = %.2f\n",fNum1,fNum2,fResult);//prints the result
		}
		//runs the multiplication operation if the user chooses 3
		else if(iChoice==3){
			//creates two float variables
			float fNum1;
			float fNum2;
			
			//assigns fNum1 and fNum2 to the numbers the user wants to multiply
			printf("Enter the first number: ");
			scanf("%f",&fNum1);
			printf("Enter the second number: ");
			scanf("%f",&fNum2);
			
			float fResult=fNum1*fNum2;//creates a variable for the product of fNum1 and fNum2
			printf("%.2f * %.2f = %.2f\n",fNum1,fNum2,fResult);//prints the result
		}
		//runs the division operation if the user chooses 4
		else if(iChoice==4){
			//creates two float variables
			float fNum1;
			float fNum2;
			
			//assigns fNum1 and fNum2 to the numbers the user wants to divide
			printf("Enter the first number: ");
			scanf("%f",&fNum1);
			printf("Enter the second number: ");
			scanf("%f",&fNum2);
			
			//runs a loop if fNum2 is 0 (cannon divide by 0) and will not contiune until another value is chosen
			while(fNum2==0){
				printf("Denominator can not be 0, please enter another value: ");
				scanf("%f",&fNum2);
			}
			
			float fResult=fNum1/fNum2;//creates a variable for the quotient of fNum1 and fNum2
			printf("%.2f / %.2f = %.2f\n",fNum1,fNum2,fResult);//prints the result
		}
		//runs the modulous operation if the user chooses 5
		else if(iChoice==5){
			//creates two integer variables
			int iNum1;
			int iNum2;
			
			//assigns iNum1 and iNum2 to the numbers the user wants to mod
			printf("Enter the first number: ");
			scanf("%d",&iNum1);
			printf("Enter the second number: ");
			scanf("%d",&iNum2);
			
			int iResult=iNum1%iNum2;//creates a variable for the remainder of iNum1 and iNum2
			printf("%d %% %d = %d\n",iNum1,iNum2,iResult);//prints the result
		}
		//runs the primality check if the user chooses 6
		else if(iChoice==6){
			//creates an integer variable
			int iNum;
			
			//assigns iNum to the number the user wants to check primality for
			printf("Enter the number to be tested: ");
			scanf("%d",&iNum);
			
			//checks if iNum is 1 (never prime)
			if(iNum==1){
				printf("%d is not prime\n",iNum);
			}
			//checks if iNum is 2 (prime)
			else if(iNum==2){
				printf("%d is prime\n",iNum);
			}
			else{
				//runs a for loop from 2 up to iNum and increments by 1
				for(int i=2;i<iNum;i++){
					//checks if any of the numbers from 2 up to iNum is evenly divisible (not prime)
					if(iNum%i==0){
						//prints iNum is not prime along with two multiples that to show it is not prime and breaks the loop
						printf("Not prime: %d * %d = %d\n",i,iNum/i,iNum);
						break;
					}
					//runs for any numbers that do not make the previous condition true
					else{
						//prints iNum is prime and breaks the loop
						printf("%d is prime\n",iNum);
						break;
					}
				}
			}
		}
		//checks if the user enters a number greater than the 1-7 options
		else if (iChoice>7){
			printf("Please enter a number 1 - 7\n");
		}
	}
	//once the user enter 7, the loop breaks and prints the good bye message
	printf("Good bye!");
	
	return 0;
}