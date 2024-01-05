#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

// Define a structure for patient information
struct Patient {
    int id;
    char name[50];
    char dob[11]; // 10 characters for the date in the format YYYY-MM-DD and 1 for the null terminator
    char gender;
};

// Function to add a new patient to the system
void addPatient(struct Patient patients[], int *patientCount) {
    struct Patient patient;

    // Get patient details from the user
    printf("Enter patient details:\n");

    // Validate and get the patient's name
    label1:
    while (1) {
        printf("Name: ");
        scanf("%s", patient.name);
        int i = 0;
        while (patient.name[i] != '\0') {
            // Validate that the name contains only letters, dots, and spaces
            if ((patient.name[i] >= 97 && patient.name[i] <= 122) ||
                (patient.name[i] >= 65 && patient.name[i] <= 90) ||
                patient.name[i] == '.') {
                i++;
            } else {
                printf("Enter a valid name.\n");
                break;
            }
        }
        // If the name is invalid, prompt the user to enter it again
        if (patient.name[i] != '\0')
            goto label1;
        break;
    }

    // Validate and get the patient's date of birth
    while (1) {
        printf("Date of Birth (YYYY-MM-DD): ");
        scanf("%s", patient.dob);

        // Validate the format of the date of birth
        if (strlen(patient.dob) == 10 &&
            patient.dob[4] == '-' && patient.dob[7] == '-' &&
            isdigit(patient.dob[0]) && isdigit(patient.dob[1]) &&
            isdigit(patient.dob[2]) && isdigit(patient.dob[3]) &&
            isdigit(patient.dob[5]) && isdigit(patient.dob[6]) &&
            isdigit(patient.dob[8]) && isdigit(patient.dob[9]) &&
            (patient.dob[5] == '0' || patient.dob[5] == '1') && // Check for valid month
            ((patient.dob[5] == '0' && patient.dob[6] >= '1' && patient.dob[6] <= '9') ||
            (patient.dob[5] == '1' && patient.dob[6] >= '0' && patient.dob[6] <= '2')) && // Check for valid day
            (patient.dob[8] >= '0' && patient.dob[8] <= '3') && // Check for valid year (decade)
            (patient.dob[9] >= '0' && patient.dob[9] <= '9')) { // Check for valid year (unit)
            break; // Exit the loop if the input is valid
        } else {
            printf("Invalid date of birth format or values. Please enter in YYYY-MM-DD format with valid month and day.\n");
        }
    }

    // Validate and get the patient's gender
    while (1) {
        printf("Gender: Please enter 'm' or 'f'\n");
        scanf(" %c", &patient.gender); // Use %c for a single character
        if (patient.gender == 'm' || patient.gender == 'f') {
            break; // Exit the loop if input is valid
        } else {
            printf("Invalid gender. Please enter 'm' or 'f'.\n");
        }
    }

    // Assign a unique ID to the patient
    patient.id = *patientCount + 1;

    // Display entered patient details
    printf("Entered patient details\n");
    printf("ID    : %d\nname  : %s\ndob   : %s\ngender: %c\n", patient.id, patient.name, patient.dob, patient.gender);

    // Open the file for appending patient details
    FILE *file = fopen("patients.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write patient details to the file
    fprintf(file, "%d %s %s %c\n", patient.id, patient.name, patient.dob, patient.gender);
    fclose(file);

    // Update the array of patients and increment the patient count
    patients[*patientCount] = patient;
    (*patientCount)++;

    printf("Patient added successfully.\n");
}




