#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

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
//##################################################    Functions for basic operations    ################################################################

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

//for getting twos completement of any number......................................
void twos_completement(char *number_to_change, char *changed_number_store){
	
	int i, length= strlen(number_to_change), first_sight_of_one= 0;
	
	for(i= length; i>=0; i--){
		if(first_sight_of_one==1){
			if(number_to_change[i]== '0'){
				changed_number_store[i]= '1';
			}else if(number_to_change[i]== '1'){
				changed_number_store[i]= '0';
			}
		}else if(first_sight_of_one== 0 && number_to_change[i]== '1'){
			first_sight_of_one= 1;
			changed_number_store[i]= number_to_change[i];
		}else{
			changed_number_store[i]= number_to_change[i];
		}
	}
}

//adding two binary numbers 0=getting last carry -1= not getting last carry..............................................................
char binary_addition(char *number_to_add_1, char *number_to_add_2, char *result, int is_take_carry){
	
	if (strlen(number_to_add_1)!= strlen(number_to_add_2)){
		make_same_length(number_to_add_1, number_to_add_2);
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
	return prev_carry;
}

//for calculation tow's completement using substraction....................................................
char binary_substraction(char *number_from_sub, char *number_to_sub, char *result, int is_sub_operation){
	
	if (strlen(number_from_sub)!= strlen(number_to_sub)){
		make_same_length(number_from_sub, number_to_sub);
	}
	
	char temp_completement[strlen(number_to_sub)], cary_generated;
	
	twos_completement(number_to_sub, temp_completement);
	cary_generated= binary_addition(number_from_sub, temp_completement, result, -1);
	if(cary_generated== '0' && is_sub_operation!= -1){
		twos_completement(result, result);
		return '-';
	}
	return ' ';
}

//to shifting binary number to one digit right[reurns right most digit after shifting, first_number replace the first digit with].............................
char binary_right_shift(char *number_to_change, char first_number){
	
	int i, length= strlen(number_to_change);
	char excluding_rightmost= number_to_change[length-1];
	
	for(i= length-1; i>0; i--){
		
		number_to_change[i]= number_to_change[i-1];
	}
	number_to_change[0]= first_number;
	return excluding_rightmost;
}

char booths_multiplication(char *multiplicant, char *multipliar, char *result){
	
	if (strlen(multiplicant)!= strlen(multipliar)){
		make_same_length(multiplicant, multipliar);
	}
	
	int length= strlen(multiplicant), count;
	char accumulator[length], Q[length], Qe= '0';
	
	strcpy(Q, multipliar);
	strcpy(accumulator, "0");
	change_numb_length(accumulator, length);
	
	for(count= length-1; count>= 0; count--){
		if(Q[length-1]== '1' && Qe== '0'){
			binary_substraction(accumulator, multiplicant, accumulator, -1);
		}else if(Q[length-1]== '0' && Qe== '1'){
			binary_addition(accumulator, multiplicant, accumulator, -1);
		}
		Qe= binary_right_shift(Q, binary_right_shift(accumulator, accumulator[0]));//arithmatic shift right with (Accumulator, Q, Qe)
	}
	strcpy(result, accumulator);
	strcat(result, Q);
	if(result[0]== '1'){
		twos_completement(result, result);
		return '-';
	}
	return ' ';
}

//###############################################################    Functions for UI Support(Visual)    #####################################################

//for visualy represent two's completement.................................................
void twos_completement_visual(char *number_to_process, char *lable){
	
	char temp_first_numb[strlen(number_to_process)];
	
	printf("\n\n\n\t\t\t\t----   Two's Completement %s Number   ----", lable);
	twos_completement(number_to_process, temp_first_numb);
	printf("\n\n\t\t\t Two's Completement of \"%s\" is \"%s\"", number_to_process, temp_first_numb);
	
}

//loading number into...........................................................................
void load_number(char *number_to_load, char *lable){
	
	int temp_chek_code;
	printf("\n\n\n\t\t\t\t----   Loading %s Binary Number   ----", lable);
	printf("\n\n\t\tEnter the Number: ");
	for(;;){
		fflush(stdin);
		scanf("%s", number_to_load);
		temp_chek_code = number_check(number_to_load);
		if(temp_chek_code==1&& strlen(number_to_load)>0){
			printf("\n\n\t\t\t\t----   Verifying %s Number   ----", lable);
			printf("\n\n\t\t\tEntered Number: %s", number_to_load);
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
}

//for printing on the screen about the addition output
void binary_addition_visual(char *first_number, char *second_number, char *lable){
	
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)];
	
	printf("\n\n\n\t\t\t\t----   Binary Addition for %s Number   ----", lable);
	binary_addition(first_number, second_number, result, 0);
	
	printf("\n\n\t\t\t\"%s\" added with \"%s\" equals \"%s\"", first_number, second_number, result);
}

//for visually represent binary substraction using twos completement...................................
void binary_substraction_visual(char *first_number, char *second_number, char *lable){
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)], numb_sign;
	
	printf("\n\n\n\t\t\t\t----   Binary Subtraction for %s Number   ----", lable);
	numb_sign= binary_substraction(first_number, second_number, result, 0);
	
	printf("\n\n\t\t\t\"%s\" Substracted from \"%s\" equals to \"%c%s\"", first_number, second_number, numb_sign, result);	
}
void booths_multiplication_visuual(char *first_number, char *second_number, char *lable){
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)], numb_sign;

	printf("\n\n\n\t\t\t\t----   Booths Multiplication for %s Numbers   ----", lable);
	numb_sign= booths_multiplication(first_number, second_number, result);
	
	printf("\n\n\t\t\t\"%s\" Multiplied by \"%s\" equals to \"%c%s\"", first_number, second_number, numb_sign, result);
}

//#########################################################################    Menu Driven Functions(Display)    ##########################################

//main menu content display..................................................................
void main_menu_display(int display_option, char *number_to_display_1, char *number_to_display_2){
	
	int binary_digit= (strlen(number_to_display_1)>=strlen(number_to_display_2)) ? strlen(number_to_display_1) : strlen(number_to_display_2);
	system("cls");
	printf("\n\n\n\t\t\t\t----   Operations On Binary[Operation Width: %d]   ----", binary_digit);
	if(binary_digit> 0){
		printf("\n\n\tBinary Number 1: %s\t\t\t\t\t\t\tBinary Number 2: %s", number_to_display_1, number_to_display_2);
	}
	printf("\n\n\t\t\t01. Load Number\t\t\t\t\t02. Binary Addition");
	printf("\n\t\t\t03. Binary Substraction\t\t\t\t04. Two\'s Completement");
	printf("\n\t\t\t05. Bootrh's Multiplication\t\t\t06. Exit");
	if(display_option==1){
		printf("\n\n\t\tPlease Choose a Option: ");
	}else if(display_option==2){
		printf("\n\n\t\tWrong option try again: ");
	}
}

//Main Menu to deside where to go.............................................................
void main_menu(){
	
	char numb_1[20], numb_2[20], temp_number_1[20], temp_number_2[20];
	system("cls");
	strcpy(numb_1, "");
	strcpy(numb_2, "");
	main_menu_display( 1, numb_1, numb_2);
	
	for(;;){
		switch(getch()){
			case '1':
				system("cls");
				load_number(numb_1, "First");
				load_number(numb_2, "Second");
				make_same_length(numb_1, numb_2);
				main_menu_display( 1, numb_1, numb_2);
				break;
			case '2':
				system("cls");
				binary_addition_visual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\t\tPress Enter to GoBack or any other key to try Temporal Number..........");
					if(getch()!= '\r'){
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						system("cls");
						binary_addition_visual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2);
				break;
			case '3':
				system("cls");
				binary_substraction_visual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\t\tPress Enter to GoBack or any other key to try Temporal Number..........");
					if(getch()!= '\r'){
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						system("cls");
						binary_substraction_visual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2);
				break;
			case '4':
				system("cls");
				twos_completement_visual(numb_1, "First");
				twos_completement_visual(numb_2, "Second");
				for(;;){
					printf("\n\n\n\t\tPress Enter to GoBack or any other key to try a Temporal Number..........");
					if(getch()!= '\r'){
						system("cls");
						load_number(temp_number_1, "Temporal");
						system("cls");
						twos_completement_visual(temp_number_1, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2);
				break;
			case '5':
				system("cls");
				booths_multiplication_visuual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\t\tPress Enter to GoBack or any other key to try Temporal Number..........");
					if(getch()!= '\r'){
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						system("cls");
						booths_multiplication_visuual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2);
				break;
			case '6':
				exit(0);
				break;
			default:
				main_menu_display( 2, numb_1, numb_2);
				
		}
	}
}

//Main function runs first......................................................................
int main(int argc, char const *argv[]) {
	
	welcome();
	//system("cls");
	//load_number(numb_1, "First");
	//load_number(numb_2, "Second");
	//make_same_length(numb_1, numb_2);
	main_menu();
	return 0;
}
