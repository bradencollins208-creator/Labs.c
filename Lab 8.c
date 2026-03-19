//Braden Collins
//Lab 8 Assignment: phonebook3
//Lab Section: Online
//date

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
void sortAlphabetically(cont *,int);
void findPhoneNumber(cont *,int);
void randomFriend(cont *,int);
void deleteAll(cont **,int *);
void storeEntires(cont *,int);
void retrieveEntires(cont **,int *);

//creates a global variable for the file name used for storing/retrieving files
char gFileName[50];

int main(){
	//seeds the rand() function with the current time
	srand(time(NULL));
	
	int iUserInput=0;//creates a variable for the value the user chooses
	int iSize=0;//creates a variable for the size of phonebook array
	cont *phonebook=NULL;//creates a NULL pointer to an array with cont elements
	
	//always true while loop
	while(1){
		//prints the menu
		printf("\nPhone Book Application");
		printf("\n\t1) Add friend");
		printf("\n\t2) Delete friend");
		printf("\n\t3) Show phone book");
		printf("\n\t4) Sort alphabetically");
		printf("\n\t5) Find phone number");
		printf("\n\t6) Randomly find friend");
		printf("\n\t7) Delete all friends");
		printf("\n\t8) Store entries into a location");
		printf("\n\t9) Retrive entries from location");
		printf("\n\t0) Exit\n");
		
		//asks and takes an input from the user
		printf("\nWhat do you want to do: ");
		scanf("%d",&iUserInput);
		
		//uses a while loop to ensure the user only enter a number 1-7
		while(!(iUserInput>=0 && iUserInput<=9)){
			printf("Please enter a value 0-9: ");
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
		
		//calls the sortAlphabetically() function if the user enters 4
		else if(iUserInput==4){
			sortAlphabetically(phonebook,iSize);
		}//end else if
		
		//calls the findPhoneNumber() function if the user enters 5
		else if(iUserInput==5){
			findPhoneNumber(phonebook,iSize);
		}//end else if
		
		//calls the randomFriend() function if the user enters 6
		else if(iUserInput==6){
			randomFriend(phonebook,iSize);
		}//end else if
		
		//calls the deleteAll() function if the user enters 7
		else if(iUserInput==7){
			deleteAll(&phonebook,&iSize);
		}//end else if
		
		//calls the storeEntries() function if the user enters 8
		else if(iUserInput==8){
			storeEntires(phonebook,iSize);
		}//end else if
		
		//calls the retrieveEntries() function if the user enters 9
		else if(iUserInput==9){
			retrieveEntires(&phonebook,&iSize);
		}//end else if
		
		//ends the while loop if the user enters 0
		else if(iUserInput==0){
			break;
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
	
	//runs a for loop up to s
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

//function definition for the sort alphabetically option
void sortAlphabetically(cont *phbk,int s){
	//checks if the phonebook is empty
	if(s==0){
		printf("Phonebook is empty\n");
		return;
	}
	
	int iFirstOrLast=0;
	printf("\n1) Sort by first name");
	printf("\n2) Sort by last name");
	printf("\nWhat do you want to do: ");
	
	scanf("%d",&iFirstOrLast);
	
	//uses a while loop to ensure the user only enter a number 1-2
	while(!(iFirstOrLast>=1 && iFirstOrLast<=2)){
		printf("Please enter a value 1-2: ");
		scanf("%d",&iFirstOrLast);
	}//end while loop
	
	cont temp;
	if(iFirstOrLast==1){
		//runs a for loop up to s
		for(int i=0;i<s;i++){
			//runs another for loop up to s
			for(int k=i;k<s;k++){
				//checks if i is less than k and sorts based off the result
				if(strcmp(phbk[i].fname,phbk[k].fname)>0){
					temp=phbk[i];
					phbk[i]=phbk[k];
					phbk[k]=temp;
				}//end if
			}//end for loop
		}//end for loop
	}//end if
	
	else if (iFirstOrLast==2){
		//runs a for loop up to s
		for(int i=0;i<s;i++){
			//runs another for loop up to s
			for(int k=i;k<s;k++){
				//checks if i is less than k and sorts based off the result
				if(strcmp(phbk[i].lname,phbk[k].lname)>0){
					temp=phbk[i];
					phbk[i]=phbk[k];
					phbk[k]=temp;
				}//end if
			}//end for loop
		}//end for loop		
	}//end else if
	printf("Phonebook sorted\n");
	
}//end sortAlphabetically()

//function definition for the find phone number option
void findPhoneNumber(cont *phbk,int s){
	//creates a variable for the phone number
	char phoneNum[9];
	
	//gets the phone number
	printf("Phone number: ");
	scanf("%8s",phoneNum);
	
	//runs a for loop up to s
	for(int i=0;i<s;i++){
		//checks if the the phone number the user enters is equal to a phone number in the phonebook array
		if(strcmp(phbk[i].phoneNum,phoneNum)==0){
			printf("%s %s\n",phbk[i].fname,phbk[i].lname);
			return;
		}//end if
	}//end for loop
	printf("Phone number not found\n");//runs if the phone number the user enters is not equal to any phone number in the phonebook array
}//end findPhoneNumber()

//function definition for the random friend option
void randomFriend(cont *phbk,int s){
	//checks if the phonebook is empty
	if(s==0){
		printf("Phonebook is empty\n");
		return;
	}//end if
	
	//runs if the phonebook is not empty
	else{
		int randomVal=rand()%s;//creates a random variable
		
		printf("%s %s %s\n",phbk[randomVal].fname,phbk[randomVal].lname,phbk[randomVal].phoneNum);
		return;
	}//end else
}//end randomFriend()

//function definition for the delete all option
void deleteAll(cont **phbk,int *s){
	free(*phbk);//frees the memory used in the phonebook
	*phbk=NULL;//sets the phonebook to NULL
	*s=0;//sets to the size of the phonebook to 0
	printf("All records deleted\n");
}//end deleteAll()

//function definition for the store entries option
void storeEntires(cont *phbk,int s){
	int iChoice=0;//creates a variable
	
	//allows the user to choose to store the entries in a default file name or a custom file name
	printf("1) Default file-name\n");
	printf("2) Custom file-name\n");
	printf("What do you want to do: ");
	
	scanf("%d",&iChoice);
	
	//uses a while loop to ensure the user only enter a number 1-2
	while(!(iChoice>=1 && iChoice<=2)){
		printf("Please enter a value 1-2: ");
		scanf("%d",&iChoice);
	}//end while loop
	
	//if the user chooses 1, the global file name is set to "phonebook.txt"
	if(iChoice==1){
		strcpy(gFileName,"phonebook.txt");
	}//end if
	//if the user chooses 2, the global file name is set to what the user enters
	else if(iChoice==2){
		printf("Enter file-name (please include \".txt\"): ");
		scanf("%49s",gFileName);
	}//end else if
	
	FILE *pWrite;//creates a file pointer
	
	//opens a file in write mode
	pWrite=fopen(gFileName,"w");
	
	//if the file pointer is NULL, prints an error
	if(pWrite==NULL){
		printf("Error: File cannot be opened\n");
	}//end if
	
	//uses a for loop up to the size of phonebook and prints each phonebook entry on a new line of the text file
	for(int i=0;i<s;i++){
		fprintf(pWrite,"%s %s %s\n",phbk[i].fname,phbk[i].lname,phbk[i].phoneNum);
	}//end for loop
	printf("Entries added\n");//tells the user the entries have been added to the file
	
	fclose(pWrite);//closes the file pointer
}//end storeEntries()

//function definition for the retrive entires option
void retrieveEntires(cont **phbk,int *s){
	int iChoice=0;//creates a variable
	
	//allows the user to choose to store the entries in a default file name or a custom file name
	printf("1) Default file-name\n");
	printf("2) Custom file-name\n");
	printf("What do you want to do: ");
	
	scanf("%d",&iChoice);
	
	//uses a while loop to ensure the user only enter a number 1-2
	while(!(iChoice>=1 && iChoice<=2)){
		printf("Please enter a value 1-2: ");
		scanf("%d",&iChoice);
	}//end while loop
	
	//if the user chooses 1, the global file name is set to "phonebook.txt"
	if(iChoice==1){
		strcpy(gFileName,"phonebook.txt");
	}//end if
	//if the user chooses 2, the global file name is set to what the user enters
	else if(iChoice==2){
		printf("Enter file-name (please include \".txt\"): ");
		scanf("%49s",gFileName);
	}//end else if
	
	FILE *pRead;//creates a file pointer
	
	//opens a file in read mode
	pRead=fopen(gFileName,"r");
	
	//if the file pointer is NULL, prints an error
	if(pRead==NULL){
		printf("Error: File cannot be opened\n");
	}//end if
	
	//creates a temporary cont variable
	cont temp;
	
	//uses a while loop to go through the file
	while(fscanf(pRead,"%49s %49s %9s",temp.fname,temp.lname,temp.phoneNum)==3){
		
		//allcoates memory as necessay
		*phbk=realloc(*phbk,(*s+1) * sizeof(cont));
		
		//checks that the memory was properly allocated (exits if failed)
		if(*phbk==NULL){
			printf("Memory allocation failed\n");
			exit(1);
		}//end if
		
		//sets the phonebook element s equal to the temp value
		(*phbk)[*s]=temp;
		(*s)++;//increases the size of the phonebook
	}//end while loop
	
	fclose(pRead);//closes the file pointer
	printf("Entries retrieved\n");//tells the user the entries have been retrieved
}//end retrieveEntires()