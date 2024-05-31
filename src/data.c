/*  Project Name    : A2AF
 *  File Name       : data.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintCity(struct City* city) {
    printf(
        "%-3s  %-32s  Pop: %8d  (%8.3f, %8.3f)\n",
        city->country,
        city->name,
        city->pop,
        city->lat,
        city->lng);
}

int CountNumOfRecords_(FILE* fp) {
    int n = 0;
    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
        ++n;
    }
    return n - 1;
}

void ReadValues_(struct City** table, FILE* fp) {
    fseek(fp, 0L, SEEK_SET);
    char buf[BUF_SIZE];
    char* token;

    char city[CITY_NAME_SIZE];          // Unused
    char city_ascii[CITY_NAME_SIZE];
    float lat;
    float lng;
    char country[CTRY_NAME_SIZE];       // Unused
    char iso2[ISO2_NAME_SIZE];          // Unused
    char iso3[ISO3_NAME_SIZE];
    char admin_name[ADMN_NAME_SIZE];    // Unused
    char capital[CPTL_NAME_SIZE];       // Unused
    int population;
    int id;                             // Unused

    fgets(buf, BUF_SIZE, fp);  // Skip the header
    int n = 0;
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
        token = strtok(buf, ",");
        sscanf_s(token, "\"%[^\"]\"", city,        sizeof(city));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%[^\"]\"", city_ascii,  sizeof(city_ascii));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%f\"",     &lat,        sizeof(int));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%f\"",     &lng,        sizeof(int));
        token = strtok(NULL, "\"");
        sscanf_s(token, "%s",         country,     sizeof(country));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%[^\"]\"", iso2,        sizeof(iso2));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%[^\"]\"", iso3,        sizeof(iso3));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%[^\"]\"", admin_name,  sizeof(admin_name));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%[^\"]\"", capital,     sizeof(capital));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%d\"",     &population, sizeof(int));
        token = strtok(NULL, ",");
        sscanf_s(token, "\"%d\"",     &id,         sizeof(int));

        strncpy((*table)[n].name, city_ascii, CITY_NAME_SIZE - 1);
        (*table)[n].name[CITY_NAME_SIZE - 1] = '\0';
        strncpy((*table)[n].country, iso3, ISO3_NAME_SIZE - 1);
        (*table)[n].country[ISO3_NAME_SIZE - 1] = '\0';

        (*table)[n].pop = population;
        (*table)[n].lat = lat;
        (*table)[n].lng = lng;

        ++n;
    }
}

void ReadData(struct City** table, int* n, char filename[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: Could not open %s.\n", filename);
        exit(1);
    }
    *n = CountNumOfRecords_(fp);
    *table = malloc(sizeof(struct City)*(*n));
    if (*table == NULL) {
        printf("ERROR: Could not allocate memory.\n");
        fclose(fp);
        exit(1);
    }
    ReadValues_(table, fp);
    fclose(fp);
}

void DisplayTable(struct City* table, int n) {
    const int max_records = 25;
    int min_index = 0;

    char command = 'n';

    int exits = 0;
    while (!exits) {
        for (int i = 0; i < max_records; ++i) {
            printf("  ");
            PrintCity(&table[min_index + i]);
        }
        printf(
            "    <%d - %d / %d>\n",
            min_index, min_index + max_records - 1, n - 1);
        printf("    [n] next  [p] previous  [e] exit\n? ");
        scanf(" %c", &command);

        switch (command) {
        case 'e':
            exits = 1;
            break;
        case 'p':
            min_index -= max_records;
            if (min_index < 0) {
                min_index = 0;
            }
            break;
        case 'n':
        default:
            min_index += max_records;
            if (min_index >= n) {
                exits = 1;
            }
            break;
        }
    }
    printf("    EXIT > Display Table\n");
}
