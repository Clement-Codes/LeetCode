class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int l = 0;
        int sum = 0;
        int result[] = new int[n];
        Arrays.fill(result, 0);
        for (int r = 0; r < n + Math.abs(k); r++){
            sum += code[r % n];
            if (r - l + 1 > Math.abs(k)){
                sum -= code[l];
                l = (l + 1) % n;
            }

            if (r - l + 1 == Math.abs(k)){
                if (k > 0){
                    result[(l - 1 + n) % n] = sum;
                }
                else if (k < 0){
                    result[(r + 1 + n) % n] = sum;
                }
            }

        }
        return result;
        // Using loops
        // int n = code.length;
        // int result[] = new int[n];
        // Arrays.fill(result, 0);
        // for (int i = 0; i < n; i++)
        //     if (k > 0)
        //         for (int j = i + 1; j < i + k + 1; j++)
        //             result[i] += code[j % n];
        //     else if (k < 0)
        //         for (int j = i - 1; j > i - Math.abs(k) -1 ; j--)
        //             result[i] += code[(j + n)% n];                    
        // return result;
    }
}