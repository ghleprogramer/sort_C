/* Function sorts a list of integers  */
void
merge_sort(int L[], int index_i, int len)
{
    /*
     * L a list of integers
     * INDEX_I is the start of the list (zero)
     * LEN in the length of the list
     */
    if (len <= 1) /* base case */
        return;
    /*
     * Sorting of the right and the left sides
     * of the list
     */
    int right_i = index_i;
    int right_len = len / 2;
    int left_i = right_i + right_len;
    int left_len = len - right_len;
    merge_sort(L, right_i, right_len);
    merge_sort(L, left_i, left_len);
    /* Mergeing of the two sides  */
    int sorted[len];
    int sorted_index = 0;
    int right_index = 0;
    int left_index = 0;
    for (; right_index < right_len
        && left_index < left_len; sorted_index++) {
        if (L[right_i + right_index] < L[left_i + left_index]) {
            /* right in smaller  */
            sorted[sorted_index] = L[right_i + right_index];
            right_index++;
            continue;
        }
        /* left is smaller  */
        sorted[sorted_index] = L[left_i + left_index];
        left_index++;
    }
    /* adding the remaining list  */
    for (; right_index < right_len;
    right_index++, sorted_index++) {
        sorted[sorted_index] = L[right_i + right_index];
    }
    for (; left_index < left_len
        ;left_index++, sorted_index++) {
        sorted[sorted_index] = L[left_i + left_index];
    }
    /* final assignment to list  */
    for (int i = 0; i < len; i++) {
        L[index_i + i] = sorted[i];
    }
    return;
}
