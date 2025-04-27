# Trees

A tree is a hierarchical data structure consisting of nodes connected by edges.

- Root: The topmost node (no parent).
- Child: A node directly connected to another node moving away from the root.
- Parent: A node directly connected to another node moving towards the root.
- Siblings: Nodes that share the same parent.
- Leaf: A node with no children.
- Edge: The connection between two nodes.
- Path: A sequence of nodes connected by edges.
- Depth: The number of edges from the root to a node. Root is at depth 0.
- Height: The number of edges on the longest path from a node down to a leaf. Height of a leaf is 0. Height of the tree is the height of the root.
- Subtree: A node and all of its descendants.

## Binary Trees

A binary tree is a tree where each node has at most two children, typically referred to as the left child and the right child.

- Full Binary Tree: Every node has either 0 or 2 children.
- Complete Binary Tree: Every level is completely filled, except possibly the last level, and the last level nodes are as far left as possible.
- Perfect Binary Tree: All internal nodes have two children and all leaf nodes are at the same level.
- Balanced Binary Tree: The height difference between the left and right subtrees of any node is not more than 1. (e.g., AVL, Red-Black Trees). Binary Search Trees (BSTs) can become unbalanced.

## Binary Search Trees (BSTs)

A special type of binary tree where for every node:

- All values in the left subtree are less than the node's value.
- All values in the right subtree are greater than the node's value.
- Both the left and right subtrees are also BSTs.

### Common Operations on BSTs:

- Search: O(h) where h is the height (O(log N) average for balanced, O(N) worst case for skewed).
- Insertion: O(h).
- Deletion: O(h).
- Min/Max: O(h) (leftmost/rightmost node).

### Tree Traversals: Systematically visiting every node in the tree.

#### Depth-First Traversals:

- In-order: Left -> Node -> Right (For BSTs, this visits nodes in sorted order).
- Pre-order: Node -> Left -> Right (Useful for copying trees, expression trees).
- Post-order: Left -> Right -> Node (Useful for deleting trees, expression trees).

#### Breadth-First Traversal:

- Level-order: Visit nodes level by level from left to right. Uses a queue.

### C++ Code Example (TreeNode Struct & Recursive Traversals):

```C++
#include <iostream>
#include <vector>
#include <queue> // For Level Order

// Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive In-order Traversal
void inorderTraversal(TreeNode\* root) {
if (root == NULL) return;
inorderTraversal(root->left);
std::cout << root->val << " "; // Process node
inorderTraversal(root->right);
}

// Recursive Pre-order Traversal
void preorderTraversal(TreeNode\* root) {
if (root == NULL) return;
std::cout << root->val << " "; // Process node
preorderTraversal(root->left);
preorderTraversal(root->right);
}

// Recursive Post-order Traversal
void postorderTraversal(TreeNode\* root) {
if (root == NULL) return;
postorderTraversal(root->left);
postorderTraversal(root->right);
std::cout << root->val << " "; // Process node
}

// Iterative Level-order Traversal (using a Queue)
void levelorderTraversal(TreeNode\* root) {
if (root == NULL) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* currentNode = q.front();
        q.pop();

        std::cout << currentNode->val << " "; // Process node

        if (currentNode->left != NULL) {
            q.push(currentNode->left);
        }
        if (currentNode->right != NULL) {
            q.push(currentNode->right);
        }
    }

}

// Example Usage (Building a simple tree):
/_
// 1
// / \
// 2 3
// / \
// 4 5
TreeNode_ root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

std::cout << "In-order: "; inorderTraversal(root); std::cout << std::endl; // 4 2 5 1 3
std::cout << "Pre-order: "; preorderTraversal(root); std::cout << std::endl; // 1 2 4 5 3
std::cout << "Post-order: "; postorderTraversal(root); std::cout << std::endl; // 4 5 2 3 1
std::cout << "Level-order: "; levelorderTraversal(root); std::cout << std::endl; // 1 2 3 4 5
```

### Relevant LeetCode Problems (Trees):

- Traversals: 94. Binary Tree Inorder Traversal, 144. Binary Tree Preorder Traversal, 102. Binary Tree Level Order Traversal
- Properties: 104. Maximum Depth of Binary Tree, 110. Balanced Binary Tree, 543. Diameter of Binary Tree, 124. Binary Tree Maximum Path Sum
- BST Specific: 700. Search in a Binary Search Tree, 98. Validate Binary Search Tree, 450. Delete Node in a BST
- Other Tree Problems: 101. Symmetric Tree, 226. Invert Binary Tree, 236. Lowest Common Ancestor of a Binary Tree 2. Queues

---

### Queues

A queue is a linear data structure that follows the FIFO (First-In, First-Out) principle. The first element added is the first one to be removed.

Operations:

- enqueue (or push): Add an element to the rear of the queue.
- dequeue (or pop): Remove an element from the front of the queue.
- front (or peek): Get the front element without removing it.
- isEmpty: Check if the queue is empty.
- size: Get the number of elements.

Implementation: Can be implemented using arrays (often as a circular array to handle wrapping around) or linked lists. Linked lists are generally more efficient for dynamic size as array-based might require resizing.

Time Complexity: O(1) for enqueue, dequeue, front, isEmpty, size (with proper implementation).

Space Complexity: O(N) where N is the number of elements.

C++ Code Example (using std::queue):

C++

#include <queue>
#include <iostream>

void demonstrateQueue() {
std::queue<int> myQueue;

    // Enqueue elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    std::cout << "Queue size: " << myQueue.size() << std::endl; // Output: 3
    std::cout << "Front element: " << myQueue.front() << std::endl; // Output: 10

    // Dequeue elements
    myQueue.pop(); // Removes 10
    std::cout << "Front element after pop: " << myQueue.front() << std::endl; // Output: 20

    myQueue.pop(); // Removes 20

    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty. Front: " << myQueue.front() << std::endl; // Output: 30
    }

    myQueue.pop(); // Removes 30

    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl; // Output: Queue is empty.
    }

}

// Example usage:
// demonstrateQueue();
Use Cases for Queues:

- Breadth-First Search (BFS): The core data structure for managing nodes to visit level by level.
- Job Scheduling: Handling tasks in the order they arrive (e.g., printer queues).
- Buffering: Storing data temporarily before it's processed.
- Level Order Tree Traversal: As shown above.

### Relevant LeetCode Problems (Queues & BFS):

- 102. Binary Tree Level Order Traversal
- 103. 01 Matrix (Multi-source BFS)
- 104. Shortest Bridge (BFS from multiple sources)
- 105. Number of Islands (Can use BFS or DFS)
- 106. Stacks

---

### Stacks

A stack is a linear data structure that follows the LIFO (Last-In, First-Out) principle. The last element added is the first one to be removed.

Operations:

- push: Add an element to the top of the stack.
- pop: Remove an element from the top of the stack.
- top (or peek): Get the top element without removing it.
- isEmpty: Check if the stack is empty.
- size: Get the number of elements.

Implementation: Can be implemented using arrays or linked lists.

Time Complexity: O(1) for all operations.

Space Complexity: O(N) where N is the number of elements.

C++ Code Example (using std::stack):

```C++
#include <stack>
#include <iostream>
#include <string>
#include <algorithm> // For reverse

void demonstrateStack() {
std::stack<int> myStack;

    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Stack size: " << myStack.size() << std::endl; // Output: 3
    std::cout << "Top element: " << myStack.top() << std::endl; // Output: 30

    // Pop elements
    myStack.pop(); // Removes 30
    std::cout << "Top element after pop: " << myStack.top() << std::endl; // Output: 20

    myStack.pop(); // Removes 20

    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty. Top: " << myStack.top() << std::endl; // Output: 10
    }

    myStack.pop(); // Removes 10

    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl; // Output: Stack is empty.
    }

}

// Use case example: Reverse a string using a stack
std::string reverseString(const std::string& str) {
std::stack<char> charStack;
for (char c : str) {
charStack.push(c);
}
std::string reversed_str = "";
while (!charStack.empty()) {
reversed_str += charStack.top();
charStack.pop();
}
return reversed_str;
}
```

### Use Cases for Stacks:

- Depth-First Search (DFS): Can be implemented iteratively using a stack. Recursive DFS uses the call stack implicitly.
- Function Call Stack: Manages function calls and local variables.
- Expression Evaluation: Converting infix to postfix, evaluating postfix expressions.
- Backtracking: Managing states in recursive backtracking algorithms.
- Undo/Redo Functionality.
- Parsing.

### Relevant LeetCode Problems (Stacks & DFS):

- 20. Valid Parentheses (Classic stack problem)
- 21. Evaluate Reverse Polish Notation (Stack for expression evaluation)
- 22. Daily Temperatures (Monotonic Stack)
- 23. Largest Rectangle in Histogram (Stack-based O(N) solution)
- 24. Number of Islands (Can use BFS or DFS - recursive DFS uses stack)
- 25. Hash Tables (Maps and Sets)
      Hash tables provide very fast average-case performance for insertion, deletion, and lookup by using a hash function to map keys to indices (buckets) in an underlying array.

Concept: A hash function takes a key and returns an integer hash code. This hash code is then mapped to an index in the internal array.
Collision Handling: When two different keys hash to the same index, collisions occur. Common strategies are Chaining (using linked lists in each bucket) or Open Addressing (probing for the next available slot).
Average Time Complexity: O(1) for insertion, deletion, and lookup.
Worst-Case Time Complexity: O(N) if there are excessive collisions leading to a linked list traversal (in chaining) or extensive probing (in open addressing). This usually happens with a poor hash function or adversarial input.
Space Complexity: O(N) to store N elements.
C++ STL Equivalents:

std::unordered_map: Implements a hash map (key-value pairs). Average O(1) operations.
std::unordered_set: Implements a hash set (stores unique keys). Average O(1) operations.
std::map: Implemented using a balanced Binary Search Tree (Red-Black Tree). O(log N) operations. Keys are stored in sorted order.
std::set: Implemented using a balanced Binary Search Tree. O(log N) operations. Keys are stored in sorted order.
In interviews, unordered_map and unordered_set are often used when O(1) average time complexity is needed. map and set are used when sorted order is required.

C++ Code Example (using std::unordered_map and std::unordered_set):

```C++
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

void demonstrateHashTables() {
// Using unordered_map (key-value)
std::unordered_map<std::string, int> wordCounts;
wordCounts["apple"] = 2;
wordCounts["banana"] = 3;
wordCounts["apple"]++; // Increment count

    std::cout << "Apple count: " << wordCounts["apple"] << std::endl; // Output: 3

    if (wordCounts.count("banana")) { // Check if key exists
        std::cout << "Banana count: " << wordCounts["banana"] << std::endl; // Output: 3
    }

    // Iterate
    for (const auto& pair : wordCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Order is not guaranteed
    }

    // Using unordered_set (stores unique keys)
    std::unordered_set<int> uniqueNumbers;
    uniqueNumbers.insert(10);
    uniqueNumbers.insert(20);
    uniqueNumbers.insert(10); // Duplicate, won't be inserted

    std::cout << "Set size: " << uniqueNumbers.size() << std::endl; // Output: 2

    if (uniqueNumbers.count(20)) { // Check if element exists
        std::cout << "Set contains 20." << std::endl; // Output: Set contains 20.
    }
    if (uniqueNumbers.find(50) == uniqueNumbers.end()) { // Another way to check existence
         std::cout << "Set does not contain 50." << std::endl; // Output: Set does not contain 50.
    }

}
```

### Use Cases for Hash Tables:

- Frequency Counting: Counting occurrences of elements (using map).
- Checking Presence/Uniqueness: Quickly checking if an element exists (using set).
- Caching/Memoization: Storing computed results (like in DP, though arrays are used for integer indices).
- Implementing Dictionaries/Associative Arrays.
- Grouping Elements: Grouping items by a common key (e.g., anagrams).

### Relevant LeetCode Problems (Hash Tables):

- 1. Two Sum (Classic hash map problem)
- 2. Contains Duplicate (Using hash set)
- 3. Group Anagrams (Using hash map where key is sorted string/char count, value is list of anagrams)
- 4. Longest Consecutive Sequence (Efficient solution uses hash set)
- 5. Longest Substring Without Repeating Characters (Sliding window with hash map/set)
- 6. Ransom Note (Frequency counting with hash map)

### Linked Lists

A linked list is a linear data structure where elements are not stored in contiguous memory locations. Instead, each element (node) contains data and a pointer (or link) to the next node in the sequence.

- Node: Typically a struct or class containing data and a next pointer.
- Head: Pointer to the first node.
- Tail: Pointer to the last node.
- Types:
  - Singly Linked List: Nodes have a pointer only to the next node.
  - Doubly Linked List: Nodes have pointers to both the next and the previous nodes.
  - Circular Linked List: The last node points back to the first node.

Common Operations on Singly Linked Lists:

- Traversal: O(N)
- Insertion: O(1) at the head (if you have a head pointer). O(1) at the tail if you have a tail pointer. O(1) after a given node. O(N) to insert at a specific index.
- Deletion: O(1) at the head. O(N) to delete a specific node or at a specific index (requires traversal to the previous node).
- Search: O(N).

C++ Code Example (Singly Linked List Node & Basic Operations):

```cpp
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
int val;
ListNode\* next;
ListNode(int x) : val(x), next(NULL) {}
// Note: In real code, destructor for memory management would be needed
};

// Function to insert a node at the head
ListNode* insertAtHead(ListNode* head, int val) {
ListNode\* newNode = new ListNode(val);
newNode->next = head;
return newNode; // New head is the inserted node
}

// Function to print the linked list
void printList(ListNode* head) {
ListNode* current = head;
while (current != NULL) {
std::cout << current->val << " -> ";
current = current->next;
}
std::cout << "NULL" << std::endl;
}

// Function to reverse a linked list (iterative)
ListNode* reverseList(ListNode* head) {
ListNode* prev = NULL;
ListNode* current = head;
ListNode\* next_node = NULL;

    while (current != NULL) {
        next_node = current->next; // Store next
        current->next = prev;      // Reverse current node's pointer
        prev = current;            // Move pointers one position ahead
        current = next_node;
    }
    return prev; // Prev is the new head

}

// Example Usage:
/_
ListNode_ head = NULL;
head = insertAtHead(head, 3); // List: 3 -> NULL
head = insertAtHead(head, 2); // List: 2 -> 3 -> NULL
head = insertAtHead(head, 1); // List: 1 -> 2 -> 3 -> NULL

std::cout << "Original list: ";
printList(head); // Output: 1 -> 2 -> 3 -> NULL

head = reverseList(head);

std::cout << "Reversed list: ";
printList(head); // Output: 3 -> 2 -> 1 -> NULL
```

### Use Cases for Linked Lists:

- Implementing Stacks and Queues.
- Managing dynamic collections of data where frequent insertions/deletions occur, especially in the middle (though finding the insertion/deletion point can still be O(N)).
- Representing sparse data structures.
- Polynomial representation.

### Relevant LeetCode Problems (Linked Lists):

- 206. Reverse Linked List (Iterative and Recursive)
- 207. Merge Two Sorted Lists
- 208. Linked List Cycle (Floyd's cycle-finding algorithm)
- 209. Remove Nth Node From End of List (Two-pointer approach)
- 210. Middle of the Linked List (Two-pointer fast/slow approach)
- 211. Merge k Sorted Lists (Often uses a priority queue)
- 212. Add Two Numbers
- 213. Heaps and Priority Queues

### Heaps and Priority Queues

A heap is a complete binary tree that satisfies the heap property:

- In a Min-Heap, the value of a node is less than or equal to the values of its children. The minimum element is at the root.
- In a Max-Heap, the value of a node is greater than or equal to the values of its children. The maximum element is at the root.
  Heaps are typically implemented using an array.

#### Priority Queue:

An abstract data structure that functions like a queue but where each element has a priority. Elements are dequeued based on their priority. Heaps are the most common way to implement priority queues efficiently.

#### Common Operations on Heaps/Priority Queues:

- insert: Add an element. O(log N).
- deleteMax/deleteMin (or pop): Remove the root (max or min element). O(log N).
- peekMax/peekMin (or top): Get the root element without removing it. O(1).
- heapify: Building a heap from an array. O(N).
  C++ STL Equivalent:

std::priority_queue: Implements a max-heap by default. Can be made a min-heap by providing a custom comparator or storing negated values.

```C++
#include <queue> // Includes priority_queue
#include <vector>
#include <iostream>
#include <functional> // For std::greater

void demonstratePriorityQueue() {
// Max-heap (default)
std::priority_queue<int> maxHeap;
maxHeap.push(10);
maxHeap.push(30);
maxHeap.push(20);

    std::cout << "Max-heap top: " << maxHeap.top() << std::endl; // Output: 30
    maxHeap.pop(); // Removes 30
    std::cout << "Max-heap top after pop: " << maxHeap.top() << std::endl; // Output: 20

    // Min-heap (using std::greater)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    std::cout << "Min-heap top: " << minHeap.top() << std::endl; // Output: 10
    minHeap.pop(); // Removes 10
    std::cout << "Min-heap top after pop: " << minHeap.top() << std::endl; // Output: 20

}

// Example usage:
// demonstratePriorityQueue();
```

### Use Cases for Heaps/Priority Queues:

- Graph Algorithms: Dijkstra's algorithm (finding shortest paths), Prim's algorithm (finding MST).
- Sorting: Heapsort.
- Finding Kth Smallest/Largest Element: Using a min-heap or max-heap of size K.
- Event Simulation.
- Huffman Coding.

### Relevant LeetCode Problems (Heaps/Priority Queues):

- 215. Kth Largest Element in an Array (Classic Heap problem)
- 216. Top K Frequent Elements (Heap + Hash Map)
- 217. Merge k Sorted Lists (Using a min-priority queue)
- 218. Kth Largest Element in a Stream
- 219. Task Scheduler (Heap/Priority Queue + Greedy)

### 220. Other Data Structures (Briefly)

- Arrays/Vectors: Contiguous memory, O(1) access by index, O(N) insertion/deletion (unless at end for vector). Fundamental.
- Strings: Sequence of characters, often treated like arrays or character vectors. String manipulation problems are common.
- Union-Find (Disjoint Set Union): Efficiently manages disjoint sets. O(α(N)) amortized time for find/union with path compression and union by rank/size. Used in Kruskal's MST algorithm and connected components. (Covered partially in Graphs section).

### 221. General Data Structure Interview Tips

- Understand the Problem Constraints: What are the data size, time limits, memory limits? This helps determine which DS/algorithm is feasible.
- Analyze Access Patterns: Will you need fast lookups? Frequent insertions/deletions? Ordered traversal? Random access? This strongly dictates the DS choice.
- Trade-offs: Be aware of the trade-offs between different data structures (e.g., Hash Table O(1) average vs. BST O(log N) worst case, but BSTs provide sorted order).
- Know Your Standard Library: Be familiar with the C++ STL containers (vector, list, deque, queue, stack, priority_queue, set, map, unordered_set, unordered_map). Know their complexities and typical use cases.
- Practice Implementations: While STL is often used, being able to implement basic DS operations (like linked list reversal, tree traversals) from scratch shows deeper understanding.
- Consider Space Complexity: Sometimes an algorithm with a slightly worse time complexity might be preferred if it has significantly better space complexity.
- Think Step-by-Step: Break down the problem. Can a specific DS help manage the data needed at each step?
