#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

// Define a structure for appointment information
struct Appointment {
    int id;
    int patientId;
    char dob[11]; // 10 characters for the date in the format YYYY-MM-DD and 1 for the null terminator
    char time[10]; // Assuming a simple string for time (HH:MM AM/PM)
};

// Function to schedule an appointment
void scheduleAppointment(struct Appointment appointments[], int *appointmentCount, struct Patient patients[], int patientCount) {
    struct Appointment appointment;

    // Get appointment details from the user
    printf("Enter appointment details:\n");

    // Get and validate patient ID
    printf("Enter patient ID: ");
    scanf("%d", &appointment.patientId);

    // Check if the patient ID is valid
    if (appointment.patientId <= 0 || appointment.patientId > patientCount) {
        printf("Invalid patient ID. Please enter a valid patient ID.\n");
        return;
    }

    // Assign a unique ID to the appointment
    appointment.id = *appointmentCount + 1;

    // Validate and get the patient's date of birth
    while (1) {
        printf("Date of Birth (YYYY-MM-DD): ");
        scanf("%s", appointment.dob);

        // Validate the format of the date of birth
        if (strlen(appointment.dob) == 10 &&
            appointment.dob[4] == '-' && appointment.dob[7] == '-' &&
            isdigit(appointment.dob[0]) && isdigit(appointment.dob[1]) &&
            isdigit(appointment.dob[2]) && isdigit(appointment.dob[3]) &&
            isdigit(appointment.dob[5]) && isdigit(appointment.dob[6]) &&
            isdigit(appointment.dob[8]) && isdigit(appointment.dob[9]) &&
            (appointment.dob[5] == '0' || appointment.dob[5] == '1') && // Check for valid month
            ((appointment.dob[5] == '0' && appointment.dob[6] >= '1' && appointment.dob[6] <= '9') ||
             (appointment.dob[5] == '1' && appointment.dob[6] >= '0' && appointment.dob[6] <= '2')) && // Check for valid day
            (appointment.dob[8] >= '0' && appointment.dob[8] <= '3') && // Check for valid year (decade)
            (appointment.dob[9] >= '0' && appointment.dob[9] <= '9')) { // Check for valid year (unit)
            break; // Exit the loop if the input is valid
        } else {
            printf("Invalid date of birth format or values. Please enter in YYYY-MM-DD format with valid month and day.\n");
        }
    }

    // Get appointment time
    printf("Time: ");
    scanf("%s", appointment.time);

    // Open the file for appending appointment details
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write appointment details to the file
    fprintf(file, "%d %d %s %s\n", appointment.id, appointment.patientId, appointment.dob, appointment.time);
    fclose(file);

    // Update the array of appointments and increment the appointment count
    appointments[*appointmentCount] = appointment;
    (*appointmentCount)++;

    printf("Appointment scheduled successfully.\n");
}
