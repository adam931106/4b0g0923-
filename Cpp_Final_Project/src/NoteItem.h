#ifndef NOTEITEM_H
#define NOTEITEM_H

#include <iostream>
#include <string>

// 基底類別
class NoteItem {
protected:
    std::string title;
    std::string date;
public:
    NoteItem(std::string t, std::string d) : title(t), date(d) {}
    virtual ~NoteItem() = default;

    virtual void display() const = 0;          // 純虛擬函式（多型）
    virtual std::string serialize() const = 0;   // 用於寫檔的序列化

    std::string getTitle() const { return title; }
};

// 衍生類別 A：文字筆記
class TextNote : public NoteItem {
private:
    std::string content;
public:
    TextNote(std::string t, std::string d, std::string c) : NoteItem(t, d), content(c) {}

    void display() const override {
        std::cout << "[" << date << "] (文字) " << title << "\n";
        std::cout << "-----------------------\n" << content << "\n-----------------------\n";
    }

    std::string serialize() const override {
        return "TEXT|" + title + "|" + date + "|" + content;
    }
};

// 衍生類別 B：待辦清單
class TodoNote : public NoteItem {
private:
    bool isDone;
public:
    TodoNote(std::string t, std::string d, bool done = false) : NoteItem(t, d), isDone(done) {}

    void display() const override {
        std::cout << "[" << date << "] (待辦) " << title
            << " -> [" << (isDone ? "已完成" : "未完成") << "]\n";
    }

    std::string serialize() const override {
        return "TODO|" + title + "|" + date + "|" + (isDone ? "1" : "0");
    }
};

#endif