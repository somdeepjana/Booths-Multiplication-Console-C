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
int number_check(char *number_to_check){
	int temp= 0, checked_length=0;
	while(number_to_check[temp]!= '\0'){
		if(number_to_check[temp]== '1' || number_to_check[temp]== '0'){
			checked_length++;
		}else{
			return -1;
		}
		temp++;
	}
	if(checked_length== strlen(number_to_check)){
		return 1;
	}else{
		return 0;
	}
}

//changing the number to required length[returns commited digit change length]......................................................
int change_numb_length(char *number_to_change, int length){
	
	int i, i_2, commited_change= 0;
	
	i_2= strlen(number_to_change);
	for(i=length; i>=0; i--){
		if(i_2>=0){
			number_to_change[i]= number_to_change[i_2--];
		}else{
			number_to_change[i]= '0';
			commited_change++;
		}
	}
	return commited_change;
}

//making both the numbers same width[returns the numbers length]...........................................................
int make_same_length(char *number_to_change_1, char *number_to_change_2){
	
	if(strlen(number_to_change_1)>strlen(number_to_change_2)){
		
		int greater_numb_length= strlen(number_to_change_1);
		
		change_numb_length(number_to_change_2, greater_numb_length);
		return greater_numb_length;
	}else if(strlen(number_to_change_1)!=strlen(number_to_change_2)){
		return make_same_length(number_to_change_2, number_to_change_1);
	}else{
		return strlen(number_to_change_1);
	}
}

//loading number into...........................................................................
void load_number(){
	
	int temp_chek_code;
	
	system("cls");
	printf("\n\n\n\t\t\t\t----   Loading Binary Number   ----");
	printf("\n\n\t\t01. Enter the First Number: ");
	for(;;){
		fflush(stdin);
		scanf("%s", numb_1);
		temp_chek_code = number_check(numb_1);
		if(temp_chek_code==1&& strlen(numb_1)>0){
			printf("\n\n\t\t\t\t----   Verifying First Number   ----");
			printf("\n\n\t\t\tEntered Number: %s", numb_1);
			printf("\n\t\tEnter to proceed with the number or any other key to tryAgain....");
			if(getch()== '\r'){
				break;
			}else{
				printf("\n\t\tEnter Again: ");
			}
		}else{
			printf("\n\t\tWrong entry TryAgain[error code: %d]: ", temp_chek_code);
		}
	}
	
	printf("\n\n\t\t02. Enter the Second Number: ");
	for(;;){
		fflush(stdin);
		scanf("%s", numb_2);
		temp_chek_code = number_check(numb_2);
		if(temp_chek_code==1&& strlen(numb_2)>0){
			printf("\n\n\t\t\t\t----   Verifying First Number   ----");
			printf("\n\n\t\t\tEntered Number: %s", numb_2);
			printf("\n\t\tEnter to proceed with the number or any other key to tryAgain....");
			if(getch()== '\r'){
				break;
			}else{
				printf("\n\t\tEnter Again: ");
			}
		}else{
			printf("\n\t\tWrong entry TryAgain[error code: %d]: ", temp_chek_code);
		}
	}
	
	binary_digit= make_same_length(numb_1, numb_2);
}

//adding two binary numbers......................................................................
void binary_addition(char *number_to_add_1, char *number_to_add_2, char *result, int is_take_carry){
	
	if (strlen(number_to_add_1)!= strlen(number_to_add_2)){
		binary_digit= make_same_length(numb_1, numb_2);
	}
	int i, length= strlen(number_to_add_1), result_travel_pointer;
	char prev_carry= '0';
	
	if(is_take_carry== -1){
			result_travel_pointer= length-1;
	}else{
		result_travel_pointer= length;
	}
	for(i= length-1; i>=0; i--){
		if(number_to_add_1[i]== '0' && number_to_add_2[i]== '0'){
			if(prev_carry== '0'){
				result[result_travel_pointer--]= '0';
			}else{
				result[result_travel_pointer--]= prev_carry;
			}
			prev_carry= '0';
		}else if(number_to_add_1[i]== '0' && number_to_add_2[i]== '1'){
			if(prev_carry== '0'){
				result[result_travel_pointer--]= '1';
			}else{
				result[result_travel_pointer--]= '0';
				prev_carry= '1';
			}
		}else if(number_to_add_1[i]== '1' && number_to_add_2[i]== '1'){
			if(prev_carry== '0'){
				result[result_travel_pointer--]= '0';
				prev_carry= '1';
			}else{
				result[result_travel_pointer--]= '1';
				prev_carry= '1';
			}
		}else if(number_to_add_1[i]== '1' && number_to_add_2[i]== '0'){
			if(prev_carry== '0'){
				result[result_travel_pointer--]= '1';
			}else{
				result[result_travel_pointer--]= '0';
				prev_carry= '1';
			}
		}
	}
	if(is_take_carry== -1){
		result[length]= '\0';
	}else{
		result[0]= prev_carry;
		result[length+1]= '\0';
	}
}

void binary_addition_visual(){
	
	char result[binary_digit];
	
	system("cls");
	printf("\n\n\n\t\t\t\t----   Binary Addition   ----");
	binary_addition(numb_1, numb_2, result, 0);
	
	printf("\n\n\t\t\t\"%s\" added with \"%s\" equals \"%s\"", numb_1, numb_2, result);
	
	printf("\n\n\t\t\tPress any key to goBack..........");
	getch();
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
				binary_addition_visual();
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
