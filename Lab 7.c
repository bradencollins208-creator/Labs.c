//Braden Collins
//Lab 7 Assignment: phonebook2
//Lab Section: Online
//date

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//contact structure
typedef struct contact{
	char fname[50];
	char lname[50];
	char phoneNum[9];
}cont;

//function prototypes
void addFriend(cont **,int *);
void deleteFriend(cont *,int *);
void showPhonebook(cont *,int);
void sortAlphabetically();
void findPhoneNumber();
void randomFriend();
void deleteAll();

int main(){
	int iUserInput=0;//creates a variable for the value the user chooses
	int iSize=0;//creates a variable for the size of phonebook array
	cont *phonebook=NULL;//creates a NULL pointer to an array with cont elements
	
	//always true while loop
	while(1){
		//prints the menu
		printf("\nPhone Book Application");
		printf("\n\t1) Add friend");
		printf("\n\t2) Delete friend");
		printf("\n\t3) Show phone book\n");
		printf("\n\t4) Sort alphabetically\n");
		printf("\n\t5) Find phone number\n");
		printf("\n\t6) Randomly find friend\n");
		printf("\n\t7) Delete all friends\n");
		
		//asks and takes an input from the user
		printf("\nWhat do you want to do: ");
		scanf("%d",&iUserInput);
		
		//uses a while loop to ensure the user only enter a number 1-3
		while(!(iUserInput>=1 && iUserInput<=7)){
			printf("Please enter a value 1-7: ");
			scanf("%d",&iUserInput);
		}//end while loop
		
		//calls the addFriend() function if the user enters 1
		if(iUserInput==1){
			addFriend(&phonebook,&iSize);
		}//end if
		
		//calls the deleteFriend() function if the user enters 2
		else if(iUserInput==2){
			deleteFriend(phonebook,&iSize);
		}//end else if
		
		//calls the showPhonebook() function if the user enters 3
		else if(iUserInput==3){
			showPhonebook(phonebook,iSize);
		}//end else if
	}//end while loop
	free(phonebook);//frees the memory used in the phonebook array
	return 0;
}//end main()

//function defition for the add friend option
void addFriend(cont **phbk,int *s){
	*phbk=realloc(*phbk,(*s+1)*sizeof(cont));//dynamically allocates memory for the phonebook array
	
	//checks that the memory was properly allocated (exits if failed)
	if(*phbk==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}//end if
	
	//gets the first name, last name, and phone number and increases the iSize variable to account for the new entry
	printf("First name: ");
	scanf("%49s",(*phbk)[*s].fname);
	
	printf("Last name: ");
	scanf("%49s",(*phbk)[*s].lname);
	
	printf("Phone number: ");
	scanf("%8s",(*phbk)[*s].phoneNum);
	
	printf("Record added to the phone book\n");
	(*s)++;
}//end addFriend()

//function definition for the delete friend option
void deleteFriend(cont *phbk,int *s){
	//creates variables for a first name and last name
	char fname[50];
	char lname[50];
	
	//gets the first name and last name
	printf("First name: ");
	scanf("%49s",fname);
	
	printf("Last name: ");
	scanf("%49s",lname);
	
	//runs a for loop up to iSize
	for(int i=0;i<*s;i++){
		//checks if the the name the user enters is equal to a name in the phonebook array
		if(strcmp(phbk[i].fname,fname)==0 && strcmp(phbk[i].lname,lname)==0){
			//shifts the phonebook array one to the left
			for(int k=i;k<*s-1;k++){
				phbk[k]=phbk[k+1];
			}//end for loop
			
			//decreases iSize to account for the removal of an entry
			(*s)--;
			printf("Record deleted from the phone book\n");
			return;
		}//end if
	}//end for loop
	printf("Entry not found\n");//runs if the name the user enters is not equal to any name in the phonebook array
}//end deleteFriend()

//function definition for the show phone book option
void showPhonebook(cont *phbk,int s){
	printf("Phone Book Entries:\n");
	//runs a for loop to print each entry of the phonebook array
	for(int i=0;i<s;i++){
		printf("%s %s %s\n",phbk[i].fname,phbk[i].lname,phbk[i].phoneNum);
	}//end for loop
}//end showPhonebook()