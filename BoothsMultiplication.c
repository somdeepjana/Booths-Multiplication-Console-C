#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int binary_digit= 0;
char numb_1[20], numb_2[20], numb_add[8];

//welcome scree credit printing...............................................................
void welcome_creadit(){
	
	system("cls");
	printf("\n\n\n\t\t\t\t----   Operations On Binary   ----");
	printf("\n\n\t\tCreated by");
	printf("\n\t\t\t\tName: Somdeep Jana\tEnrollment No: 12017009001009");
	printf("\n\t\t\t\tName: Soumodip Roy\tEnrollment No: 12017009001422");
}

void welcome(){
	
	welcome_creadit();
	printf("\n\n\n\t\tPlease enter any key to continue......");
	getch();
}
//error code==0 means length not matched, code== -1 user entry is other than 0 or 1, code==2 means programmer error...............
int number_check(int number_to_check){
	
	int temp= 0, checked_length=0;
	if(number_to_check==1){
		while(numb_1[temp]!= '\0'){
			if(numb_1[temp]== '1' || numb_1[temp]== '0'){
				checked_length++;
			}else{
				return -1;
			}
			temp++;
		}
		if(checked_length== strlen(numb_1)){
			return 1;
		}else{
			return 0;
		}
	}else if(number_to_check== 2){
		while(numb_2[temp]!= '\0'){
			if(numb_2[temp]== '1' || numb_2[temp]== '0'){
				checked_length++;
			}else{
				return -1;
			}
			temp++;
		}
		if(checked_length== strlen(numb_2)){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 2;
	}
}

//making both the numbers same width..................................
void make_same_length(){
	
	int i, i_2;
	if(strlen(numb_1)>strlen(numb_2)){
		i_2= strlen(numb_2)-1;
		for(i=strlen(numb_1)-1; i>=0; i--){
			if(i_2>=0){
				numb_2[i]= numb_2[i_2--];
			}else{
				numb_2[i]= '0';
			}
		}
		numb_2[strlen(numb_1)]= '\0';
		binary_digit= strlen(numb_1);
	}else{
		i_2= strlen(numb_1)-1;
		for(i=strlen(numb_2)-1; i>=0; i--){
			if(i_2>=0){
				numb_1[i]= numb_1[i_2--];
			}else{
				numb_1[i]= '0';
			}
		}
		numb_1[strlen(numb_2)]= '\0';
		binary_digit= strlen(numb_2);
	}
}

//loading number into...........................................................................
void load_number(){
	
	system("cls");
	printf("\n\n\n\t\t\t\t----   Loading Binary Number   ----");
	printf("\n\n\t\t01. Enter the First Number: ");
	for(;;){
		fflush(stdin);
		scanf("%s", numb_1);
		if(number_check(1)==1&& strlen(numb_1)>0){
			printf("\n\n\t\t\t\t----   Verifying First Number   ----");
			printf("\n\n\t\t\tEntered Number: %s", numb_1);
			printf("\n\t\tEnter to proceed with the number or any other key to tryAgain....");
			if(getch()== '\r'){
				break;
			}else{
				printf("\n\t\tEnter Again: ");
			}
		}else{
			printf("\n\t\tWrong entry TryAgain[error code: %d]: ", number_check(1));
		}
	}
	
	printf("\n\n\t\t02. Enter the Second Number: ");
	for(;;){
		fflush(stdin);
		scanf("%s", numb_2);
		if(number_check(2)==1&& strlen(numb_2)>0){
			printf("\n\n\t\t\t\t----   Verifying First Number   ----");
			printf("\n\n\t\t\tEntered Number: %s", numb_2);
			printf("\n\t\tEnter to proceed with the number or any other key to tryAgain....");
			if(getch()== '\r'){
				break;
			}else{
				printf("\n\t\tEnter Again: ");
			}
		}else{
			printf("\n\t\tWrong entry TryAgain[error code: %d]: ", number_check(2));
		}
	}
	
	make_same_length();
}

void binary_addition(){
	
	int i;
	system("cls");
	printf("\n\n\n\t\t\t\t----   Binary Addition   ----");
	
	printf("\n\n\t\t\t%s + %s = %s", numb_1, numb_2, numb_add);
}

void booths_multiplication(){
	printf("Booths Multiplication");
	getch();
}

//main menu content display..................................................................
void main_menu_display(int display_option){
	
	system("cls");
	printf("\n\n\n\t\t\t\t----   Operations On Binary[Operation Width: %d]   ----", binary_digit);
	if(binary_digit> 0){
		printf("\n\n\tBinary Number 1: %s\t\t\t\t\t\t\tBinary Number 2: %s", numb_1, numb_2);
	}
	printf("\n\n\t\t\t01. Load Number\t\t\t\t\t02. Binary Addition");
	printf("\n\t\t\t03. Bootrh's Multiplication\t\t\t04. Exit");
	if(display_option==1){
		printf("\n\n\t\t\tPlease Choose a Option: ");
	}else if(display_option==2){
		printf("\n\n\t\t\tWrong option try again: ");
	}
}

//Main Menu to deside where to go.............................................................
void main_menu(){
	
	main_menu_display( 1);
	
	for(;;){
		switch(getch()){
			case '1':
				load_number();
				main_menu_display( 1);
				break;
			case '2':
				binary_addition();
				main_menu_display( 1);
				break;
			case '3':
				booths_multiplication();
				main_menu_display( 1);
				break;
			case '4':
				exit(0);
				break;
			default:
				main_menu_display( 2);
				
		}
	}
}

//Main function runs first......................................................................
int main(int argc, char const *argv[]) {
	
	welcome();
	load_number();
	main_menu();
	return 0;
}
