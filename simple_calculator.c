/*SIMPLE CALCULATOR
Author: Sumit Yeotkar*/


#include<stdio.h>
#include<math.h>


void print_menu();  // function to print menu
double Division(double, double);
double Modulus(double, double);


int main(){
    int choice;
    double num1, num2, result;

   while(1){
    print_menu();
    printf("\nPlease, Enter Your Choice (1 to 7):");
    scanf("%d", &choice);
    if(choice == 7){
        break;
    }

    if( choice < 1 || choice > 7){
        fprintf(stderr, "\nPlease Enter Valid Choice");
        continue;
        print_menu();
    }

    printf("Enter the First Number:");
    scanf("%lf", &num1);
    printf("Enter the Second Number:");
    scanf("%lf", &num2);
    
    // operations
    switch(choice){
        case 1 : // Add
        result = num1 + num2;
             break;
        case 2 : // Subtract
        result = num1 - num2;
             break;
        case 3 : // Multiply
        result = num1 * num2;
             break;
        case 4 : // Divide
        result = Division(num1, num2);
             break;
        case 5 : // Modulus
        result = Modulus(num1, num2);
             break;
        case 6 : // Power
        result = pow(num1, num2) ;
             break;
                            
    }

    if(!isnan(result)){
    printf("\nResult of Operation is %.2f\n", result);
    }

}

return 0;

}


double Division(double a, double b){
    if( b == 0){
        fprintf(stderr, "Invalid Argument for Division");
        return NAN;
    }else{
        return a/b ;
    }

}

double Modulus(double a, double b){
    if( b == 0){
        fprintf(stderr, "\nInvalid Argument for Modulus");
        return NAN;
    }else{
        return (int)a % (int)b ;
    }

}

void print_menu(){
printf("\n\n************************************");
printf("\nWELCOME TO SIMPLE CALCULATOR");
printf("\nSelect an Option:");
printf("\n1.Add");
printf("\n2.Subtract");
printf("\n3.Multiply");
printf("\n4.Divide");
printf("\n5.Modulus");
printf("\n6.Power");
printf("\n7.Exit");

}
