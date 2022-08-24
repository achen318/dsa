# Data Structures

| Data Structure                                                      | `get()` | `has()` | `set()` | `add()`    | `remove()` |
| ------------------------------------------------------------------- | ------- | ------- | ------- | ---------- | ---------- |
| [ArrayList](https://en.wikipedia.org/wiki/Dynamic_array)            | `O(1)`  | `O(n)`  | `O(1)`  | `O(n)`     | `O(n)`     |
| [HashMap](https://en.wikipedia.org/wiki/Hash_table)                 | `O(1)`  | `O(1)`  | `O(1)`  | `O(1)`     | `O(1)`     |
| [LinkedList](https://en.wikipedia.org/wiki/Linked_list)             | `O(n)`  | `O(n)`  | `O(n)`  | `O(n)`\*   | `O(n)`\*   |
| [Queue](<https://en.wikipedia.org/wiki/Queue_(abstract_data_type)>) | `O(1)`  | `O(n)`  | `O(1)`  | `O(1)`\*\* | `O(1)`\*\* |
| [Stack](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>) | `O(1)`  | `O(n)`  | `O(1)`  | `O(1)`\*\* | `O(1)`\*\* |

## Notes

\* LinkedList: `add()` and `remove()` are `O(1)` at the head

\*\* Stack & Queue: `push()`/`pop()` and `enqueue()`/`dequeue()` are `O(1)`
