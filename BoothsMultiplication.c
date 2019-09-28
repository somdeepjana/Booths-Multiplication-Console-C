#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void hello(){
	SetConsoleTitle("HELLO");
	system("cls");
	system("COLOR 0E");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 186.5, 124, 993, 518, TRUE);
	printf("\n\n\n\n");
	printf("              _____                      _____                      _____            _____           _______         \n");
	printf("             /     :                    /     :                    /     :          /     :         /::     :        \n");
	printf("            /:: ____:                  /::     :                  /:: ____:        /:: ____:       /::::     :       \n");
	printf("           /:::/    /                 /::::     :                /:::/    /       /:::/    /      /::::::     :      \n");
	printf("          /:::/    /                 /::::::     :              /:::/    /       /:::/    /      /::::::::     :     \n");
	printf("         /:::/    /                 /:::/::::     :            /:::/    /       /:::/    /      /:::/~~::::     :    \n");
	printf("        /:::/____/                 /:::/__::::     :          /:::/    /       /:::/    /      /:::/    ::::     :   \n");
	printf("       /::::.    :                /::::    ::::     :        /:::/    /       /:::/    /      /:::/    / ::::     :  \n");
	printf("      /::::::.    :   _____      /::::::    ::::     :      /:::/    /       /:::/    /      /:::/____/   :::: ____: \n");
	printf("     /:::/::::.    : /     .    /:::/::::    ::::     :    /:::/    /       /:::/    /      |:::|    |     |:::|    |\n");
	printf("    /:::/  ::::.    /:: ____.  /:::/__::::    :::: ____:  /:::/____/       /:::/____/       |:::|____|     |:::|    |\n");
	printf("     ::/    ::::.  /:::/    /  ::::    ::::    :::/    /  ::::     :       ::::     :        ::::    :    /:::/    / \n");
	printf("      /____/ ::::./:::/    /    ::::    ::::    :/____/    ::::     :       ::::     :        ::::    :  /:::/    /  \n");
	printf("              :::::::/    /      ::::    ::::     :         ::::     :       ::::     :        ::::    :/:::/    /   \n");
	printf("               :::::/    /        ::::    :::: ____:         ::::     :       ::::     :        :::: __/:::/    /    \n");
	printf("               /:::/    /          ::::    :::/    /          ::::     :       ::::     :        :::::::::/    /     \n");
	printf("              /:::/    /            ::::    :/____/            ::::     :       ::::     :        :::::::/    /      \n");
	printf("             /:::/    /              ::::     :                 ::::     :       ::::     :        :::::/    /       \n");
	printf("            /:::/    /                :::: ____:                 :::: ____:       :::: ____:        :::/____/        \n");
	printf("            '::/    /                  :::/    /                  :::/    /        :::/    /         ~~              \n");
	printf("             '/____/                    :/____/                    :/____/          :/____/                          \n");
	getch();
}

//welcome scree credit printing...............................................................
void about(){
	SetConsoleTitle("BinaryOperation @ About");
	system("cls");
	system("COLOR 0E");
	printf("\n\n   |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~           [ ABOUT ]          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |\n\n");
	printf("         PROJECT NAME: Booth's Multiplication.\n");
	printf("         DATE: 28 September 2019, TIME: 12:54:42\n");
	printf("         SECTION: 3A\n");
	printf("         SEMESTER: 5th,  YEAR: 2019\n\n");
	printf("         ----------------------------        -------   GROUP MEMBERS   -------        -------------------------\n\n");
	printf("         ------------------------------------------------------------------------------------------------------\n");
	printf("         ROLL NO.         | NAME                           | ENEOLLMENT NO.                  | REGISTRATION NO.\n");
	printf("         ------------------------------------------------------------------------------------------------------\n");
	printf("                      55. | Somdeep Jana                   |                  12017009001009 |  304201700900661\n");
	printf("                      56. | Soumodip Roy                   |                  12017009001422 |  304201700900677\n");
	printf("         ------------------------------------------------------------------------------------------------------\n\n");
	printf("         ---------------------------         -------   FEATURE LIST   -------         -------------------------\n\n");
	printf("         01. Binary Addititon.\n");
	printf("         02. Binary Subtraction.\n");
	printf("         03. Two's Completement.\n");
	printf("         04. Booth's Multiplication.\n");
	printf("         05. Command Line Tools.\n\n");
	printf("   |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |");
	
}

void welcome(){
	hello();
	about();
	getch();
	system("COLOR 07");
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
	
	printf("\n\n\n\033[1;36m   |     ~~~~~~~~~~~~~~~~~~~~~~~           Two's Completement \033[0;33m%s \033[1;36mNumber            ~~~~~~~~~~~~~~~~~~~~~~", lable);
	if(strlen(lable)>5){
		printf("     |\n");
	}else{
		printf("~     |\n");
	}
	twos_completement(number_to_process, temp_first_numb);
	printf("\n\n\033[0;33m   |     Two's Completement of \033[1;32m\"%s\" \033[0;33mis \033[1;32m\"%s\"\033[0m", number_to_process, temp_first_numb);
	
}

//loading number into...........................................................................
void load_number(char *number_to_load, char *lable){
	SetConsoleTitle("BinaryOperation @ Loading Number");
	
	int temp_chek_code;
	
	printf("\n\n\033[1;36m   |     ~~~~~~~~~~~~~~~~~~~~~~~~~            Loading \033[0;33m%s \033[1;36mBinary Number           ~~~~~~~~~~~~~~~~~~~~~~~~", lable);
	if(strlen(lable)>5){
		printf("     |\n");
	}else{
		printf("~     |\n");
	}
	printf("\n\n\033[0;33m   |     Enter the Number: \033[1;32m");
	for(;;){
		fflush(stdin);
		scanf("%s", number_to_load);
		temp_chek_code = number_check(number_to_load);
		if(temp_chek_code==1&& strlen(number_to_load)>0){
			printf("\n\n\033[0;33m   |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~            Verifying \033[1;32m%s \033[0;33mNumber            ~~~~~~~~~~~~~~~~~~~~~~~~~~", lable);
			if(strlen(lable)>5){
				printf("     |\n");
			}else{
				printf("~     |\n");
			}
			printf("\n\033[1;36m   |     Entered Number: \033[0;33m%s", number_to_load);
			printf("\n\n\033[1;34m   |     Enter to proceed with the number or any other key to tryAgain: ");
			if(getch()== '\r'){
				printf("\033[0m");
				break;
			}else{
				printf("\n\n\033[0;33m   |     Enter Again: \033[1;32m");
			}
		}else{
			printf("\n\033[0;35m   |     Wrong entry TryAgain[error code: %d]: \033[0;33m", temp_chek_code);
		}
	}
}

//for printing on the screen about the addition output
void binary_addition_visual(char *first_number, char *second_number, char *lable){
	
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)];
	
	printf("\n\n\n\033[1;36m   |     ~~~~~~~~~~~~~~~~~~~~~~~           Binary Addition for \033[0;33m%s \033[1;36mNumber            ~~~~~~~~~~~~~~~~~~~~~~", lable);
	if(strlen(lable)>5){
		printf("     |\n");
	}else{
		printf("~     |\n");
	}
	binary_addition(first_number, second_number, result, 0);
	
	printf("\n\n\033[1;32m   |     \"%s\" \033[0;33madded with \033[1;32m\"%s\" \033[0;33mequals \033[1;32m\"%s\"\033[0m", first_number, second_number, result);
}

//for visually represent binary substraction using twos completement...................................
void binary_substraction_visual(char *first_number, char *second_number, char *lable){
	
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)], numb_sign;

	printf("\n\n\n\033[1;36m   |     ~~~~~~~~~~~~~~~~~~~~~~           Binary Subtraction for \033[0;33m%s \033[1;36mNumber          ~~~~~~~~~~~~~~~~~~~~~~", lable);
	if(strlen(lable)>5){
		printf("     |\n");
	}else{
		printf("~     |\n");
	}
	numb_sign= binary_substraction(first_number, second_number, result, 0);
	
	printf("\n\n\033[1;32m   |     \"%s\" \033[0;33mSubstracted from \033[1;32m\"%s\"\033[0;33m equals to \033[1;32m\"%c%s\"\033[0m", first_number, second_number, numb_sign, result);	
}
void booths_multiplication_visuual(char *first_number, char *second_number, char *lable){
	char result[(strlen(first_number)>=strlen(second_number)) ? strlen(first_number) : strlen(second_number)], numb_sign;

	printf("\n\n\n\033[1;36m   |     ~~~~~~~~~~~~~~~~~~~~~          Booths Multiplication for \033[0;33m%s \033[1;36mNumbers          ~~~~~~~~~~~~~~~~~~~~~", lable);
	if(strlen(lable)>5){
		printf("     |\n");
	}else{
		printf("~     |\n");
	}
	numb_sign= booths_multiplication(first_number, second_number, result);
	
	printf("\n\n\033[1;32m   |     \"%s\" \033[0;33mMultiplied by \033[1;32m\"%s\" \033[0;33mequals to \033[1;32m\"%c%s\"\033[0m", first_number, second_number, numb_sign, result);
}

int is_contain(char *search_array, char to_search){
	int i= 0;
	while(search_array[i]!='\0'){
		if(search_array[i]== to_search){
			return 1;
		}
		i++;
	}
	return -1;
}

void optional_color_change(char *checking_array, int first_condition, char *first_color, char *default_color, char visited_condition, char *visited_color){
	if(first_condition<= 0){
		printf("%s", first_color);
	}else{
		if(is_contain(checking_array, visited_condition)== -1){
			printf("%s", default_color);
		}else{
			printf("%s", visited_color);
		}
	}
}
//#########################################################################    Menu Driven Functions(Display)    ##########################################

//main menu content display..................................................................
void main_menu_display(int display_option, char *number_to_display_1, char *number_to_display_2, char *visited_options){
	SetConsoleTitle("BinaryOperation @ MainMenu");
	HWND wh = GetConsoleWindow();
	MoveWindow(wh, 186.5, 124, 993, 518, TRUE);
	int binary_digit= (strlen(number_to_display_1)>=strlen(number_to_display_2)) ? strlen(number_to_display_1) : strlen(number_to_display_2);
	system("cls");
	
	if(binary_digit> 0){
		printf("\n\n\n\n\n\n\n");
	}else{
		printf("\n\n\n\n\n\n\n");
	}
	printf("\033[1;35m   |     ~~~~~~~~~~~~~~~~~~           Operations On Binary[ \033[0;36mOperation Width: %d\033[1;35m ]           ~~~~~~~~~~~~~~~~~~     |", binary_digit);
	if(binary_digit> 0){
		printf("\n\n");
		printf("         \033[1;36mBinary Number 1: \033[0;33m%s\n         \033[1;36mBinary Number 2: \033[0;33m%s\n\n", number_to_display_1, number_to_display_2);
		printf("\033[1;35m   |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |\n\n");
	}else{
		printf("\n\n\n\n");
	}
	optional_color_change( visited_options, binary_digit, "\033[1;32m", "\033[0;32m", 'l', "\033[1;33m");
	printf("         01. Load Number");
	optional_color_change( visited_options, binary_digit, "\033[1;31m", "\033[0;32m", 'a', "\033[1;33m");
	printf("                                                               02.    Binary Addition\n");
	optional_color_change( visited_options, binary_digit, "\033[1;31m", "\033[0;32m", 's', "\033[1;33m");
	printf("         03. Binary Substraction");
	optional_color_change( visited_options, binary_digit, "\033[1;31m", "\033[0;32m", 't', "\033[1;33m");
	printf("                                                       04. Two\'s Completement\n");
	optional_color_change( visited_options, binary_digit, "\033[1;31m", "\033[0;32m", 'b', "\033[1;33m");
	printf("         05. Bootrh's Multiplication");
	printf("\033[0;31m                                                   06.               Exit");
	if(binary_digit> 0){
		printf("\n\n");
	}else{
		printf("\n\n\n\n");
	}
	printf("\033[1;35m   |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     |\n\n\n");
	if(display_option==1){
		printf("\033[0;32m   |     Choose a Opton: ");
	}else if(display_option==2){
		printf("\033[0;33m   |     Wrong Option Try Again: ");
	}
	printf("\033[0m");
}

//Main Menu to deside where to go.............................................................
void main_menu(){
	
	char numb_1[20], numb_2[20], temp_number_1[20], temp_number_2[20], options_visited[9];
	system("cls");
	strcpy(numb_1, "");
	strcpy(numb_2, "");
	strcpy(options_visited, "");
	main_menu_display( 1, numb_1, numb_2, options_visited);
	
	for(;;){
		switch(getch()){
			case '1':
				strcpy(options_visited, "");
				strcat(options_visited, "l");
				system("cls");
				load_number(numb_1, "First");
				load_number(numb_2, "Second");
				make_same_length(numb_1, numb_2);
				main_menu_display( 1, numb_1, numb_2, options_visited);
				break;
			case '2':
				if(0== ((strlen(numb_1)>=strlen(numb_2)) ? strlen(numb_1) : strlen(numb_2))){
					goto lable_no_data_addition;
				}
				SetConsoleTitle("BinaryOperation @ Primary Addition");
				strcat(options_visited, "a");
				system("cls");
				binary_addition_visual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\033[1;34m   |     Press Enter to GoBack or any other key to try Temporal Number..........\033[0m");
					if(getch()!= '\r'){
lable_no_data_addition:
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						SetConsoleTitle("BinaryOperation @ Binary Addition");
						system("cls");
						binary_addition_visual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2, options_visited);
				break;
			case '3':
				if(0== ((strlen(numb_1)>=strlen(numb_2)) ? strlen(numb_1) : strlen(numb_2))){
					goto lable_no_data_substraction;
				}
				SetConsoleTitle("BinaryOperation @ Primary Substraction");
				strcat(options_visited, "s");
				system("cls");
				binary_substraction_visual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\033[1;34m   |     Press Enter to GoBack or any other key to try Temporal Number..........\033[0m");
					if(getch()!= '\r'){
lable_no_data_substraction:
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						system("cls");
						SetConsoleTitle("BinaryOperation @ Binary Substraction");
						binary_substraction_visual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2, options_visited);
				break;
			case '4':
				if(0== ((strlen(numb_1)>=strlen(numb_2)) ? strlen(numb_1) : strlen(numb_2))){
					goto lable_no_data_2scompletement;
				}
				SetConsoleTitle("BinaryOperation @ Primary Tow's Complement");
				strcat(options_visited, "t");
				system("cls");
				twos_completement_visual(numb_1, "First");
				twos_completement_visual(numb_2, "Second");
				for(;;){
					printf("\n\n\n\033[1;34m   |     Press Enter to GoBack or any other key to try a Temporal Number:\033[0m");
					if(getch()!= '\r'){
lable_no_data_2scompletement:
						system("cls");
						load_number(temp_number_1, "Temporal");
						system("cls");
						SetConsoleTitle("BinaryOperation @ Binary Tow's Complement");
						twos_completement_visual(temp_number_1, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2, options_visited);
				break;
			case '5':
				if(0== ((strlen(numb_1)>=strlen(numb_2)) ? strlen(numb_1) : strlen(numb_2))){
					goto lable_no_data_boothsmulti;
				}
				SetConsoleTitle("BinaryOperation @ Primary Booth's Multiplication");
				strcat(options_visited, "b");
				system("cls");
				booths_multiplication_visuual(numb_1, numb_2, "Primary");
				for(;;){
					printf("\n\n\n\033[1;34m   |     Press Enter to GoBack or any other key to try Temporal Number..........\033[0m");
					if(getch()!= '\r'){
lable_no_data_boothsmulti:
						system("cls");
						load_number(temp_number_1, "Temporal 1");
						load_number(temp_number_2, "Temporal 2");
						system("cls");
						SetConsoleTitle("BinaryOperation @ Binary Booth's Multiplication");
						booths_multiplication_visuual(temp_number_1, temp_number_2, "Temporal");
					}else{
						break;
					}
				}
				main_menu_display( 1, numb_1, numb_2, options_visited);
				break;
			case '6':
				exit(0);
				break;
			default:
				main_menu_display( 2, numb_1, numb_2, options_visited);
				
		}
	}
}

//Main function runs first......................................................................
int main(int argc, char const *argv[]) {
	
	welcome();
	main_menu();
	return 0;
}
