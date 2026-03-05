//Braden Collins
//Lab 5 Assignment: generative story
//Lab Section: Online
//2-19-26

#include <stdio.h>
#include <time.h>

int main(){
	//seeds the rand() function with the current time
	srand(time(NULL));
	
	//creates string variables
	char sName[20];
	char sAge[3];
	char sFavColor[20];
	char sFavAnimal[20];
	
	//creates arrays with each of the random options as arrays of string pointers
	char *locations[]={
	"a quiet forest",
	"a mysterious castle",
	"an abandoned spaceship",
	"a hidden underground city"
	};//end locations[] array
	
	char *objects[]={
	"a glowing key",
	"a strange map",
	"an ancient book",
	"a golden compass"
	};//end objects[] array
	
	char *endings[]={
	"From that day on, life was never the same.",
	"And that was only the beginning of an unforgettable journey.",
	"It was only the beginning of their greatest adventure.",
	"The mystery was solved, but many more adventures were still waiting."
	};//end endings[] array
	
	//creates a random varaible to use as an index for each random option
	int iRandomLocIndex=rand()%4;
	int iRandomObjIndex=rand()%4;
	int iRandomEndIndex=rand()%4;
	
	
	//questions
	printf("Enter your name: ");
	scanf("%s",sName);
	
	printf("\nEnter your age: ");
	scanf("%s",sAge);
	
	printf("\nEnter your favorite color: ");
	scanf("%s",sFavColor);
	
	printf("\nEnter your favorite animal: ");
	scanf("%s",sFavAnimal);
	
	//story
	printf("\nOne ordinary afternoon, %s, a bold %s-year-old, decided to take a walk through %s.",sName,sAge,locations[iRandomLocIndex]);
	
	printf("\nThe air felt different that day, almost electric, as if something important was about to happen. ");
	
	printf("\nSuddenly, in the distance, %s spotted %s",sName,objects[iRandomObjIndex]);
	
	printf(" shining brightly in a soft %s light.",sFavColor);
	
	printf("\nCurious and excited, %s stepped closer and reached out carefully.",sName);
	
	printf("\nJust as their fingers touched it, a friendly %s appeared and began to speak, ",sFavAnimal);
	
	printf("\nexplaining that this object held a powerful secret meant only for someone brave enough to find it.");
	
	printf("\nThough it felt surprising at first, %s knew this was the beginning of something special.",sName);
	
	printf("\nWith courage and determination, they followed the adventure wherever it led.");
	
	printf("\n%s",endings[iRandomEndIndex]);
	
	return 0;
}//end main()