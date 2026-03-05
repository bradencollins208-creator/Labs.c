//Braden Collins
//Lab 1 Assignment: ASCII-art representation of Dr. Yampolskiy
//Lab Section: Online
//1-13-26
#include <stdio.h>
int main()
{
	printf("\t  _______"); //underscores create the top of the head
	printf("\n\t / _   _ \\"); //underscores create the eyebrows and slashes start the sides of the head
	printf("\n\t | O   O |"); //O's create the eyes and vertical lines create more of the sides of the head
	printf("\n\t(|   J   |)"); //a J creates the nose, two open perenthesis create the ears, and vertical lines create more of the sides of the head
	printf("\n\t |  ___  |"); //underscores create the mustach and vertical lines create more of the sides of the head
	printf("\n\t |_/---\\_|"); //underscores and slashes create the top of the beard, the dashes create the mouth, and vertical lines create more of the sides of the head
	printf("\n   ______\\\t /______"); //underscores create the shoulders and dashes create more of the beard
	printf("\n  /\t  \\     /\t\\"); //dashes on the ends create more of the shoulders and dashes create more of the beard
	printf("\n\t   \\___/"); //dashes create more of beard and the underscores make the bottom of the beard
	//uses \n on each line to create each on a new line and uses \t to tab sections over to match different sections without the use of spaces
	return 0;
}