#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

//TreeNode Definition
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree Operations
TreeNode* insertIntoBinaryTree(TreeNode* root, int data) {
    if (root == nullptr) {
        root = new TreeNode(data);
        return root;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new TreeNode(data);
            return root; // Return the unchanged root after insertion
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new TreeNode(data);
            return root; // Return the unchanged root after insertion
        } else {
            q.push(temp->right);
        }
    }

    return root;
}


void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

bool searchBinaryTree(TreeNode* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchBinaryTree(root->left, key) || searchBinaryTree(root->right, key);
}

TreeNode* deleteBinaryTree(TreeNode* root, int key, bool& isDeleted) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteBinaryTree(root->left, key, isDeleted);
    } else if (key > root->data) {
        root->right = deleteBinaryTree(root->right, key, isDeleted);
    } else {
        isDeleted = true;
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteBinaryTree(root->right, temp->data, isDeleted);
    }
    return root;
}

void binaryTreeOperations(TreeNode*& root) {
    int value;
    cout << "Enter numbers to insert into Binary Tree (enter 0 to stop):\n";
    while (true) {
        cin >> value; // Read user input
        if (value == 0) { // Stop loop immediately if user enters 0
            break;
        }

        // Call insert function only if value is valid and not 0
        root = insertIntoBinaryTree(root, value);
        cout << "Inserted " << value << endl;
    }

    int choice;
    do {
        cout << "\nBinary Tree Options:\n";
        cout << "1. Traversals\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nPreorder: ";
                preorderTraversal(root);
                cout << "\nInorder: ";
                inorderTraversal(root);
                cout << "\nPostorder: ";
                postorderTraversal(root);
                cout << endl;
                break;
           case 2: {
                int key;
                cout << "Please enter the number you want to search: ";
                cin >> key;

                bool found = searchBinaryTree(root, key);
                if (found) {
                    cout << "The number " << key << " was found in the tree." << endl;
                } else {
                    cout << "The number " << key << " is not in the tree." << endl;
                }
                break;
            }
            case 3: {
                int key;
                bool isDeleted = false;

                cout << "Enter number to delete: ";
                cin >> key;

                root = deleteBinaryTree(root, key, isDeleted);

                if (isDeleted) {
                    cout << "Deleted successfully." << endl;
                    cout << "Current Inorder Traversal: ";
                    inorderTraversal(root);
                    cout << endl;
                } else {
                    cout << "Number not found." << endl;
                }

                break;
            }

            case 4:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}


// BST Operations
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->data)
        root->left = insertIntoBST(root->left, val);
    else if (val > root->data)
        root->right = insertIntoBST(root->right, val);
    return root;
}

void bstOperations() {
    TreeNode* root = nullptr;
    int val;

    // Input loop with stop condition
    cout << "\nEnter numbers to insert into BST (enter 0 to stop):\n";
    while (true) {
        cin >> val; // Read user input
        if (val == 0) { // Stop the loop on entering 0
            break;
        }

        // Insert value into BST only if it's valid
        root = insertIntoBST(root, val);
        cout << "Inserted " << val << endl;
    }

    int choice;
    do {
        cout << "\nBST Options:\n";
        cout << "1. Traversals\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nPreorder: ";
                preorderTraversal(root);
                cout << "\nInorder: ";
                inorderTraversal(root);
                cout << "\nPostorder: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 2: {
                int key;
                cout << "Please enter the number you want to search: ";
                cin >> key;

                bool found = searchBinaryTree(root, key);
                if (found) {
                    cout << "The number " << key << " was found in the tree." << endl;
                } else {
                    cout << "The number " << key << " is not in the tree." << endl;
                }
                break;
            }

            case 3: {
                int key;
                bool isDeleted = false;

                cout << "Enter number to delete: ";
                cin >> key;

                root = deleteBinaryTree(root, key, isDeleted);

                if (isDeleted) {
                    cout << "Deleted successfully." << endl;
                    cout << "Current Inorder Traversal: ";
                    inorderTraversal(root);
                    cout << endl;
                } else {
                    cout << "Number not found." << endl;
                }

                break;
            }

            case 4:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

// Max-Heapify Logic
void maxHeapify(vector<int>& heap, int i, int n) {
    int largest = i;                     // Start with root index
    int left = 2 * i + 1;               // Left child index
    int right = 2 * i + 2;              // Right child index

    // If left child is larger than root
    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    // If root is not largest, swap and heapify recursively
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest, n);
    }
}

// Min-Heapify Logic
void minHeapify(vector<int>& heap, int i, int n) {
    int smallest = i;                   // Start with root index
    int left = 2 * i + 1;               // Left child index
    int right = 2 * i + 2;              // Right child index

    // If left child is smaller than root
    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }

    // If right child is smaller than the smallest so far
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // If root is not the smallest, swap and heapify recursively
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest, n);
    }
}

// Build Max-Heap
void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, i, n);
    }
}

// Build Min-Heap
void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, i, n);
    }
}
// Heap Sort with Max-Heap logic (Descending order)
void heapSortMaxHeap(vector<int>& heap) {
    buildMaxHeap(heap);
    int n = heap.size();
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (largest element) with the last element
        swap(heap[0], heap[i]);
        // Restore heap property
        maxHeapify(heap, 0, i);
    }
}
// Heap Sort with Min-Heap logic (Ascending order)
void heapSortMinHeap(vector<int>& heap) {
    buildMinHeap(heap);
    int n = heap.size();
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (smallest element) with the last element
        swap(heap[0], heap[i]);
        // Restore heap property
        minHeapify(heap, 0, i);
    }
}
// Menu system for heap operations
void heapOperations() {
    vector<int> heap;
    int value;

    // Prompt for heap input until the user enters 0 to stop
    cout << "Enter numbers to insert into Heap (enter 0 to stop):\n";
    while (true) {
        cin >> value; // Read input
        if (value == 0) {
            break; // Stop loop if 0 is entered
        }
        heap.push_back(value);
        cout << "Inserted " << value << endl;
    }

    int choice;
    do {
        cout << "\nHeap Options:\n";
        cout << "1. Max-Heap\n";
        cout << "2. Min-Heap\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                heapSortMinHeap(heap);
                cout << "Max-Heap: ";
                for (int x : heap) {
                    cout << x << " ";
                }
                cout << endl;
                break;

            case 2:
                heapSortMaxHeap(heap);
                cout << "Min-Heap: ";
                for (int x : heap) {
                    cout << x << " ";
                }
                cout << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);
}
int main() {
    TreeNode* binaryTreeRoot = nullptr;
    int choice;

    do {
        cout << "Exploring and Building Binary Tree, Binary Search Tree, and Heaps" << endl;
        cout << "Main Menu:" << endl;
        cout << "1. Binary Tree" << endl;
        cout << "2. BST" << endl;
        cout << "3. Heap" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                binaryTreeOperations(binaryTreeRoot);
                break;
            case 2:
                bstOperations();
                break;
            case 3:
                heapOperations();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
