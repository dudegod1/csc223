# RGPTQ

## Overview

The assignment:
Design a queue-like class, `RGTPQ`, that accepts `RGThing` objects but only removes *pairs* specifically, one Red and one Green

### Given types:
```cpp
enum Color { RED, GREEN };
struct RGThing {
    Color color;
    string label;
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};
```

### Core Operations

- `insert(RGThing)` – Add one item at a time.
- `remove()` – Return a `RGTpair` made of one RED and one GREEN.
- `empty()` – True if not enough to form a pair.

---
