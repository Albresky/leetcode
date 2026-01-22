# [mid] #0011 盛最多水的容器

## 思路

用双指针：l和r分别代表容器的左右两边，始终向中心移动高度较小的边，每次移动后更新 max volume。

显然，这样的时间复杂度是 $O(n）$，而模拟法为$O(n^2)$。易证：上述算法严格收敛，过程见题解：[LeetCode/0011-盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/solutions/207215/sheng-zui-duo-shui-de-rong-qi-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked)