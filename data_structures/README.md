# Data Structures

| Data Structure | `get()` | `has()` | `set()` | `add()`    | `remove()` |
| -------------- | ------- | ------- | ------- | ---------- | ---------- |
| ArrayList      | `O(1)`  | `O(n)`  | `O(1)`  | `O(n)`     | `O(n)`     |
| HashMap        | `O(1)`  | `O(1)`  | `O(1)`  | `O(1)`     | `O(1)`     |
| LinkedList     | `O(n)`  | `O(n)`  | `O(n)`  | `O(n)`\*   | `O(n)`\*   |
| Queue          | `O(1)`  | `O(n)`  | `O(1)`  | `O(1)`\*\* | `O(1)`\*\* |
| Stack          | `O(1)`  | `O(n)`  | `O(1)`  | `O(1)`\*\* | `O(1)`\*\* |

## Notes

\* LinkedList: `add()` and `remove()` are `O(1)` at the head

\*\* Stack & Queue: `push()`/`pop()` and `enqueue()`/`dequeue()` are `O(1)`
