#include <iostream>
#include <chrono>
#include <cstring>

class FixedSizeMemoryPool {
private:
    struct Block {
        Block* next;
    };

    Block* freeList;
    size_t blockSize;
    size_t poolSize;
    uint8_t* pool;

public:
    FixedSizeMemoryPool(size_t blockSize, size_t poolSize)
        : blockSize(blockSize), poolSize(poolSize), freeList(nullptr), pool(nullptr) {
        if (blockSize < sizeof(Block)) {
            std::cerr << "Error: Block size too small\n";
            return;
        }

        pool = new uint8_t[blockSize * poolSize];
        if (!pool) {
            std::cerr << "Error: Failed to allocate memory pool\n";
            return;
        }

        freeList = reinterpret_cast<Block*>(pool);

        Block* current = freeList;
        for (size_t i = 1; i < poolSize; ++i) {
            current->next = reinterpret_cast<Block*>(pool + i * blockSize);
            current = current->next;
        }
        current->next = nullptr;
    }

    ~FixedSizeMemoryPool() {
        delete[] pool;
    }

    void* allocate() {
        if (!freeList) {
            std::cerr << "Error: Memory pool exhausted\n";
            return nullptr;
        }

        Block* allocatedBlock = freeList;
        freeList = freeList->next;
        return allocatedBlock;
    }

    void deallocate(void* ptr) {
        if (!ptr) {
            std::cerr << "Error: Attempt to deallocate a null pointer\n";
            return;
        }

        Block* block = reinterpret_cast<Block*>(ptr);
        block->next = freeList;
        freeList = block;
    }

    size_t getFreeBlocks() const {
        size_t count = 0;
        Block* current = freeList;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }
};

#define ITERATIONS 10000

void measurePoolAllocation(FixedSizeMemoryPool& memoryPool) {
    const size_t iterations = ITERATIONS;
    volatile uint8_t* dummy; // Prevent optimization by using volatile
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < iterations; ++i) {
        void* ptr = memoryPool.allocate();
        if (ptr) {
            dummy = reinterpret_cast<uint8_t*>(ptr); // Use allocated memory
            *dummy = static_cast<uint8_t>(i);        // Write to memory
            memoryPool.deallocate(ptr);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Time taken for pool allocation/deallocation: " << elapsed.count() << " milliseconds\n";
}

int main() {
    const size_t blockSize = 32;
    const size_t poolSize = 100;

    FixedSizeMemoryPool memoryPool(blockSize, poolSize);

    measurePoolAllocation(memoryPool);

    return 0;
}
