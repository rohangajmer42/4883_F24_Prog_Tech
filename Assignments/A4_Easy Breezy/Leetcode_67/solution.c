char* addBinary(char* a, char* b) {
    static char result[10005];  
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i = lenA - 1, j = lenB - 1;
    int k = 10004;  
    result[k--] = '\0';  

    int carry = 0;

    // Traverse both strings from end to beginning
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;  // Start with carry value
        if (i >= 0) sum += a[i--] - '0';  // Add digit from `a` if available
        if (j >= 0) sum += b[j--] - '0';  // Add digit from `b` if available
        
        result[k--] = (sum % 2) + '0';  // Store the binary result in static array
        carry = sum / 2;  // Update carry for next position
    }

    // Return the pointer to the result, skipping leading zeros
    return &result[k + 1];
}
