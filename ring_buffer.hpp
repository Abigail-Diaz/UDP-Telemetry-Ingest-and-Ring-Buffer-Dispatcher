#pragma once

#include <atomic>
#include <cstddef>

// TODO: implement a bounded lock-free ring buffer.
// Decide SPSC vs MPMC first. Think about memory orders and false sharing.
template <typename T, std::size_t Capacity>
class RingBuffer {
    static_assert(Capacity >= 2 && (Capacity & (Capacity - 1)) == 0,
                  "Capacity must be a power of two");

public:
    // Producer side. Returns false if full. Must never block.
    bool try_push(const T& item) {
        (void)item;
        return false;  // TODO
    }

    // Consumer side. Returns false if empty. Must never block.
    bool try_pop(T& out) {
        (void)out;
        return false;  // TODO
    }
};
