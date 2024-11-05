#include "reminder.h"

// Function to insert a reminder into the calendar
void insert_to_calendar(int day, const char* value) {
    if (day < 1 || day > 30) {
        printf("Invalid day. Please enter a day between 1 and 30.\n");
        return;
    }
    strncpy(November.reminder_str[day - 1], value, MAX_STR_LEN - 1);
    November.reminder_str[day - 1][MAX_STR_LEN - 1] = '\0';
    November.reminders[day - 1] = true;
}

// Function to read reminder input from the user
int read_reminder(char *str, int n) {
    printf("Enter reminder: ");
    if (fgets(str, n, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
        return 1;
    }
    return 0;
}

// Function to display the calendar with reminder indicators
void print_calendar() {
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print leading spaces for days before the first of the month
    for (int i = 0; i < November.start_day; i++) {
        printf("     ");
    }

    // Print the days with reminder indicators
    for (int day = 1; day <= November.month_days; day++) {
        if (November.reminders[day - 1]) {
            printf(" (%2d)", day);  // Day with reminder in parentheses
        } else {
            printf("  %2d ", day);  // Day without reminder
        }

        // Line break at the end of each week
        if ((day + November.start_day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to display all reminders
void print_reminders() {
    printf("Reminders:\n");
    for (int day = 0; day < November.month_days; day++) {
        if (November.reminders[day]) {
            printf("Day %d: %s\n", day + 1, November.reminder_str[day]);
        }
    }
    printf("_______________________________________\n");
}
