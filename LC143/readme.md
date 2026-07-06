# 143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

- L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

- L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

## Example 1:
<img width="422" height="222" alt="image" src="https://github.com/user-attachments/assets/1f0e924e-e539-4354-9ac0-0f5754a9e555" />


Input: head = [1,2,3,4]

Output: [1,4,2,3]
## Example 2:
<img width="542" height="222" alt="image" src="https://github.com/user-attachments/assets/d60f5910-a1f3-4f77-af46-ed1135bbe4a3" />


Input: head = [1,2,3,4,5]

Output: [1,5,2,4,3]
 

## Constraints:

The number of nodes in the list is in the range [1, 5 * 104].

1 <= Node.val <= 1000
