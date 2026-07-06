# 108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:

<img width="302" height="222" alt="image" src="https://github.com/user-attachments/assets/54895958-3258-4d67-9e30-24ee22766e7e" />

Input: nums = [-10,-3,0,5,9]

Output: [0,-3,9,-10,null,5]

<img width="302" height="222" alt="image" src="https://github.com/user-attachments/assets/b0559d91-0b64-4dd9-afa7-d7a1ebb4d82d" />

Explanation: [0,-10,5,null,-3,null,9] is also accepted:


## Example 2:
<img width="342" height="142" alt="image" src="https://github.com/user-attachments/assets/000c606a-b67d-4f23-a1e3-06566370bd67" />

Input: nums = [1,3]

Output: [3,1]

Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

## Constraints:

1 <= nums.length <= 10^4

-10^4 <= nums[i] <= 10^4

nums is sorted in a strictly increasing order.
