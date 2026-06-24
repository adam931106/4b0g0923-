#include <iostream>
#include "NoteManager.h"

int main() {
    NoteManager manager;
    manager.loadFromFile(); // 開機自動讀檔

    int choice;
    while (true) {
        std::cout << "\n===== 終端機個人筆記管理系統 =====\n";
        std::cout << "1. 顯示所有筆記\n";
        std::cout << "2. 新增文字筆記\n";
        std::cout << "3. 新增待辦事項\n";
        std::cout << "4. 儲存並離開\n";
        std::cout << "請輸入選項 (1-4): ";

        if (!(std::cin >> choice)) {
            std::cout << "輸入錯誤，請輸入數字！\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "\n--- 筆記列表 ---\n";
            manager.listNotes();
        }
        else if (choice == 2) {
            std::string title, date, content;
            std::cout << "請輸入標題: "; std::getline(std::cin, title);
            std::cout << "請輸入日期 (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "請輸入內容: "; std::getline(std::cin, content);
            manager.addNote(std::make_unique<TextNote>(title, date, content));
        }
        else if (choice == 3) {
            std::string title, date;
            std::cout << "請輸入待辦事項名稱: "; std::getline(std::cin, title);
            std::cout << "請輸入日期 (YYYY-MM-DD): "; std::getline(std::cin, date);
            manager.addNote(std::make_unique<TodoNote>(title, date, false));
        }
        else if (choice == 4) {
            manager.saveToFile(); // 關機自動寫檔
            std::cout << "資料已儲存。系統安全關閉。\n";
            break;
        }
        else {
            std::cout << "無效選項，請重新輸入。\n";
        }
    }
    return 0;
}