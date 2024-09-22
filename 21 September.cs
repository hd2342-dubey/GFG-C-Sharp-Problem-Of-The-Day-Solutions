public int lps(string str) 
{
    int n = str.Length;
    
    int[] ans = new int[n];
    
    int i = 0, j = 1;
    
    while (j < n) {
        if (str[i] == str[j]) {
            ans[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                ans[j] = 0;
                j++;
            } else {
                i = ans[i - 1];
            }
        }
    }
    
    return ans[n - 1];
}