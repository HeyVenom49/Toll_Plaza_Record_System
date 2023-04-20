#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 100

// Define a structure for a vehicle record
struct vehicle {
    char reg_no[10];
    int category;
    int num_wheels;
    int is_return;
};

// Define an array to store the vehicle records
struct vehicle vehicles[MAX_VEHICLES];
int num_vehicles = 0;

// Define the fare details for each category of vehicle
int fare_details[5][2] = {
    {50, 90},   // Category 1 (car, jeep, van)
    {70, 130},  // Category 2 (LCV, minibus)
    {100, 180}, // Category 3 (bus, truck)
    {120, 220}, // Category 4 (multi-axle vehicle)
    {150, 270}  // Category 5 (heavy vehicle)
};

// Display the fare details for each category of vehicle
void display_fare_details() {
    printf("Fare details:\n");
    printf("Category 1 (car, jeep, van): Rs. %d (single side) / Rs. %d (return)\n", fare_details[0][0], fare_details[0][1]);
    printf("Category 2 (LCV, minibus): Rs. %d (single side) / Rs. %d (return)\n", fare_details[1][0], fare_details[1][1]);
    printf("Category 3 (bus, truck): Rs. %d (single side) / Rs. %d (return)\n", fare_details[2][0], fare_details[2][1]);
    printf("Category 4 (multi-axle vehicle): Rs. %d (single side) / Rs. %d (return)\n", fare_details[3][0], fare_details[3][1]);
    printf("Category 5 (heavy vehicle): Rs. %d (single side) / Rs. %d (return)\n", fare_details[4][0], fare_details[4][1]);
}

// Update the basic fare for each category of vehicle
void update_fare_details() {
    int category, num_wheels, is_return, fare;
    printf("Enter category (1-5): ");
    scanf("%d", &category);
    printf("Enter number of wheels: ");
    scanf("%d", &num_wheels);
    printf("Is return included? (1=yes, 0=no): ");
    scanf("%d", &is_return);
    printf("Enter new fare: ");
    scanf("%d", &fare);
    fare_details[category-1][is_return] = fare;
    printf("Fare updated successfully!\n");
}

// Record the daily traffic details
void record_traffic() {
    printf("Enter number of vehicles: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle %d details:\n", i+1);
        struct vehicle v;
        printf("Registration number: ");
        scanf("%s", v.reg_no);
        printf("Category (1-5): ");
        scanf("%d", &v.category);
        printf("Number of wheels: ");
        scanf("%d", &v.num_wheels);
        printf("Is return? (1=yes, 0=no): ");
        scanf("%d", &v.is_return);
        vehicles[num_vehicles++] = v;
    }
    printf("Traffic recorded successfully!\n");
}


// Delete a vehicle record
void delete_vehicle_record() {
    char reg_no[10];
    printf("Enter registration number: ");
    scanf("%s", reg_no);
    for (int i = 0; i < num_vehicles; i++) {
        if (strcmp(vehicles[i].reg_no, reg_no) == 0) {
            for (int j = i; j < num_vehicles - 1; j++) {
                vehicles[j] = vehicles[j+1];
            }
            num_vehicles--;
            printf("Vehicle record deleted successfully!\n");
            return;
        }
    }
    printf("Vehicle not found!\n");
}
// Search a vehicle record
void search_vehicle_record() {
    char reg_no[10];
    printf("Enter registration number: ");
    scanf("%s", reg_no);
    for (int i = 0; i < num_vehicles; i++) {
        if (strcmp(vehicles[i].reg_no, reg_no) == 0) {
            printf("Vehicle found!\n");
            printf("Registration number: %s\n", vehicles[i].reg_no);
            printf("Category: %d\n", vehicles[i].category);
            printf("Number of wheels: %d\n", vehicles[i].num_wheels);
            printf("Is return? %s\n", vehicles[i].is_return ? "yes" : "no");
            return;
        }
    }
    printf("Vehicle not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n");
        printf("1. Display fare details\n");
        printf("2. Update fare details\n");
        printf("3. Record traffic\n");
        printf("4. Delete vehicle record\n");
        printf("5. Search vehicle record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_fare_details();
                break;
            case 2:
                update_fare_details();
                break;
            case 3:
                record_traffic();
                break;
            case 4:
                delete_vehicle_record();
                break;
            case 5:
                search_vehicle_record();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
