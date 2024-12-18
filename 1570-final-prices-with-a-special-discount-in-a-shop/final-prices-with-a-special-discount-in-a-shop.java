class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < prices.length; i++)
        {
            while (s.size() > 0 && prices[i] <= prices[s.peek()])
            {
                prices[s.peek()] -= prices[i];
                s.pop();
            }
            s.push(i);
        }
        return prices;
    }
}