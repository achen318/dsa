# Data Structures

| Data Structure | `get()`    | `has()` | `set()` | `add()`    | `remove()` |
| -------------- | ---------- | ------- | ------- | ---------- | ---------- |
| ArrayList      | `O(1)`     | `O(n)`  | `O(1)`  | `O(n)`     | `O(n)`     |
| LinkedList     | `O(n)`     | `O(n)`  | `O(n)`  | `O(n)`\*   | `O(n)`\*   |
| Stack          | `O(1)`\*\* | `O(n)`  | `O(n)`  | `O(1)`\*\* | `O(1)`\*\* |

## Notes

\* LinkedList: `add()` and `remove()` are `O(1)` at the head

\*\* Stack: `top()`, `push()`, and `pop()` are `O(1)`
