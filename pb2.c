#include <cs50.h>
#include <stdio.h>
#include <string.h>

//IMPORTANT!
//Define number of people!
const int p = 3;

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "Jorge";
    people[0].number = "+49 178-801-7838";

    people[1].name = "Fernanda";
    people[1].number = "+49 178-641-6689";

    people[2].name = "Katzi";
    people[2].number = "+49 178-371-3158";

    string name = get_string("Search name: ");
    for (int i = 0; i < p; i++)
    if (strcmp(people[i].name, name) == 0)
    {
        printf("Found: %s\n", people[i].number);
        return 0;
    }
    printf("Not found\n");
    return 1;
}