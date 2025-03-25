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

## Design Approach

We use **two internal queues**:

- `queue<RGThing> redQ`
- `queue<RGThing> greenQ`

Each queue stores items of a single color. This keeps the logic clean and avoids tricky reordering.

---

## Behavior

### `insert(RGThing item)`

Each `RGThing` goes into its matching color queue:

```cpp
void insert(RGThing item) {
    if (item.color == RED)
        redQ.push(item);
    else
        greenQ.push(item);
}
```

---

### `remove()`

Return the frontmost RED and GREEN as a pair, if both exist:

```cpp
RGTpair remove() {
    if (redQ.empty() || greenQ.empty())
        throw runtime_error("Not enough to form a pair");

    RGTpair pair = { redQ.front(), greenQ.front() };
    redQ.pop();
    greenQ.pop();
    return pair;
}
```

---

### `empty()`

```cpp
bool empty() {
    return redQ.empty() || greenQ.empty();
}
```

---

## Why This Works

This method:

- Keeps insertion O(1)
- Keeps removal O(1)
- Avoids unnecessary traversal or reordering
- Keeps color order independent but respects arrival time within each color

---

## Edge Cases

| Situation                  | Behavior                         |
|---------------------------|----------------------------------|
| Only RED or GREEN items   | `empty()` returns true           |
| No items at all           | `empty()` returns true           |
| One RED and one GREEN     | `remove()` returns the pair      |

---

## Final Thoughts

This queue isn’t just about order. It’s about coordination between RED and GREEN.  
Separating them makes it easy to know when a match is ready—no need for color-matching logic inside one big queue.
