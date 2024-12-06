#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Patient.h"

using namespace std;


class HashTable {
private:
    // size of the hash table
    static const int SIZE = 100;

    // an array of linked lists (buckets)
    LinkedList table[SIZE];

    // Hash function
    int badHash(int key);
    int betterHash(int key);
    int bestHash(int key);

public:
    // Constructor 
    HashTable();


    // insert a Patient object into the hash table
    void insert(Patient pat, int hashType);

    //  retrieve the Patient
    Patient get(Patient pat, int hashType);


    // display the hash table
    void displayHashTable();


    // does the table contain your element?
    bool contains(Patient toFind, int hashType);

    void remove(Patient, int hashType);
};



//=================implementation===========================

/**
    HashTable Constructor that initalizes linked lists in the HashTable.
*/
HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++) {
        table[i];
    }
}


/**
    Hash function that uses the key and mods by the number of buckets. It returns
    the index of the array for the hash table.

    This ended up being the best hash function with the least amount of collisions.
    I tried with different bucket numbers and it still proved to have the least amount of collisions.

    @param key - the id number to use in the hash function.

    @ return the index in the hash table to map the object to 
*/
int HashTable::bestHash(int key) {
    return key % SIZE;
}


/**
    Hash function that uses the key, squares it and takes the middle 3 numbers
    then mods by the number of buckets. It returns the index of the array for the hash table.

    This ended up being the worst hash function with the highest amount of collisions.
    I tried with different bucket numbers and it still proved to have the highest amount of collisions.
    I found this concept in my research of hash functions. It is called the mid-square method.
    I thought it would be the best because of the complexity but it had many collisions.

    @param key - the id number to use in the hash function.

    @ return the index in the hash table to map the object to
*/
int HashTable::badHash(int key) {
    long val = key * key;
    string strVal = to_string(val);
    int mid = strVal.length() / 2;
    int len = 3;
    int hashValue = 0;
    if (strVal.length() >= mid + 3)
        hashValue = stoi(strVal.substr(mid, mid + 3));
    else
        cout << "Hash value is too small " << hashValue << endl;

    return hashValue % SIZE;
}

/**
    Hash function that uses the square root of the key, multiplies by 2000 and mods by the
    number of buckets. It returns the index of the array for the hash table.

    This was slightly better than the mid-square method but still produced more collisions than I 
    thought it would. I made this one up myself, thinking that if I could change the last two numbers
    in the id, it would produce better results. Taking the square root produced the greatest differences
    across numbers where the last 2 digits were the same, but still resulted in more collisions than the
    simplest hash function.

    @param key - the id number to use in the hash function.

    @ return the index in the hash table to map the object to
*/
int HashTable::betterHash(int key) {
    double val = (sqrt(key) / 2);
    int hashVal = (int) (val * 1000) % SIZE;

    return hashVal;
}


/**
    Inserts a new Patient object into the hash table using the indicated hashing function.

    @param pat the Patient object to insert
    @param hashType an integer indicating which hash function to use (1 = bad, 2 = better, 3 = best)
*/
void HashTable::insert(Patient pat, int hashType) {
    int index = 0;

    switch (hashType) {
    case 1:
        index = badHash(pat.getPatientID());
        break;
    case 2:
        index = betterHash(pat.getPatientID());
        break;
    case 3:
        index = bestHash(pat.getPatientID());
        break;
    default:
        break;
    }
    table[index].insert(pat);
}


/**
    Retrieves a patient from the HashTable

    @param pat The Patient object to get from the HashTable
    @param hashType an integer indicating which hash function to use (1 = bad, 2 = better, 3 = best)
*/
Patient HashTable::get(Patient pat, int hashType) {
    int index = 0;
    switch (hashType) {
    case 1:
        index = badHash(pat.getPatientID());
        break;
    case 2:
        index = betterHash(pat.getPatientID());
        break;
    case 3:
        index = bestHash(pat.getPatientID());
        break;
    default:
        break;
    }
    return table[index].get(pat);
}


/**
    Displays the HashTable contents. Calls the LinkedList displayList() method to display each of the
    nodes in the linked list at each index.
*/
void HashTable::displayHashTable() {
    int total = 0;
    int runningTotal = 0;
    for (int i = 0; i < SIZE; ++i) {
        total = table[i].displayList();
        cout << endl;
        cout << endl;
        cout << "Bucket " << i << ": " << total << " collisions" << endl;
        cout << endl;
        cout << endl;
        runningTotal += total;
        total = 0;
    }

    cout << endl;
    cout << endl;

    cout << "For this hash function, there were " << runningTotal << " collisions." << endl;

    cout << endl;
    cout << endl;
}


/**
    Returns true if the specified Patient object is in the hash table and false otherwise.

    @param toFind The Patient object to find in the HashTable
    @param hashType an integer indicating which hash function to use (1 = bad, 2 = better, 3 = best)
*/
bool HashTable::contains(Patient toFind, int hashType) {
    int index = 0;
    switch (hashType) {
    case 1:
        index = badHash(toFind.getPatientID());
        break;
    case 2:
        index = betterHash(toFind.getPatientID());
        break;
    case 3:
        index = bestHash(toFind.getPatientID());
        break;
    default:
        break;
    } 
    return table[index].contains(toFind);
}


/**
    Finds the index of the specified object and removes it from the HashTable

    @param toFind The Patient object to remove from the HashTable
    @param hashType an integer indicating which hash function to use (1 = bad, 2 = better, 3 = best)
*/
void HashTable::remove(Patient toFind, int hashType) {
    int index = 0;
    switch (hashType) {
    case 1:
        index = badHash(toFind.getPatientID());
        break;
    case 2:
        index = betterHash(toFind.getPatientID());
        break;
    case 3:
        index = bestHash(toFind.getPatientID());
        break;
    default:
        break;
    }  

    table[index].remove(toFind);

}