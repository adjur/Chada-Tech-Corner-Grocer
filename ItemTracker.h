#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> itemMap;

    void LoadItemsFromFile(const std::string& filename);
    void SaveFrequenciesToFile(const std::string& filename);

public:
    ItemTracker(const std::string& inputFilename, const std::string& backupFilename);

    int GetItemFrequency(const std::string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;
};

#endif
