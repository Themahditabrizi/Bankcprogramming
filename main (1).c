
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>    
#include <stdbool.h>   
#include <math.h>      

#define MAX_NAME_LENGTH 30
#define MAX_ADDRESS_LENGTH 50
#define MAX_CITY_LENGTH 30
#define MAX_PROVINCE_LENGTH 2
#define MAX_POSTAL_CODE_LENGTH 6
#define MAX_PHONE_NUMBER_LENGTH 10
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_CARD_NUMBER_LENGTH 16
#define MAX_PHONE_TYPES 3
#define MAX_PHONE_TYPE_LENGTH 10
#define MAX_COMMON_PASSWORDS 10
typedef struct{
char firstName[MAX_NAME_LENGTH];
char lastName[MAX_NAME_LENGTH];
int birthMonth, birthDay, birthYear;
int age;
char email[MAX_EMAIL_LENGTH];
char phoneTypes[MAX_PHONE_TYPES][MAX_PHONE_TYPE_LENGTH];
char phoneNumbers[MAX_PHONE_TYPES][MAX_PHONE_NUMBER_LENGTH];
char address1[MAX_ADDRESS_LENGTH];
char address2[MAX_ADDRESS_LENGTH];
char city[MAX_CITY_LENGTH];
char province[MAX_PROVINCE_LENGTH];
char postalCode[MAX_POSTAL_CODE_LENGTH];
int livingSituation;
int yearsAtAddress, monthsAtAddress;
int jobCategory;
long long socialInsuranceNumber;
char jobDescription[30];
long long yearlyIncome;
long long householdIncome;
int housingPayment;
char customerId[9];

char newPassword[MAX_PASSWORD_LENGTH];
char newCardNumber[MAX_CARD_NUMBER_LENGTH];
}Customer;
char cardNumber[MAX_CARD_NUMBER_LENGTH];
char password[MAX_PASSWORD_LENGTH];
// Function prototypes
void getCardNumber(char *cardNumber);
void getPassword(char *password);
void getFirstName(Customer *customer);
void getLastName(Customer *customer);
void getDateOfBirth(Customer *customer);
int checkAge(int birthMonth, int birthDay, int birthYear);
int checkName(const char *name);
int checkCardNumber(const char *cardNumber);
int checkPassword(const char *password);
void getAddress(Customer *customer);
void getPhoneNumber(Customer *customer);
void getLivingSituation(Customer *customer);
void getYearsAtAddress(Customer *customer);
void getMonthsAtAddress(Customer *customer);
void getSocialInsuranceNumber(Customer *customer);
void getJobDescription(Customer *customer);
void getYearlyIncome(Customer *customer);
void getHouseholdIncome(Customer *customer);
void getHousingPayment(Customer *customer);
void generateCustomerId(Customer *customer);
void printDataElements( Customer *customer);
void getEmail(Customer *customer);
void getPhoneNumbers(Customer *customer);
void clearMemory();
void clearInputBuffer();
void getJobCategory(Customer *customer);
void generateCardNumber(Customer *customer);
void getNewPassword(Customer *customer);
int main() {
    Customer customer;
    char existingClientResponse[4];
    int loginAttempts = 0;
    int validLogin = 0;

    printf("Welcome to the Credit Card Application!\n");

     while (!validLogin && loginAttempts < 3) {
        printf("Are you an existing client? (Yes/No): ");
        scanf("%s", existingClientResponse);

        if (strcmp(existingClientResponse, "Yes") == 0 || strcmp(existingClientResponse, "yes") == 0) {
            getCardNumber(cardNumber);
            getPassword(password);  // in getPassword


            // Validate card number and password
            validLogin = checkCardNumber(cardNumber) && checkPassword(password);
            if (!validLogin) {
                loginAttempts++;
                printf("Invalid card number or password. Please try again.\n");
            }
        } else if (strcmp(existingClientResponse, "No") == 0 || strcmp(existingClientResponse, "no") == 0) {
            // Get data elements from the customer
            getFirstName(&customer);
    getLastName(&customer);
    getDateOfBirth(&customer);
    getEmail(&customer);
    getPhoneNumbers(&customer);
    getAddress(&customer);
    getLivingSituation(&customer);
    getYearsAtAddress(&customer);
    getMonthsAtAddress(&customer);
    getSocialInsuranceNumber(&customer);
    getJobCategory(&customer);
    getJobDescription(&customer);
    getYearlyIncome(&customer);
    getHouseholdIncome(&customer);
    getHousingPayment(&customer);
    generateCustomerId(&customer);
    generateCardNumber(&customer);
    getNewPassword(&customer);

            validLogin = 1;
        } else {
            printf("Invalid response. Please enter 'Yes' or 'No'.\n");
        }
    }

    if (validLogin) {
        printf("\n---- Applicant Information ----\n");
    printDataElements(&customer);
    } else {
        printf("Maximum login attempts reached. Application terminated.\n");
    }
clearMemory();
    return 0;
}

void getCardNumber(char *cardNumber) {
    printf("Please enter your card number: ");
    scanf(" %s", cardNumber);
    int m;
    int charcount;

    charcount = 0;
    for(m=0; cardNumber[m]; m++) {
    if(cardNumber[m] != ' ') {
        charcount ++;
    }
}
if (charcount!=8){
getCardNumber(cardNumber);
}
    
}

void getPassword(char *password) {
    printf("Please enter your password: ");
    scanf(" %s", password);
}

void getFirstName(Customer *customer) {
    
    while (1) {
        printf("Please enter your first name (max 30 characters, no numbers): ");
        if (scanf("%30s", customer->firstName) != 1) {
            // Input error, clear the input buffer and try again
            clearInputBuffer();
            continue;
        }

        // Check if the input is not empty
        if (customer->firstName[0] == '\0') {
            printf("First name is mandatory. Please try again.\n");
            continue;
        }

        // Check if the input contains any numbers
        int hasNumber = 0;
        for (int i = 0; customer->firstName[i]; i++) {
            if (isdigit(customer->firstName[i])) {
                hasNumber = 1;
                break;
            }
        }

        if (hasNumber) {
            printf("First name should not contain any numbers. Please try again.\n");
        } else {
            // Valid input, break out of the loop
            break;
        }
    }
}

void getLastName(Customer *customer) {
   
    while (1) {
        printf("Please enter your last name (max 30 characters, no numbers): ");
        if (scanf("%30s", customer->lastName) != 1) {
            // Input error, clear the input buffer and try again
            clearInputBuffer();
            continue;
        }

        // Check if the input is not empty
        if (customer->lastName[0] == '\0') {
            printf("Last name is mandatory. Please try again.\n");
            continue;
        }

        // Check if the input contains any numbers
        int hasNumber = 0;
        for (int i = 0; customer->lastName[i]; i++) {
            if (isdigit(customer->lastName[i])) {
                hasNumber = 1;
                break;
            }
        }

        if (hasNumber) {
            printf("Last name should not contain any numbers. Please try again.\n");
        } else {
            // Valid input, break out of the loop
            break;
        }
    }
}

void getDateOfBirth(Customer *customer) {
    printf("Please enter your date of birth (MM DD YYYY): ");
    scanf("%d %d %d", &customer->birthMonth, &customer->birthDay, &customer->birthYear);

    // Validate birth date
    if (customer->birthMonth > 12 || customer->birthMonth == 0 ||
        customer->birthDay > 31 || customer->birthDay == 0 ||
        customer->birthYear == 0 || customer->birthYear < 1900) {
        printf("Invalid birth date. Please enter a valid date.\n");
        getDateOfBirth(customer);
    }

    customer->age = checkAge(customer->birthMonth, customer->birthDay, customer->birthYear);

    if (customer->age < 18) {
        printf("Applicants must be 18 years or older. Application terminated.\n");
        exit(0);
    }
}

int checkAge(int birthMonth, int birthDay, int birthYear) {
    
    int currentMonth = 6;
    int currentDay = 30;
    int currentYear = 2023;

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    return age;
}

int checkName(const char *name) {
    int nameLength = strlen(name);

    if (nameLength == 0 || nameLength > MAX_NAME_LENGTH) {
        return 0;
    }

    for (int i = 0; i < nameLength; i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }

    return 1;
}

int checkCardNumber(const char *cardNumber) {
    int cardNumberLength = strlen(cardNumber);

    if (cardNumberLength != MAX_CARD_NUMBER_LENGTH) {
        return 0;
    }

    for (int i = 0; i < cardNumberLength; i++) {
        if (!isdigit(cardNumber[i])) {
            return 0;
        }
    }

    return 1;
}

int checkPassword(const char *password) {
    int passwordLength = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    int hasBirthYear = strstr(password, "19") || strstr(password, "20");
    char commonPasswords[MAX_COMMON_PASSWORDS][20] = {"12345678", "1234567890", "qwerty12", "password",
                                                      "qwerty123", "1q2w3e4r", "11111111", "abcd1234",
                                                      "AAAAAAAA"};

    if (passwordLength < 8) {
        return 0;
    }

    for (int i = 0; i < passwordLength; i++) {
        if (islower(password[i])) {
            hasLower = 1;
        } else if (isupper(password[i])) {
            hasUpper = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (!isalnum(password[i])) {
            hasSpecial = 1;
        }
    }

    if (!hasLower || !hasUpper || !hasDigit || !hasSpecial || hasBirthYear) {
        return 0;
    }

    for (int i = 0; i < MAX_COMMON_PASSWORDS; i++) {
        if (strcmp(password, commonPasswords[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

bool is_valid(char *email)
{
    if (!isChar(email[0]))
    {
        return false;
    }

    int At = -1, Dot = -1;
    int len = strlen(email);

    for (int i = 0; i < len; i++)
    {
        if (email[i] == '@')
        {
            At = i;
        }
        else if (email[i] == '.')
        {
            Dot = i;
        }
    }

    if (At == -1 || Dot == -1)
        return false;

    if (At > Dot)
        return false;

    return !(Dot >= (len - 1));
}
void getEmail(Customer *customer) {
    printf("Please enter your email address: ");
    scanf(" %s", customer->email);

    if (!is_valid(customer->email)) {
        printf("Invalid email address. Please enter a valid email.\n");
        getEmail(customer);
    }
}

int isNumber(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void getPhoneNumbers(Customer *customer) {
    int count = 0;

    while (count < 3) {
        printf("Please enter phone number type (1-Home, 2-Work, 3-Mobile): ");
        int phoneType;
        scanf(" %d", &phoneType);

        if (phoneType < 1 || phoneType > 3) {
            break;
        }

        printf("Please enter phone number: ");
        scanf(" %s", customer->phoneNumbers[phoneType - 1]);

        // Validate phone number
        if (strlen(customer->phoneNumbers[phoneType - 1]) != 10 ||
            !isNumber(customer->phoneNumbers[phoneType - 1])) {
            printf("Invalid phone number. Phone number must be exactly 10 digits and contain only numbers. Please try again.\n");
            continue;
        }

        count++;
    }
}

int isValidProvince(const char* province) {
    // List of valid provinces
    const char* validProvinces[] = {
        "ab", "bc", "mb", "nb", "nl", "nt", "ns", "nu", "on", "pe", "qc", "sk", "yt"
    };

    for (int i = 0; i < sizeof(validProvinces) / sizeof(validProvinces[0]); i++) {
        if (strcmp(province, validProvinces[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void getAddress(Customer *customer) {
    printf("Please enter address line 1 (max 50 characters): ");
    scanf(" %50[^\n]", customer->address1);
    clearInputBuffer();

    printf("Please enter address line 2 (max 50 characters): ");
    scanf(" %50[^\n]", customer->address2);
    clearInputBuffer();

    printf("Please enter city (max 30 characters): ");
    scanf(" %30[^\n]", customer->city);
    clearInputBuffer();

    while (1) {
        printf("Please enter province (ab, bc, mb, nb, nl, nt, ns, nu, on, pe, qc, sk, yt): ");
        scanf(" %2s", customer->province);
        clearInputBuffer();

        if (!isValidProvince(customer->province)) {
            printf("Invalid province. Please enter a valid two-letter province code.\n");
        } else {
            break;
        }
    }

    printf("Please enter postal code (6 characters): ");
    scanf(" %6s", customer->postalCode);
    clearInputBuffer();
}

int isValidLivingSituation(int input) {
    return input >= 1 && input <= 5;
}

void getLivingSituation(Customer *customer) {
    while (1) {
        printf("Please enter living situation (1-Rent, 2-Own/Buying, 3-Live with Parents, 4-Room or Board, 5-Other): ");
        if (scanf(" %d", &customer->livingSituation) != 1) {
            // Input error (non-numeric input)
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }

        if (!isValidLivingSituation(customer->livingSituation)) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
        } else {
            break;
        }
    }
}

int isValidYearsAtAddress(int input) {
    return input >= 0 && input <= 999; // Assuming the number of years can be up to 999
}

void getYearsAtAddress(Customer *customer) {
    while (1) {
        printf("Please enter years at current address: ");
        if (scanf(" %d", &customer->yearsAtAddress) != 1) {
            // Input error (non-numeric input)
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (!isValidYearsAtAddress(customer->yearsAtAddress)) {
            printf("Invalid input. Please enter a number up to 3 digits.\n");
        } else {
            break;
        }
    }
}

int isValidMonthsAtAddress(int input) {
    return input >= 0 && input <= 12;
}

void getMonthsAtAddress(Customer *customer) {
    while (1) {
        printf("Please enter months at current address: ");
        if (scanf(" %d", &customer->monthsAtAddress) != 1) {
            // Input error (non-numeric input)
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (!isValidMonthsAtAddress(customer->monthsAtAddress)) {
            printf("Invalid input. Please enter a number between 0 and 12.\n");
        } else {
            break;
        }
    }
}

int isValidSIN(const char* sin) {
    // Check if SIN contains exactly 9 digits
    int digitsCount = 0;
    for (int i = 0; sin[i]; i++) {
        if (isdigit(sin[i])) {
            digitsCount++;
        }
    }
    return (digitsCount == 9);
}

void getSocialInsuranceNumber(Customer *customer) {
    while (1) {
        printf("Please enter social insurance number (optional): ");
        scanf(" %lld", &customer->socialInsuranceNumber);
        clearInputBuffer();

        char sinStr[12]; // Adjust the size based on your input requirements
        snprintf(sinStr, sizeof(sinStr), "%lld", customer->socialInsuranceNumber);
        if (!isValidSIN(sinStr)) {
            printf("Invalid social insurance number. Please enter 9 digits (0-9).\n");
        } else {
            printf("Social insurance number entered: %lld\n", customer->socialInsuranceNumber);
            break;
        }
    }
}

int isValidJobCategory(int input) {
    return input >= 1 && input <= 5;
}

void getJobCategory(Customer *customer) {
    while (1) {
        printf("Please enter the job category (1-5):\n");

        if (scanf(" %d", &(customer->jobCategory)) != 1) {
            // Input error (non-numeric input)
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }

        if (!isValidJobCategory(customer->jobCategory)) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
        } else {
            break;
        }
    }
}
void getJobDescription(Customer *customer) {
    while (1) {
        printf("Please enter job description (max 30 characters): ");
        scanf(" %30[^\n]", customer->jobDescription);
        clearInputBuffer();

        // Check if job description is empty (optional)
        if (customer->jobDescription[0] == '\0') {
            printf("Job description is optional. If you want to provide one, it should not be empty.\n");
            continue;
        }

        // Check if job description exceeds the maximum length
        if (strlen(customer->jobDescription) > 30) {
            printf("Invalid input. Job description should be up to 30 characters.\n");
        } else {
            // Valid input, break out of the loop
            break;
        }
    }
}
int isValidNumber(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}
void getYearlyIncome(Customer *customer) {
    char yearlyIncomeStr[8 + 1];
    while (1) {
        printf("Please enter yearly income: ");
        scanf(" %8s", yearlyIncomeStr);
        clearInputBuffer();

        // Validate the income string
        if (strlen(yearlyIncomeStr) != 8 || !isValidNumber(yearlyIncomeStr)) {
            printf("Invalid input. Yearly income should contain exactly 8 digits.\n");
            continue;
        }

        // Convert the income string to a long long integer
        customer->yearlyIncome = strtoll(yearlyIncomeStr, NULL, 10);

        // Check if the income is greater than 15,000
        if (customer->yearlyIncome <= 15000) {
            printf("Invalid input. Yearly income should be greater than 15,000.\n");
        } else {
            // Valid input, break out of the loop
            break;
        }
    }
}

void getHouseholdIncome(Customer *customer) {
    char incomeStr[8 + 1]; // +1 for null terminator

    printf("Please enter other household income (optional, max 8 characters): ");
    scanf(" %8s", incomeStr);
    clearInputBuffer();

    // Check if income is provided
    if (incomeStr[0] != '\0') {
        // Validate the income string
        if (strlen(incomeStr) > 8 || !isValidNumber(incomeStr)) {
            printf("Invalid input. Other household income should contain up to 8 digits.\n");
            return; // Exit the function if input is invalid
        }

        // Convert the income string to a long long integer
        customer->householdIncome = strtoll(incomeStr, NULL, 10);
    }
}

void getHousingPayment(Customer *customer) {
    char paymentStr[8 + 1]; // +1 for null terminator

    while (1) {
        printf("Please enter how much you pay for housing (8 characters of numbers): ");
        scanf(" %8s", paymentStr);
        clearInputBuffer();

        // Validate the payment string
        if (strlen(paymentStr) != 8 || !isValidNumber(paymentStr)) {
            printf("Invalid input. Housing payment should contain exactly 8 characters of numbers.\n");
        } else {
            // Convert the payment string to an integer
            customer->housingPayment = atoi(paymentStr);
            break;
        }
    }
}

void generateCustomerId(Customer *customer) {
    // Generate a random 8-digit customer ID
    srand(time(NULL));
    sprintf(customer->customerId, "%08d", rand() % 100000000);
}

void generateCardNumber(Customer *customer) {
    // +1 for null terminator
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < 16; i++) {
        customer->newCardNumber[i] = '0' + (rand() % 10); // Generate a random digit (0 to 9)
    }
    customer->newCardNumber[16] = '\0'; //
}
bool containsBirthYear(const char* password, int birthYear) {
    char yearStr[5];
    snprintf(yearStr, sizeof(yearStr), "%d", birthYear);

    return (strstr(password, yearStr) != NULL);
}

bool containsCommonPasswords(const char* password) {
    const char* commonPasswords[] = {
        "12345678", "1234567890", "qwerty12", "password",
        "qwerty123", "1q2w3e4r", "11111111", "abcd1234", "AAAAAAAA"
    };
    int numCommonPasswords = sizeof(commonPasswords) / sizeof(commonPasswords[0]);

    for (int i = 0; i < numCommonPasswords; i++) {
        if (strcmp(password, commonPasswords[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isValidPassword(const char* password, int birthYear) {
    int length = strlen(password);

    if (length < 8) {
        return false;
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasNumber = false;
    bool hasSpecialCharacter = false;

    for (int i = 0; i < length; i++) {
        char ch = password[i];
        if (isupper(ch)) {
            hasUpperCase = true;
        } else if (islower(ch)) {
            hasLowerCase = true;
        } else if (isdigit(ch)) {
            hasNumber = true;
        } else if (ispunct(ch)) {
            hasSpecialCharacter = true;
        }
    }

    if (!(hasUpperCase && hasLowerCase && hasNumber && hasSpecialCharacter)) {
        return false;
    }

    if (containsBirthYear(password, birthYear)) {
        return false;
    }

    if (containsCommonPasswords(password)) {
        return false;
    }

    return true;
}
void getNewPassword(Customer *customer) {
    while (1) {
        printf("Please enter your password: ");
        scanf(" %49s", customer->newPassword);

        if (isValidPassword(customer->newPassword, customer->birthYear)) {
            printf("Password accepted!\n");
            break;
        } else {
            printf("Invalid password. Please try again.\n");
        }
    }
}

void clearMemory(Customer *customer) {
    memset(customer->firstName, 0, sizeof(customer->firstName));
    memset(customer->lastName, 0, sizeof(customer->lastName));
    memset(customer->email, 0, sizeof(customer->email));
    memset(customer->phoneNumbers, 0, sizeof(customer->phoneNumbers));
    memset(customer->address1, 0, sizeof(customer->address1));
    memset(customer->address2, 0, sizeof(customer->address2));
    memset(customer->city, 0, sizeof(customer->city));
    memset(customer->province, 0, sizeof(customer->province));
    memset(customer->postalCode, 0, sizeof(customer->postalCode));
    memset(customer->newCardNumber, 0, sizeof(customer->newCardNumber));
    memset(customer->newPassword, 0, sizeof(customer->newPassword));
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void printDataElements(Customer *customer) {
    printf("First Name: %s\n", customer->firstName);
    printf("Last Name: %s\n", customer->lastName);
    printf("Date of Birth: %02d/%02d/%04d\n", customer->birthMonth, customer->birthDay, customer->birthYear);
    printf("Email: %s\n", customer->email);

    printf("Phone Numbers:\n");
    for (int i = 0; i < MAX_PHONE_TYPES; i++) {
        if (strlen(customer->phoneNumbers[i]) > 0) {
            printf("Type: %s, Number: %s\n", customer->phoneTypes[i], customer->phoneNumbers[i]);
        }
    }

    printf("Address:\n");
    printf("Address 1: %s\n", customer->address1);
    printf("Address 2: %s\n", customer->address2);
    printf("City: %s\n", customer->city);
    printf("Province: %s\n", customer->province);
    printf("Postal Code: %s\n", customer->postalCode);

    printf("Living Situation: %d\n", customer->livingSituation);
    printf("Years at Address: %d\n", customer->yearsAtAddress);
    printf("Months at Address: %d\n", customer->monthsAtAddress);
    printf("Social Insurance Number: %lld\n", customer->socialInsuranceNumber);
    printf("Job Category: %d\n", customer->jobCategory);
    printf("Job Description: %s\n", customer->jobDescription);
    printf("Yearly Income: %lld\n", customer->yearlyIncome);
    printf("Household Income: %lld\n", customer->householdIncome);
    printf("Housing Payment: %d\n", customer->housingPayment);
    printf("Customer ID: %s\n", customer->customerId);
    printf("Card Number: %s\n", customer->newCardNumber);
}