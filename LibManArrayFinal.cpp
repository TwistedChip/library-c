#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<string.h>
// Daniel Kevin Siboro (1906423050) & Edrian Budiharsono (1906423063)
// counter for book id and book name index
static int counter=0;
// initialize function
int addBooks(char bookName[100][100], int bookID[100]);
void borrowBooks(char bookName[100][100], int bookID[100], int borrow[100]);
void removeBooks(char bookName[100][100], int bookID[100]);
void editBooks(char bookName[100][100], int bookID[100]);
void viewBooks(char bookName[100][100], int bookID[100], int borrow[100]);
void searchBooks(char bookName[100][100], int bookID[100], int borrow[100]);
void start();

int main(){
	char bookName[100][100]={NULL}, choice1, choice2;
	int bookID[100]={NULL}, borrow[100]={NULL};
	start();
	printf("\n\n\n\n\n");
	printf("\t\t\t\tWelcome to the Library!\n");
	choice:
	printf("\t\t\t\tWould you like to access the library?(Y/N):");
	scanf("%s", &choice1);
	if(choice1=='Y' || choice1=='y'){
		system("cls");
		goto menu;
	}
	else if(choice1=='N' || choice1=='n'){
		system("cls");
		printf("\t\t\t\tSee you! Please come again!");
		return 0; 
	}
	else{
		printf("Invalid input, please try again.\a");
		goto choice;
	}
	// Main menu
	menu:
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 What would you like to do today?        \xB2\n");
	printf("\t\t\t\t\xB2 1. Add Books to library                 \xB2\n");
	printf("\t\t\t\t\xB2 2. Borrow Books from library            \xB2\n");
	printf("\t\t\t\t\xB2 3. Remove Books from library            \xB2\n");
	printf("\t\t\t\t\xB2 4. Edit Books in the library            \xB2\n");
	printf("\t\t\t\t\xB2 5. View Books in the library            \xB2\n");
	printf("\t\t\t\t\xB2 6. Search books in the library          \xB2\n");
	printf("\t\t\t\t\xB2 7. Exit Application                     \xB2\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\tPlease enter your number of choice:");
	// selection of function
	switch(getch()){
    	case '1':
    		addBooks(bookName, bookID);
    		break;
    	case '2':
    		borrowBooks(bookName, bookID, borrow);
    		break;
    	case '3':
    		removeBooks(bookName, bookID);
    		break;
    	case '4':
    		editBooks(bookName, bookID);
    		break;
    	case '5':
    		viewBooks(bookName, bookID, borrow);
    		break;
    	case '6':
    		searchBooks(bookName, bookID, borrow);
    		break;
    	case '7':
    		system("cls");
    		printf("\t\t\t\tSee you! Please come again!");
			return 0;
		default:
			printf("Invalid input, please try again.\a");
    		goto menu;
	}
	// loop
	while(0<1){
		goto menu;
	}
	return 0;
}
//initialize animation
void start(){
	int c;
	init:
	printf("\n\n\n\n\n");
	printf("\t\t\t\tInitializing program please wait");
	for(int i=0; i<3; i++){ 
		Sleep(500); //delay
		printf(".");
	}
	c++;
	system("cls"); // clear the screen
	if(c<2){
	goto init;
	}
	system("cls"); // clear the screen
}
//add book function
int addBooks(char bookName[100][100], int bookID[100]){
	int i, idTemp;
	char nameTemp[100], choice;
	addBook:
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Please enter the specifics of the book \n");
	printf("\t\t\t\t\xB2 Please do no enter a book ID of 0 \n");
	printf("\t\t\t\t\xB2 Book ID: ");
	scanf("%d", &idTemp);
	if(idTemp==0){
		printf("You printed a book ID of 0, please try again.");
		goto addBook;
	}
	for(i=0; i<100; i++){	// loop checking
		if(idTemp==bookID[i]){	//comparing input to array
			system("cls");
			printf("\n\n\n\n\n");
			printf("\t\t\t\tBook with this book ID already exists\n");
			printf("\t\t\t\tWould you like to enter the book ID again?(Y/N): ");
			scanf("%s", &choice); // inserting new input option
				if(choice=='Y'||choice=='y'){
					goto addBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
		}
		else{
			continue;
		}
	}
	bookID[counter]=idTemp; //overwritting the array to new value
	printf("\t\t\t\t\xB2 Book Name: ");
	scanf(" %[^\n]%*c", &nameTemp[0]);
		for(i=0; i<100; i++){
		if(strcmp(bookName[i],nameTemp)==0){	//comparing input to array
			system("cls"); //clear the screen
			printf("\n\n\n\n\n");
			printf("\t\t\t\tBook with this name already exists");
			printf("\t\t\t\tWould you like to enter the name again?(Y/N): ");
			scanf("%s", &choice); // option for inserting new input
				if(choice=='Y'||choice=='y'){
					goto addBook; // goes to the start of the function
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
		}
		else{
			continue;
		}
	}
	strcpy(bookName[counter],nameTemp); //overwritting the array to new value
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\tYour book information has been saved!\n");
	counter++; // to insert the next array
	printf("\t\t\t\tWould you like to add another book?(Y/N):");
	scanf("%s", &choice);	// option for inserting new input
	if(choice=='Y'||choice=='y'){
		goto addBook;
	}
	else if(choice=='N'||choice=='n'){
		goto end; 
	}
	end:
	system("cls");// clear the screen
}

void borrowBooks(char bookName[100][100], int bookID[100], int borrow[100]){
	int idCheck, i, j, temp, c;
	char nameCheck[100], choice;
	time_t currentTime;	// display current time
	time(&currentTime);
	borrowBook:
	c=0;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Please enter the specifics of the book you want to borrow \n");
	printf("\t\t\t\t\xB2 Book ID: ");
	scanf("%d", &idCheck);
	printf("\t\t\t\t\xB2 Book Name: ");
	scanf(" %[^\n]%*c", &nameCheck);
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	for(i=0; i<100; i++){ //scan the array 
		if(idCheck==bookID[i] && strcmp(bookName[i], nameCheck)==0){
			printf("\t\t\t\tThe book exists in the library, you may borrow it.\n");
			printf("\t\t\t\tThis book is borrowed on %s.", ctime(&currentTime)); // printing current time when the book is being borrowed
			printf("\t\t\t\tPlease remember the date as you will need to provide the date when returning the book.\n");
			printf("\t\t\t\tPlease return the book after 7 days.\n");
			borrow[i]=1;
			c++;
			break;
		}
		if(i==19 && c!=1){
			printf("\t\t\t\tBook does not exist in the library.\n");
			printf("\t\t\t\tWould you like to try again?(Y/N):");
			scanf("%s", &choice); // option for inserting new input
				if(choice=='Y'||choice=='y'){
					goto borrowBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
			}	
	}
	
	printf("\t\t\t\tWould you like to borrow another book?(Y/N):");
	scanf("%s", &choice); // option for inserting new input
	if(choice=='Y'||choice=='y'){
		goto borrowBook;
	}
	else if(choice=='N'||choice=='n'){
		goto end; 
	}
	end:
	system("cls"); // clear the screen
}

void removeBooks(char bookName[100][100], int bookID[100]){
	int idCheck, i, j, temp, c;
	char nameCheck[100], choice, zero[100]={NULL};
	removeBook:
	c=0;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Please enter the specifics of the book you want to remove \n");
	printf("\t\t\t\t\xB2 Book ID: ");
	scanf("%d", &idCheck);
	printf("\t\t\t\t\xB2 Book Name: ");
	scanf(" %[^\n]%*c", &nameCheck);
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	for(i=0; i<100; i++){ // loop for scanning the array 
		if(idCheck==bookID[i] && strcmp(bookName[i], nameCheck)==0){
			printf("\t\t\t\tThe book exists in the library, this book will be removed.\n");
			bookID[i]=0;
			strcpy(bookName[i],zero); //to remove the value inside the array
			c++;
			break;
		}
		if(i==19 && c!=1){
			printf("\t\t\t\tBook does not exist in the library.\n");
			printf("\t\t\t\tWould you like to try again?(Y/N):");
			scanf("%s", &choice); // option for inserting new input
				if(choice=='Y'||choice=='y'){
					goto removeBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
			}
	} 
	for(i=0; i<counter-1; i++){ //to move up the remaining array when there is a book being removed
		loop:
		if(bookID[i]!=0 && bookID[i+1]==0){
			j=i+2;
			temp=bookID[i+1];
			bookID[i+1]=bookID[j];
			bookID[j]=temp;
		    strcpy(bookName[i+1],bookName[j]);
		    strcpy(bookName[j],zero);
		    counter--;
		}
		else if(bookID[0]==0 && bookID[i+1]!=0){
			j=i+1;
			temp=bookID[i];
			bookID[i]=bookID[j];
			bookID[j]=temp;
		    strcpy(bookName[i],bookName[j]);
		    strcpy(bookName[j],zero);
		    counter--;
		    goto loop;
		}
		else{
			continue;
		}
	}
	printf("\t\t\t\tWould you like to remove another book?(Y/N):");
	scanf("%s", &choice); // option for inserting new input
	if(choice=='Y'||choice=='y'){
		goto removeBook;
	}
	else if(choice=='N'||choice=='n'){
		goto end; 
	}
	end:
	system("cls"); // clear the screen
}

void editBooks(char bookName[100][100], int bookID[100]){
	int idCheck, i, j, temp, c;
	char nameCheck[100], choice;
	editBook:
		c=0;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Please enter the specifics of the book you want to edit \n");
	printf("\t\t\t\t\xB2 Book ID: ");
	scanf("%d", &idCheck);
	printf("\t\t\t\t\xB2 Book Name: ");
	scanf(" %[^\n]%*c", &nameCheck);
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	for(i=0; i<100; i++){ // loop scanning of array
		if(idCheck==bookID[i] && strcmp(bookName[i], nameCheck)==0){ // compaing name and id of book in the array
			system("cls");
			printf("\n\n\n\n\n");
			printf("\t\t\t\tThe book exists in the library, what do you want to edit?\n");
			// choose between name or id to edit
			printf("\t\t\t\t1. Book ID       \n");
			printf("\t\t\t\t2. Book Name       \n");
			printf("\t\t\t\tPlease enter a number of your choice: ");
			switch(getch()){
				case '1':
					printf("\n\t\t\t\tPlease enter the new book ID: ");
					scanf("%d", &temp);
					bookID[i]=temp;
					break;
				case '2':
					printf("\n\t\t\t\tPlease enter the new book Name: ");
					scanf(" %[^\n]%*c", &nameCheck);
					strcpy(bookName[i],nameCheck);
					break;	
				default:			
					printf("Invalid input, please try again.\a");
    				goto editBook;
			}
			c++;
			break;
		}
		if(i==19 && c!=1){
			printf("\t\t\t\tBook does not exist in the library.\n"); // option for inserting new input
			printf("\t\t\t\tWould you like to try again?(Y/N):");
			scanf("%s", &choice);
				if(choice=='Y'||choice=='y'){
					goto editBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
			}
		else{
			continue;
		}	
	}
	printf("\t\t\t\tWould you like to edit another book?(Y/N):"); // option for inserting new input
	scanf("%s", &choice); 
	if(choice=='Y'||choice=='y'){
		goto editBook;
	}
	else if(choice=='N'||choice=='n'){
		goto end; 
	}
	end:
	system("cls"); // clear the screen
}

void viewBooks(char bookName[100][100], int bookID[100], int borrow[100]){
	int choice;
	system("cls"); // clear the screen
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Which books do you want to view? \n");
	printf("\t\t\t\t\xB2 1. Books in the library \n");
	printf("\t\t\t\t\xB2 2. Books borrowed from the library \n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\tPlease enter your number of choice:");
	scanf("%d", &choice);
	choiceL:
	if(choice==1){
	system("cls");
	printf("Books available in the libary\n");
	printf("--------------------------------------------\n");
	printf("%s%25s\n", "ID", "Book Name"); 
	for(int i=0; i<counter; i++){ // scanning for the saved value inside the array
		if(borrow[i]==0){
			printf("%2d%25s\n", bookID[i], bookName[i]);// printing the list of added books
		}
		else{
			continue;
		}
	}
}
	else if(choice==2){
	system("cls");
	printf("Borrowed books from the library\n");
	printf("--------------------------------------------\n");
	printf("%s%25s\n", "ID", "Book Name"); 
	for(int i=0; i<counter; i++){ // scanning for the saved value inside the array
		if(borrow[i]==1){
			printf("%2d%25s\n", bookID[i], bookName[i]);// printing the list of added books
		}
		else{
			continue;
		}
	}
}
	else{
		printf("Invalid input, please try again.\a");
		goto choiceL;
	}
	
	printf("Press any key to go back to menu");
	getch(); // to continue the program with any input form the keyboard
}

void searchBooks(char bookName[100][100], int bookID[100], int borrow[100]){
	int idCheck, i, j, temp, c;
	char nameCheck[100], choice;
	searchBook:
	c=0;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t\t\t\xB2 Please enter the specifics of the book you want to find \n");
	printf("\t\t\t\t\xB2 Book ID: ");
	scanf("%d", &idCheck);
	printf("\t\t\t\t\xB2 Book Name: ");
	scanf(" %[^\n]%*c", &nameCheck);
	printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	for(i=0; i<100; i++){ // loop for scanning the array 
		if(idCheck==bookID[i] && strcmp(bookName[i], nameCheck)==0){
			printf("\t\t\t\tThe book exists in the library, here are the details\n");
			printf("\t\t\t\tBook ID: %d\n", bookID[i]);
			printf("\t\t\t\tBook Name: %s\n", bookName[i]);
			if(borrow[i]==1){
				printf("\t\t\t\tThe book is currently being borrowed\n");
			}
			else if(borrow[i]==0){
				printf("\t\t\t\tThe book is available in the library\n");
			}
			c++;
			printf("\t\t\t\tWould you like to search for another book?(Y/N):");
			scanf("%s", &choice); // option for inserting new input
				if(choice=='Y'||choice=='y'){
					goto searchBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
		}
		if(i==19 && c!=1){
			printf("\t\t\t\tBook does not exist in the library.\n");
			printf("\t\t\t\tWould you like to try again?(Y/N):");
			scanf("%s", &choice); // option for inserting new input
				if(choice=='Y'||choice=='y'){
					goto searchBook;
				}
				else if(choice=='N'||choice=='n'){
					goto end; 
				}
			}
	} 
	end:
	system("cls"); // clear the screen
}

/*this function can be used instead of sleep, but with windows.h we don't need to make another function.
void delay(float seconds){	//delay function, used to to delay output into cli, used for aesthetic purposes, and so user can properly read instructions.
	float mSeconds = seconds * 1000;	//time.h clock() function uses miliseconds so we change the parameter into mSeconds in this function
	clock_t start = clock();	//clock_t is a variable for clock(), here we initialize a start for the time. it is measured in clock ticks
	while(clock()<start+mSeconds); //here we make a condition so the function loops until clock==start+mSeconds
}*/
