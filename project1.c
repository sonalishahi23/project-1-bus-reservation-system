#include<stdio.h>
#include<string.h>

/* ===== Function Declarations ===== */
int menu();                 
int registration();
int validate_name(char full_name[]);
int validate_username(char username[]);
int validate_password(char password[]);
int validate_email(char email[]);
int validate_phone(char mobile[]);
int login();
int dashboard();
int book_ticket();
int cancel_ticket();
int bus_status();
int payment();
int validate_upi(char upi_id[]);
int validate_card(char card_number[]);
int ticket();


char username[20],password[20];       

int seats_booked[10] = {0};             
int bus_number[10]={101,102,103,104,105,106,107,108,109,110};  
int total_seats[10] = {20,25,18,30,20,22,15,28,20,25};          

float fare[10] = {2500.0, 1200.0, 850.0, 920.0, 1050.0, 1100.0, 750.0, 600.0, 1300.0, 1500.0};           
char source[10][20]={"Delhi","Mumbai","Rajasthan","Gurugram","Chandhigarh","Uttrakhand","Punjab","Jaipur","Lucknow","Chennai"};
char destination[10][20]={"Chennai","Chandhigarh","Bihar","Punjab","Lucknow","Jaipur","Delhi","Gujarat","Gurugram","Mumbai"};

int current_bus_index , user_seats,user_bus;          
int transaction_id = 10000001;



int main()
{
 int choice;
 int registered=0;
 do
   {
       choice = menu();
       if (choice == 1)
       {
        printf("\n========================================\n");
        printf("~~~~~~~~~~User Registration~~~~~~~~~~");
        printf("\n========================================\n");
         registered = registration();
       }
       else if (choice == 2)
       {
           if (registered == 0)
           {
              printf("No user registered yet. Please register first.\n");
           }
           else
           {
              if (login() == 1)   
              {
                  dashboard();
              }
           }
       }
       else if (choice==3)
       {
           printf("Exit Option is Selected.\nThank You for using our Bus Reseveration system.\n\n");
       }
       else
       {
           printf("Invaild Option Selected. Please try again.\n");
       }
    }
    while (choice!=3);
    
    return 0;
}

/*function definition*/
/*~~~~~~~~Menu Function~~~~~~~~~*/
int menu()
{
    int choice;
    printf("\n========================================\n");
    printf("*********BUS RESERVATION SYSTEM*********");
    printf("\n========================================\n");
    printf("1. Registration\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("----------------------------------------\n");
    printf("Choose Any Option:- ");
    scanf("%d", &choice);

    return choice;
}

/*~~~~~~~~Registration Function~~~~~~~~~*/
int registration()
{
    char confirm[20],mobile[11],fullname[30],email[30];
    int registered=0;
       do
       {
          printf ("Enter your Full name   :- ");
          scanf (" %[^\n]",&fullname);
       } 
       while ( validate_name(fullname)==0 );
       
       do
       {
          printf ("Enter Username         :- ");
          scanf (" %s",&username );
       } 
       while ( validate_username(username)==0 );
      
        do                                   
        {
           printf ("Enter a Password      :- ");
           scanf (" %s", &password);
           printf ("Confirm Password      :- ");
           scanf(" %s",&confirm);
           if(strcmp(password, confirm) != 0)
           {
              printf("Mismatch Password!!\n");
           }
           else if(validate_password(password) == 0)
           {
             /*Password is Invalid*/
           }
           else
           {
              printf("Password is Created Successfully.\n");
              break;
           }
        } 
        while (1);
        
        do
        {
          printf("Enter Your E-mail Id    :- ");
          scanf(" %s",&email);
        } 
        while (validate_email(email)==0);
        
        do
        {
          printf("Enter Your Mobile Number :- ");
          scanf(" %s", &mobile);  
          registered = validate_phone(mobile);
        } 
        while (registered == 0);
    
    return registered;
}

int validate_name(char fullname[])
{
    int valid=1;
    int length = strlen(fullname);
    if(length < 4)
    {
        printf("Invalid Name! Must be at least 4 characters long.\n");
        return 0;
    }
    for (int i=0;fullname[i]!='\0';i++)
    {
        if ((fullname[i] >= 'A' && fullname[i] <= 'Z') || (fullname[i] >= 'a' && fullname[i] <= 'z')||fullname[i]==' ')
        {
            // Check that name entered is in alphabet. 
        }
        else
        {
           valid=0;
           break;
        }
    }
       if (valid==0)
       {
          printf("Invalid Name! Only alphabets allowed.\n");
          return 0;
       }
       else
       {
          return 1;
       }
}
int validate_username(char username[])
{
    int valid=1;
    int alphabet=0;
    int length = strlen(username);
    if (length < 6)
    {
        printf("Invalid Username! Must be at least 6 characters long.\n");
        return 0;
    }

     for (int i = 0; username[i] != '\0'; i++)
    {
        if ((username[i] >= 'A' && username[i] <= 'Z') || (username[i] >= 'a' && username[i] <= 'z'))
        {
            alphabet=1;
        }
        else if ((username[i] >= '0' && username[i] <= '9') || username[i] == '_')
        {
            //checks that username consist digits and underscore.
        }
        else
        {
            valid = 0;
            break;
        }
    }
    if (valid == 0|| alphabet==0)
    {
        printf("Invalid Username!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int validate_password(char password[])
{
    int digit=0, uppercase=0,at_the_rate=0;
    int length = strlen(password);
    if (length < 6)
    {
        printf("Password must be at least 6 characters long.\n");
        return 0;
    }
    if (password[0] >= 'A' && password[0] <= 'Z')
    {
        uppercase=1;
    }
    for (int i = 0; password[i] != '\0'; i++)
    {
       if (password[i] >= '0' && password[i] <= '9')
       {
           digit = 1;
       }
       else if (password[i] == '@')
       {
         at_the_rate=1;
       }
    }
    if (uppercase && digit && at_the_rate)
    {
        return 1;  
    }
    else
    {
        printf("Password must start with uppercase letter, contain digits and '@'.\n");
        return 0;  
    }
}

int validate_email(char email[])
{
    int i = 0;
    if ((email[0] >= 'A' && email[0] <= 'Z') || (email[0] >= 'a' && email[0] <= 'z'))
    {
    // First character is a letter
    }
    else
    {
    printf("Invalid Email! Username must start with a letter.\n");
    return 0;
}
    while (email[i] != '\0' && email[i] != '@')
    {
        if( (email[i] >= 'A' && email[i] <= 'Z') || (email[i] >= 'a' && email[i] <= 'z') || (email[i] >= '0' && email[i] <= '9') )
        {
           //check email username
        }
        else
        {
            printf("Invalid Email! Only letters and digits allowed before '@'.\n");
            return 0;
        }
        i++;
    }
    if (i == 0)
    {
        printf("Invalid Email! Username missing before '@'.\n");
        return 0;
    }
    if (email[i] != '@') 
    {
        printf("Invalid Email! \n");
        return 0;
    }
    i++; 
    if (strcmp(&email[i], "gmail.com") == 0)
    {
        return 1; 
    }
    else
    {
        printf("Invalid Email! \n");
        return 0;
    }
}

int validate_phone(char mobile[])
{
    int length,userotp,otp=7865, registered=0, same = 1;;
    length = strlen(mobile);
    if(length != 10)
    {
        printf("Invalid Mobile Number! Must be exactly 10 digits.\n");
        return 0;
    }
    for(int i = 0; i < 10; i++)
    {
        if(mobile[i] < '0' || mobile[i] > '9')
        {
            printf("Invalid Mobile Number! Only digits allowed.\n");
            return 0;
        }
    }
    for(int i = 1; i < 10; i++)
    {
        if(mobile[i] != mobile[0])
        {
            same = 0;
            break;
        }
    }

    if(same == 1)
    {
        printf("Invalid Mobile Number! Digits cannot be all same.\n");
        return 0;
    }
    printf("Valid Mobile Number.\n");
    printf("You get An OTP On this Mobile Number\n");
    for(int i=1;i<=3;i++)
    {
    printf("\n");
    printf("OTP is :- %d\n", otp);
    printf("\n");
    printf("Enter Your OTP:- ");
    scanf("%d", &userotp);
    if(userotp==otp)
    {
       printf("You are Registered Successfully!!\n");
       registered = 1;
       break;
    }
    else if(i<3)
    {
        printf("Invaild OTP.");
    }
    }
    if(registered == 0)
    {
        printf("OTP verification failed. Please restart registration.\n");
    }
    return registered;
}

//~~~~~~~~~~Login Function~~~~~~~~~~~~//
int login()
{
    char login_user[20], login_pass[20];
    printf("\n========================================\n");
    printf("~~~~~~~~~~~Login Credentials~~~~~~~~~~~");
    printf("\n========================================\n");
    printf("Enter Username  :- ");
    scanf(" %s", login_user);
    printf("Enter Password  :- ");
    scanf(" %s", login_pass);
    if(strcmp(login_user, username) == 0 && strcmp(login_pass, password) == 0)
    {
       printf("Login Successfully. Welcome %s\n\n", login_user);
       return 1;
    }
    else
    {
        printf("Invalid Username or Password\n\n");
        return 0;
    }
}

//______Dashboard Function__________//
int dashboard()
{
    int option;
    do
    {
       printf("\n========================================\n");
       printf("^^^^^^^^^^^^User Dashboard^^^^^^^^^^^^");
       printf("\n========================================\n");
       printf("1. Book a Ticket\n");
       printf("2. Cancel a Ticket\n");
       printf("3. Check Bus Status\n");
       printf("4. Logout\n\n");
       printf("----------------------------------------\n");
       printf("Enter Any Option:- ");
       scanf("%d", &option);
       if(option==1)
        {
            book_ticket();
        }
        else if(option==2)
        {
            cancel_ticket();
        }
        else if(option==3)
        {
            bus_status();
        }
        else if(option==4)
        {
            printf("Logout successful. Thank you!\n\n");
        }
    } 
    while (option != 4);

    return 0;
}

/*Booking a Ticket Function*/
int book_ticket()
{
    int found=0;
    printf("\n========================================\n");
    printf("***********Booking a Ticket***********");
    printf("\n========================================\n");
    printf("Enter Bus Number:- ");
    scanf("%d", &user_bus);
    for( int i=0;i<10;i++)
    {
        if(user_bus==bus_number[i])
        {
            current_bus_index = i;  
            found=1;
            printf("Enter the Number of Seats you want to book:- ");
            scanf("%d", &user_seats);
            if (user_seats <= 0)
            {
               printf("Invalid seat count! Please enter at least 1 seat.\n\n");
               break;
            }
            else if(user_seats <= total_seats[i] - seats_booked[i])
            {
               seats_booked[i] += user_seats;
               if (payment()==1)
               {
                  printf("\nBooking is Successfully Done.\n%d seats booked on Bus %d successfully.\n\n", user_seats, user_bus);
                  ticket();
                  break;
               }
               else
               {
                  printf("Payment Failed. Booking Cancelled.\n");
                  seats_booked[i] -= user_seats;  
                  break;
               }
            }
            else
            {
               printf("Only %d seats are available on Bus %d.\n\n", total_seats[i] - seats_booked[i], user_bus);
            }
               break;
        }
    }
    if(found==0)
    {
        printf("Invalid Bus Number\n");
    }
    return 0;
}

//Cancelling a ticket//
int cancel_ticket()
{
    int found;
    int cancel_seat;
    found=0;
    printf("\n========================================\n");
    printf("**********Cancelling a Ticket**********");
    printf("\n========================================\n");
    printf("Enter Bus Number:- ");
    scanf("%d", &user_bus);
    for(int i=0;i<10;i++)
    {
        if(user_bus==bus_number[i])
        {
            found=1;
            printf("Enter the Number of Seats you want to Cancel:- ");
            scanf("%d", &cancel_seat);
            if ( seats_booked[i]==0)
            {
                printf("No Seats are booked yet to cancel\n");
                break;
            }
            else if(cancel_seat <= seats_booked[i])
            {
                seats_booked[i] -= cancel_seat;

                printf("Cancellation Successfully Done.\n%d seats are cancelled on Bus Number %d.\n\n", cancel_seat, user_bus);
                break;
            }
            else
            {
                printf("Cannot cancel more seats than booked!\n\n");
                break;
            }
        }

    }
    if(found==0)
    {
        printf("Invalid Bus Number\n\n");
    } 
    return 0;
}

//Checking Status Of a bus or bus details//
int bus_status()
{
    int user_bus;
    int found=0;
    printf("Enter The Bus Number:- ");
    scanf("%d",&user_bus);
    for(int i=0;i<10;i++)
    {
        if(user_bus==bus_number[i])
        {
            found=1;
            printf("\n========================================\n");
            printf("***********BUS %d DETAILS***********\n\n",bus_number[i]);
            printf("\n========================================\n");
            printf("Bus Number       : %d\n",bus_number[i]);
            printf("Source City      : %s\n",source[i]);
            printf("Destination City : %s\n",destination[i]);
            printf("Total Seats      : %d\n",total_seats[i]);
            printf("Available Seats  : %d\n",total_seats[i]-seats_booked[i]);
            printf("Amount           : %.2f\n",fare[i]);
            printf("----------------------------------------\n");
            break;
        }
    }
    if(found==0)
    {
        printf("Invalid Bus Number\n\n");
    }
    return 0;
}

/*Payment of ticket*/
int payment()
{
   float total= fare[current_bus_index]*user_seats;
   int method;
   printf("\n========================================\n");
   printf("             PAYMENT DETAILS\n");
   printf("========================================\n");
   printf("Total Amount to be Paid:- %.2f\n",total);
   printf("Choose Payment Method\n");
   printf("1.UPI\n");
   printf("2.Credit Card\n");
   printf("Enter option: ");
   scanf("%d", &method);
   if(method==1)
   {
        char upi_id[30];
        do
        {
        printf("Enter UPI ID: ");
        scanf(" %s", &upi_id);
        }
        while (validate_upi(upi_id)==0);
        transaction_id++;
        printf("UPI Payment is Successfull.\n");
        printf("Transaction ID:- %d\n", transaction_id);
        return 1;
   }
   else if(method==2)
   {
      char card_number[17];
      do
      {
      printf("Enter Credit Card Number: ");
      scanf(" %s", &card_number);
      }
      while (validate_card(card_number)==0);
      transaction_id++;
      printf("Credit Card Payment is Successfull.\n");
      printf("Transaction ID:- %d\n", transaction_id);
      return 1;
   }
   else
   {
      printf("Invalid Payment Method Selected.\n");
      return 0;
   }
   printf("----------------------------------------\n");
   return 0;
}
int validate_upi(char upi_id[])
{
    int i=0;
    int length=strlen(upi_id);
    if(length<6)
    {
        printf("Invalid UPI ID!! Must be at least 6 characters long.\n");
        return 0;
    }
    if ((upi_id[0] >= 'A' && upi_id[0] <= 'Z') || (upi_id[0] >= 'a' && upi_id[0] <= 'z') ||(upi_id[0] >= '0' && upi_id[0] <= '9'))
    {
        // valid start
    }
    else
    {
        printf("Invalid UPI ID! Must start with a letter or digit.\n");
        return 0;
    }
    while(upi_id[i] != '\0' && upi_id[i] != '@')
    {
        if((upi_id[i] >= 'A' && upi_id[i] <= 'Z') ||(upi_id[i] >= 'a' && upi_id[i] <= 'z') ||(upi_id[i] >= '0' && upi_id[i] <= '9') ||
           upi_id[i] == '.' || upi_id[i] == '_')
        {
            // valid character
        }
        else
        {
            printf("Invalid UPI ID! Only letters, digits, '.' and '_' allowed before '@'.\n");
            return 0;
        }
        i++;
    }
    if(upi_id[i] != '@')
    {
        printf("Invalid UPI ID! '@' is Missing.\n");
        return 0;
    }
    i++;
    if(upi_id[i] == '\0') {
    printf("Invalid UPI ID! Bank name missing after '@'.\n");
    return 0;
}
for(; upi_id[i] != '\0'; i++)
{
    if (!((upi_id[i] >= 'A' && upi_id[i] <= 'Z') || (upi_id[i] >= 'a' && upi_id[i] <= 'z')))
    {
        printf("Invalid UPI ID! Bank name should contain only letters.\n");
        return 0;
    }
}
return 1;
}

int validate_card(char card_number[])
{
    int length = strlen(card_number);

   
    if(length != 16)
    {
        printf("Invalid Card Number! Must be exactly 16 digits.\n");
        return 0;
    }
    int all_same = 1;
    for(int i = 0; i < 16; i++)
    {
        if(card_number[i] < '0' || card_number[i] > '9')
        {
            printf("Invalid Card Number! Only digits allowed.\n");
            return 0;
        }
        if(card_number[i] != card_number[0])
        {
            all_same = 0;
        }
    }

    if(all_same==1)
    {
        printf("Invalid Card Number! All digits cannot be the same.\n");
        return 0;
    }

    return 1; // Valid card
}

int ticket()
{
   printf("\n");
   printf("\n========================================\n");
   printf("\n************* BUS TICKET *************\n");
   printf("\n========================================\n");
   printf("Bus Number       : %d\n", bus_number[current_bus_index]);
   printf("Source           : %s\n", source[current_bus_index]);
   printf("Destination      : %s\n", destination[current_bus_index]);
   printf("Seats Booked     : %d\n", user_seats);
   printf("Total Amount Paid: %.2f\n", fare[current_bus_index] * user_seats);
   printf("Transaction ID   : %d\n", transaction_id);
   printf("*******************************************\n\n");
   printf("\n");
   return 0;
}



    

