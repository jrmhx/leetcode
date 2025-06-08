# A Code Template Cheatsheet

## Two pointers: one input, opposite ends

```cpp
int fn(vector<int>& arr) {
    int left = 0;
    int right = int(arr.size()) - 1;
    int ans = 0;

    while (left < right) {
        // do some logic here with left and right
        if (CONDITION) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}
```

## Two pointers: two inputs, exhaust both

```cpp
int fn(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, ans = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // do some logic here
        if (CONDITION) {
            i++;
        } else {
            j++;
        }
    }

    while (i < arr1.size()) {
        // do logic
        i++;
    }

    while (j < arr2.size()) {
        // do logic
        j++;
    }

    return ans;
}
```

## Two pointers: slow and fast pointer

```cpp
int fn(vector<int>& arr) {
    int slow = 0;
    int fast = 0;

    while (fast < arr.size()) {
        // do some logic here
        if (CONDITION) {
            slow++;
        }

        fast++;
    }

    return slow;
}
```

## Sliding Window

```cpp
int fn(vector<int>& arr) {
    int left = 0, ans = 0, curr = 0;

    for (int right = 0; right < arr.size(); right++) {
        // do logic here to add arr[right] to curr

        while (WINDOW_CONDITION_BROKEN) {
            // remove arr[left] from curr
            left++;
        }

        // update ans
    }

    return ans;
}
```

## Build a prefix sum

```cpp
vector<int> fn(vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}
```

## Efficient string building

```cpp
string fn(vector<char>& arr) {
    return string(arr.begin(), arr.end())
}
```

## Linked list: fast and slow pointer

```cpp
int fn(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int ans = 0;

    while (fast != nullptr && fast->next != nullptr) {
        // do logic
        slow = slow->next;
        fast = fast->next->next;
    }

    return ans;
}
```

## Linked list: reverse a linked list

```cpp
ListNode* fn(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
```

## Find number of subarrays that fit an exact criteria

```cpp
int fn(vector<int>& arr, int k) {
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;

    for (int num: arr) {
        // do logic to change curr
        ans += counts[curr - k];
        counts[curr]++;
    }

    return ans;
}
```

## Monotonic increasing stack

```cpp
int fn(vector<int>& arr) {
    stack<integer> stack;
    int ans = 0;

    for (int num: arr) {
        // for monotonic decreasing, just flip the > to <
        while (!stack.empty() && stack.top() > num) {
            // do logic
            stack.pop();
        }

        stack.push(num);
    }
}
```

## Binary Tree: preorder traversal

```cpp
void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // do logic
    preorder(root->left);
    preorder(root->right);
}
```

## Binary tree: DFS (recursive)

```cpp
int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    // do logic
    dfs(root.left);
    dfs(root.right);
    return ans;
}
```

## Binary tree: BFS (iterative)

```cpp
int dfs(TreeNode* root) {
    stack<TreeNode*> stack;
    stack.push(root);
    int ans = 0;

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        // do logic
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        if (node->right != nullptr) {
            stack.push(node->right);
        }
    }

    return ans;
}
```

## Binary tree: BFS

```cpp
int fn(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.push(root);
    int ans = 0;

    while (!queue.empty()) {
        int currentLength = queue.size();
        // do logic for current level

        for (int i = 0; i < currentLength; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            // do logic
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }

    return ans;
}
```

## Graph: DFS (recursive)

```cpp
unordered_set<int> seen;

int fn(vector<vector<int>>& graph) {
    seen.insert(START_NODE);
    return dfs(START_NODE, graph);
}

int dfs(int node, vector<vector<int>>& graph) {
    int ans = 0;
    // do some logic
    for (int neighbor: graph[node]) {
        if (seen.find(neighbor) == seen.end()) {
            seen.insert(neighbor);
            ans += dfs(neighbor, graph);
        }
    }

    return ans;
}
```

## Graph: DFS (iterative)

```cpp
int fn(vector<vector<int>>& graph) {
    stack<int> stack;
    unordered_set<int> seen;
    stack.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
}
```

## Graph: BFS

```cpp
int fn(vector<vector<int>>& graph) {
    queue<int> queue;
    unordered_set<int> seen;
    queue.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}
```

## create heap

```cpp

int main() {
  std::vector<int> v {4, 8, 5, 7, 8,10,10};

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq(v.begin(), v.end());
  // min heap, pq by default is max heap
  // O(n) for constructor from range

  // pop() push() O(log(n))

  return 0;
}

```

## Find top k elements with heap

```cpp
vector<int> fn(vector<int>& arr, int k) {
    priority_queue<int, CRITERIA> heap;
    for (int num: arr) {
        heap.push(num);
        if (heap.size() > k) {
            heap.pop();
        }
    }

    vector<int> ans;
    while (heap.size() > 0) {
        ans.push_back(heap.top());
        heap.pop();
    }

    return ans;
}
```

## Binary search

```cpp

//找“最左满足条件”的值
while (l < r) {
    int mid = l + (r - l) / 2;
    if (condition(mid)) {
        r = mid; // 保留 mid
    } else {
        l = mid + 1; // 舍弃 mid
    }
}
// l 是最左满足的位置

//找“最右满足条件”的值
while (l < r) {
    int mid = l + (r - l + 1) / 2; // 注意这里用上取整
    if (condition(mid)) {
        l = mid; // 保留 mid
    } else {
        r = mid - 1; // 舍弃 mid
    }
}
// r 是最右满足的位置

```

```cpp
int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = int(arr.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                // do something;
                return mid;
            }
            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // left is the insertion point
        return left;
    }
```

## Binary search: duplicate elements, left-most insertion point

```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
```

## Binary search: duplicate elements, right-most insertion point

```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
```

## Binary search: for greedy problems

### If looking for a minimum

```cpp
int fn(vector<int>& arr) {
    int left = MINIMUM_POSSIBLE_ANSWER;
    int right = MAXIMUM_POSSIBLE_ANSWER;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return BOOLEAN;
}
```

### If looking for a maximum

```cpp
int fn(vector<int>& arr) {
    int left = MINIMUM_POSSIBLE_ANSWER;
    int right = MAXIMUM_POSSIBLE_ANSWER;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return BOOLEAN;
}
```

## Backtracking

```python
def backtrack(candidate):
    if find_solution(candidate):
        output(candidate)
        return
    
    # iterate all possible candidates.
    for next_candidate in list_of_candidates:
        if is_valid(next_candidate):
            # try this partial candidate solution
            place(next_candidate)
            # given the candidate, explore further.
            backtrack(next_candidate)
            # backtrack
            remove(next_candidate)
```
### 🧠 回溯题型剪枝与去重技巧大全

| 类别               | 是否含重复 | 是否需要排序 | 是否使用 visited | 是否需要剪枝           | 去重/合法性技巧                                                                 |
|--------------------|------------|---------------|-------------------|--------------------------|----------------------------------------------------------------------------------|
| 子集 `subsets()`   | ❌ 否       | ❌ 否          | ❌ 否              | ❌ 否                     | 所有组合天然唯一                                                                |
| 子集 `subsetsWithDup()` | ✅ 是   | ✅ 是          | ❌ 否              | ✅ 是                     | `if (i > start && nums[i] == nums[i-1]) continue;`                              |
| 组合 `combinationSum()` | ❌ 否   | ❌ 否          | ❌ 否              | ✅ 是                     | 每个数可多次选，递归继续用 `i`                                                  |
| 组合 `combinationSum2()` | ✅ 是  | ✅ 是          | ❌ 否              | ✅ 是                     | 排序 + `if (i > start && nums[i] == nums[i-1]) continue;`，递归用 `i+1`         |
| 排列 `permute()`         | ❌ 否 | ❌ 否          | ✅ 是              | ❌ 否                     | 标准 visited[] 递归                                                             |
| 排列 `permuteUnique()`   | ✅ 是 | ✅ 是（方法1） | ✅ 是（方法1）     | ✅ 是（方法1）            | 方法1: 排序 + visited + 剪枝<br>方法2: 使用 `unordered_map<int, int>`         |
| 括号生成 `generateParenthesis()` | - | ❌ 否         | ❌ 否              | ✅ 是                     | 条件限制：左括号 < n，右括号 < 左括号                                           |
| N 皇后 `solveNQueens()` | -        | ❌ 否          | ❌ 否              | ✅ 是                     | 使用 `cols, diag1, diag2` 集合判断位置合法性                                   |
| 数独 `solveSudoku()`     | -        | ❌ 否          | ❌ 否              | ✅ 是                     | 同行/同列/九宫格是否合法，回溯恢复状态                                         |
| 单词搜索 `wordSearch()` | -        | ❌ 否          | ✅ 是              | ✅ 是                     | 使用 `visited[][]`，上下左右 DFS                                                 |
| 解迷宫（路径搜索）       | -        | ❌ 否          | ✅ 是              | ✅ 是                     | DFS 方向探索，使用 visited 或回退标记                                            |
| 分割回文串 `partition()` | -        | ❌ 否          | ❌ 否              | ✅ 是                     | 每次判断子串是否是回文（`isPalindrome`）                                        |
| 数字 IP 复原 `restoreIpAddresses()` | - | ❌ 否        | ❌ 否              | ✅ 是                     | 限制每段 0-255，不能前导 0                                                      |
| 全排列 II（频次表法）    | ✅ 是    | ❌ 否          | ❌ 否              | ❌ 是                     | 使用 `map[num]--` 控制剩余次数                                                  |

### 📘 技巧说明

| 技巧              | 作用与适用场景                         | 示例题目                               |
|-------------------|----------------------------------------|----------------------------------------|
| visited[]         | 用于排列类问题，标记当前元素是否已使用 | `permute`, `wordSearch`, `maze path`   |
| 排序 + 剪枝       | 去重策略，适合子集/组合/排列（含重复） | `subsetsWithDup`, `combinationSum2`    |
| 频次表 unordered_map | 控制重复元素使用次数                 | `permuteUnique` 方法2                  |
| 左右括号条件剪枝   | 保证生成合法括号字符串                 | `generateParenthesis`                  |
| 回文判断剪枝       | 切割子串时判断是否合法                 | `partition`                            |
| 数字合法性判断     | 限制数字大小/格式                     | `restoreIpAddresses`, `sudoku`         |
| 同行/列/对角线约束 | 约束某个位置是否合法                 | `solveNQueens`, `solveSudoku`          |

### ✅ 回溯口诀速查

| 场景     | 口诀                               |
|----------|------------------------------------|
| 子集     | 排序剪枝跳相同                     |
| 组合     | 排序剪枝不回头（i+1）              |
| 排列     | visited 标记配剪枝 / 可用频次表     |
| 括号生成 | 左小于右，右不多于左               |
| N 皇后   | 列、正对角、反对角不能重复         |
| 数独     | 行、列、宫格不能重复               |
| 拆分类   | 判断合法性再分割                   |

## DP

### DP: top-down memoization

```cpp
unordered_map<STATE, int> memo;

int fn(vector<int>& arr) {
    return dp(STATE_FOR_WHOLE_INPUT, arr);
}

int dp(STATE, vector<int>& arr) {
    if (BASE_CASE) {
        return 0;
    }

    if (memo.find(STATE) != memo.end()) {
        return memo[STATE];
    }

    int ans = RECURRENCE_RELATION(STATE);
    memo[STATE] = ans;
    return ans;
}
```

### DP: bottom-up tabulation

```cpp
int fn(vector<int>& arr) {
    vector<int> dp(arr.size() + 1);
    dp[0] = 0;

    for (int i = 1; i <= arr.size(); i++) {
        dp[i] = RECURRENCE_RELATION(i);
    }

    return dp[arr.size()];
}
```

### DP: bottom-up tabulation with 2D array

```cpp
int fn(vector<int>& arr) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1));
    dp[0][0] = 0;

    for (int i = 1; i <= arr.size(); i++) {
        for (int j = 1; j <= arr.size(); j++) {
            dp[i][j] = RECURRENCE_RELATION(i, j);
        }
    }

    return dp[arr.size()][arr.size()];
}
```

## Build a trie

```cpp
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <optional>
#include <iostream>

using namespace std;

struct TrieNode {
    bool is_end;
    unordered_map<char, unique_ptr<TrieNode>> childern;
};

optional<unique_ptr<TrieNode>> buildTrie(vector<string>& strs) {
    try {
        auto root = std::make_unique<TrieNode>();
        for (auto str : strs) { // start from first word
            auto curr = root.get();
            for (auto c : str) { // start from first letter of the word
                if (curr->childern.find(c) == curr->childern.end()){
                    curr->childern[c] = std::make_unique<TrieNode>();
                }
                curr = curr->childern[c].get();
            }
            // end of the word
            curr->is_end = true;
        }
        return root;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return std::nullopt;
    }
}
```

## Dijkstra's algorithm

```cpp
vector<int> distances(n, INT_MAX);
distances[source] = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
heap.push({0, source});

while (!heap.empty()) {
    int currDist = heap.top().first;
    int node = heap.top().second;
    heap.pop();
    
    if (currDist > distances[node]) {
        continue;
    }
    
    for (pair<int, int> edge: graph[node]) {
        int nei = edge.first;
        int weight = edge.second;
        int dist = currDist + weight;
        
        if (dist < distances[nei]) {
            distances[nei] = dist;
            heap.push({dist, nei});
        }
    }
}
```

## Bit manipulation

### Count the number of set bits

```cpp
int popCount(int x) {
    int count;
    for (count = 0; x != 0; ++count) {
        x &= x - 1; // zeroing out the least significant nonzero bit
    }
    return count;
}
```
