#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants for maximum name length and maximum records
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

// Structure to represent a date
struct Date {
    int day;
    int month;
    int year;
};

// Structure to store patient information
struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    char dob[12]; // 11 characters for the date in the format YYYY-MM-DD and 1 for the null terminator
    char gender;
};

// Structure to store appointment information
struct Appointment {
    int id;
    int patientId;
    char dob[12]; // 11 characters for the date in the format YYYY-MM-DD and 1 for the null terminator
    char time[10]; // Assuming a simple string for time (HH:MM AM/PM)
};

// Function to add a new patient
void addPatient(struct Patient patients[], int *patientCount);

// Function to schedule an appointment
void scheduleAppointment(struct Appointment appointments[], int *appointmentCount, struct Patient patients[], int patientCount);
