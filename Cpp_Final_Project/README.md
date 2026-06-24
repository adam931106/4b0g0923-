# 終端機個人筆記管理系統 (C++ 期末專題)

## 📌 規格說明 (Specification)
本系統為基於終端機之文字筆記與待辦清單管理器。
* 展現 C++ 類別繼承（`NoteItem` -> `TextNote`, `TodoNote`）。
* 使用 STL `std::vector` 與 `std::unique_ptr` 管理動態記憶體。
* 實作檔案序列化讀寫，確保資料在關閉程式後不會遺失。

## 🔄 開發迭代流程 (Development Iteration)
* **Iteration 1**: 設計 `NoteItem` 繼承體系與多型架構。
* **Iteration 2**: 引入 STL 容器進行記憶體管理。
* **Iteration 3**: 實作檔案輸出與輸入流（I/O Streams）。
* **Iteration 4**: 建構互動式選單 UI 與輸入防呆機制。