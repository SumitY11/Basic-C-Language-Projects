/* USER MANAGEMENT
Author: Sumit Yeotkar*/

#include <stdio.h>
#include <string.h>

#define MAX_USER 10
#define CRIDENTIAL_LENGTH 30

typedef struct {
   char username[CRIDENTIAL_LENGTH];
   char password[CRIDENTIAL_LENGTH];
} User;

User users [MAX_USER];
int user_count = 0;

void register_user();
int user_login(); // returns user index
void fix_fgets_inputs(char*);
void intput_credentials(char* username, char* password);

int main(){
    int option;
    int user_index;
    while(1){
    printf("\nWELCOME TO USER MANAGEMENT");
    printf("\n1.New User");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("\nSelect an Option:");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1:
    register_user();
        break;
    case 2:
    user_index = user_login();
    if(user_index >=0){
        printf("\nLogin Successful!!\nWelcome %s!!\n", users[user_index].username);
    }else{
        printf("\nLogin Failed ##\nIncorrect username or password.\n");
    }
        break;
    case 3:
    printf("\nExiting Program.");
    return 0;
    break;        
    
    default:
    printf("\nInvalid Option.\nPlease try again.");
    return 0;
    break;
    }
}
}


void register_user(){
    if (user_count == MAX_USER){
        printf("\nMaximum %d users are supported. No more user registration allowed.",MAX_USER);
        return;
    }

    int new_index = user_count;
    printf("\nRegister a New User");
    intput_credentials(users[new_index].username, users[new_index].password);
    user_count++ ;
    printf("\nRegistration successful!!\n");
}

int user_login(){
    char username[CRIDENTIAL_LENGTH];
    char password[CRIDENTIAL_LENGTH];

    intput_credentials(username,password);

    for (int i= 0; i < user_count; i++){
        if(strcmp(username, users[i].username) == 0 && strcmp(password,users[i].password) == 0){
            return i;
        }
    }
    return -1;
}

//fixes fgets enter problem
void fix_fgets_inputs(char* string){
   int index = strcspn(string, "\n");
   string[index] = '\0';
}


void intput_credentials(char* username, char* password){

    printf("\nEnter Username: ");
    fgets(username, CRIDENTIAL_LENGTH, stdin );
    fix_fgets_inputs(username);

    printf("Enter Password: ");
    fgets(password, CRIDENTIAL_LENGTH, stdin);
    fix_fgets_inputs(password);
}