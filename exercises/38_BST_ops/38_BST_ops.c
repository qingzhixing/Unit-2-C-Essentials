/* 38_BST_ops.c — 二叉搜索树：插入、查找与删除
 *
 * 任务: 实现 BST 三个核心操作
 *       1. find_min(root)  — 找最小值（最左节点）
 *       2. bst_insert(root, val) — 插入：小于往左，大于往右，遇 NULL 新建
 *       3. bst_search(root, val) — 查找：返回找到的节点或 NULL
 *       4. bst_delete(root, val) — 删除【难点】，三种情况:
 *          a. 叶子: 直接 free 返回 NULL
 *          b. 单子树: 保留子树，free 被删节点
 *          c. 双子树: 右子树最小值替换，再递归删除该最小值
 *
 * 知识点: BST 性质、递归插入/删除、find_min、右子树最小值替代法
 *
 * 验证：
 *   stdin: "insert 5 3 7 2 4\n"          → 2 3 4 5 7  (中序遍历=有序)
 *   stdin: "insert 5 3 7\nsearch 3\n"     → found
 *   stdin: "insert 5 3 7\nsearch 9\n"     → not found
 *   stdin: "insert 5 3 7 2 4\ndelete 3\n" → 2 4 5 7
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node *make_node(int val) {
    struct node *p = malloc(sizeof(*p));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

void inorder(struct node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* 找 BST 最小值：不断向左走，直到 left == NULL */
struct node *find_min(struct node *root) {
    /* 空树返回 NULL */
    if (!root) return NULL;
    /* while (左孩子非空) → 向左移动 */
    while (root->left) root = root->left;
    /* 返回最左节点 */
    return root;
}

/* BST 插入：小于往左子树递归，大于往右子树递归 */
struct node *bst_insert(struct node *root, int val) {
    /* 到达空位置 → 创建新节点并返回 */
    if (!root) {
        return make_node(val);
    }
    /* val < root->data → 递归插入左子树 */
    if (val < root->data) {
        root->left = bst_insert(root->left, val);
    } else {
        /* val > root->data → 递归插入右子树 */
        root->right = bst_insert(root->right, val);
    }

    /* 返回 root */
    return root;
}

/* BST 查找 */
struct node *bst_search(struct node *root, int val) {
    /* root == NULL 或 root->data == val → 返回 root */
    if (!root || root->data == val) return root;
    /* val < root->data → 递归查找左子树 */
    if (val < root->data) {
        return bst_search(root->left, val);
    } else {
        /* 否则 → 递归查找右子树 */
        return bst_search(root->right, val);
    }
}

/* BST 删除 — 三种情况 */
struct node *bst_delete(struct node *root, int val) {
    /* root == NULL → 返回 NULL */
    if (!root) return NULL;
    /* val < root->data → 递归删除左子树 */
    if (val < root->data) {
        root->left = bst_delete(root->left, val);
    } else if (val > root->data) {
        /* val > root->data → 递归删除右子树 */
        root->right = bst_delete(root->right, val);
    } else if (val == root->data) {
        /* 找到要删的节点 (val == root->data)：
         *   叶子: 无左右子 → free(root); return NULL
         *   只有左子: tmp = root->left; free(root); return tmp
         *   只有右子: tmp = root->right; free(root); return tmp
         *   双子: min = find_min(root->right);
         *         root->data = min->data;
         *         root->right = bst_delete(root->right, min->data) */
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        if (!root->right) {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }
        if (!root->left) {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }
        struct node *min = find_min(root->right);
        root->data = min->data;
        root->right = bst_delete(root->right, min->data);
        return root;
    }
    /* 返回 root */
    return root;
}

int main(void) {
    struct node *root = NULL;
    /* 处理最多两行命令：
     *   第一行 → 构建一颗树（insert）或空树（search/delete）
     *   第二行 → 对树执行查询或删除 */
    for (int ln = 0; ln < 2; ln++) {
        char line[256];
        if (!fgets(line, sizeof(line), stdin)) break;
        int i = 0;
        while (line[i] && line[i] != '\n') i++;
        line[i] = '\0';

        char *cmd = strtok(line, " ");
        if (!cmd) continue;

        /* 根据 cmd 分发：
         *   "insert": 循环 tok = strtok(NULL, " ") 读数字，逐个 bst_insert
         *             最后 printf("inorder: "); inorder(root); printf("\n");
         *   "search": 读数字，bst_search，打印 found/not found
         *   "delete": 循环读数字，逐个 bst_delete，最后打印中序遍历结果 */
        if (strcmp(cmd, "insert") == 0) {
            char *tok;
            while ((tok = strtok(NULL, " ")) != NULL) {
                int val = atoi(tok);
                root = bst_insert(root, val);
            }
            printf("inorder: ");
            inorder(root);
            printf("\n");
        } else if (strcmp(cmd, "search") == 0) {
            char *tok = strtok(NULL, " ");
            if (tok) {
                int val = atoi(tok);
                struct node *found = bst_search(root, val);
                if (found) {
                    printf("found\n");
                } else {
                    printf("not found\n");
                }
            }
        } else if (strcmp(cmd, "delete") == 0) {
            char *tok;
            while ((tok = strtok(NULL, " ")) != NULL) {
                int val = atoi(tok);
                root = bst_delete(root, val);
            }
            printf("inorder: ");
            inorder(root);
            printf("\n");
        }
    }
    return 0;
}
