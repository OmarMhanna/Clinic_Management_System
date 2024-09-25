#include "CMS.h"

void main_Menu(void){

    unsigned char choice;
    unsigned char check_Password;
    volatile unsigned char is_Admin_Mode_Locked=0;

    database=malloc(database_Length * sizeof(patient));

    while(1){

        if(is_Admin_Mode_Locked){

            printf("\n=================Main Menu==================\n\n1. Admin (LOCKED)\n2. Guest\n3. Exit\n\nPlease enter your choice: ");
        }
        else{

            printf("\n=================Main Menu==================\n\n1. Admin\n2. Guest\n3. Exit\n\nPlease enter your choice: ");

        }

        fflush(stdin);
        scanf("%i", &choice);

        if(1==choice){

            if(is_Admin_Mode_Locked){

                printf("\nAdmin mode is locked!\n");
            }
            else{

                short password;

                printf("\nPlease enter password to access admin mode: ");
                scanf("%i", &password);

                if(1248!=password){

                    for(check_Password=0;check_Password<3;check_Password++){

                        printf("\nIncorrect password, please try again\n%i tries left!\n\nPlease enter password to access admin mode: ", 3-check_Password);
                        scanf("%i", &password);

                        if(1248==password){

                            break;
                        }
                    }
                }

                if(3!=check_Password){

                    while(1){

                        printf("\n=================Admin Mode=================\n\n1. Add new patient to system\n2. Remove patient from system\n3. Check patient data\n4. Book an appointment for patient\n5. Edit patient data\n6. Show all patients\n7. Return to main menu\n\nPlease enter your choice: ");
                        fflush(stdin);
                        scanf("%i", &choice);

                        if(1==choice){

                            add_Patient(&database[0]);
                        }
                        else if(2==choice){

                            remove_Patient(&database[0]);
                        }
                        else if(3==choice){

                            check_Patient(&database[0]);
                        }
                        else if(4==choice){

                            book_Appointment(&database[0]);
                        }
                        else if(5==choice){

                            edit_Patient(&database[0]);
                        }
                        else if(6==choice){

                            show_Patients(&database[0]);
                        }
                        else if(7==choice){

                            break;
                        }
                        else{

                            printf("\nInvalid input!\nPlease choose a number from \'1\' to \'7\'\n");
                        }
                    }
                }
                else{

                    is_Admin_Mode_Locked=1;

                    printf("\nYou have entered the wrong password 3 times\nAdmin mode is now locked!\n");
                }
            }
        }
        else if(2==choice){

            printf("\n=================Guest Mode=================\n");

            check_Patient(&database[0]);
        }
        else if(3==choice){

            free(database);
            database=NULL;

            printf("\n==================Exiting===================\n");

            return;
        }
        else{

            printf("\nInvalid input!\nPlease choose a number from \'1\' to \'3\'\n");
        }
    }
}

void add_Patient(patient *p){

    unsigned char check=0;
    unsigned char i;

    incremental_ID++;

    for(i=0;i<database_Length;i++){

        if(!(p[i].ID)){

            check=1;
            break;
        }
    }

    if(check){

        printf("\n================Add Patient=================");
        p[i].ID=incremental_ID;
        printf("\nPlease enter patient's name: ");
        fflush(stdin);
        gets(p[i].name);
        printf("Please enter patient's age: ");
        scanf("%i", &p[i].age);
        printf("Please enter patient's gender: ");
        fflush(stdin);
        gets(p[i].gender);
        printf("Please enter patient's address: ");
        fflush(stdin);
        gets(p[i].address);

        strcpy(p[i].disease, "N/A");
        strcpy(p[i].appointment_Date, "N/A");

        sort_Database(&database[0]);
    }
    else{

        database_Length++;
        database=realloc(database,sizeof(patient)*database_Length);

        printf("\n================Add Patient=================");
        p[i].ID=incremental_ID;
        printf("\nPlease enter patient's name: ");
        fflush(stdin);
        gets(p[i].name);
        printf("Please enter patient's age: ");
        scanf("%i", &p[i].age);
        printf("Please enter patient's gender: ");
        fflush(stdin);
        gets(p[i].gender);
        printf("Please enter patient's address: ");
        fflush(stdin);
        gets(p[i].address);

        strcpy(p[i].disease, "N/A");
        strcpy(p[i].appointment_Date, "N/A");
    }

    printf("\nPatient added successfully!\n");
}

void remove_Patient(patient *p){

    unsigned int search_ID;
    unsigned char check=0;
    unsigned char i;

    printf("\n===============Remove Patient===============");
    printf("\nPlease enter patient's ID: ");
    scanf("%i", &search_ID);

    for(i=0;i<database_Length;i++){

        if(p[i].ID==search_ID){

            check=1;
            break;
        }
    }

    if(check){

        p[i].ID=0;
        strcpy(p[i].name, "");
        p[i].age=0;
        strcpy(p[i].gender, "");
        strcpy(p[i].address, "");
        strcpy(p[i].disease, "");
        strcpy(p[i].appointment_Date, "");

        printf("\nPatient removed successfully!\n");
    }
    else{

        printf("\nPatient not found!\n");
    }
}

void check_Patient(patient *p){

    unsigned int search_ID;
    unsigned char check=0;
    unsigned char i;

    printf("\n===============Check Patient================");
    printf("\nPlease enter patient's ID: ");
    scanf("%i", &search_ID);

    for(i=0;i<database_Length;i++){

        if(p[i].ID==search_ID){

            check=1;
            break;
        }
    }

    if(check){

        printf("\n============Patient Information=============");
        printf("\nPatient's ID: %i", p[i].ID);
        printf("\nPatient's name: ");
        puts(p[i].name);
        printf("Patient's age: %i", p[i].age);
        printf("\nPatient's gender: ");
        puts(p[i].gender);
        printf("Patient's address: ");
        puts(p[i].address);
        printf("Patient's disease: ");
        puts(p[i].disease);
        printf("Patient's appointment date: ");
        puts(p[i].appointment_Date);
        printf("============================================\n");
    }
    else{

        printf("\nPatient not found!\n");
    }
}

void book_Appointment(patient *p){

    unsigned int search_ID;
    unsigned char check=0;
    unsigned char i;

    printf("\n============Book an Appointment=============");
    printf("\nPlease enter patient's ID: ");
    scanf("%i", &search_ID);

    for(i=0;i<database_Length;i++){

        if(p[i].ID==search_ID){

            check=1;
            break;
        }
    }

    if(check){

        printf("Please enter patient's new appointment date: ");
        fflush(stdin);
        gets(p[i].appointment_Date);
        printf("\nPatient's appointment date updated successfully!\n");
    }
    else{

        printf("\nPatient not found!\n");
    }
}

void edit_Patient(patient *p){

    unsigned int search_ID;
    unsigned char check=0;
    unsigned char i;

    printf("\n================Edit Patient================");
    printf("\nPlease enter patient's ID: ");
    scanf("%i", &search_ID);

    for(i=0;i<database_Length;i++){

        if(p[i].ID==search_ID){

            check=1;
            break;
        }
    }

    if(!check){

        printf("\nPatient not found!\n");
        return;
    }

    while(1){

        unsigned char choice;

        printf("\n1. Edit name\n2. Edit age\n3. Edit gender\n4. Edit address\n5. Edit disease\n6. Return to admin mode\n\nPlease enter your choice: ");
        fflush(stdin);
        scanf("%i", &choice);

        if(1==choice){

            printf("\nPlease enter patient's new name: ");
            fflush(stdin);
            gets(p[i].name);
            printf("\nPatient's name updated successfully!\n");
        }
        else if(2==choice){

        char tempgender[7];

            for(char j=0;j<7;j++){

                tempgender[j]=p[i].gender[j];
            }

            printf("\nPlease enter patient's new age: ");
            scanf("%i", &p[i].age);
            printf("\nPatient's age updated successfully!\n");

            for(char j=0;j<7;j++){

                p[i].gender[j]=tempgender[j];
            }
        }
        else if(3==choice){

            printf("\nPlease enter patient's new gender: ");
            fflush(stdin);
            gets(p[i].gender);
            printf("\nPatient's gender updated successfully!\n");
        }
        else if(4==choice){

            printf("\nPlease enter patient's new address: ");
            fflush(stdin);
            gets(p[i].address);
            printf("\nPatient's address updated successfully!\n");
        }
        else if(5==choice){

            printf("\nPlease enter patient's new disease: ");
            fflush(stdin);
            gets(p[i].disease);
            printf("\nPatient's disease updated successfully!\n");
        }
        else if(6==choice){

            return;
        }
        else{

            printf("\nInvalid input!\nPlease choose a number from \'1\' to \'6\'\n");
        }
    }
}

void show_Patients(patient *p){

    if(!database_Length){

        printf("\nNo data to show!\n");
    }
    else{

        printf("\n==========All Patients Information==========");

        for(unsigned char i=0;i<database_Length;i++){

            if(!(p[i].ID)){

                continue;
            }

            printf("\nPatient's ID: %i", p[i].ID);
            printf("\nPatient's name: ");
            puts(p[i].name);
            printf("Patient's age: %i", p[i].age);
            printf("\nPatient's gender: ");
            puts(p[i].gender);
            printf("Patient's address: ");
            puts(p[i].address);
            printf("Patient's disease: ");
            puts(p[i].disease);
            printf("Patient's appointment date: ");
            puts(p[i].appointment_Date);
            printf("============================================");
        }

        printf("\n");
    }
}

void sort_Database(patient *p){

    for(unsigned char i=0;i<database_Length-1;i++){

        for(unsigned char j=0;j<database_Length-i-1;j++){

            if(p[j].ID>p[j+1].ID){

                patient temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
