# [hard] #0041 缺失的第一个正数

## 思路

置换法。

考虑：

- 长度为 N 的 int 数组，一定有最小正整数 $X \in [1, N+1]$。证：若 $ \forall x \in [1,N] $，则 $X=N+1$；若 $\exist x \notin [0,N]$，则 $X=x_{min}$。
- 遍历 $nums[i]$，原地置换
    - 对于 $nums[i] \in [1,N]$, 置换 $nums[i]$ 到下标为 $nums[i]-1$ 的位置，直到 $ nums[i] \notin [1,N]$
- 遍历 $nums[i]$
    - 若 $nums[i]$ != $nums[i] + 1$， 说明 $ nums[i] \notin [1,N]$，返回 $i + 1$; 
- 返回 $N + 1$
