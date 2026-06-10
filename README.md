# C 语言训练营 Unit 2 — C Essentials

> 覆盖常用的库函数、数据结构和算法——包括单向/循环链表，栈，队列，二叉树，堆和散列表等，掌握常用的排序查找算法和问题求解算法，学会使用递归思想编程，能够解决迷宫问题、表达式求值问题、最短路径问题等。

## 📚 练习题列表

25. [**25_my_strstr** - 实现 my_strstr — 暴力字符串匹配](./exercises/25_my_strstr/)
26. [**26_my_memcpy** - 实现 my_memcpy — 标准内存拷贝](./exercises/26_my_memcpy/)
27. [**27_my_memmove** - 实现 my_memmove — 内存重叠拷贝【重点】](./exercises/27_my_memmove/)
28. [**28_permutations** - 全排列问题 — 回溯算法入门](./exercises/28_permutations/)
29. [**29_eight_queens** - 八皇后问题 — 回溯 + 剪枝【标杆题】](./exercises/29_eight_queens/)
30. [**30_singly_list_insert** - 单链表动态插入：头插法与尾插法](./exercises/30_singly_list_insert/)
31. [**31_singly_list_modify** - 单链表查找与删除](./exercises/31_singly_list_modify/)
32. [**32_singly_list_reverse** - 单链表反转与快慢指针环检测【高频题】](./exercises/32_singly_list_reverse/)
33. [**33_circular_josephus** - 循环链表与约瑟夫环问题](./exercises/33_circular_josephus/)
34. [**34_bracket_match** - 栈实现括号匹配](./exercises/34_bracket_match/)
35. [**35_queue_base** - 环形队列基础实现](./exercises/35_queue_base/)
36. [**36_binary_tree_traversal** - 二叉树的前中后序遍历（递归实现）](./exercises/36_binary_tree_traversal/)
37. [**37_binary_tree_level_order** - 二叉树层序遍历（BFS）](./exercises/37_binary_tree_level_order/)
38. [**38_BST_ops** - 二叉搜索树：插入、查找与删除](./exercises/38_BST_ops/)
39. [**39_heap_base_topk** - 堆与 Top-K 问题](./exercises/39_heap_base_topk/)
40. [**40_binary_search** - 二分查找与边界变体](./exercises/40_binary_search/)
41. [**41_quick_sort** - 快速排序实现](./exercises/41_quick_sort/)
42. [**42_snprintf** - snprintf 格式化安全](./exercises/42_snprintf/)
43. [**43_strtok_r** - strtok_r 线程安全字符串切分](./exercises/43_strtok_r/)
44. [**44_qsort** - qsort 泛型排序：int 与字符串数组](./exercises/44_qsort/)
45. [**45_realloc** - realloc 动态扩容实验](./exercises/45_realloc/)
46. [**46_sscanf** - sscanf 高级格式化解析](./exercises/46_sscanf/)
47. [**47_setjmp_longjmp** - setjmp/longjmp 非局部跳转](./exercises/47_setjmp_longjmp/)
48. [**48_io_buffer_perf** - 标准 I/O 缓冲性能对比：文件拷贝](./exercises/48_io_buffer_perf/)

## 前置条件

- 您必须报名 [C 语言训练营](https://opencamp.cn/C/camp/2026?lang=zh_CN)

  ![](resource/c.jpg)

- 您必须在训练营个人中心完成 CNB 账号绑定

  ![](resource/bangding.jpg)

## 操作流程

1. Fork 本仓库，解锁作业副本。
2. 在您 Fork 的仓库中点击 **云原生开发** 按钮进入开发环境。
3. 根据文档完成 24 个 exercises 中的练习题（共 24 道小题）。
4. 完成后提交代码到 main 分支，并创建合并请求。

   ![](resource/pr.png)

5. 在 PR 页面查看评分结果（可多次提交，每次提交都会触发评分，以最高分为准）。

   ![](resource/pingce.png)

6. 如果通过，则可以在 OpenCamp 的晋级榜单上看到自己的成绩。

   ![](resource/bangdan.jpg)

## 云原生开发 / 本地开发

### 🛠️ 系统要求

- GCC 编译器
- Python 3.11+
- （推荐）安装 [uv](https://docs.astral.sh/uv/) 用于运行 clings

```bash
# Ubuntu/Debian
sudo apt-get update && sudo apt-get install -y gcc python3
# 安装 uv (推荐)
curl -LsSf https://astral.sh/uv/install.sh | sh

# macOS (Homebrew)
brew install gcc uv
```

### 安装 clings

```bash
# 方式 1: uvx (推荐，无需安装，隔离运行)
uvx clings init unit2
uvx clings

# 方式 2: pipx (隔离安装到独立环境)
pipx install clings

# 方式 3: pip + 虚拟环境
python3 -m venv .venv && source .venv/bin/activate
pip install clings
```

> **注意**: Ubuntu 23.04+ / Python 3.11+ 禁止直接 `pip install` 到系统环境。
> 请使用上述 uvx / pipx / venv 方式，避免 `--break-system-packages`。

### 🚀 快速开始

```bash
# 1. 初始化练习 (如果还没有 exercises/ 目录)
clings init unit2

# 2. 进入交互式 watch 模式 (保存即验证)
clings

# 3. 或者查看练习列表
clings list

# 4. 查看当前题目提示
clings hint

# 5. 查看当前得分
clings score unit2
```

### 命令参考

```bash
clings                    # 交互式 watch 模式 (默认)
clings watch unit2 --manual-run  # 手动模式: 按 r 重新运行
clings list               # 列出练习 + ✔/• 进度状态
clings hint [exercise]    # 查看提示
clings run [exercise]     # 运行单个练习
clings check unit2        # 批量验证所有题目
clings score unit2        # 打分 (输出 JSON 报告)
clings reset <exercise>   # 重置练习文件
clings doctor             # 检查环境
clings -v                 # 显示版本号
```

### Watch 模式

Rustlings 风格的交互式练习体验 — 保存文件即自动验证，按键即可导航：

```
Progress: [████████████░░░░░░░░] 12/24 (50.0%)

  ❌ Current: 25_my_strstr
  File: exercises/25_my_strstr/25_my_strstr.c
  Title: 实现 my_strstr — 暴力字符串匹配

  compile failed for 25_my_strstr
  ...

  Commands: h:hint  l:list  r:rerun  x:reset  q:quit
```

交互命令：

| 按键 | 功能                                        |
| ---- | ------------------------------------------- |
| `n`  | 当前题通过后推进到下一题                    |
| `h`  | 显示/隐藏当前题提示                         |
| `l`  | 进入列表模式 (j/k 导航、s 搜索、Enter 跳转) |
| `r`  | 强制重新运行当前题                          |
| `x`  | 重置当前题 (git checkout 恢复原始文件)      |
| `c`  | 检查所有题目                                |
| `q`  | 退出 watch 模式                             |

列表模式快捷键：`j`/`k` 上下移动 · `g`/`G` 首尾 · `d`/`p`/`a` 筛选 · `s` 或 `/` 搜索 · `r` 重置 · `Enter` 跳转 · `q` 返回

> **进度持久化**：进度自动保存到 `.clings-state.txt`，关闭终端后重新进入 watch 即恢复。

## 📁 项目结构

```
Unit-2-C-Essentials/
├── exercises/                  # 练习题源码 (clings 格式)
│   ├── 25_my_strstr/
│   │   ├── README.md           # 课程讲义
│   │   ├── exercises.toml      # 练习元数据 + 测试用例
│   │   └── 25_my_strstr.c      # 练习题 (补全代码)
│   ├── 26_my_memcpy/
│   └── ...
├── lessons/                    # 原始课程讲义 (NCCL 格式)
├── clings.toml                 # Unit 配置
├── .cnb.yml                    # CI 打分 + 云开发环境配置
├── Dockerfile.ci               # CI 打分环境
├── .ide/Dockerfile             # 云开发环境 (code-server)
└── README.md                   # 本文件
```

## 🔧 故障排除

1. **编译错误** — 仔细阅读编译器报错信息，检查语法
2. **输出不匹配** — 注意换行符 `\n`、空格、制表符 `\t` 是否与期望输出完全一致
3. **环境问题** — 运行 `clings doctor` 检查 gcc 和 Python 是否就绪

## 📄 许可证

MIT

---

**Happy Coding! 🚀**
