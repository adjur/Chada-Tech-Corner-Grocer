#include "ItemTracker.h"

ItemTracker::ItemTracker(const std::string& inputFilename, const std::string& backupFilename) {
    LoadItemsFromFile(inputFilename);
    SaveFrequenciesToFile(backupFilename);
}

void ItemTracker::LoadItemsFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string item;

    if (!inFile) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return;
    }

    while (inFile >> item) {
        ++itemMap[item];
    }

    inFile.close();
}

void ItemTracker::SaveFrequenciesToFile(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Could not write to file " << filename << std::endl;
        return;
    }

    for (const auto& pair : itemMap) {
        outFile << pair.first << " " << pair.second << std::endl;
    }

    outFile.close();
}

int ItemTracker::GetItemFrequency(const std::string& item) const {
    auto it = itemMap.find(item);
    if (it != itemMap.end()) {
        return it->second;
    }
    return 0;
}

void ItemTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void ItemTracker::PrintHistogram() const {
    for (const auto& pair : itemMap) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
