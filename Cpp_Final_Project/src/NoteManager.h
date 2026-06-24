#include "NoteManager.h"
#include <fstream>
#include <sstream>

void NoteManager::addNote(std::unique_ptr<NoteItem> note) {
    notes.push_back(std::move(note));
}

void NoteManager::saveToFile() const {
    std::ofstream outFile(filename);
    if (!outFile) return;
    for (const auto& note : notes) {
        outFile << note->serialize() << "\n";
    }
}

void NoteManager::loadFromFile() {
    notes.clear();
    std::ifstream inFile(filename);
    if (!inFile) return;

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string type, title, date, extra;

        std::getline(ss, type, '|');
        std::getline(ss, title, '|');
        std::getline(ss, date, '|');
        std::getline(ss, extra, '|');

        if (type == "TEXT") {
            notes.push_back(std::make_unique<TextNote>(title, date, extra));
        }
        else if (type == "TODO") {
            notes.push_back(std::make_unique<TodoNote>(title, date, extra == "1"));
        }
    }
}

void NoteManager::listNotes() const {
    if (notes.empty()) {
        std::cout << "目前沒有任何筆記。\n";
        return;
    }
    for (size_t i = 0; i < notes.size(); ++i) {
        std::cout << i + 1 << ". ";
        notes[i]->display();
    }
}