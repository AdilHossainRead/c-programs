#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100
#define MATCHES 30

// Structure for storing cricketer information
struct Cricketer {
    char name[50];
    char country[50];
    char cricketer_type[10]; // "bowler" or "batsman"
    int wickets[MATCHES];    // Wickets in the last 30 matches
    int runs[MATCHES];       // Runs in the last 30 matches
    int total_matches;       // Total matches played in the last year
    float performance_score; // Overall performance score
};

// Function to calculate total wickets
int total_wickets(int wickets[]) {
    int sum = 0;
    for (int i = 0; i < MATCHES; i++) {
        sum += wickets[i];
    }
    return sum;
}

// Function to calculate total runs
int total_runs(int runs[]) {
    int sum = 0;
    for (int i = 0; i < MATCHES; i++) {
        sum += runs[i];
    }
    return sum;
}

int main() {
    struct Cricketer players[MAX_PLAYERS];
    int n;

    // Input number of players
    printf("Enter the number of cricketers (up to %d): ", MAX_PLAYERS);
    scanf("%d", &n);
    getchar(); // Consume newline

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for cricketer %d:\n", i + 1);

        // Input name
        printf("Enter name: ");
        fgets(players[i].name, 50, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove trailing newline

        // Input country
        printf("Enter country: ");
        fgets(players[i].country, 50, stdin);
        players[i].country[strcspn(players[i].country, "\n")] = 0; // Remove trailing newline

        // Input cricketer type (only "bowler" or "batsman")
        while (1) {
            printf("Enter cricketer type (bowler/batsman): ");
            fgets(players[i].cricketer_type, 10, stdin);
            players[i].cricketer_type[strcspn(players[i].cricketer_type, "\n")] = 0; // Remove trailing newline

            if (strcmp(players[i].cricketer_type, "bowler") == 0 || strcmp(players[i].cricketer_type, "batsman") == 0) {
                break;
            } else {
                printf("Invalid cricketer type. Please enter 'bowler' or 'batsman'.\n");
            }
        }

        // Input wickets for the last 30 matches (only for bowlers)
        if (strcmp(players[i].cricketer_type, "bowler") == 0) {
            printf("Enter wickets taken in the last 30 matches:\n");
            for (int j = 0; j < MATCHES; j++) {
                scanf("%d", &players[i].wickets[j]);
            }
        }

        // Input runs for the last 30 matches (only for batsmen)
        if (strcmp(players[i].cricketer_type, "batsman") == 0) {
            printf("Enter runs scored in the last 30 matches:\n");
            for (int j = 0; j < MATCHES; j++) {
                scanf("%d", &players[i].runs[j]);
            }
        }

        // Input total matches played in the last year
        printf("Enter total matches played in the last year: ");
        scanf("%d", &players[i].total_matches);
        getchar(); // Consume newline

        // Calculate overall performance
        if (strcmp(players[i].cricketer_type, "bowler") == 0) {
            int total_wicks = total_wickets(players[i].wickets);
            players[i].performance_score = (float)total_wicks / players[i].total_matches;
        } else if (strcmp(players[i].cricketer_type, "batsman") == 0) {
            int total_run = total_runs(players[i].runs);
            players[i].performance_score = (float)total_run / players[i].total_matches;
        }
    }

    // Find the "Cricketer of the Year" with the highest performance score
    int cricketer_of_year_index = 0;
    float highest_performance = players[0].performance_score;

    for (int i = 1; i < n; i++) {
        if (players[i].performance_score > highest_performance) {
            highest_performance = players[i].performance_score;
            cricketer_of_year_index = i;
        }
    }

    // Display the Cricketer of the Year
    printf("\nCricketer of the Year:\n");
    printf("Name: %s\n", players[cricketer_of_year_index].name);
    printf("Country: %s\n", players[cricketer_of_year_index].country);
    printf("Cricketer Type: %s\n", players[cricketer_of_year_index].cricketer_type);
    printf("Performance Score: %.2f\n", players[cricketer_of_year_index].performance_score);

    return 0;
}
