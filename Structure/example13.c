#include<stdio.h>
#include<string.h>

struct Cricketer {
    char name[50];
    char country[50];
    char cricketer_type[10];
    int wickets[30];
    int run[30];
    int total_match;
    float overall_p;
};

int main() {
    struct Cricketer player[100];
    int total_wickets, total_runs;
    float max_performance = 0;
    int cricketer_of_the_year = 0;

    for (int i = 0; i < 100; i++) {
        printf("Enter details for Cricketer %d:\n", i + 1);

        printf("Name: ");
        fgets(player[i].name, 50, stdin);


        printf("Country: ");
        fgets(player[i].country, 50, stdin);


        printf("Cricketer Type (bowler/batsman): ");
        fgets(player[i].cricketer_type, 10, stdin);


        printf("Enter wickets taken in the last 30 matches:\n");
        for (int j = 0; j < 30; j++) {
            printf("Match %d wickets: ", j + 1);
            scanf("%d", &player[i].wickets[j]);
        }

        printf("Enter runs scored in the last 30 matches:\n");
        for (int j = 0; j < 30; j++) {
            printf("Match %d runs: ", j + 1);
            scanf("%d", &player[i].run[j]);
        }

        printf("Enter total matches played in the last year: ");
        scanf("%d", &player[i].total_match);

        total_wickets = 0;
        total_runs = 0;
        for (int j = 0; j < 30; j++) {
            total_wickets += player[i].wickets[j];
            total_runs += player[i].run[j];
        }

        if (strcmp(player[i].cricketer_type, "bowler") == 0) {
            player[i].overall_p = (float) total_wickets / player[i].total_match;
        } else if (strcmp(player[i].cricketer_type, "batsman") == 0) {
            player[i].overall_p = (float) total_runs / player[i].total_match;
        }

        if (player[i].overall_p > max_performance) {
            max_performance = player[i].overall_p;
            cricketer_of_the_year = i;
        }

        getchar();
    }

    printf("\nCricketer of the Year:\n");
    printf("Name: %s\n", player[cricketer_of_the_year].name);
    printf("Country: %s\n", player[cricketer_of_the_year].country);
    printf("Type: %s\n", player[cricketer_of_the_year].cricketer_type);
    printf("Overall Performance: %.2f\n", player[cricketer_of_the_year].overall_p);

    return 0;
}

