#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Voter {
    char aadharID[20];
    char name[50];
    char birthDate[15];
    struct Voter *next;
} VoterNode;

VoterNode *voterList = NULL;
int remainingAttempts = 3;
int totalVotes = 0;
int votesForCandidate1 = 0, votesForCandidate2 = 0, votesForCandidate3 = 0, votesForCandidate4 = 0, votesForCandidate5 = 0;

VoterNode *findVoter(char aadhar[], char name[], char birthDate[], VoterNode *list, int *alreadyVoted);
VoterNode *addVoter(VoterNode *list);
VoterNode *mainMenu(VoterNode *list);
void adminPanel();
void displayWinner();
void exitPortal();
void votingProcess();
void alreadyVotedMessage();
void portalClosedMessage();
void showVoteCounts();

int main() {
    while (1) {
        system("cls");
        printf("\n\n\n");
        printf("\t****** WELCOME TO THE ONLINE VOTING PORTAL ******\n\n");
        printf("\t************************************************\n\n\n\n");
        printf("\t\t***** Enter 1 for accessing the voting portal *****\n\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            voterList = mainMenu(voterList);
        }
    }
    return 0;
}

VoterNode *mainMenu(VoterNode *list) {
    system("cls");
    printf("\n\n\n");
    printf("\t\t1. Vote\n");
    printf("\t\t2. Admin Panel\n");
    printf("\t\t3. View Winner\n");
    printf("\n\tIf your details match our records, you can cast your vote.\n\n");

    int option;
    scanf("%d", &option);
    if (option == 1) {
        list = addVoter(list);
    } else if (option == 2) {
        adminPanel();
    } else if (option == 3) {
        displayWinner();
    } else {
        mainMenu(list);
    }
    return list;
}

VoterNode *addVoter(VoterNode *list) {
    int alreadyVotedFlag = 0;
    int *votedFlagPtr = &alreadyVotedFlag;
    VoterNode *temp;
    char aadhar[20], name[50], birthDate[15];

    system("cls");
    printf("\n\n\n");
    printf("\tEnter your AADHAR ID, Name, and Date of Birth to vote:\n");
    printf("\tYou have %d attempts left before the portal closes.\n\n", remainingAttempts);

    printf("\tAADHAR ID: ");
    gets(aadhar);
    gets(aadhar);
    printf("\tName: ");
    gets(name);
    printf("\tBirth Date (dd-mm-yyyy): ");
    gets(birthDate);

    temp = (VoterNode *)malloc(sizeof(VoterNode));
    strcpy(temp->aadharID, aadhar);
    strcpy(temp->name, name);
    strcpy(temp->birthDate, birthDate);
    temp->next = NULL;

    if ((strcmp(temp->aadharID, "10001") == 0 && strcmp(temp->name, "Rajat Kumar") == 0 && strcmp(temp->birthDate, "31-03-1999") == 0) ||
        (strcmp(temp->aadharID, "10002") == 0 && strcmp(temp->name, "Goutam Kumar") == 0 && strcmp(temp->birthDate, "01-01-1999") == 0) ||
        (strcmp(temp->aadharID, "10003") == 0 && strcmp(temp->name,"Shiva Kumar")==0 &&strcmp(temp->birth_date,"12-10-1999")==0)||
        (strcmp(temp->aadharID, "10004") == 0 && strcmp(temp->name,"Kundan Kumar")==0 &&strcmp(temp->birth_date,"08-12-1999")==0)||
        (strcmp(temp->aadharID, "10005") == 0 && strcmp(temp->name,"Aniket Arora")==0 &&strcmp(temp->birth_date,"28-08-1999")==0)||
        (strcmp(temp->aadharID, "10006") == 0 && strcmp(temp->name,"Dipika Singh")==0 &&strcmp(temp->birth_date,"20-10-2000")==0)||
        (strcmp(temp->aadharID, "10007") == 0 && strcmp(temp->name,"Avinash Kumar")==0 &&strcmp(temp->birth_date,"02-03-1999")==0)||
        (strcmp(temp->aadharID, "10008") == 0 && strcmp(temp->name,"Ravi Raj")==0 &&strcmp(temp->birth_date,"26-12-1999")==0)||
        (strcmp(temp->aadharID, "10009") == 0 && strcmp(temp->name,"Madhumita Rajashree")==0 &&strcmp(temp->birth_date,"02-01-1999")==0)||
        (strcmp(temp->aadharID, "10010") == 0 && strcmp(temp->name, "Avinash Rao") == 0 && strcmp(temp->birthDate, "03-01-1999") == 0)) {

        remainingAttempts = 3;
        list = findVoter(temp->aadharID, temp->name, temp->birthDate, list, votedFlagPtr);

        if (alreadyVotedFlag == 0) {
            votingProcess();
        } else {
            alreadyVotedMessage();
        }
    } else {
        remainingAttempts--;
        if (remainingAttempts == 0) {
            portalClosedMessage();
        } else {
            printf("\nInvalid AADHAR ID, Name, or Birth Date. Please try again.\n");
            system("pause");
            list = mainMenu(list);
        }
    }
    return list;
}

void votingProcess() {
    system("cls");
    printf("\n\n\t\t*** LIST OF CANDIDATES ***\n\n");
    printf("\t\t1. Mamata Banerjee - Fish\n");
    printf("\t\t2. Deepa Dasmunsi - Boat\n");
    printf("\t\t3. Protima Rajak - Motorcycle\n");
    printf("\t\t4. Joydeb Halder - Broomstick\n");
    printf("\t\t5. Kartik Chandra Ghosh - Wheel\n");

    int choice;
    printf("\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: votesForCandidate1++; printf("\nYou voted for Mamata Banerjee\n"); break;
        case 2: votesForCandidate2++; printf("\nYou voted for Deepa Dasmunsi\n"); break;
        case 3: votesForCandidate3++; printf("\nYou voted for Protima Rajak\n"); break;
        case 4: votesForCandidate4++; printf("\nYou voted for Joydeb Halder\n"); break;
        case 5: votesForCandidate5++; printf("\nYou voted for Kartik Chandra Ghosh\n"); break;
        default: printf("\nInvalid choice. Please try again.\n"); votingProcess();
    }

    printf("\nThank you for voting!\n");
    getch();
}

void adminPanel() {
    int password;
    printf("\n\nEnter Admin Password: ");
    scanf("%d", &password);
    if (password == 3692) {
        showVoteCounts();
    } else {
        printf("Wrong Password\n");
    }
}

void showVoteCounts() {
    int choice;
    system("cls");
    printf("\n\n\tCurrent Vote Count:\n");
    printf("\tMamata Banerjee: %d votes\n", votesForCandidate1);
    printf("\tDeepa Dasmunsi: %d votes\n", votesForCandidate2);
    printf("\tProtima Rajak: %d votes\n", votesForCandidate3);
    printf("\tJoydeb Halder: %d votes\n", votesForCandidate4);
    printf("\tKartik Chandra Ghosh: %d votes\n\n", votesForCandidate5);

    printf("\nEnter 1234 to close the portal or any other key to return to the menu: ");
    scanf("%d", &choice);
    if (choice == 1234) {
        exitPortal();
    } else {
        mainMenu(voterList);
    }
}

void displayWinner() {
    system("cls");
    printf("\n\n\t*** Winner ***\n\n");
    if (votesForCandidate1 > votesForCandidate2 && votesForCandidate1 > votesForCandidate3 && votesForCandidate1 > votesForCandidate4 && votesForCandidate1 > votesForCandidate5) {
        printf("The current winner is Mamata Banerjee with %d votes.\n", votesForCandidate1);
    } else if (votesForCandidate2 > votesForCandidate1 && votesForCandidate2 > votesForCandidate3 && votesForCandidate2 > votesForCandidate4 && votesForCandidate2 > votesForCandidate5) {
        printf("The current winner is Deepa Dasmunsi with %d votes.\n", votesForCandidate2);
    } else if (votesForCandidate3 > votesForCandidate1 && votesForCandidate3 > votesForCandidate2 && votesForCandidate3 > votesForCandidate4 && votesForCandidate3 > votesForCandidate5) {
        printf("The current winner is Protima Rajak with %d votes.\n", votesForCandidate3);
    } else if (votesForCandidate4 > votesForCandidate1 && votesForCandidate4 > votesForCandidate2 && votesForCandidate4 > votesForCandidate3 && votesForCandidate4 > votesForCandidate5) {
        printf("The current winner is Joydeb Halder with %d votes.\n", votesForCandidate4);
    } else {
        printf("The current winner is Kartik Chandra Ghosh with %d votes.\n", votesForCandidate5);
    }
    printf("\nPress any key to return to the menu.\n");
    getch();
    mainMenu(voterList);
}

void portalClosedMessage() {
    system("cls");
    printf("\n\n\tYou have entered wrong credentials three times.\n");
    printf("\tPlease try again later.\n");
    getch();
}

void alreadyVotedMessage() {
    system("cls");
    int choice;
    printf("\n\n\tYou have already voted.\n");
    printf("\tEnter 1 to view the current winner, or any other key to return to the menu: ");
    scanf("%d", &choice);
    if (choice == 1) {
        displayWinner();
    } else {
        mainMenu(voterList);
    }
}
void exitPortal() {
    system("cls");
    printf("\n\n\t*** YOU ARE NOW EXITING THE PORTAL ***\n");
    printf("\tThank you for using this online voting platform!\n");
    exit(0);
}

VoterNode *findVoter(char aadhar[], char name[], char birthDate[], VoterNode *list, int *alreadyVoted) {
    *alreadyVoted = 0;
    VoterNode *current = list;

    while (current != NULL) {
        if (strcmp(current->aadharID, aadhar) == 0 && strcmp(current->name, name) == 0 && strcmp(current->birthDate, birthDate) == 0) {
            *alreadyVoted = 1;
            return list;
        }
        current = current->next;
    }
    
    VoterNode *newVoter = (VoterNode *)malloc(sizeof(VoterNode));
    strcpy(newVoter->aadharID, aadhar);
    strcpy(newVoter->name, name);
    strcpy(newVoter->birthDate, birthDate);
    newVoter->next = list;  
    return newVoter;
}
