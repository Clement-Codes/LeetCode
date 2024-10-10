class Solution {
    public String reverse(String num1){
        String result = "";
        for (int i = num1.length() - 1; i >= 0; i--)
            result += num1.charAt(i);
        return result;
    }
    public int[] reverseArray(int num1[]){
        int result[] = new int[num1.length];
        int index = 0;
        for (int i = num1.length - 1; i >= 0; i--){
            result[index] = num1[i];
            index += 1;
        }
        return result;
    }
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        int temp[] = new int[num1.length() + num2.length()];
        Arrays.fill(temp, 0);
        num1 = reverse(num1);
        num2 = reverse(num2);
        for (int i = 0; i < num1.length(); i++){
            for (int j = 0; j < num2.length(); j++){
                int k = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                temp[i + j] += k;
                temp[i + j + 1] += temp[i + j] / 10;
                temp[i + j] = temp[i + j] % 10;
            }
        }
        temp = reverseArray(temp);

        int begin = 0;
        while (begin < (num1.length() +  num2.length()) && temp[begin] == 0)
            begin += 1;

        String result = "";
        for (int i = begin; i < (num1.length() + num2.length()); i++)
            result += temp[i];
        return result;
    }
}