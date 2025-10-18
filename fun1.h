#ifndef FUN1_H
#define FUN1_H
struct contact { 
    int id; // id of the contact 
    char name[32]; // Member to store contact's 
    char surname[32]; // Member to store contact's name 
    char homephone[16]; // Member to store home phone num 
    char mobphone[16]; // Member to store mobile phone num
    char address[64]; // stores contact address
};
int load_contact(struct contact *conts);
int print_contact(struct contact *conts);
#endif
