#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

// Constants for maximum name length and maximum records
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

// Main function
int main() {
    // Arrays to store patients and appointments
    struct Patient patients[MAX_RECORDS];
    struct Appointment appointments[MAX_RECORDS];

    // Counters for the number of patients, appointments, and billing records
    int patientCount = 0;
    int appointmentCount = 0;
    int billingCount = 0;

    // Variable to store the user's choice
    int choice;

    // Menu-driven loop
    do {
        // Display menu options
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Schedule Appointment\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Get user input for the menu choice
        scanf("%d", &choice);

        // Switch statement to perform actions based on user's choice
        switch (choice) {
            case 1:
                // Call the function to add a new patient
                addPatient(patients, &patientCount);
                break;
            case 2:
                // Call the function to schedule an appointment
                scheduleAppointment(appointments, &appointmentCount, patients, patientCount);
                break;
            case 3:
                // Placeholder for generating a bill (implementation needed)
                printf("Generating Bill...\n");
                break;
            case 4:
                // Exit the program
                printf("Exiting the program.\n");
                break;
            default:
                // Handle invalid choices
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4); // Repeat the loop until the user chooses to exit

    return 0;
}
