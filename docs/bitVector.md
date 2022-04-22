# Bit Vector


C++ class of bit vector. Bit vector is array of values { 0,1 }.

```cpp
#inlcude <halkoPP/BitVector>

int main() {
    int32_t n = 10;
    Bitvector bv = Bitvector(n); // bit vector of lenght ten
}
```

## Functions

### access(<font color="#E9A900">uint32_t</font> $i$)

* uint32_t $i = [0..n]$, where $n = |B|$

**Return**: $i$ **th** bit value in bit vector $B$

**Time complexity**: $O(1)$

#### Example

```cpp
#inlcude <halkoPP/BitVector>

int main() {
    int32_t n = 10;
    Bitvector bv = Bitvector(n); // bit vector of lenght ten

    bv.set(3);
    bv.set(7);

    cout << bv.access(0) << "\n";
    cout << bv.access(2) << "\n";
    cout << bv.access(3) << "\n";
    cout << bv.access(4) << "\n";
    cout << bv.access(7) << "\n";
}
```
```
0
0
1
0
1
```

### rank1

### select1
