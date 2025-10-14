# [mid] #0039 组合总和

## 思路

- 从 candidates 里选数，使得和为 target。
- 有两种选法：
  - 1. 要么 选 candidates[idx]，继续从 idx 位置选（因为可以重复选）
  - 2. 要么 不选 candidates[idx]，从 idx + 1 位置选
  - 3. 结束条件是当 target == 0 时，找到一种组合；当 target < 0 时，剪枝
  - 4. idx 越界时，剪枝
  