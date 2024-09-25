#ifndef CMS_H_INCLUDED
#define CMS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    unsigned int ID;
    char name[21];
    unsigned char age;
    char gender[7];
    char address[21];
    char disease[21];
    char appointment_Date[11];
}patient;

void main_Menu(void);
void add_Patient(patient *p);
void remove_Patient(patient *p);
void check_Patient(patient *p);
void book_Appointment(patient *p);
void edit_Patient(patient *p);
void show_Patients(patient *p);
void sort_Database(patient *p);

static unsigned int incremental_ID=1319000;
static unsigned char database_Length=0;
static patient *database;

#endif // CMS_H_INCLUDED
