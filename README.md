# 🚀 LeetCode Solutions | 编程之美与算法探索

欢迎来到我的 LeetCode 刷题与算法笔记仓库！这里记录了我攻克算法难题的历程、代码实现以及解题思路。

[![LeetCode Stats](https://img.shields.io/badge/LeetCode-Algorithm-FFA116?style=flat-square&logo=leetcode)](https://leetcode.cn/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)](https://github.com/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=flat-square)](https://opensource.org/licenses/MIT)

---

## 📌 仓库简介

建立这个仓库的初衷是沉淀数据结构与算法的核心知识，培养良好的编码习惯。

* **语言选择**：目前全部使用 **C++**，专注于高效的内存管理与底层性能调优。
* **解题标准**：不仅追求 `Accept`，更追求优化的时间/空间复杂度。多数题目在同一文件内保留了**多种解法**（如暴力、递推、动态规划、双指针、矩阵快速幂等）与思路对比，便于横向比较。

---

## 📂 目录结构

代码按照**算法/数据结构分类**进行组织，方便按主题检索。文件命名统一为 `题号-英文题名.cpp`（题号补零至 4 位，便于排序）：

```text
.
├── solutions/
│   ├── dynamic-programming/           # 动态规划 / 递推
│   ├── array-and-matrix/             # 数组 / 矩阵 / 模拟
│   └── two-pointers-and-hashing/     # 双指针 / 哈希
└── README.md                         # 本主页导航
```

> 💡 单文件内如包含多种解法，通常按「暴力 → 优化」的顺序排列；被注释掉的代码块为早期或次优解法，保留以作对照。

---

## 📋 题目索引

### 🧮 动态规划 / 递推 (`solutions/dynamic-programming/`)

| 题号 | 题目 | 关键思路 |
| :--: | :-- | :-- |
| 70  | [爬楼梯](solutions/dynamic-programming/0070-climbing-stairs.cpp) | 递推 / 滚动数组 |
| 121 | [买卖股票的最佳时机](solutions/dynamic-programming/0121-best-time-to-buy-and-sell-stock.cpp) | 暴力 / 一次遍历 DP |
| 338 | [比特位计数](solutions/dynamic-programming/0338-counting-bits.cpp) | Brian Kernighan / DP |
| 509 | [斐波那契数](solutions/dynamic-programming/0509-fibonacci-number.cpp) | 递推 / 矩阵快速幂 |
| 746 | [使用最小花费爬楼梯](solutions/dynamic-programming/0746-min-cost-climbing-stairs.cpp) | 滚动数组 DP |
| 1025 | [除数博弈](solutions/dynamic-programming/1025-divisor-game.cpp) | 博弈 DP |
| 1137 | [第 N 个泰波那契数](solutions/dynamic-programming/1137-n-th-tribonacci-number.cpp) | 递推 / 矩阵快速幂 |

### 🔢 数组 / 矩阵 / 模拟 (`solutions/array-and-matrix/`)

| 题号 | 题目 | 关键思路 |
| :--: | :-- | :-- |
| 118 | [杨辉三角](solutions/array-and-matrix/0118-pascals-triangle.cpp) | 逐行递推 |
| 119 | [杨辉三角 II](solutions/array-and-matrix/0119-pascals-triangle-ii.cpp) | 滚动数组 / 组合公式 |

### 👉 双指针 / 哈希 (`solutions/two-pointers-and-hashing/`)

| 题号 | 题目 | 关键思路 |
| :--: | :-- | :-- |
| 219 | [存在重复元素 II](solutions/two-pointers-and-hashing/0219-contains-duplicate-ii.cpp) | 哈希表 / 滑动窗口 |
| 392 | [判断子序列](solutions/two-pointers-and-hashing/0392-is-subsequence.cpp) | 双指针 |

---

## 🛠️ 约定与规范

* **命名**：`题号-英文题名.cpp`，题号左侧补零至 4 位（如 `0070-climbing-stairs.cpp`），保证目录内字典序即题号序。
* **分类归属**：一题涉及多类算法时，按其**最核心的解法**归类。
* **新增题目**：将解法放入对应分类目录，并在上方「题目索引」表格中补充一行。

---

## 📜 License

本仓库采用 [MIT License](https://opensource.org/licenses/MIT) 开源。
