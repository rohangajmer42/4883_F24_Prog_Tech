bool judgeSquareSum(int c) {
    long a = 0, b = (long)sqrt(c);  // Use long to avoid overflow for large values of c
    
    while (a <= b) {
        long sum = a * a + b * b;
        if (sum == c) return true;
        else if (sum < c) a++;
        else b--;
    }
    
    return false;
}
