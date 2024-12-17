#include <stdio.h>
#include <string.h> 

int regularexp(char str[]) {
    int count_b = 0; 
    int len = strlen(str); 

    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            continue;
        } else if (str[i] == 'b') {
            count_b++;
        } else {
            return 0;
        }
    }

    if (count_b == 2) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (regularexp(str)) {
        printf("Valid string.");
    } else {
        printf("Invalid string.");
    }

    return 0;
}
