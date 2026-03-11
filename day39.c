class MinHeap:
    def __init__(self):
        self.heap = []

    # Insert element
    def insert(self, x):
        self.heap.append(x)
        self.heapify_up(len(self.heap) - 1)

    # Heapify upward
    def heapify_up(self, index):
        parent = (index - 1) // 2
        while index > 0 and self.heap[parent] > self.heap[index]:
            self.heap[parent], self.heap[index] = self.heap[index], self.heap[parent]
            index = parent
            parent = (index - 1) // 2

    # Heapify downward
    def heapify_down(self, index):
        smallest = index
        left = 2 * index + 1
        right = 2 * index + 2
        n = len(self.heap)

        if left < n and self.heap[left] < self.heap[smallest]:
            smallest = left

        if right < n and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self.heapify_down(smallest)

    # Peek minimum element
    def peek(self):
        if len(self.heap) == 0:
            print(-1)
        else:
            print(self.heap[0])

    # Extract minimum element
    def extractMin(self):
        if len(self.heap) == 0:
            print(-1)
            return

        root = self.heap[0]
        last = self.heap.pop()

        if len(self.heap) > 0:
            self.heap[0] = last
            self.heapify_down(0)

        print(root)


# Main Program
n = int(input())

heap = MinHeap()

for _ in range(n):
    operation = input().split()

    if operation[0] == "insert":
        heap.insert(int(operation[1]))

    elif operation[0] == "peek":
        heap.peek()

    elif operation[0] == "extractMin":
        heap.extractMin()