/**
 * @file lphashtable.cpp
 * Implementation of the LPHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */
#include "lphashtable.h"

using hashes::hash;
using std::pair;

template <class K, class V>
LPHashTable<K, V>::LPHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new pair<K, V>*[size];
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = NULL;
        should_probe[i] = false;
    }
    elems = 0;
}

template <class K, class V>
LPHashTable<K, V>::~LPHashTable()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
}

template <class K, class V>
LPHashTable<K, V> const& LPHashTable<K, V>::operator=(LPHashTable const& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < size; i++)
            delete table[i];
        delete[] table;
        delete[] should_probe;

        table = new pair<K, V>*[rhs.size];
        should_probe = new bool[rhs.size];
        for (size_t i = 0; i < rhs.size; i++) {
            should_probe[i] = rhs.should_probe[i];
            if (rhs.table[i] == NULL)
                table[i] = NULL;
            else
                table[i] = new pair<K, V>(*(rhs.table[i]));
        }
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
LPHashTable<K, V>::LPHashTable(LPHashTable<K, V> const& other)
{
    table = new pair<K, V>*[other.size];
    should_probe = new bool[other.size];
    for (size_t i = 0; i < other.size; i++) {
        should_probe[i] = other.should_probe[i];
        if (other.table[i] == NULL)
            table[i] = NULL;
        else
            table[i] = new pair<K, V>(*(other.table[i]));
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void LPHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >= 0.7).
     * **Do this check *after* increasing elems (but before inserting)!!**
     * Also, don't forget to mark the cell for probing with should_probe!
     */

    elems += 1;
    if (shouldResize()) {
        resizeTable();
    }

    size_t idx = hash(key, size);
    pair<K, V>* p = new pair<K, V>(key, value);
    while (should_probe[idx]) {
        idx = (size_t)((idx + 1) % size);
    }
    if (!should_probe[idx]) {
        table[idx] = p;
        should_probe[idx] = true;
    }
}

template <class K, class V>
void LPHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo: implement this function
     */
    size_t idx = hash(key, size);
    while (should_probe[idx]) {
        if (table[idx] != NULL && table[idx]->first == key) {
            // delete table[idx];
            table[idx] = NULL;
            elems -= 1;
            break;
        } else {
            idx = (idx + 1) % size;
        }
    }
}

template <class K, class V>
int LPHashTable<K, V>::findIndex(const K& key) const
{
    
    /**
     * @todo Implement this function
     *
     * Be careful in determining when the key is not in the table!
     */
    size_t idx = hash(key, size);
    while (should_probe[idx]) {
        if (table[idx] != NULL && table[idx]->first == key) {
            return idx;
        } else {
            idx = (idx + 1) % size;
        }
    }

    return -1;
}

template <class K, class V>
V LPHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& LPHashTable<K, V>::operator[](K const& key)
{
    // First, attempt to find the key and return its value by reference
    int idx = findIndex(key);
    if (idx == -1) {
        // otherwise, insert the default value and return it
        insert(key, V());
        idx = findIndex(key);
    }
    return table[idx]->second;
}

template <class K, class V>
bool LPHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void LPHashTable<K, V>::clear()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
    table = new pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void LPHashTable<K, V>::resizeTable()
{

    /**
     * @todo Implement this function
     *
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
    size_t oldSize = size;
    size = findPrime(2 * size);

    //save all data into an oldtable
    std::pair<K, V>** oldTable = table;
    for (size_t i = 0; i < oldSize; i++) {
        if (table[i] != NULL) {
            oldTable[i] = table[i];
        }
    }
    //update a new table with new size
    table = new std::pair<K, V>*[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = nullptr;
    }

    //update the should_probe array with new size and set to be false
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        should_probe[i] = false;
    }

    //update elems to 0 and re-insert data
    elems = 0;

    //rehash data in old table to new table
    for (size_t i = 0; i < oldSize; i++) {
        if (oldTable[i] != NULL) {
            insert(oldTable[i]->first, oldTable[i]->second);
        }
    }
    //we have to add the new element since we add elems before insert
    elems += 1;
}
