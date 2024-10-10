class Solution {
    public int[] plusOne(int[] digits) {
        List<Integer> result = Arrays.stream(digits).boxed().collect(Collectors.toList());
        Collections.reverse(result);
        int add = 1, i = 0;
        while (add > 0){
            if (i < result.size()){
                if (result.get(i) == 9){
                    result.set(i, 0);
                }
                else{
                    result.set(i, result.get(i) + 1);
                    add = 0;
                }
            }
            else{
                result.add(1);
                add = 0;
            }
            i += 1;
        }
        Collections.reverse(result);
        return result.stream().mapToInt(j->j).toArray();
    }
}