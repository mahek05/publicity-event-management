#include <stdio.h>
#include <string.h>

void printevent()
{
    printf("List of Technical events\n");
    printf("Event code \t Event name      \t Price(Rs)\n");
    printf("CP1        \t Code Dosh       \t 40\n");
    printf("CP2        \t Talaash-e-code  \t 50 \n");
    printf("CP3        \t Code Sutra      \t 40 \n");
    printf("\n");

    printf("List of Non-Technical events\n");
    printf("Event code \t Event name         \t Price(Rs)\n");
    printf("NT1        \t Krishna-Sudhama    \t 40\n");
    printf("NT2        \t Guru               \t 50 \n");
    printf("NT3        \t Maharaja- Maharani \t 40 \n");
    printf("NT4        \t Mayajaal           \t 40\n");
    printf("\n");


    printf("List of Cultural events\n");
    printf("Event code \t Event name        \t Price(Rs)\n");
    printf("CL1        \t Sur Shetra        \t 50\n");
    printf("CL2        \t Bolly Birbal      \t 40\n");
    printf("CL3        \t Modern Mantralaya \t 40\n");
    printf("CL4        \t History           \t 40\n");
    printf("\n");
}

struct e
{
    char s[4];
    char name[100];
    char id[8];
};

int isEventValid(char code[])
{
    // Check if the event code is valid
    if (strcmp(code, "CP1") == 0 || strcmp(code, "CP2") == 0 || strcmp(code, "CP3") == 0 ||
        strcmp(code, "NT1") == 0 || strcmp(code, "NT2") == 0 || strcmp(code, "NT3") == 0 ||
        strcmp(code, "NT4") == 0 || strcmp(code, "CL1") == 0 || strcmp(code, "CL2") == 0 ||
        strcmp(code, "CL3") == 0 || strcmp(code, "CL4") == 0)
    {
        return 1; // Event code is valid
    }
    else
    {
        return 0; // Event code is invalid
    }
}

int isNameValid(char name[])
{
    // Check if the name is valid (no numbers or special characters)
    for (int i = 0; i < strlen(name); i++)
    {
        if (!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z'))
        {
            return 0; // Name is invalid
        }
    }
    return 1; // Name is valid
}

int isIDValid(char id[])
{
    // Check if the ID is valid (format: 2 numbers, 2 alphabets, 3 numbers)
    if (!(id[0] >= '0' && id[0] <= '9') || !(id[1] >= '0' && id[1] <= '9'))
    {
        return 0; // First two characters are not numbers
    }

    if (
        !((id[2] >= 'A' && id[2] <= 'Z') || (id[2] >= 'a' && id[2] <= 'z')) ||
        !((id[3] >= 'A' && id[3] <= 'Z') || (id[3] >= 'a' && id[3] <= 'z'))
    )
    {
        return 0; // Third and fourth character is not an alphabet
    }

    for (int i = 4; i < 7; i++)
    {
        if (!(id[i] >= '0' && id[i] <= '9'))
        {
            return 0; // Last three characters are not numbers
        }
    }

    return 1; // ID is valid
}

int main()
{
    char a;
    int i = 0, count = 0;
    struct e event[400];
    printevent();

    printf("Enter name: ");
    scanf("%s", event[i].name);

    if (!isNameValid(event[i].name))
    {
        printf("Error: Invalid name entered. Name should not contain numbers or special characters.\n");
        return 1; // Exit the program with an error code
    }

    printf("Enter your ID: ");
    scanf("%s", event[i].id);

    if (!isIDValid(event[i].id))
    {
        printf("Error: Invalid ID entered. ID should have the format: 2 numbers, 2 alphabets, 3 numbers.\n");
        return 1; // Exit the program with an error code
    }

    do {
        printf("Add Event Code: ");
        scanf("%s", event[i].s);

        if (!isEventValid(event[i].s))
        {
            printf("Error: Invalid event code entered. Please try again.\n");
            a = '+';
            continue;
        }

        printf("Enter + to add more events or any other character to stop: ");
        scanf(" %c", &a);
        count++;
        i++;
    } while (a == '+');

    printf("\nSelected Events: %d\n", count );
    for (i = 0; i < count; i++)
    {
        printf("Event Code: %s\n", event[i].s);
    }

    int price = 0;

    for (i = 0; i < count; i++)
    {
        if (strcmp(event[i].s, "CP1") == 0 || strcmp(event[i].s, "CP3") == 0 || strcmp(event[i].s, "NT1") == 0 || strcmp(event[i].s, "NT3") == 0 || strcmp(event[i].s, "NT4") == 0 || strcmp(event[i].s, "CL2") == 0 || strcmp(event[i].s, "CL3") == 0 || strcmp(event[i].s, "CL4") == 0)
        {
            price += 40;
        }
        else if (strcmp(event[i].s, "CP2") == 0 || strcmp(event[i].s, "NT2") == 0 || strcmp(event[i].s, "CL1") == 0)
        {
            price += 50;
        }
    }

    printf("Total Price: Rs%d\n", price);

    return 0;
}
