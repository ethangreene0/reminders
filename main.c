#include "reminder.h"

struct Month November = { .month_days = 30, .start_day = 3, .reminders = { false } };

void print_reminders(void);

int main() {
    int day;
    char reminder[MAX_STR_LEN];

    printf("Welcome to the November Reminder Program\n");

    while (1) {
        printf("Enter day and reminder (0 to quit): ");
        scanf("%d", &day);
        
        // Clear input buffer
        while (getchar() != '\n');

        if (day == 0) break;

        if (day < 1 || day > 30) {
            printf("Invalid day. Please enter a day between 1 and 30.\n");
            continue;
        }

        if (read_reminder(reminder, MAX_STR_LEN)) {
            insert_to_calendar(day, reminder);
            printf("\n");
            print_calendar();
            printf("\n");
            print_reminders();
        }
    }

    printf("Exiting program. Goodbye!\n");
    return 0;
}
