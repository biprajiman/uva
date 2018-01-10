/*
Must know things for bit operations
-   STL bitset = vector of boolean
    supports set, reset and bitset[i]
-   BITMASKS very important use interger representation and think bit representation
    MULTIPLY or divide and integer by 2 shift left or right e.g:
        S = S << 1 = S * 2
        S = S >> 2 = S / 4
        S = S >> 1 = S / 2
    SET j-th bit on use bitwise OR operation
        S |= (1 << j)
    CHECK if j-th bit is on use bitwise AND operation
        T = S & (1 << j)
    RESET j-th bit use bitwise AND operation
        S &= ~(1 << j)
    TOGGLE j-th bit on/off use bitwise XOR operation
        S ^= (1 << j)
    GET the value of LSB that is on first from the right
        T = (S & (-S)) // -S is two's complement
    To turn all the bits on use
        S = (1 << n) - 1
*/